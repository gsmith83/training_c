#!/bin/bash

# double quoting prevents "word splitting"
List="one two three"

# splits the variable in parts at whitespace
for a in $List
do
 echo "$a"
done
# one
# two
# three

for a in "$List"
do
 echo "$a" 
done
# one two three

echo

echo 'Why can'\''t I write '"'"'s between single quotes'
#    |-------|  |----------|   |-----------------------|

echo

# escaping a newline
echo "This will print
as two lines"
echo "This will print \     
as one line"        # escaping the newline will also work for multiline commands

echo

echo "(Maybe) BEEP"
echo $'\a'  # Alert (beep). May only flas, depending on terminal

exit    # equivalent to exit $?

