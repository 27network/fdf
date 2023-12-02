#!/bin/bash

#
# Script that removes unwanted elements for submission to the moulinette
#

# Submit branch
git checkout -b submit

# Recreates all submodules as standalone files
SUBMODULES=$(git config --file .gitmodules --get-regexp path | awk '{ print $2 }')
for SUBMODULE in $SUBMODULES; do
	# Get submodule info 
	SUBMODULE_COMMIT=$(git config --file .gitmodules --get "submodule.$SUBMODULE.commit")
	if [ -z "$SUBMODULE_COMMIT" ]; then
		SUBMODULE_COMMIT=$(git submodule status $SUBMODULE | awk '{ print $1 }')
	fi
	if [ -z "$SUBMODULE_COMMIT" ]; then
		SUBMODULE_COMMIT=$(git config --file .gitmodules --get "submodule.$SUBMODULE.branch")
	fi
	if [ -z "$SUBMODULE_COMMIT" ]; then
		SUBMODULE_COMMIT="main"
	fi
	SUBMODULE_URL=$(git config --file .gitmodules --get "submodule.$SUBMODULE.url")
	# Deinit submodule
	git submodule deinit -f $SUBMODULE
	git rm --cached $SUBMODULE
	rm -rf $SUBMODULE
	# Clone back the submodule as a singular repository
	git clone $SUBMODULE_URL $SUBMODULE
	# Checkout the submodule at the specific commit
	cd $SUBMODULE
	git checkout $SUBMODULE_COMMIT
	cd ..
done

# Remove libft tests folder
rm -rf ./libft/tests

# Remove git files
find . -wholename "./*/.git" -exec rm -rf {} \;
find . -name ".gitignore" -type f -exec rm -rf {} \;
find . -name ".gitmodules" -type f -exec rm -rf {} \;
find . -name ".gitattributes" -type f -exec rm -rf {} \;
find . -name ".git-blame-ignore-revs" -type f -exec rm -rf {} \;

# If a Makefile exists, run fclean
if [ -f "Makefile" ]; then
	make fclean
fi

# Remove this script
rm -rf submit.sh

# Move to submit branch
git add .
git commit -sm "chore: submit branch setup"
git push origin submit --force
