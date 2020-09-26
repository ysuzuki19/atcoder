#!/bin/bash

while :
do
	make
	./test.sh
	res=$(fswatch -1 --event Updated .)
done
