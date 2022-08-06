typedef struct word {
    int opcode;
    int soam;
    int doam;
    int are;
} word ;

enum commands {
    mov = 0,
    cmp = 1,
    add = 2,
    sub = 3,
    not = 4,
    clr = 5,
    lea = 6,
    inc = 7,
    dec = 8,
    jmp = 9,
    bne = 10,
    get = 11,
    prn = 12,
    jsr = 13,
    rts = 14,
    hlt = 15
};