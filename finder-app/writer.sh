#!/bin/sh

writefile=$1
writestr=$2

if [ $# -lt 2 ]
then
    echo Input arguments missing!
    exit 1
fi

filedir=$(dirname "$writefile")

mkdir -p "$filedir"

echo $writestr > "$writefile" || (echo Failed to create file $writefile with content: "'$writestr'"! ; exit 1)

