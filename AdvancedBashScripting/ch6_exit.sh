#!/bin/bash

echo '$? holds value of previous command exit status'
echo "Exit status = $?"

lskdf   # unrecognized command
echo "Exit status = $?"

exit 113    # will return 113 to shell. verify by typing 'echo $?' after script terminates
