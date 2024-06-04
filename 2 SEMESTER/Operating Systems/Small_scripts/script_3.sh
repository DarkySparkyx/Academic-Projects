#!/bin/bash

while [[ "$INPUT" != "Exit" ]]
do
	INPUT=$(zenity --list --title="WYSZUKIWANIE" --column="Według czego chcesz wyszukać plik?" "Nazwa: $NAZWA" "Katalog: $KATALOG" "Typ pliku: $TYP" "Liczba dni od utworzenia: $DNI" "Nazwa właściciela: $WLASCICIEL" "Minimalny rozmiar: $ROZMIAR" "Szukaj" "Exit")
if [ "$INPUT" == "Nazwa: $NAZWA" ]; then
	NAZWA=$(zenity --entry --text="Podaj nazwe szukanego pliku")
elif [ "$INPUT" == "Katalog: $KATALOG" ]; then
	KATALOG=$(zenity --entry --text="Podaj nazwe katalogu")
elif [ "$INPUT" == "Typ pliku: $TYP" ]; then
        TYP=$(zenity --entry --text="Podaj typ")
elif [ "$INPUT" == "Liczba dni od utworzenia: $DNI" ]; then
        DNI=$(zenity --entry --text="Podaj liczbe dni")
elif [ "$INPUT" == "Nazwa właściciela: $WLASCICIEL" ]; then
        KATALOG=$(zenity --entry --text="Podaj nazwe właściciela")
elif [ "$INPUT" == "Minimalny rozmiar: $ROZMIAR" ]; then
        KATALOG=$(zenity --entry --text="Podaj minimalny rozmiar")
elif [ "$INPUT" == "Szukaj" ]; then
        result="find $katalog"
        if  [ -n "$NAZWA" ]
        then
                result="$result -name $NAZWA"
        fi

        if  [ -n "$TYP" ]
        then
                result="$result -type $TYP"
        fi

        if [ -n "$DNI" ]
        then
                 result="$result -mtime +$DNI"
        fi

        if [ -n "$WLASCICIEL" ]
        then
                 result="$result -user $WLASCICIEL"
        fi

        if [ -n "$ROZMIAR" ]
        then
                 result="$result -size +$ROZMIAR"
        fi

        result="$result"
        echo $result
        eval "$result" | zenity --text-info
fi
done
