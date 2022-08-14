//
// Created by Omer Munk on 09/08/2022.
//
#include <ctype.h>


int opcode;
int operands_amount;
int command_detected;


int labels_detected;
int operands_detected;
int success;
int sub_words_count;

char *declared_label;

int sub_word_type;
char *sub_word;

int word_type;

int determine_sub_word(char *given_sub_word) {
    // check if a string ends with ':', less then 31 chars, and starts with a letter
    if (given_sub_word[strlen(given_sub_word) - 1] == ':' &&
        strlen(given_sub_word) < 31 &&
        isalpha(given_sub_word[0]) &&
        check_if_label_name_available(given_sub_word)) {
        return label_declaration;
    } else if (
        //check if a string contains digits only
            ((given_sub_word[0] == FIRST_CHAR_OF_IMMEDIATE_ADDRESSING) &&
             strspn(given_sub_word, "0123456789") == strlen(given_sub_word)) ||
            //check if a string starts with '+' or '-' and is a number or is a number
            ((given_sub_word[0] == FIRST_CHAR_OF_IMMEDIATE_ADDRESSING) && (given_sub_word[1] == '+' || given_sub_word[1] == '-') &&
             (strspn(given_sub_word, "0123456789") == strlen(given_sub_word) - 2))
            ) {
        return number;
    } else if (
        //check if a string is wrapped with '"', with no more '"' in between the other two
            given_sub_word[0] == '"' &&
                    given_sub_word[strlen(given_sub_word) - 1] == '"' &&
            strlen(given_sub_word) > 2 &&
            strcspn(given_sub_word, "\"") == strlen(given_sub_word) - 2
            ) {
        return string;
    } else if (
        //check if a string is a command name
            strcmp(given_sub_word, "mov") == 0 ||
            strcmp(given_sub_word, "cmp") == 0 ||
            strcmp(given_sub_word, "add") == 0 ||
            strcmp(given_sub_word, "sub") == 0 ||
            strcmp(given_sub_word, "lea") == 0 ||
            strcmp(given_sub_word, "not") == 0 ||
            strcmp(given_sub_word, "clr") == 0 ||
            strcmp(given_sub_word, "inc") == 0 ||
            strcmp(given_sub_word, "dec") == 0 ||
            strcmp(given_sub_word, "jmp") == 0 ||
            strcmp(given_sub_word, "bne") == 0 ||
            strcmp(given_sub_word, "get") == 0 ||
            strcmp(given_sub_word, "prn") == 0 ||
            strcmp(given_sub_word, "jsr") == 0 ||
            strcmp(given_sub_word, "rts") == 0 ||
            strcmp(given_sub_word, "hlt") == 0
            ) {
        return command;
    } else if (strcmp(".data", given_sub_word) == 0) {
        return data_order;
    } else if (strcmp(".string", given_sub_word) == 0) {
        return string_order;
    } else if (strcmp(".struct", given_sub_word) == 0) {
        return struct_order;
    } else if (strcmp(".entry", given_sub_word) == 0) {
        return entry_order;
    } else if (strcmp(".extern", given_sub_word) == 0) {
        return extern_order;
    }


    return 0;
}


// A function that analyzes the beginning of a word
int word_beginning(char *word, int *binary_word) {
    if (word[0] == ';') {
        return comment_word;
    }

    while (word[j] != '\0') {
        i = j;
        while (word[i] == ' ') {
            if (word[i] == ',') {
                return 0;
            }
            i++;
        }
        j = i;
        while (word[j] != '\0' && word[j] != ' ') {
            if (word[i] == ',') {
                return 0;
            }
            j++;
        }
        if (i == j) {
            return empty_word;
        }
        sub_word = substring(word, i, j - i);

        sub_word_type = determine_sub_word(sub_word);

        if (sub_word_type == label_declaration) {
            if (labels_detected == 0 && sub_words_count == 0) {
                add_label(sub_word, current_address);
                //copy the content of sub_word to declared_label
                strcpy(declared_label, sub_word);
            } else {
                return 0;
            }

        } else if (sub_word_type == command) {
            if (command_detected) {
                return 0;
            } else {
                opcode = determine_opcode(sub_word);
                operands_amount = determine_operands_amount(sub_word);
                command_detected = 1;
                if (sub_words_count == 1 && labels_detected == 1) {
                    assign_label_type(declared_label, instruction_label);
                }
                return instruction_word;
//                return operands_handling(word, binary_word, j);
            }
        } else if (
                sub_word_type == data_order ||
                sub_word_type == string_order ||
                sub_word_type == struct_order ||
                sub_word_type == entry_order ||
                sub_word_type == extern_order
                ) {

        } else {
            return 0;
        }
//        else if (sub_word_type == string) {
//            if (command_detected && operands_detected < operands_amount) {
//                operands_detected++;
//            }
//        }


        sub_words_count++;
    }
    return 1;
}

int operands_handler(char *word, int *binary_word){
    switch (operands_amount){
        case 0:
            return 1;
        case 1:
            i = j;
            if(word[i] == '\0'){
                return 0;
            }
            while (word[i] == ' ') {
                i++;
                if(word[i] == '\0'){
                    return 0;
                }
            }
            j = i;
            while (word[j] != '\0' && word[j] != ' ') {
                j++;
            }
            determine_operand_addressing_method(substring(word, i, j - i));
            return 2;
        case 2:
            return 3;
        default:
            return 0;
    }
}


// A function that analyzes a word from string representation into a binary representation
// using the determine_sub_word function
int string_to_binary(char *word, int *binary_word) {

    declared_label = malloc(sizeof(char) * 30);
    success = 1;
    j = 0;
    opcode = -1;
    operands_amount = -1;
    command_detected = 0;
    sub_words_count = 0;
    labels_detected = 0;

    word_type = word_beginning(word, binary_word);
    switch (word_type) {
        case comment_word:
            return 1;
        case empty_word:
            return 1;
        case order_word:
            return order_handling(word, binary_word);
        case instruction_word:
            return operands_handler(word, binary_word);
        default:
            return 0;
    }


    return success;
}



