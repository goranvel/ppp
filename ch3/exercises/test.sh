#!/bin/bash

i=1;

while read line
do
	echo -ne "$i\t$line\t"
	echo -e "$line" | ./a.out
	(( i++ ))
done < test.txt
