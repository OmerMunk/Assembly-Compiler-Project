typedef struct label_struct{
    int label_type;
    char *name;
    int address;
}label_struct;

enum label_type{
    data_label = 1,
    string_label = 2,
    struct_label = 3,
    entry_label = 4,
    instruction_label = 5
};

int labels_count;

label_struct *labels;