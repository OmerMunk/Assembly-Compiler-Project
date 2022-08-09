//
// Created by Omer Munk on 08/08/2022.
//

// A function that gets two addresses, and store the value of the first address to the second address
void move(int *source_operand, int *destination_operand) {
    *destination_operand = *source_operand;
}

int compare(int *source_operand, int *destination_operand) {
    return *source_operand - *destination_operand;
}

void addition(int *source_operand, int *destination_operand) {
    *destination_operand += *source_operand;
}

void subtraction(int *source_operand, int *destination_operand) {

    *destination_operand -= *source_operand;
}

// function that gets an address, and stores the address in the value of the second parameter
void load_effective_address(int *source_operand_address, int *destination_operand) {
    printf("\n%p", source_operand_address);
    printf("\n%d", *destination_operand);
    *destination_operand = (int)source_operand_address;
}


// A function that gets a binary representation of a number, and swaps every bit in the number
void swap_bits(int *source_operand) {
    int i;
    for (i = 0; i < 10; i++) {
        if ((*source_operand >> i) & 1) {
            *source_operand = *source_operand & ~(1 << i);
        } else {
            *source_operand = *source_operand | (1 << i);
        }
    }
}

void clear(int *operand) {
    *operand = 0;
}

// A function that gets a pointer to variable, and stores a char from the input to the value of the variable
void get_input(int *operand) {
    char input[10];
    scanf("%s", input);
    *operand = input[0];
}

// A function that gets a pointer to variable, and prints the char stored in the value of the variable
void print_char(int *operand) {
    printf("\n%c", *operand);
}

void exit_program(){
    printf("\nExiting program");
    exit(0);
}
