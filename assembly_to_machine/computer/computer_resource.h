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
    char* address[10];
    char* word[10]

} address_struct;

typedef struct memory{
    address_struct* address[255]
}memory;


memory computer_memory;
