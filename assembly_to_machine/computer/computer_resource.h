typedef struct register_struct {
    unsigned int value : 10;
} register_struct;



register_struct r1;
register_struct r2;
register_struct r3;
register_struct r4;
register_struct r5;
register_struct r6;
register_struct r7;
register_struct r8;

//todo: change the word of the address_struct to bits

//todo: the DC array and the IC array, needs to be malloc to 0, and realloc every time we encounter more data or more instructions
// instructions first and then data
// realoc 10 cells every time , if it fails, try realloc 1, until it fails again then it means:
// error: memory overflow.

typedef struct address_struct {
    int address;
    char *label;
    char word[10];
} address_struct;

//typedef struct memory{
//    address_struct* cells[255];
//}memory;

//todo: consider not making it static size, but instaed, malloc and realoc.
address_struct computer_memory[256];

//todo: change this acording to what written above.
typedef struct memory_array_type {
    int address;
    char word[10];
} memory_array_type;

memory_array_type instructions_array[256];
memory_array_type data_array[256];

int current_address;

unsigned int IC;

unsigned int DC;

int FIRST_ADDRESS = 100;
