#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main (int argc, char **argv) {
	long maxsleep;
	char * strtol_err;

	if (argc < 2) {
		fputs("Usage: randsleep <max> [<cmd> [<args ...>]]\n", stderr);
		return 1;
	}

	maxsleep = strtol(argv[1], &strtol_err, 0);

	if (strtol_err) {
		printf("randsleep: strtol: Conversion error at '%s'\n", strtol_err);
		return 1;
	}

	srand(time(NULL) + getpid());

	sleep((rand() % maxsleep) + 1);

	if (argc > 2) {
		execvp(argv[2], argv + 2);
		perror("execvp");
	}

	return 0;
}
