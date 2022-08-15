//
// Created by Omer Munk on 07/08/2022.
//
#include "computer_resource.h"


void turn_on_computer() {
    r1.value = 0;
    r2.value = 0;
    r3.value = 0;
    r4.value = 0;
    r5.value = 0;
    r6.value = 0;
    r7.value = 0;
    r8.value = 0;
    current_address = FIRST_ADDRESS;
    IC = 0;
    DC = 0;
}


int i;
int j;

void assign_word(char *word) {
    for (i = 0; i < 10; i++) {
        computer_memory[current_address].word[i] = word[i];
    }
}

void assign_to_memory(char *word) {
    if (current_address > 255) {
        //todo: add error handling
        printf("Memory is full");
        return;
    }
    computer_memory[current_address].address = current_address;
    assign_word(word);
    current_address++;
};

void print_address_content(int address) {
    printf("\nThe content of address %d is: %s", address, computer_memory[address].word);
}