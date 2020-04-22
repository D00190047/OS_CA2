.PHONY: run-task-1 run-task-2 run-task-3 run-task-4

run-task-1:
	@tail access.log

run-task-2:
	@cut -d ' ' -f 1 access.log | sort -u

run-task-3:
	@egrep " 404 " access.log | cut -d ' ' -f 3-5

run-task-4:
	@egrep "Trident" access.log > access.ie.log
