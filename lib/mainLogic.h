#ifndef MAINLOGIC_H_
#define MAINLOGIC_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void header();
void clear();
int pause();
int countLine(char file[]);

struct tm* waktu;

typedef struct menu {
    int id;
    char nama[20];
    int price;
} menu;

typedef struct pesanan {
    int id;
    struct pesanan *next;
} pesanan;

typedef struct pelanggan {
    int id;
    char nama[20];
    struct pesanan *head;
    struct pelanggan *left, *right;
} pelanggan;

#endif