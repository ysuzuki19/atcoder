#!/bin/bash

while :;
do
	./test.sh
#	res=$(fswatch -1 . >/dev/null)
	fswatch -1 .
done
