#include <stdlib.h>
#include <stdio.h>
#include "../analayzers.c"

FILE *ptr;

char *read_per_line(char *file_name) {
    char *line_string = malloc(sizeof(char) * 200);
    char *file_string = malloc(sizeof(char) * 1000);
    ptr = fopen(file_name, "r");
    if (ptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fgets(file_string, 200, ptr);
    while (fgets(line_string, 200, ptr) != NULL) {
        string_to_binary(line_string,"");
    }
    fclose(ptr);
    return file_string;
}
