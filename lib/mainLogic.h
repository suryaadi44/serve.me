#ifndef MAINLOGIC_H_
#define MAINLOGIC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

#define FOOD_DB_PATH "./db_menu/food_menu.csv"
#define TEMP_FOOD_DB_PATH "./db_menu/temp.csv"
#define DRINK_DB_PATH "./db_menu/drink_menu.csv"
#define TEMP_DRINK_DB_PATH "./db_menu/temp.csv"

void header();
void clear();
int pause();
int countLine(char file[]);

struct tm* waktu;

typedef struct menu {
    int id;
    char nama[20];
    int price;
    struct menu* left, * right;
} menu;

typedef struct pesanan {
    int id;
    int type;
    char message[200];
    struct pesanan* next;
} pesanan;

typedef struct pelanggan {
    int id;
    int meja;
    char nama[20];
    struct pesanan* head;
    struct pelanggan* next;
} pelanggan;

#endif