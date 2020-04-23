.PHONY: run-task-1 run-task-2 run-task-3 run-task-4

run-task-1:
#ref-- awk command = https://www-users.york.ac.uk/~mijp1/teaching/2nd_year_Comp_Lab/guides/grep_awk_sed.pdf
# added custome c to add FF at the end of every 6 digit rgb code (Not sure if needed)
	@awk ' { if (length($0) == 7 ||length($0) == 9) print }' colours.txt >> valid.txt && gcc task1.c -o task2 -Wextra -Wall -Wpedantic && ./task1 > valid.txt && cat valid.txt

run-task-2:
#ref -- find char using awk = https://stackoverflow.com/questions/11401070/using-awk-to-print-characters-of-specific-index-on-a-line
#@awk ' { print substr($$0, 4, 2) }' valid.txt > task2.txt && sed ':a;N;$!ba;s/\n/;/g' task2.txt task2.txt
	@awk ' { print substr($$0, 4, 2) }' valid.txt > task2.txt &&  gcc task2.c -o task2 -Wextra -Wall -Wpedantic && ./task2 && rm task2.txt

run-task-3:

