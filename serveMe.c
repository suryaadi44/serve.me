#include "lib/mainLogic.h"
#include "lib/default.h"
#include "lib/order.h"
#include "lib/menu.h"

void mainMenu();
void settingMenu();

menu* foodRoot;
menu* drinkRoot;
pelanggan* head;
int counter;

void main() {
    foodRoot = NULL;
    drinkRoot = NULL;
    head = NULL;
    counter = 1;
    
    directoryCheck();
    fileCheck();

    loadMenu();

    mainMenu();
}

void mainMenu() {
    int pil, lanjut = 1;

    do {
        clear();
        header();
        printf("==============================================================\n");
        printf("       Aplikasi Pemesanan Makanan dan Minuman Serve.Me        \n");
        printf("==============================================================\n");
        printf(" Menu Utama : \n");
        printf("  1. Tambah Pesanan\n");
        printf("  2. Proses Pesanan\n");
        printf("  3. Cari Pesanan\n");
        printf("  4. Lihat Antrian\n");
        printf("  5. Lihat Daftar Menu\n");
        printf("  6. Pengaturan\n");
        printf("  7. Keluar \n");
        printf("==============================================================\n");
        printf(" Pilihan : ");
        fflush(stdin);
        scanf("%d", &pil);

        switch (pil) {
        case 1:
            enqueue(inputPesanan());
            //lanjut = pause();
            break;
        case 2:
            dequeue();
            lanjut = pause();
            break;
        case 3:
            search();
            lanjut = pause();
            break;
        case 4:
            viewQueue();
            lanjut = pause();
            break;
        case 5:
            viewMenu();
            lanjut = pause();
            break;
        case 6:
            settingMenu();
            break;
        default:
            break;
        }
    } while (pil != 7 && lanjut == 1);
}

void settingMenu() {
    int pil, lanjut = 1;

    do {
        clear();
        header();
        printf("==============================================================\n");
        printf("                          Pengaturan                          \n");
        printf("==============================================================\n");
        printf(" Menu Pengaturan : \n");
        printf("  1. Tambah Daftar Menu\n");
        printf("  2. Edit Daftar Menu\n");
        printf("  3. Hapus Daftar Menu\n");
        printf("  4. Kembali\n");
        printf("==============================================================\n");
        printf(" Pilihan : ");
        fflush(stdin);
        scanf("%d", &pil);

        switch (pil) {
        case 1:
            addMenu();
            lanjut = pause();
            break;
        case 2:
            editMenu();
            break;
        case 3:
            delMenu();
            break;
        default:
            break;
        }
    } while (pil != 4 && lanjut == 1);
}