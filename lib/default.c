#include "default.h"

void directoryCheck() {
    struct stat st = { 0 };

    if (stat("db_menu", &st) == -1) {
        mkdir("db_menu");
    }

    if (stat("tx_log", &st) == -1) {
        mkdir("tx_log");
    }
}

void fileCheck(){
    FILE *makanan, *minuman;
    int baris;

    makanan = fopen(FOOD_DB_PATH, "a+");
    minuman = fopen(DRINK_DB_PATH, "a+");

    baris = countLine(FOOD_DB_PATH);
    if(baris == 0){
        fprintf(makanan, "1,\"Pisang Goreng\",12000\n");
        fprintf(makanan, "2,\"Roti Bakar\",10000\n");
        fprintf(makanan, "3,\"Siomay\",8000\n");
        fprintf(makanan, "4,\"Nachos\",5000\n");
        fprintf(makanan, "5,\"Onion Ring\",10000\n");
        fprintf(makanan, "6,\"Chicken Fingers\",15000\n");
        fprintf(makanan, "7,\"Jamur Crispy\",14000\n");
        fprintf(makanan, "8,\"Kentang Goreng\",10000\n");
        fprintf(makanan, "9,\"Pudding\",7000\n");
        fprintf(makanan, "10,\"Pancake\",16000\n");
        fprintf(makanan, "11,\"Waffle\",17000\n");        
    }

    baris = countLine(DRINK_DB_PATH);
    if(baris == 0){
        fprintf(minuman, "1,\"Milk Tea\",8000\n");
        fprintf(minuman, "2,\"Lemon Tea\",8000\n");
        fprintf(minuman, "3,\"Iced Matcha Latte\",10000\n");
        fprintf(minuman, "4,\"Cold Brew Milk Coffe\",8000\n");
        fprintf(minuman, "5,\"Brown Sugar Coffe\",11000\n");
        fprintf(minuman, "6,\"Es Cincau\",8000\n");
        fprintf(minuman, "7,\"Es Lemon\",7000\n");
        fprintf(minuman, "8,\"Thai Tea\",9000\n");
    }

    fclose(makanan);
    fclose(minuman);
}
