#!/bin/bash
# Script name: mmanager (music manager)
# Author: Michal Jasiak s197577@student.pg.edu.pl
# Version: 1.0
# Last update: 19.05.2024r.
# Description:
# External software required: curl, yt-dlp, ffmpeg, rhytmbox
# License Information:
#
# Name: MIT License
# URL: https://opensource.org/licenses/MIT
# 
# The MIT License is a permissive license that allows you to do anything with the software, 
# as long as you include the original copyright and license notice.
#
# Description:
# Script uses curl,yt-dlp and ffmpeg to provide a terminal interface for searching youtube platform and download desired music in mp3 format.
# It also uses rhytmbox to provide the posibility to manage, play, enqueue downloaded music,


#Check if all required utilities are installed
initial_check()
{
    echo "Music Bot 2024 - University Project"
    if [ "$(which curl)" == "" ] #Check for curl
    then
        echo "Critical error - Curl has not been installed."
        exit 1;
    fi

    if [ -f "../yt-dlp" ] #Check for yt-dlp. The binary release of the tool is provided with the script by the author
    then
        echo "Critical error - yt-dlp has not been installed"
        exit 1;
    fi

    if [ -f "../ffmpeg" ] #Check for ffmpeg - crucial software that enables user to convert downloaded file to mp3 format
    then
        echo "Critical error - ffmpeg has not been installed"
        exit 1;
    fi

    if [ "$(which rhythmbox)" == "" ] #Check for rhytmbox
    then
        echo "Critical error - Rhytmbox has not been installed."
        exit 1;
    fi
}

#Funciton that searches the youtube platform and returns the first 3 results. It also downloads the chosen song.
search()
{
    SEARCHPHRASE=$( echo $1 | sed 's/ /+/g') #Change all white spaces to '+'. 
    echo "Getting results for phrase: $SEARCHPHRASE"

    eval "curl -s https://www.youtube.com/results?search_query=$SEARCHPHRASE" > cache.html #Get the results from yt
    videoId[0]=$(grep -o '"videoId":"[^"]*' cache.html | uniq | head -n 3 | cut -d '"' -f 4 | sed -n '1p') #Get the videoes ID from downloaded data
    videoId[1]=$(grep -o '"videoId":"[^"]*' cache.html | uniq | head -n 3 | cut -d '"' -f 4 | sed -n '2p')
    videoId[2]=$(grep -o '"videoId":"[^"]*' cache.html | uniq | head -n 3 | cut -d '"' -f 4 | sed -n '3p')
    resultsOfSearch[0]=$(grep -o '"title":{"runs":\[{"text":"[^"]*' cache.html | awk '{gsub(/"title"/, "\n&")}1' | sed 's/.*text":"//' | sed -n '2p' | sed 's#/# #g') #get Video titles
    resultsOfSearch[1]=$(grep -o '"title":{"runs":\[{"text":"[^"]*' cache.html | awk '{gsub(/"title"/, "\n&")}1' | sed 's/.*text":"//' | sed -n '4p' | sed 's#/# #g')
    resultsOfSearch[2]=$(grep -o '"title":{"runs":\[{"text":"[^"]*' cache.html | awk '{gsub(/"title"/, "\n&")}1' | sed 's/.*text":"//' | sed -n '6p' | sed 's#/# #g') 

    echo "Results of youtube search: "
    echo "1. ${resultsOfSearch[0]}"
    echo "2. ${resultsOfSearch[1]}"
    echo "3. ${resultsOfSearch[2]}"
    echo "4. CANCEL"
    echo "Choose which one to download: "

    while true #Choose and download
    do
        read CHOICE
        case "$CHOICE" in 
        "1")
            echo "Downloading...${resultsOfSearch[0]}"
            ./yt-dlp --no-warnings -o "./playlist/${resultsOfSearch[0]}" -x --audio-format mp3 --audio-quality 0 --ffmpeg-location ./ffmpeg "https://www.youtube.com/watch?v=${videoId[0]}" > dlpdump
            if [[ "$?" == "1" ]]
            then
                echo "Error occured - Download failed"
                return 4
            else
                echo "Download succesful"
                update_track_list "${resultsOfSearch[0]}"
            fi
            break
            ;;
        "2")
            echo "Downloading...${resultsOfSearch[1]}"
            ./yt-dlp --no-warnings -o "./playlist/${resultsOfSearch[1]}" -x --audio-format mp3 --audio-quality 0 --ffmpeg-location ./ffmpeg "https://www.youtube.com/watch?v=${videoId[1]}" > dlpdump
            if [[ "$?" == "1" ]]
            then
                echo "Error occured - Download failed"
                return 4
            else
                echo "Download succesful"
                update_track_list "${resultsOfSearch[1]}"
            fi
            break
            ;;
        "3")
            echo "Downloading...${resultsOfSearch[2]}"
            ./yt-dlp --no-warnings -o "./playlist/${resultsOfSearch[2]}" -x --audio-format mp3 --audio-quality 0 --ffmpeg-location ./ffmpeg "https://www.youtube.com/watch?v=${videoId[2]}" dlpdump
            ERROR=$( grep -i "ERROR:" dlpdump )
            if [[ "$?" == "1" ]]
            then
                echo "Error occured - Download failed"
                return 4;
            else
                echo "Download succesful. Use play command to play it!"
                update_track_list "${resultsOfSearch[2]}"
            fi
            break
            ;;
        "4")
            return 4;
            break
            ;;
        *)
            echo "Choose correct option"
            ;;
        esac
    done
}

