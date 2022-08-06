#include <stdlib.h>
void fileHandler(char *arg)
{
    /* Initialize an object of type FILE as source,destination */
    FILE *source = NULL, *destination = NULL;
    /* Dynamic allocation for holding the filename provided as args pointer */
    char *fileName = (char*) malloc(strlen(arg)+1 * sizeof(char));
    /* sets the fileName to be arg */
    strncpy(fileName, arg, strlen(arg));
    /* Change the file suffix to .as - before manipulation */
    strcat(fileName, ".as")
    /* Validate the file is properly opened */
    if ((source = fopen(fileName, "r")) == NULL)
    {
        fprintf(stderr, "ERROR! file %s failed to open\n", fileName);
        free(fileName);
        return;
    }
    /* Change filename to .am suffix  */
    fileName[strlen(fileName) - 1] = 'm';
    if ((destination = fopen(fileName, "w+")) == NULL)
    {

        fprintf(stderr, "ERROR! expended file %s could not be created\n", fileName);
        fclose(source);
        free(fileName);
        return;
    }
    else
    {
        /* Deploy Macros, call pre-assembler */

        /* First Iteration */

        /* Second Iteration */
    }
    /*
    Translate argument into filename that ends with .as
    DeployMacro
    pre-assembler (returns .am file, same as .as if no Macro exists)
    first iteration
    Second interation
    if file contains extern guide
    generate externals file .ext
    if file contains entry guide
    generate entries file .ent
    */
}