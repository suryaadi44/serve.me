#ifndef ORDER_H_
#define ORDER_H_

#include "mainLogic.h"
#include "menu.h"

pelanggan* inputPesanan();
pelanggan* searchByID(int id);
pelanggan* searchByName(char nama[]);

void enqueue(pelanggan* new);
void dequeue();
void search();
void viewQueue();
void printQueue(pelanggan* temp);

#endif