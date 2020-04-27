CC = gcc
FLAGS = -Wall -Wextra -Wpedantic
SOURCE = task5.c
BUILD = ./build/task5

#tail will return last 10 lines by default
run-task-1:
	tail access.log

#https://shapeshed.com/unix-sort/#how-to-sort-and-remove-duplicates
#using cut with delimiter of ' ' and sort to remove any duplicated ip addresses
run-task-2:
	cut -d ' ' -f 1 access.log | sort -u


#egrep will return any logs with 404
#note the space before and after 404, to prevent confusion with other 404s in dates or ip addresses
run-task-3:
	egrep " 404 " access.log | cut -d ' ' -f 3-5

#Microsoft Internet Explorer uses Trident as browser engine
run-task-4:
	egrep "Trident" access.log > access.ie.log

#using regex to find more than 5 
#output the text file, create a build directory to store built files, compile and run the solution
run-task-5:
	egrep " [1-9][0-9] | [5-9] " access.log | cut -d ' ' -f 4,7 > access.moreThan5.txt && mkdir ./build && ${CC} ${SOURCE} ${FLAGS} -o ${BUILD} && ${BUILD}

#remove the build folder and its contents and created files from previous tasks
clean:
	rm -rf ./build && rm access.ie.log && rm access.moreThan5.txt