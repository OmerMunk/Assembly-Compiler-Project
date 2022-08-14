#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "headers/types.h"
#include "util_functions/utils_omer1_header.h"
#include "util_functions/command_functions.h"

#include "source_to_assembly//pre-assembler/pre_assembler.c"
#include "assembly_to_machine/computer/computer_resource.c"
#include "assembly_to_machine/operations/commands.c"
#include "labels/labels.c"
#include "util_functions/base_functions.c"
#include "util_functions/addressing_functions.c"

#include "util_functions/command_functions.c"
#include "source_to_assembly/analayzers.c"





//#include "util_functions/utils_omer1_header.h"
//#include "./pre-assembler/pre_assembler.h"

char x;

//substring function



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
        binary_to_word(arr4, &word1);
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
    char *file_string = read_file("../source_code2.txt");

    printf("\nThe File String is:\n\n%s", file_string);

    macro_struct (*macro_struct_ptr) = malloc(sizeof(macro_struct));

//    char *macro_name1;
//    macro_name1 = malloc(sizeof(char) * 200);
//    char *macro_body1;
//    macro_body1 = malloc(sizeof(char) * 200);
//    char *macro_name2;
//    macro_name2 = malloc(sizeof(char) * 200);
//    char *macro_body2;
//    macro_body2 = malloc(sizeof(char) * 200);

    printf("\nLINE 78\n");

//    int next_position = is_macro(file_string, macro_name1, macro_body1, 0);
    int next_position = is_macro(file_string, macro_struct_ptr[0].name, macro_struct_ptr[0].body, 0);



//    is_macro(file_string, macro_name2, macro_body2, next_position);
    printf("\nLINE 86\n");

    int i = 1;
    while (next_position != 0) {
        next_position = is_macro(file_string, macro_struct_ptr[i].name, macro_struct_ptr[i].body, next_position);
        i++;
    }
    printf("\nLINE 93\n");

    char *result = (get_string_without_macros(file_string));

    printf("\n\n\nThe Result is:\n\n%s", result);

    char *ongoing_string = result;
//    ongoing_string = replace_macro(result, macro_name1, macro_body1);
//    ongoing_string = replace_macro(ongoing_string, macro_name1, macro_body1);
//    ongoing_string = replace_macro(ongoing_string, macro_name2, macro_body2);
//    ongoing_string = replace_macro(ongoing_string, macro_name2, macro_body2);
    printf("\nLINE 109\n");
    printf("%s", macro_struct_ptr[0].name);
    printf("\nLINE 110\n");
    ongoing_string = replace_macro(result, macro_struct_ptr[0].name, macro_struct_ptr[0].body);
    printf("\nLINE 111\n");
    int j = 1;
    int k;
    int count = 0;
    while (j < i){
        printf("\nLINE 114\n");
        count = count_macro(ongoing_string, macro_struct_ptr[j].name);
        k = 0;
        printf("\nLINE 115\n");
        while (k <= count){
            ongoing_string = replace_macro(ongoing_string, macro_struct_ptr[j].name, macro_struct_ptr[j].body);
            k++;
        }
        j++;
    }
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
    turn_on_computer();
    r1.value = 1;
    printf("\n%d", r1.value);
    printf("\n%p", &r1);
    printf("\n%d", r2.value);
    printf("\n%p", &r2);


    int a = 7;
    r1.value = 12;
    printf("\nThe address of a is : %p", &a);
    printf("\nThe address of a is : %d", (int)&a);
    printf("\nThe value of r1 is: %d", r1.value);
    load_effective_address(&a, &r1.value);
    printf("\nThe value of r1 is: %d", r1.value);
    printf("\nThe value of r1 is: %p", (void*)r1.value);
    int b = 992;
    swap_bits(&b);
    printf("\n%d", b);
    printf("\nThe value of r1 is: %d", r1.value);
    clear(&r1.value);
    printf("\nThe value of r1 is: %d", r1.value);
//    get_input(&r1.value);
    printf("\nThe value of r1 is: %d", r1.value);
    print_char(&r1.value);
//    exit_program();
    printf("\nwow\n");
    char* sub = "kaka";
    init_labels();
    add_label(sub, 123);
    add_label("ari", 129);
    print_label(0);
    print_label(1);
    print_label(2);
    if(check_if_label_name_available("r1")){
        printf("\nr1 is available");
    }
    else{
        printf("\nr1 is not available");
    }

    assign_to_memory("1111100000");
    assign_to_memory("0000011111");
    print_address_content(2);
    print_address_content(1);
    print_address_content(0);



//    computer_memory.address[0]->address[0] = "0";
//    computer_memory.address[0]->address[1] = "1";



    return 0;
}
