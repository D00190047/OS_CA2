.PHONY: run-task-1 run-task-2 run-task-3 run-task-4

run-task-1:
	@echo "The quick brown fox jumps over the lazy dog\n" | wc -w

run-task-2:
	@printf "The quick brown fox jumps over the lazy dog\n" | tr [a-z] [A-Z]

run-task-3:
	@curl https://www.dkit.ie > dkit.html

run-task-4:
	@{ head -1 dkit.html & tail -1 dkit.html; } | tr '<>' '[]' > mangled.txt 
