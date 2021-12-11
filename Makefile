CC=gcc
multiImpl:  main.c implementationMulti.c *.h 
	$(CC) $(filter-out %.h,$^) -o $@ -Wall -Wextra 
