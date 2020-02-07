#include <stdio.h>
#include <string.h>

#include "cmd.h"

int main(int argc, char **argv)
{
	char * progname = strrchr(argv[0], '/');

	if(!progname || (progname == argv[0] && !progname[1]))
		progname = argv[0];
	else
		progname++;

	/* If our name was called, assume argv[1] is the command */
	if(strcmp(progname, "busyelks") == 0) {
		progname = argv[1];
		argv++;
		argc--;
	}

#if defined(CMD_basename)
	if(!strcmp(progname, "basename"))
		basename_main(argc, argv);
#endif

	if(!strcmp(progname, "true"))
		return 0;

	if(!strcmp(progname, "false"))
		return 1;

	/*
	if(strcmp(progname, "sync") == 0) { sync(); exit(0); }
	*/

	fputs("BusyELKS commands:\n"
#if defined(CMD_basename)
		"\tbasename NAME [SUFFIX]\n"
#endif
		"\tfalse\n"
		"\ttrue\n"
		, stderr);

	return 1;
}
