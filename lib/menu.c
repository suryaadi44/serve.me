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
    if (root == NULL || root->id == id) {
        return root;
    }

    if (root->id < id)
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

void addMenu() {
    FILE* db;
    int pil, max;

    menu* new = (menu*)malloc(sizeof(menu));

    printf("==============================================================\n");
    printf(" Tambah Menu :\n");
    printf("  1. Makanan\n");
    printf("  2. Minuman\n");
    printf(" Pilih : ");
    scanf("%d", &pil);
    printf("==============================================================\n");
    printf(" Masukan Menu Baru : \n");
    printf("  Nama Menu : ");
    fflush(stdin);
    scanf("%[^\n]", new->nama);
    printf("  Harga     : ");
    fflush(stdin);
    scanf("%d", &new->price);
    printf("==============================================================\n");

    if (pil == 1) {
        db = fopen(FOOD_DB_PATH, "a");
        max = countLine(FOOD_DB_PATH);
        menuTree(new, &foodRoot);
    } else {
        db = fopen(DRINK_DB_PATH, "a");
        max = countLine(DRINK_DB_PATH);
        menuTree(new, &drinkRoot);
    }

    
    fprintf(db, "%d,\"%s\",%d\n", max + 1, new->nama, new->price);
    fclose(db);
}

void delMenu() {
    FILE* db, * temp;
    int pil, max, del;

    menu read;

    printf("==============================================================\n");
    printf(" Pilih Menu :\n");
    printf("  1. Makanan\n");
    printf("  2. Minuman\n");
    printf(" Pilih : ");
    scanf("%d", &pil);
    printf("==============================================================\n");

    if (pil == 1)
        printFood();
    else
        printDrink();

    printf(" Masukan ID Menu yang akan Dihapus : ");
    scanf("%d", &del);
    printf("==============================================================\n");

    if (pil == 1) {
        db = fopen(FOOD_DB_PATH, "r");
        temp = fopen(TEMP_FOOD_DB_PATH, "a");
        max = countLine(FOOD_DB_PATH);
        deleteMenuTree(foodRoot);
    } else {
        db = fopen(DRINK_DB_PATH, "r");
        temp = fopen(TEMP_DRINK_DB_PATH, "a");
        max = countLine(DRINK_DB_PATH);
        deleteMenuTree(drinkRoot);
    }

    int line = 1;
    for (int i = 0; i < max; i++) {
        fscanf(db, "%d,\"%[^\"]\",%d", &read.id, read.nama, &read.price);
        if (read.id != del) {
            fprintf(temp, "%d,\"%s\",%d\n", line, read.nama, read.price);
            line++;
        }
    }

    fclose(db);
    fclose(temp);

    if (pil == 1) {
        remove(FOOD_DB_PATH);
        rename(TEMP_FOOD_DB_PATH, FOOD_DB_PATH);
        return;
    }

    remove(DRINK_DB_PATH);
    rename(TEMP_DRINK_DB_PATH, DRINK_DB_PATH);
}

void editMenu() {
    FILE* db, * temp;
    int pil, max, edit;

    menu read;
    menu new;

    printf("==============================================================\n");
    printf(" Edit Menu :\n");
    printf("  1. Makanan\n");
    printf("  2. Minuman\n");
    printf(" Pilih : ");
    scanf("%d", &pil);
    printf("==============================================================\n");

    if (pil == 1)
        printFood();
    else
        printDrink();

    printf(" Masukan ID Menu yang akan Diedit : ");
    scanf("%d", &edit);
    printf(" Masukan Menu Baru : \n");
    printf("  Nama Menu : ");
    fflush(stdin);
    scanf("%[^\n]", new.nama);
    printf("  Harga     : ");
    fflush(stdin);
    scanf("%d", &new.price);
    printf("==============================================================\n");

    if (pil == 1) {
        db = fopen(FOOD_DB_PATH, "r");
        temp = fopen(TEMP_FOOD_DB_PATH, "a");
        max = countLine(FOOD_DB_PATH);
        deleteMenuTree(foodRoot);
    } else {
        db = fopen(DRINK_DB_PATH, "r");
        temp = fopen(TEMP_DRINK_DB_PATH, "a");
        max = countLine(DRINK_DB_PATH);
        deleteMenuTree(drinkRoot);
    }

    int line = 1;
    for (int i = 0; i < max; i++) {
        fscanf(db, "%d,\"%[^\"]\",%d", &read.id, read.nama, &read.price);
        if (read.id == edit)
            fprintf(temp, "%d,\"%s\",%d\n", read.id, new.nama, new.price);

        else
            fprintf(temp, "%d,\"%s\",%d\n", read.id, read.nama, read.price);
    }


    fclose(db);
    fclose(temp);

    if (pil == 1) {
        remove(FOOD_DB_PATH);
        rename(TEMP_FOOD_DB_PATH, FOOD_DB_PATH);
        return;
    }

    remove(DRINK_DB_PATH);
    rename(TEMP_DRINK_DB_PATH, DRINK_DB_PATH);
}

void deleteMenuTree(menu* root) {
    if (root == NULL) return;

    deleteMenuTree(root->left);
    deleteMenuTree(root->right);
    
    free(root);
}