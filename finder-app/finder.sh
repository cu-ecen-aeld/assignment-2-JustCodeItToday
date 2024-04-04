#!/bin/sh

filesdir=$1
searchstr=$2

filescount=0
linescount=0

if [ $# -lt 2 ]
then
    echo Input arguments missing!
    exit 1
fi

if [ ! -d $filesdir ]
then
    echo $filesdir is not a directory!
    exit 1
fi

# Number of files in the directory and all subdirectories
filescount=$(find $filesdir -type f | wc -l)

# Number of matching lines found in respective files, where a matching line refers to a line which 
# contains searchstr (and may also contain additional content)
linescount=$(grep -r $searchstr $filesdir/* | wc -l)

echo The number of files are $filescount and the number of matching lines are $linescount


