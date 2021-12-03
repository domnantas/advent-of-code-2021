#!/bin/bash

ARGS=$#
DAY="$1"

if [ $ARGS -ne 1 ]; then
		echo "error: missing/too many arguments"
		exit 1
fi

if [ ! -d "$DAY" ]; then
		echo "error: directory $DAY does not exist"
		echo "usage: ./build.sh <day>"
		exit 1
fi

echo "building $DAY"

if make -C "$DAY"/; then
		echo "success"
else
		echo "error: build failed"
		exit 1
fi

./"$DAY"/a.out < "$DAY"/input
rm "$DAY"/a.out