#!/usr/bin/env bash

FILE=./include/int_ptr_cell.h
if test -f "$FILE"; then
    echo "$FILE exists. Add header file requirement met!"
else
    echo "$FILE does not exist. You failed to add the header file to revision control..."
    exit 1
fi
