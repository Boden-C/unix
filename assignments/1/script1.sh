#!/bin/sh

# Create dir1 and file10 first
mkdir dir1
touch dir1/file10

# Then create dir2 and file20
mkdir dir2
touch dir2/file20

# Then create file 1
touch file1

# Create symbolic link to file20
ln -s dir2/file20 link1