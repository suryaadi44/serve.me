#include "menu.h"

int viewMenu() {
    int pil;
    printf("==============================================================\n");
    printf(" Lihat Menu :\n");
    printf("  1. Makanan\n");
    printf("  2. Minuman\n");
    printf(" Pilih : ");
    scanf("%d", &pil);
    printf("==============================================================\n");

    if (pil == 1) {
        printFood();
        return 1;
    }
    printDrink();
    return 2;
}

void printFood() {
    printf(" +----+------------------------+-------------+\n");
    printf(" | ID |         Makanan        |    Harga    |\n");
    printf(" +----+------------------------+-------------+\n");
    inorder(foodRoot);
    printf(" +----+------------------------+-------------+\n");
}

void printDrink() {
    printf(" +----+------------------------+-------------+\n");
    printf(" | ID |         Minuman        |    Harga    |\n");
    printf(" +----+------------------------+-------------+\n");
    inorder(drinkRoot);
    printf(" +----+------------------------+-------------+\n");
}

void inorder(menu* now) {
    if (now != NULL) {
        inorder(now->left);
        printf(" | %-2d | %-22s | Rp.%8d |\n", now->id, now->nama, now->price);
        inorder(now->right);
    }
}

menu* searchMenu(menu* root, int id) {
    if(root == NULL || root->id == id){
        return root;
    }

    if(root->id < id)
        return searchMenu(root->right, id);
    
    return searchMenu(root->left, id);
}

void loadMenu() {
    FILE* food, * drink;

    int max;
    drink = fopen(DRINK_DB_PATH, "r");
    max = countLine(DRINK_DB_PATH);
    for (int i = 0; i < max; i++) {
        menu* readMenu = (menu*)malloc(sizeof(menu));
        readMenu->left = readMenu->right = NULL;
        fscanf(drink, "%d,\"%[^\"]\",%d", &readMenu->id, readMenu->nama, &readMenu->price);
        menuTree(readMenu, &drinkRoot);
    }

    food = fopen(FOOD_DB_PATH, "r");
    max = countLine(FOOD_DB_PATH);
    for (int i = 0; i < max; i++) {
        menu* readMenu = (menu*)malloc(sizeof(menu));
        readMenu->left = readMenu->right = NULL;
        fscanf(food, "%d,\"%[^\"]\",%d", &readMenu->id, readMenu->nama, &readMenu->price);
        menuTree(readMenu, &foodRoot);
    }

    fclose(drink);
    fclose(food);
}

void menuTree(menu* node, menu** root) {
    node->left = node->right = NULL;

    if (*root == NULL) {
        *root = node;
        return;
    }

    menu* temp = *root;
    while (1)
        if (temp->id > node->id) {
            if (temp->left == NULL) {
                temp->left = node;
                return;
            }
            temp = temp->left;
        } else {
            if (temp->right == NULL) {
                temp->right = node;
                return;
            }
            temp = temp->right;
        }
}