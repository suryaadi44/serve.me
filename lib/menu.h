#ifndef MENU_H_
#define MENU_H_

#include "mainLogic.h"

int viewMenu();
void printFood();
void printDrink();
void loadMenu();
void menuTree(menu* node, menu** root);
void inorder(menu* now);
void sortMenu();
void sort(menu* now, char tempFile[]);
menu* searchMenu(menu* root, int id);
void deleteMenuTree(menu *root);

void addMenu();
void delMenu();
void editMenu();

#endif