#!/bin/bash
# ------------------------------------------
INPUT=Input.csv
OLDIFS=$IFS
IFS=','
val=''
while read name email link
do
	echo "Name : $name"
	echo "E-mail : $email"
	echo "link : $link"
	echo "git-status"
	echo "build-status"
	echo "cppcheck"
	echo "valgrind"
	git clone $link
	if [ $? -eq 0 ]; then
		name=$(echo $link | sed 's|.*/||')
		folder=$(echo $name | cut -d"." -f1)
		cd $folder
		make
		if [ $? -eq 0 ]; then
			cppcheck --enable=all ./a.out 2> report.txt
			cpp=$(grep -wc "error" report.txt)
			if [ $? -eq 0 ]; then
				valgrind ./a.out 2> main.txt
				STR=$( tail -n 1 main.txt )
				val=$(echo ${STR:24:3})
				if [ $? -eq 0 ]; then
					cd ..
					printf '%s' $name,$email,$link,success,success,$cpp,$val | paste -sd ',' >> Results.csv
				fi
			fi 
		fi
	else 
		printf '%s' $name,$email,$link,notsuccess,1,1,1 | paste -sd ',' >> Results.csv
	fi
done < $INPUT
IFS=$OLDIFS
