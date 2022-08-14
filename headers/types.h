enum sub_words_types {
    label_declaration = 2,
    number = 3,
    string = 4,
    command = 5,
    data_order = 6,
    string_order = 7,
    struct_order = 8,
    entry_order = 9,
    extern_order = 10,
    label_call = 11,
    indexed_label_call = 12,
    operand = 13,
    comment = 14,
    empty = 15,
    error = 16,
};

//empty word - contatins only spaces
//comment word - starts with ;
//order word - starts with label, and the order is one of the following: .data, .string, .struct, .entry, .extern
//instruction word - starts with a command name(label before - optional), and the rest of the word is one or two valid operands
enum word_types{
    empty_word = 2,
    comment_word = 3,
    order_word = 4,
    instruction_word = 5,
};