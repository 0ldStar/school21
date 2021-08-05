#!/bin/bash

path=$1
if [ ! -f "$path" ]; then
	kill "$$"
fi
IFS=$'\n'
sCount=0
lastFile=""
lastSSH=""
fCount=0
wFlag=0
sshCount=0
nameArr=()
sshArr=()
for entry in $(cat $path); do
	wCount=0
	IFS=' '
	for word in $entry; do
		if [ "$wCount" = "0" ]; then
			nameArr+=($word)
		fi
		if [ "$wCount" = "7" ]; then
			sshArr+=($word)
		fi
		wCount=$(($wCount + 1))
	done
	sCount=$(($sCount + 1))
done

out1=()
out2=()
for word in "${nameArr[@]}"; do
	for cword in "${nameArr[@]}"; do
		if [[ "$word" = "$cword" ]]; then
			flag=1
			for aword in "${out1[@]}"; do
			if [[ "$word" = "$aword" ]]; then
				flag=0
			fi
			done
			if [ "$flag" = "1" ];then
				out1+=( $word )
			fi
		fi

	done
done


for word in "${sshArr[@]}"; do
	for cword in "${sshArr[@]}"; do
		if [[ "$word" = "$cword" ]]; then
			flag=1
			for aword in "${out2[@]}"; do
			if [[ "$word" = "$aword" ]]; then
				flag=0
			fi
			done
			if [ "$flag" = "1" ];then
				out2+=( $word )
			fi
		fi

	done
done


for word in "${out1[@]}"; do
	fCount=$(($fCount + 1))
done

for word in "${out2[@]}"; do
	sshCount=$(($sshCount + 1))
done

echo "$sCount $fCount $sshCount"