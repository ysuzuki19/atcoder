#!/bin/bash

while :;
do
	./test.sh
	res=$(fswatch -1 --event Updated .)
done