#Update the tracklist.txt file which contains all songs' name
update_track_list()
{
    NEWTRACK=$1;
    echo "$NEWTRACK" >> tracklist.txt
}

#Play the song if already downloades - otherwise download it and then play
play()
{
    PLAYPHRASE=$1
    echo "Trying to play $PLAYPHRASE..."
    RESULT=$(grep -i "$PLAYPHRASE" tracklist.txt)
    if [[ "$RESULT" != "" ]]
    then #Song found - play it
        echo "Playing...$RESULT"
        rhythmbox-client --no-present --play-uri "playlist/$RESULT.mp3"& 
    else #Song wasnt found
        echo "Didn't find desired track - looking in the web for it..."
        search "$PLAYPHRASE"
    fi 
}

#Enqueue song if it is already downloaded. Return an error if song wasnt found
queue()
{
    PLAYPHRASE=$1
    echo "Trying to play $PLAYPHRASE..."
    RESULT=$(grep "$PLAYPHRASE" tracklist.txt)
    if [[ "$RESULT" != "" ]]
    then
        echo "Adding to music queue...$RESULT"
        rhythmbox-client --no-present --enqueue "playlist/$RESULT.mp3"& 
    else
        echo "Didn't find desired track - download id before adding it to queue"
    fi 
}

#delete desired track
delete()
{
    DELETEPHRASE=$1
    echo "Kasujemy $DELETEPHRASE"
    RESULT=$(grep "$DELETEPHRASE" tracklist.txt) # Search for phrase given by user in tracklist.txt
    if [[ "$RESULT" != "" ]]
    then
        FULLTITLE=$(grep "$DELETEPHRASE" tracklist.txt)
        rm "playlist/$FULLTITLE.mp3"
        grep -v "$DELETEPHRASE" tracklist.txt > cache.txt #update tracklist and save it to cache
        rm tracklist.txt
        mv cache.txt tracklist.txt #rename the cache to tracklists
    else
        echo "You have not downloaded that song"
    fi
}

listAll()
{
    cat tracklist.txt | sort | uniq #show sorted list of songs
}

#simple deletion of all songs
deleteAll()
{
    rm -r ./playlist
    rm tracklist.txt
}

#download song directly from the link
searchlink()
{
    SEARCHPHRASE=$1
    echo "Downloading from: $SEARCHPHRASE..."
    curl -s "$SEARCHPHRASE" > linkdownload #Get the website data first
    TITLE=$( cat linkdownload | grep -o '"title":"[^"]*' | head -n 1 | cut -d '"' -f 4) #Extract the title
    ./yt-dlp --no-warnings -o "./playlist/$TITLE" -x --audio-format mp3 --audio-quality 0 --ffmpeg-location ./ffmpeg "$SEARCHPHRASE" > dlpdump #download song
    if [[ "$?" == "1" ]]
    then
        echo "Error occured - Download failed"
    else
        echo "Download succesful"
        update_track_list "$TITLE"
    fi
    rm linkdownload
}

#downlod songs from links provided in file
downloadFile()
{
    SEARCHPHRASE=$1;
    echo "FIle is: ./$SEARCHPHRASE"
    if [[ ! -f "$SEARCHPHRASE" ]]
    then
        echo "File does not exist!"
    else
        while read -r line
        do
            searchlink "$line" #Execute searchlink for every line in file
        done < "$SEARCHPHRASE"
    fi
}

initial_check

#Main loop of the programm
OPTSTRING="p:r:d:i:o:e:q:scklavh"

while getopts ${OPTSTRING} opt; do
  case ${opt} in
    p)
      play "${OPTARG}"
      ;;
    r)
      search "${OPTARG}"
      ;;
    s)
      rhythmbox-client --stop
      rhythmbox-client --clear-queue
      ;;
    q)
        queue "${OPTARG}"
        ;;
    d)
        downloadFile "${OPTARG}"
        ;;
    o)
        searchlink "${OPTARG}"
        ;;
    l)
        listAll
        ;;
    e)
        delete "${OPTARG}"
        ;;
    a)
        deleteAll
        touch tracklist.txt
        mkdir playlist
        ;;
    k)
        rhythmbox-client --next
        ;;
    c)
        rhythmbox-client --clear-queue
        ;;
    v)
        echo "music manager 1.0"
        ;;
    h)
        cat help
        ;;
    :)
      echo "Option -${OPTARG} requires an argument."
      exit 1
      ;;
    ?)
      echo "Invalid option: -${OPTARG}."
      exit 1
      ;;
  esac
done