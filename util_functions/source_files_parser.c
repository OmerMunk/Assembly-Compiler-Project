#include "file_parsing.h"

/* argc counts input arguments, argv contains the arguments as: [name, arg1, arg2, etc..., NULL] */
int sourceFilesParser(int argc, char *argv[])
{
    int fileCounter = argc - 1;
    int fileIterator = 1;
    if (fileCounter < 1)
    {
        /* perror could also be used, we chose fprintf for flexibility  */
        fprintf(stderr, "\nMissing source files! returning err code '1' to the caller (shell)\n");
        exit(1);
    }
    while (argc)
    {
        argc--;
        fileHandler(argv[fileIterator]);
        fileIterator++;
    }

    return 0;
}
