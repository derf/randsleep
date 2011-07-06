#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main (int argc, char **argv) {
	long maxsleep;
	struct timespec ntime;

	if (argc <= 2) {
		fputs("Usage: randsleep <max> <cmd>\n", stdout);
		return 1;
	}

	maxsleep = atol(argv[1]);

	if (clock_gettime(CLOCK_REALTIME, &ntime) == -1)
		perror("clock_gettime");

	srand(ntime.tv_nsec);

	sleep(rand() % maxsleep);

	execvp(argv[2], argv + 2);
	perror("execvp");
}
