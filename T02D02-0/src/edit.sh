#!/bin/bash

path=$1
if [ ! -f "$path" ]
then
kill "$$"
fi
firstStr=$2
secondStr=$3
IFS=$'\n'
for entry in $(cat $path)
do
if [ "$entry" = "$firstStr" ] 
then
sed -i '' "s/$firstStr/$secondStr/" $path
ssh=$( (shasum --a 256 $path) | (awk '{print $1}'))
size=$( (stat -f%z $path) |( awk '{print $1}'))
date=$(date +'%Y-%m-%d %k:%M')
echo "$path - $size - $(date +'%Y-%m-%d %k:%M')  - $ssh - sha256" >> $PWD/files.log
fi
done

