//
// Created by Omer Munk on 09/08/2022.
//
#include <ctype.h>

int determine_sub_word(char *sub_word) {
    // check if a string ends with ':', less then 31 chars, and starts with a letter
    if (sub_word[strlen(sub_word) - 1] == ':' &&
        strlen(sub_word) < 31 &&
        isalpha(sub_word[0]) &&
        check_if_label_name_available(sub_word)) {
        return label;
    } else if (
        //check if a string contains digits only
            strspn(sub_word, "0123456789") == strlen(sub_word) ||
            //check if a string starts with '+' or '-' and is a number or is a number
            ((sub_word[0] == '+' || sub_word[0] == '-') &&
             (strspn(sub_word, "0123456789") == strlen(sub_word) - 1))
            ) {
        return number;
    } else if (
        //check if a string is wrapped with '"', with no more '"' in between the other two
            sub_word[0] == '"' &&
            sub_word[strlen(sub_word) - 1] == '"' &&
            strlen(sub_word) > 2 &&
            strcspn(sub_word, "\"") == strlen(sub_word) - 2
            ) {
        return string;
    }


    return 0;
}



