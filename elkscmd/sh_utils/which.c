#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define errmsg(str) write(STDERR_FILENO, str, sizeof(str) - 1)
#define errstr(str) write(STDERR_FILENO, str, strlen(str))

int
main(argc,argv)
int argc;
char ** argv;
{
	char *envpath;
	char *path, *cp;
	char buf[200];
	char patbuf[512];
	int quit, found;

	if (argc < 2) {
		errmsg("Usage: which cmd [...]\n");
		return 1;
	}
	if ((envpath = getenv("PATH")) == 0)
		envpath = ".";

	argv[argc] = 0;
	for (argv++ ; *argv; argv++) {

		strcpy(patbuf, envpath);
		cp = path = patbuf;
		quit = found = 0;

		while (!quit) {
			cp = index(path, ':');
			if (cp == NULL) {
				quit++;
			} else {
				*cp = '\0'; 
			}
			sprintf(buf, "%s/%s", (*path ? path:"."), *argv);
			path = ++cp;

			if (access(buf, 1) == 0) {
				printf("%s\n", buf);
				found++;
			}
		}
		if (!found) {
			printf("No %s in %s\n", *argv, envpath);
		}
	}
	return 0;
}
