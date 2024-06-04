#!/bin/bash

ZMIENNA=$(grep "OK DOWNLOAD" cdlinux.ftp.log | cut -d'"' -f 2,4 |sort -u | sed "1,\$s#.*/##" | grep "\.iso")

echo "$ZMIENNA" > result.txt

ZMIENNA=$(grep " 200 " cdlinux.www.log | grep "GET"| cut -d ' ' -f 1,7 | sort | sort -u | sed "1,\$s#.*/##" | grep "\.iso$")

echo "$ZMIENNA" >> result.txt

