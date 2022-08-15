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
#include "source_to_assembly/pre-assembler/from_source_to_after_macro.c"





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


    char* after_macro_span = span_macros(read_file("../source_code2.txt"), "../source_code2");





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
    iteration = 1;
    //todo: where to ++ this ^^ ?
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
