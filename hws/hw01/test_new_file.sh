#!/usr/bin/env bash

FILE=./bio.md
if test -f "$FILE"; then
    echo "$FILE exists. Add requirement met!"
else
    echo "$FILE does not exist. You failed to add a new file to revision control..."
    exit 1
fi
