#ifndef ORDER_H_
#define ORDER_H_

#include "mainLogic.h"

pelanggan* inputPesanan();

void enqueue(pelanggan* new);
void dequeue();
void search();
void viewQueue();
void viewMenu();

void printFood();
void printDrink();
void view();
void loadMenu();
void menuTree();

#endif