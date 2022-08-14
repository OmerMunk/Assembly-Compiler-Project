//
// Created by Omer Munk on 20/07/2022.
//


//determine how many operands are in the command
int determine_operands_amount(char *command) {
    if (strcmp(command, "mov") == 0 ||
        strcmp(command, "cmp") == 0 ||
        strcmp(command, "add") == 0 ||
        strcmp(command, "sub") == 0 ||
        strcmp(command, "lea") == 0) {
        return 2;
    } else if (
            strcmp(command, "not") == 0 ||
            strcmp(command, "clr") == 0 ||
            strcmp(command, "inc") == 0 ||
            strcmp(command, "dec") == 0 ||
            strcmp(command, "jmp") == 0 ||
            strcmp(command, "bne") == 0 ||
            strcmp(command, "get") == 0 ||
            strcmp(command, "prn") == 0 ||
            strcmp(command, "jsr") == 0
            ) {
        return 1;
    } else if (
            strcmp(command, "rts") == 0 ||
            strcmp(command, "hlt") == 0
            ) {
        return 0;
    } else {
        return -1;
    }

}

int determine_opcode(char *command) {
    if (strcmp(command, "mov") == 0) {
        return mov;
    } else if (strcmp(command, "cmp") == 0) {
        return cmp;
    } else if (strcmp(command, "add") == 0) {
        return add;
    } else if (strcmp(command, "sub") == 0) {
        return sub;
    } else if (strcmp(command, "lea") == 0) {
        return lea;
    } else if (strcmp(command, "not") == 0) {
        return not;
    } else if (strcmp(command, "clr") == 0) {
        return clr;
    } else if (strcmp(command, "inc") == 0) {
        return inc;
    } else if (strcmp(command, "dec") == 0) {
        return dec;
    } else if (strcmp(command, "jmp") == 0) {
        return jmp;
    } else if (strcmp(command, "bne") == 0) {
        return bne;
    } else if (strcmp(command, "get") == 0) {
        return get;
    } else if (strcmp(command, "prn") == 0) {
        return prn;
    } else if (strcmp(command, "jsr") == 0) {
        return jsr;
    } else if (strcmp(command, "rts") == 0) {
        return rts;
    } else if (strcmp(command, "hlt") == 0) {
        return hlt;
    } else {
        return -1;
    }
}

//check if a char is a letter







