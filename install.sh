#!/bin/bash

url="https://github.com/hizaak/hibernate.git"

# Check if the user is root
if [ "$(id -u)" -ne 0 ]; then
    echo "This script requires root privileges to run."
    exit 1
fi

# Check if the git package is installed
if ! command -v git &> /dev/null; then
    echo "Git is not installed."
    exit 1
fi

# Check if the gcc package is installed, excluding dpkg since it's not installed by default on non-Debian based systems
if ! command -v gcc &> /dev/null; then
    echo "GCC is not installed."
    exit 1
fi

# Clone the repository
if ! git clone $url; then
    echo "Cloning the repository failed."
    exit 1
else
    echo "Repository cloned successfully."
fi

cd hibernate || exit 1

# Check if the hibernate.c script exists
if [ ! -f hibernate.c ]; then
    echo "The hibernate.c file does not exist."
    exit 1
fi

# Compile the hibernate.c script
if ! gcc hibernate.c -o hibernate; then
    echo "Compilation of the script failed."
    exit 1
else
    echo "Script compiled successfully."
fi

# Check if copying was successful
if ! cp hibernate /usr/bin/; then
    echo "Copying the script failed."
    exit 1
else
    echo "Script copied successfully."
fi

# Remove the hibernate folder
cd .. || exit 1

if ! rm -rf hibernate; then
    echo "Removing the hibernate folder failed."
    exit 1
else
    echo "Hibernate folder removed successfully."
fi

echo "The script has been installed successfully."
