typedef struct label_struct{
    int label_type;
    //todo: limit the size of the name to 30.
    char *name;
    //todo: limit the address to 356
    int address;
    int label_location;
}label_struct;

enum label_type{
    data_label = 1,
    string_label = 2,
    struct_label = 3,
    entry_label = 4,
    instruction_label = 5
};

enum label_location{
    relocatable = 1,
    external = 2,
};

int labels_count;

label_struct *labels;