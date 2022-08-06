//
// Created by Omer Munk on 22/07/2022.
//
#include <stdlib.h>
#include <string.h>
#include "pre_assembler.h"

FILE *ptr;

// function that reads a file and returns a string of the file
char *read_file(char *file_name) {
    char *line_string = malloc(sizeof(char) * 200);
    char *file_string = malloc(sizeof(char) * 1000);
    ptr = fopen(file_name, "r");
    if (ptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fgets(file_string, 200, ptr);
    while (fgets(line_string, 200, ptr) != NULL) {
        strcat(file_string, line_string);
    }
    fclose(ptr);
    return file_string;
}


//function that gets a string a checks if it has the sub-string 'macro'
int is_macro(char *string, char *macro_name, char *macro_body, int position) {
    int i = position;
    while (string[i] != '\0') {
        if (string[i] == 'm') {
            if (string[i + 1] == 'a') {
                if (string[i + 2] == 'c') {
                    if (string[i + 3] == 'r') {
                        if (string[i + 4] == 'o') {
                            if (string[i + 5] == ' ') {
                                int j = 0;
                                while (string[i + 6 + j] != '\n') {
                                    macro_name[j] = string[i + 6 + j];
                                    j++;
                                }
                                macro_name[j] = '\0';
                                int k = 0;
                                while (string[i + 6 + j + k] != '\0') {
                                    if (string[i + 6 + j + k] == 'e' &&
                                        string[i + 7 + j + k] == 'n' &&
                                        string[i + 8 + j + k] == 'd' &&
                                        string[i + 9 + j + k] == 'm' &&
                                        string[i + 10 + j + k] == 'a' &&
                                        string[i + 11 + j + k] == 'c' &&
                                        string[i + 12 + j + k] == 'r' &&
                                        string[i + 13 + j + k] == 'o') {
                                        break;
                                    }
                                    macro_body[k] = string[i + 6 + j + k];
                                    k++;
                                }
                                macro_body[k] = '\0';
                                return i+12+j+k; //the position of the end of the macro, so the next execution will start from here
                            }
                        }
                    }
                }
            }
        }
        i++;
    }
    return 0;
}

//function that gets a string and returns a sub-string without the definition of macros
char *get_string_without_macros(char *string) {
    char *string_without_macros = malloc(sizeof(char) * 1000);
    int i = 0;
    int j = 0;
    while (string[i] != '\0') {
        if (string[i] == 'm') {
            if (string[i + 1] == 'a') {
                if (string[i + 2] == 'c') {
                    if (string[i + 3] == 'r') {
                        if (string[i + 4] == 'o') {
                            if (string[i + 5] == ' ') {
                                int k = 0;
                                while (string[i + 6 + k] != '\0') {
                                    if(string[i + 6 + k] == 'e' &&
                                       string[i + 7 + k] == 'n' &&
                                       string[i + 8 + k] == 'd' &&
                                       string[i + 9 + k] == 'm' &&
                                       string[i + 10 + k] == 'a' &&
                                       string[i + 11 + k] == 'c' &&
                                       string[i + 12 + k] == 'r' &&
                                       string[i + 13 + k] == 'o'){
                                        break;
                                    }
                                    k++;
                                }
                                i = i + 15 + k;
                            }
                        }
                    }
                }
            }
        }
        string_without_macros[j] = string[i];
        i++;
        j++;
    }
    string_without_macros[j] = '\0';
    return string_without_macros;
}

//function that checks if a macro name is in substring, and replace it with the macro body
//no need to check for the string 'macro', just the macro name
char *replace_macro(char *string, char *macro_name, char *macro_body) {
    char *string_without_macros = get_string_without_macros(string);
    char *string_with_macros = malloc(sizeof(char) * 1000);
    int i = 0;
    int j = 0;
    while (string_without_macros[i] != '\0') {
        if (string_without_macros[i] == macro_name[0]) {
            int k = 0;
            while (macro_name[k] != '\0') {
                if (macro_name[k] != string_without_macros[i + k]) {
                    break;
                }
                k++;
            }
            if (macro_name[k] == '\0') {
                int l = 0;
                while (macro_body[l] != '\0') {
                    string_with_macros[j] = macro_body[l];
                    j++;
                    l++;
                }
                i = i + k;
            } else {
                string_with_macros[j] = string_without_macros[i];
                i++;
                j++;
            }
        } else {
            string_with_macros[j] = string_without_macros[i];
            i++;
            j++;
        }
    }
    string_with_macros[j] = '\0';
    return string_with_macros;
}




