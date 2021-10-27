#!/bin/bash
Value=0
for Code in $(ls tiger_samples/*.tig)
do
    ./tiger $Code
    status=$?
    [ $status -eq 0 ] && echo "$Code command was successful" ||   exit 1 
done

