//
// Created by Omer Munk on 09/08/2022.
//

#include "labels.h"

void init_labels(){
    labels_count = 0;
    labels = malloc(sizeof(label_struct) * 1000);
}

void add_label(char *name, int address){
    label_struct *new_label = (label_struct *)malloc(sizeof(label_struct));
    new_label->name = name;
    new_label->address = address;
    labels[labels_count] = *new_label;
    labels_count++;
}

void assign_label_type(char *name, int type){
    for (i = 0; i < labels_count; i++) {
        if (strcmp(labels[i].name, name) == 0) {
            labels[i].label_type = type;
        }
    }
}

void print_label(int num){
    printf("%s: %d\n", labels[num].name, labels[num].address);
}

int check_if_label_name_available(char *name){
    int i = 0;

    for (i = 0 ; i < RESERVED_NAMES_COUNT ; i++){
        if (strcmp(name, reserved_names[i]) == 0){
            return 0;
        }
    }
    i = 0;
    while (i < labels_count) {
        if (strcmp(labels[i].name, name) == 0) {
            return 0;
        }
        i++;
    }
    return 1;
}
