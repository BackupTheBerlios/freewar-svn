#!/bin/sh

if [ -f HEADER_CPP ]
    then
    LINE=`cat HEADER_CPP | wc -l`
    while [ $# -ge 1 ]; do
	HEAD=`head -n $LINE $1 | diff HEADER_CPP -`
	if [ "$HEAD" ]
	    then
	    cat $1 > tempteuh~
	    cat ~/berlios/freewar/freewar-0.1/HEADER_CPP > $1
	    cat tempteuh~ >> $1
	else
	    echo "Le fichier $1 a deja un header, skip"
	fi
	shift
    done
else
    echo "Fichier HEADER_CPP manquant"
fi
