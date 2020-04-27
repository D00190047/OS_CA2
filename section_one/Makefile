SOURCE = https://www.dkit.ie
TARGET = dkit.html
INPUT_TEXT = "The quick brown fox jumps over the lazy dog\n"
OUTPUT = mangled.txt

run-task-1:
	echo ${INPUT_TEXT} | wc -w

run-task-2:
	printf ${INPUT_TEXT} | tr [a-z] [A-Z]

run-task-3:
	curl ${SOURCE} > ${TARGET}

run-task-4:
	{ head -1 ${TARGET} & tail -1 ${TARGET}; } | tr '<>' '[]' > ${OUTPUT}

#remove created files from previous tasks
clean:
	rm dkit.html && rm mangled.txt