#!/usr/bin/env bash

cat version.txt | grep 1.0
if [ $? -eq 0 ]; then
   echo "You successfully modified version.txt. Update requirement met!"
else
   echo "You failed to modify version.txt as per specification. Update requirement not met..."
   exit 1
fi
