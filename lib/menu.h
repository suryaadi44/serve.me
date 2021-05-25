#ifndef MENU_H_
#define MENU_H_

#include "mainLogic.h"

int viewMenu();
void printFood();
void printDrink();
void loadMenu();
void menuTree(menu* node, menu** root);
void inorder(menu* now);
menu* searchMenu(menu* root, int id);




#endif