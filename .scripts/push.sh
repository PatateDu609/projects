#!/bin/sh

inotifywait -m -r --event=modify,move,create --exclude /home/teyber/git/.git --format %w%f /home/teyber/git/ | 
while read -r filename; do
	git add $filename
	git commit -m "$filename"
	git push origin master
done