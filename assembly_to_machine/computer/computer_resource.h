typedef struct register_struct {
    int value;
} register_struct;

register_struct r1;
register_struct r2;
register_struct r3;
register_struct r4;
register_struct r5;
register_struct r6;
register_struct r7;
register_struct r8;


typedef struct address_struct {
    int address;
    char* label;
    char word[10];

} address_struct;

//typedef struct memory{
//    address_struct* cells[255];
//}memory;


address_struct computer_memory[255];

int current_address;
