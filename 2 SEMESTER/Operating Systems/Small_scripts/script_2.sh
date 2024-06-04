#!/bin/bash

ISEND=0

while [[ $ISEND -eq 0 ]]
do

echo "1. Nazwa pliku: $nazwa"
echo "2. Katalog: $katalog"
echo "3. Typ pliku: $typ"
echo "4. Liczba dni od utworzenia: $dni"
echo "5. Nazwa właściciela: $wlasciciel"
echo "6. Minimalny rozmiar: $rozmiar"
echo "7. Szukaj"
echo "8. Koniec"

read input
clear
if [[ input -eq 1 ]]
then
	echo "Podaj nazwę pliku: "
	read nazwa
elif [[ input -eq 2 ]]
then
	echo "Podaj katalog: "
	read katalog
elif [[ input -eq 3 ]]
then
	echo "Podaj typ pliku: "
	read typ
elif [[ input -eq 4 ]]
then
	echo "Podaj liczbe dni, która upłynęła od momentu utworzenia pliku: "
	read dni
elif [[ input -eq 5 ]]
then
	echo "Podaj nazwe wlasciciela pliku: "
	read wlasciciel
elif [[ input -eq 6 ]]
then
	echo "Podaj minimalny rozmiar pliku: "
	read rozmiar
elif [[ input -eq 7 ]]
then
	clear
	echo "Opcja 7"
	result="find $katalog"
	if  [ -n "$nazwa" ]
	then
		result="$result -name $nazwa"
	fi

	if  [ -n "$typ" ]
        then
                result="$result -type $typ"
        fi

	if [ -n "$dni" ]
        then
                 result="$result -mtime +$dni"
        fi

	if [ -n "$wlasciciel" ]
        then
                 result="$result -user $wlasciciel"
        fi

	if [ -n "$rozmiar" ]
        then
                 result="$result -size +$rozmiar"
        fi
	
	result="$result -ls"
	echo $result
	eval "$result"

elif [[ input -eq 8 ]]
then
	ISEND=1
fi
done
