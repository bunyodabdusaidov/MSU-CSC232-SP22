#!/usr/bin/env bash

FILE=./include/point.h
if test -f "$FILE"; then
    echo "$FILE exists. Add header file (point.h) requirement met!"
else
    echo "$FILE does not exist. You failed to add point.h to revision control..."
    exit 1
fi
