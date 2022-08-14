//
// Created by Omer Munk on 14/08/2022.
//


int determine_operand_addressing_method(char *operand, int iteration_count) {
    //check if a string start with '#' and then contain only digits
    if (operand[0] == FIRST_CHAR_OF_IMMEDIATE_ADDRESSING && strspn(operand + 1, "-0123456789") == strlen(operand) - 1) {
        return immediate;
    }
        //check if a string does not contain '.' and does not start with a digit
    else if (
            operand[0] != FIRST_CHAR_OF_IMMEDIATE_ADDRESSING &&
            strchr(operand, '.') == NULL &&
            is_letter(operand[0]) &&
            operand[find_dot((operand)) + 1]
            ) {
        after_dot = substring(operand, find_dot(operand) + 1, strlen(operand));
        if (strspn(after_dot, "0123456789") == strlen(after_dot)) {
            return indirect_indexed;
        }
    } else if (operand[0] != FIRST_CHAR_OF_IMMEDIATE_ADDRESSING && strchr(operand, '.') == NULL) {
        for(i = 0 ; i < labels_count ; i++){
            if (strcmp(operand, labels[i].name) == 0) {
                return direct;
            }

        }
        if(iteration_count == 0){
            return future_possible_label;
        }
    } else if (strlen(operand) == MAXIMUM_REGISTER_NAME_LENGTH && operand[0] == 'r' &&
               strspn(operand + 1, "0123456789") == strlen(operand) - 1) {
        return register_direct;
    }
    return -1;
}