# used to compile c file
CC = gcc
FLAGS = -Wextra -Wall -Wpedantic
# txt file with colour rgb values
OBJECTS = colours.txt

BUILD1 = ./task1
BUILD3 = ./task3
# C FILE WITH CODE
CFILE1 = task1.c
CFILE3 = task3.c
# FILE THAT WILL STORE ALL VALID rgb & rgba
VALID = valid.txt

run-task-1: ${OBJECTS}
#ref-- awk command = https://www-users.york.ac.uk/~mijp1/teaching/2nd_year_Comp_Lab/guides/grep_awk_sed.pdf
# added custome c to add FF at the end of every 6 digit rgb code (Not sure if needed)
	#@ previous attempt : awk ' { if (length($0) == 7 ||length($0) == 9) print }' colours.txt >> valid.txt && gcc task1.c -o task2 -Wextra -Wall -Wpedantic && ./task1 > output.txt && cat output.txt && rm valid.txt
	$(MAKE) create_valid && cat ${VALID} && rm ${VALID}

run-task-2: ${OBJECTS}
#ref -- find char using awk : https://stackoverflow.com/questions/11401070/using-awk-to-print-characters-of-specific-index-on-a-line
#@awk ' { print substr($$0, 4, 2) }' valid.txt > task2.txt && sed ':a;N;$!ba;s/\n/;/g' task2.txt task2.txt
	$(MAKE) create_valid && cut -b 4,6 valid.txt > task2.txt && paste -s -d ";"  task2.txt && rm task2.txt && rm ${VALID}

#	@$(MAKE) create_valid && awk ' { print "rgba(" substr( $$0, 2, 2) "," substr( $$0, 4, 2) "," substr( $$0, 6, 2) "," substr( $$0, 8, 2) ")"}' ${VALID}> output.txt && rm ${VALID} && sort -t ',' -k 4 output.txt > rgba-colours.txt && rm output.txt
run-task-3: ${OBJECTS}
	$(MAKE) create_valid &&  bash -c "paste --delimiter=',' <(cut -b 2,3 ${VALID} ) <(cut -b 4,5 ${VALID} ) <(cut -b 6,7 ${VALID} ) <(cut -b 8,9 ${VALID}) | tr [:lower:] [:upper:]> output.txt" && ${CC} ${CFILE3} -o task3 ${FLAGS} && ${BUILD3} > rgba.txt && head -n -2 rgba.txt > rgba-colours.txt  && rm ${VALID} && rm output.txt && rm rgba.txt

#ref -- how to call make function in another make function : https://stackoverflow.com/questions/2206128/how-to-call-makefile-from-another-makefile
#creates a txt with all valid rgb code
create_valid: ${CFILE1}
	#@${CC} ${CFILE1} -o task1 -Wextra -Wall -Wpedantic && ${BUILD1} > output.txt && egrep "#{1}[0-9a-fA-F]{1}[0-9a-fA-F]{1}[0-9a-fA-F]{1}[0-9a-fA-F]{1}[0-9a-fA-F]{1}[0-9a-fA-F]{1}[0-9a-fA-F]{1}[0-9a-fA-F]" output.txt > ${VALID} && rm output.txt
	egrep "#[0-9a-fA-F]{6}$$" colours.txt > output.txt	&& egrep "#[0-9a-fA-F]{8}$$" colours.txt >> output.txt && ${CC} ${CFILE1} -o task1 ${FLAGS} && ${BUILD1} > ${VALID} && rm output.txt

clean: rgba-colours.txt task1  task3
	rm rgba-colours.txt && rm task1 && rm task3