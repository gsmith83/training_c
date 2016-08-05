#!/bin/bash

echo "`basename $0`"

# shift parameters one at a time to the left ( $1 <-- $2, $2 <-- $3, ... )
until [ -z "$1" ]   # space required between [ ] brackets
do
 echo -n "$1 "
 shift 1    # the one can be ommitted as it is implied in shift
done

echo
echo

exit 0
