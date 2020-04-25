CC = gcc
FLAGS = -Wall -Wextra -Wpedantic
SOURCE = task5.c
BUILD = ./build/task5

run-task-1:
	tail access.log

run-task-2:
	cut -d ' ' -f 1 access.log | sort -u

run-task-3:
	egrep " 404 " access.log | cut -d ' ' -f 3-5

run-task-4:
	egrep "Trident" access.log > access.ie.log

#output the text file, create a build directory to store built files, compile and run the solution
run-task-5:
	egrep " [5-9] | 10 " access.log | cut -d ' ' -f 4,7 > access.moreThan5.txt && mkdir ./build && ${CC} ${SOURCE} ${FLAGS} -o ${BUILD} && ${BUILD}

#remove the build folder and built files
clean:
	rm -rf ./build