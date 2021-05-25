#include "order.h"

pelanggan* head = NULL;
menu* foodRoot = NULL;
menu* drinkRoot = NULL;

pelanggan* inputPesanan() {
    pelanggan* new = (pelanggan*)malloc(sizeof(pelanggan));
    int lanjut = 1;

    printf("\n Masukan Data\n");
    printf("  Nama      : ");
    fflush(stdin);
    scanf("%[^\n]%*c", &new->nama);
    printf("  Meja      : ");
    fflush(stdin);
    scanf("%d", &new->meja);

    new->next = NULL;
    pesanan* order = (pesanan*)malloc(sizeof(pesanan));
    new->head = order;

    do{
        viewMenu();

        lanjut = pause();
    } while(lanjut == 1);
    
    return new;
}

void enqueue(pelanggan* new) {

}

void dequeue() {

}

void search() {

}

void viewQueue() {

}

void viewMenu() {
    int pil;
    printf("==============================================================\n");
    printf(" Lihat Menu :\n");
    printf("  1. Makanan\n");
    printf("  2. Minuman\n");
    printf(" Pilih : ");
    scanf("%d", &pil);
    printf("==============================================================\n");

    if(pil == 1){
        printFood();
        return;
    }
    printDrink();
}

void printFood() {
    printf(" +----+------------------------+-------------+\n");
    printf(" | ID |         Makanan        |    Harga    |\n");
    printf(" +----+------------------------+-------------+\n");
    view(foodRoot);
    printf(" +----+------------------------+-------------+\n");
}

void printDrink() {
    printf(" +----+------------------------+-------------+\n");
    printf(" | ID |         Minuman        |    Harga    |\n");
    printf(" +----+------------------------+-------------+\n");
    view(drinkRoot);
    printf(" +----+------------------------+-------------+\n");
}

void view(menu* now) {
    if (now != NULL) {
        view(now->left);
        printf(" | %-2d | %-22s | Rp.%8d |\n", now->id, now->nama, now->price);
        view(now->right);
    }
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
        menuTree(readMenu, drinkRoot, 1);
    }

    food = fopen(FOOD_DB_PATH, "r");
    max = countLine(FOOD_DB_PATH);
    for (int i = 0; i < max; i++) {
        menu* readMenu = (menu*)malloc(sizeof(menu));
        readMenu->left = readMenu->right = NULL;
        fscanf(food, "%d,\"%[^\"]\",%d", &readMenu->id, readMenu->nama, &readMenu->price);
        menuTree(readMenu, foodRoot, 0);
    }

    fclose(drink);
    fclose(food);
}

void menuTree(menu* node, menu* root, int type) {
    node->left = node->right = NULL;

    if (!type && foodRoot == NULL) {
        foodRoot = node;
        return;
    }

    if (type && drinkRoot == NULL) {
        drinkRoot = node;
        return;
    }

    menu* temp = root;
    while (1)
        if (strcmp(temp->nama, node->nama) > 0) {
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