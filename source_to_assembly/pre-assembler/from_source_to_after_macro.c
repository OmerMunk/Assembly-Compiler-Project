#include <stdlib.h>
#include <string.h>
char *span_macros(char *string, char *source_file_name) {
    //    char* file_string1 = read_file("../hello.txt");
//    char* file_string4 = read_file("../hello2.txt");
//    char* file_string3 = read_file("../hello.txt");
//    char* file_string2 = read_file("../hello3.txt");
//    char* file_string2 = read_file("../text4.txt");
//    char *file_string = read_file("../source_code2.txt");
    int k;
    printf("char *string represents content, hence: %s.\n char * source_file_name represents file name, hence %s",string,source_file_name);
    char *file_string = string;
    printf("\nThe File String is:\n\n%s", file_string);
    macro_struct (*macro_struct_ptr) = malloc(sizeof(macro_struct));
    int next_position = is_macro(file_string, macro_struct_ptr[0].name, macro_struct_ptr[0].body, 0);
    i = 1;
    while (next_position != 0) {
        next_position = is_macro(file_string, macro_struct_ptr[i].name, macro_struct_ptr[i].body, next_position);
        i++;
    }
    char *result = (get_string_without_macros(file_string));
    printf("\n\n\nThe Result is:\n\n%s", result);
    char *ongoing_string = result;
    printf("%s", macro_struct_ptr[0].name);
    ongoing_string = replace_macro(result, macro_struct_ptr[0].name, macro_struct_ptr[0].body);
    j = 1;
    int count = 0;
    while (j < i) {
        count = count_macro(ongoing_string, macro_struct_ptr[j].name);
        k = 0;
        while (k <= count) {
            ongoing_string = replace_macro(ongoing_string, macro_struct_ptr[j].name, macro_struct_ptr[j].body);
            k++;
        }
        j++;
    }
    printf("\nLine 38\n");

    //write the string 'ongoing_string' to a file with 'am' extension
    // new string that starts with 'source_file_name' and ends with 'am' extension
    char *new_string = malloc(sizeof(char) * 1000);
    strcpy(new_string, source_file_name);
    strcat(new_string, ".am");
    printf("\nLine 39\n");

    write_file(new_string, ongoing_string);
    printf("\nLine 40\n");


    printf("\n\n\n\n\nfinal result:\n\n%s", ongoing_string);
    printf("\nLine 41\n");


    //

    return ongoing_string;
}
