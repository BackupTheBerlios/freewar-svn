#!/bin/sh

while [ $# -ge 1 ]; do
    cat $1 > tempteuh~
    cat ~/berlios/freewar/freewar-0.1/HEADER_CPP > $1
    cat tempteuh~ >> $1
    shift
done
