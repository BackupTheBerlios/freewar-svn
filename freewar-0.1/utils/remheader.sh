# Copyright (C) 2004 Freewar Team <doomsday@freewar.net>

# This file is part of Freewar.

# Freewar is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.

# Freewar is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with Freewar; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
#!/bin/sh

FILE=$1
shift

if [ -f $FILE ]
    then
    if [ "$1" = "--" ]
	then
	shift
	LINE=`cat $FILE | wc -l`
	while [ $# -ge 1 ]; do
	    DIFF=`head -n $LINE $1 | diff $FILE -`
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
	echo "Syntax error: $0 HEADER_TYPE -- file1 file2 .."
    fi
else
    echo "Fichier $FILE manquant"
fi
