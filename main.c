#include <stdio.h>
#include "util_functions/base_functions.c"
#include "pre-assembler/pre_assembler.c"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#include "util_functions/utils_omer1_header.h"
//#include "./pre-assembler/pre_assembler.h"

char x;


//pointer to a function

int main() {
    bool flag = false;
    if (flag) {
        printf("%d", mov);
        printf("\n");
        printf("%d", jmp);
        printf("\n");
        printf("%d", bne);
        printf("\n");
        printf("Hello, World!\n");
        int n = 5;
        int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        printf("\ndec_to_bin: \n");
        dec_to_bin(n, arr);
        printf("\nprint_bin: \n");
        print_bin(arr);
        printf("\nbin to dec: \n");
        bin_to_dec(10, arr);
        printf("\n");
        char arr2[2] = {'!', '!'};
        char arr3[2] = {'v', '!'};
        dec_to_base32(32, arr2);
        print_base32(arr2);
        printf("\n");
        base32_to_dec(2, arr3);
        int arr4[10] = {1, 1, 0, 0, 0, 1, 1, 0, 0, 1};
        struct word word1;
        analayze_word(arr4, &word1);
        print_word_struct(&word1);
        int arr7[10] = {1, 0, 1, 1, 0, 1, 1, 0, 1, 1};
        char arr8[2] = {'!', '!'};
//    int result = bin_to_dec(10, arr7);
//    printf("%d", result);
//    dec_to_base32(731, arr8);
//    print_base32(arr8);
        bin_to_base32(arr7, arr8);
        printf("\n");
        print_base32(arr8);
        printf("\n");
    }



//    char* file_string1 = read_file("../hello.txt");
//    char* file_string4 = read_file("../hello2.txt");
//    char* file_string3 = read_file("../hello.txt");
//    char* file_string2 = read_file("../hello3.txt");
//    char* file_string2 = read_file("../text4.txt");
    char *file_string = read_file("../source_code.txt");

    printf("\nThe File String is:\n\n%s", file_string);
    char *macro_name1;
    macro_name1 = malloc(sizeof(char) * 200);
    char *macro_body1;
    macro_body1 = malloc(sizeof(char) * 200);
    char *macro_name2;
    macro_name2 = malloc(sizeof(char) * 200);
    char *macro_body2;
    macro_body2 = malloc(sizeof(char) * 200);

    int next_position = is_macro(file_string, macro_name1, macro_body1, 0);
    is_macro(file_string, macro_name2, macro_body2, next_position);

    char *result = (get_string_without_macros(file_string));

    printf("\n\n\nThe Result is:\n\n%s", result);

    char *ongoing_string = result;
    ongoing_string = replace_macro(result, macro_name1, macro_body1);
    ongoing_string = replace_macro(ongoing_string, macro_name1, macro_body1);
    ongoing_string = replace_macro(ongoing_string, macro_name2, macro_body2);
    ongoing_string = replace_macro(ongoing_string, macro_name2, macro_body2);
    printf("\n\n\n\n\nfinal result:\n\n%s", ongoing_string);




//    printf("\nfinished");
//    macro_struct macro_struct1;
//    macro_struct1.name = macro_name;
//    macro_struct1.body = macro_body;
//    printf("\nThe macro name is:\n");
//    printf("%s", macro_struct1.name);
//    printf("\nThe macro body is:\n");
//    printf("%s", macro_struct1.body);
//    printf("%s", replace_macro("omg this is so great", "so", "1234"));
    printf("\nDONE");
    return 0;
}
