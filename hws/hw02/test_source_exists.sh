#!/usr/bin/env bash

FILE=./src/point.cpp
if test -f "$FILE"; then
    echo "$FILE exists. Add implementation file (point.cpp) requirement met!"
else
    echo "$FILE does not exist. You failed to add point.cpp to revision control..."
    exit 1
fi
