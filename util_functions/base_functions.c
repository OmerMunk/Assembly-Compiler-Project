//
// Created by Omer Munk on 18/07/2022.
//
#include <math.h>


int is_letter(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    } else if (c >= 'A' && c <= 'Z') {
        return 1;
    } else {
        return 0;
    }
}

int is_valid_digit(char c) {
    if (c >= '1' && c <= '9') {
        return 1;
    } else {
        return 0;
    }
}


// A function that returns the index of the char '.' in a string
int find_dot(char *string) {
    i = 0;
    while (string[i] != '\0') {
        if (string[i] == '.') {
            return i;
        }
        i++;
    }
    return -1;
}

char *after_dot;


// A function to convert decimal to binary
void dec_to_bin(int n, int *arr) {
    i = 9;
    while (n > 0) {
        arr[i] = n % 2;
        n = n / 2;
        i--;
    }
}



// A function to print binary number
void print_bin(int *arr) {
    for (i = 0; i < 10; i++) {
        printf("%d", arr[i]);
    }
}

// A function the converts binary number to decimal number
int bin_to_dec(int length, int *arr) {
    i = length - 1;
    int sum = 0;
    while (i > -1) {
        sum = sum + arr[i] * pow(2, length - (i + 1));
        i--;
    }
    return sum;
}

// A function that converts decimal number to base32 number
void dec_to_base32(int decimal_num, char *arr) {
    int quotient, remainder;
    i = 0;
    quotient = decimal_num;
    while (quotient != 0) {
        remainder = quotient % 32;
        switch (remainder) {
            case 0:
                arr[i++] = '!'; //33
                break;
            case 1:
                arr[i++] = '@'; //64
                break;
            case 2:
                arr[i++] = '#'; //35
                break;
            case 3:
                arr[i++] = '$'; //36
                break;
            case 4:
                arr[i++] = '%'; //37
                break;
            case 5:
                arr[i++] = '^'; //94
                break;
            case 6:
                arr[i++] = '&'; //38
                break;
            case 7:
                arr[i++] = '*'; //42
                break;
            case 8:
                arr[i++] = '<'; //60
                break;
            case 9:
                arr[i++] = '>'; //62
                break;
            default:
                arr[i++] = (char) (remainder + 87);
                break;
        }
        quotient = quotient / 32;
    }
}

// A function that converts base32 number to decimal number
int base32_to_dec(int length, char *arr) {
    i = 0;
    int sum = 0;
    while (i < length) {
        switch (arr[i]) {
            case '!':
                sum = sum + 0 * (int)pow(32, i);
                break;
            case '@':
                sum = sum + 1 * (int)pow(32, i);
                break;
            case '#':
                sum = sum + 2 * (int)pow(32, i);
                break;
            case '$':
                sum = sum + 3 * (int)pow(32, i);
                break;
            case '%':
                sum = sum + 4 * (int)pow(32, i);
                break;
            case '^':
                sum = sum + 5 * (int)pow(32, i);
                break;
            case '&':
                sum = sum + 6 * (int)pow(32, i);
                break;
            case '*':
                sum = sum + 7 * (int)pow(32, i);
                break;
            case '<':
                sum = sum + 8 * (int)pow(32, i);
                break;
            case '>':
                sum = sum + 9 * (int)pow(32, i);
                break;
            default:
                sum = sum + (arr[i] - 87) * (int)pow(32, i);
                break;
        }
        i++;
    }
    return sum;
}


void print_base32(char *arr) {
    for (i = 1; i > -1; i--) {
        printf("%c", arr[i]);
    }
}

// A function that converts binary number to base32 number
void bin_to_base32(int *bin_arr, char *base32_arr) {
    int decimal;
    decimal = bin_to_dec(10, bin_arr);
    dec_to_base32(decimal, base32_arr);
}

\


// A function that analyzes a word from binary representation into a word struct
void binary_to_word(int *word, struct word *word_struct) {
    /*
     * opcode - operation code
     *  soam - source operand addressing method
     *  doam - destination operand addressing method
     *  are - codec type
     * */
    int j, sum;

    sum = 0;
    for (i = 3, j = 0; i > -1; i--, j++) {
        sum = sum + word[i] * (int)pow(2, j);
    }
    word_struct->opcode = sum;
    sum = 0;
    for (i = 5, j = 0; i > 3; i--, j++) {
        sum = sum + word[i] * (int)pow(2, j);
    }
    word_struct->soam = sum;
    sum = 0;
    for (i = 7, j = 0; i > 5; i--, j++) {
        sum = sum + word[i] * (int)pow(2, j);
    }
    word_struct->doam = sum;
    sum = 0;
    for (i = 9, j = 0; i > 7; i--, j++) {
        sum = sum + word[i] * (int)pow(2, j);
    }
    word_struct->are = sum;
}

char *substring(char *string, int position, int length) {
    char *pointer = malloc(length + 1);
    memcpy(pointer, string + position, length);
    pointer[length] = '\0';
    return pointer;
}










// A function that prints word struct
void print_word_struct(struct word *word_struct) {
    printf("opcode: %d\n", word_struct->opcode);
    printf("soam: %d\n", word_struct->soam);
    printf("doam: %d\n", word_struct->doam);
    printf("are: %d\n", word_struct->are);
}





