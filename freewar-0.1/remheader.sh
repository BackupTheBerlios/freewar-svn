#!/bin/sh

LINE=`cat HEADER_CPP | wc -l`
if [ -f HEADER_CPP ]
    then
    while [ $# -ge 1 ]; do
	DIFF=`head -n $LINE $1 | diff HEADER_CPP -`
	if [ "$DIFF" ]
	    then
	    echo "Le fichier $1 n'a pas de header, skip"
	else
	    GOT=$((`cat $1 | wc -l`-$LINE))
	    cat $1 | tail -n $GOT > tempteuh~
	    rm -f $1
	    cat tempteuh~ > $1
	fi
	shift
    done
else
    echo "Le fichier HEADER_CPP manque."
fi
