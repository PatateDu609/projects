#!/bin/sh

if [ $# != 1 ]; then
	echo "One argument needed !"
	exit
fi
echo "Request of commiting :"
echo "Message :"
echo $1
git commit -m "$1"
git push origin master