#!/bin/sh

# Print out everything before
echo "Before:"
find
echo

# Create script3.sh and make it executable
touch script3.sh
chmod +x script3.sh

# Set is as shell
echo '#!/bin/sh' > script3.sh

# Unlink all links
echo 'find . -type l ! -exec test -d {} \; -exec rm {} +' >> script3.sh

# Remove all files in current directory
echo 'rm -rf ./*' >> script3.sh

# Print out everything after
echo 'echo "After:"' >> script3.sh
echo 'find' >> script3.sh


# Run script3.sh
./script3.sh