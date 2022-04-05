#!/usr/bin/env bash

FILE=./src/array.cpp
if test -f "$FILE"; then
    echo "$FILE exists. Creation of a file named $FILE was successfully added to revision control..."
else
    echo "$FILE does not exist. You failed to add a file named $FILE to revision control..."
    exit 1
fi
