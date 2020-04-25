# used to compile c file
CC = gcc
FLAGS = -Wextra -Wall -Wpedantic
# txt file with colour rgb values
OBJECTS = colours.txt
BUILD = ./task2
# C FILE WITH CODE
CFILE = task2.c
# FILE THAT WILL STORE ALL VALID rgb & rgba
VALID = valid.txt

.PHONY: run-task-1 run-task-2 run-task-3 run-task-4

run-task-1: ${OBJECTS}
#ref-- awk command = https://www-users.york.ac.uk/~mijp1/teaching/2nd_year_Comp_Lab/guides/grep_awk_sed.pdf
# added custome c to add FF at the end of every 6 digit rgb code (Not sure if needed)
	#@ previous attempt : awk ' { if (length($0) == 7 ||length($0) == 9) print }' colours.txt >> valid.txt && gcc task1.c -o task2 -Wextra -Wall -Wpedantic && ./task1 > output.txt && cat output.txt && rm valid.txt
	@$(MAKE) create_valid && cat ${VALID} && rm ${VALID}

run-task-2: ${OBJECTS} ${CFILE}
#ref -- find char using awk : https://stackoverflow.com/questions/11401070/using-awk-to-print-characters-of-specific-index-on-a-line
#@awk ' { print substr($$0, 4, 2) }' valid.txt > task2.txt && sed ':a;N;$!ba;s/\n/;/g' task2.txt task2.txt
	@$(MAKE) create_valid && awk ' { print substr($$0, 4, 2) }' ${VALID} > task2.txt &&  ${CC} ${CFILE} -o task2 ${FLAGS} && ${BUILD} && rm task2.txt && rm ${VALID} && rm task2

#
run-task-3: ${OBJECTS}
	@$(MAKE) create_valid && awk ' { print "rgba(" substr( $$0, 2, 2) "," substr( $$0, 4, 2) "," substr( $$0, 6, 2) "," substr( $$0, 8, 2) ")"}' ${VALID}> output.txt && rm ${VALID} && sort -t ',' -k 4 output.txt > rgba-colours.txt && rm output.txt

#ref -- how to call make function in another make function : https://stackoverflow.com/questions/2206128/how-to-call-makefile-from-another-makefile
#creates a txt with all valid rgb code
create_valid:
	@awk ' { if (length($0) == 7) print $$0 "ff" } { if(length($0) == 9) print }' ${OBJECTS} >> output.txt && egrep "#{1}[0-9a-fA-F]{1}[0-9a-fA-F]{1}[0-9a-fA-F]{1}[0-9a-fA-F]{1}[0-9a-fA-F]{1}[0-9a-fA-F]{1}[0-9a-fA-F]{1}[0-9a-fA-F]" output.txt > ${VALID} && rm output.txt

clean:
	@rm rgba-colours.txt