#include "order.h"

pelanggan* inputPesanan() {
    menu* buffer = NULL;
    pelanggan* new = (pelanggan*)malloc(sizeof(pelanggan));
    int total, jumlah = 0;
    int lanjut = 1;

    new->id = counter++;
    printf("==============================================================\n");
    printf("\n Masukan Data\n");
    printf("  Nama      : ");
    fflush(stdin);
    scanf("%[^\n]%*c", &new->nama);
    printf("  Meja      : ");
    fflush(stdin);
    scanf("%d", &new->meja);
    new->head = NULL;
    new->next = NULL;

    do {
        pesanan* temp = new->head;
        pesanan* order = (pesanan*)malloc(sizeof(pesanan));
        order->next = NULL;
        order->type = viewMenu();

        printf("  Pilihan   : ");
        fflush(stdin);
        scanf("%d", &order->id);
        printf("  Banyaknya : ");
        fflush(stdin);
        scanf("%d", &order->qty);

        if (temp == NULL) new->head = order;
        else {
            while (temp->next != NULL) temp = temp->next;
            temp->next = order;
        }

        if (order->type == 1)
            buffer = searchMenu(foodRoot, order->id);
        else
            buffer = searchMenu(drinkRoot, order->id);

        total = order->qty * buffer->price;
        jumlah += total;

        lanjut = pause();
    } while (lanjut == 1);

    new->jumlah = jumlah;
    printf("==============================================================\n");

    return new;
}

void enqueue(pelanggan* new) {
    pelanggan* temp = head;

    if (temp == NULL) {
        head = new;
        return;
    }

    while (temp->next != NULL) temp = temp->next;
    temp->next = new;
}

void dequeue() {
    pelanggan* temp = head;

    printf("==============================================================\n");
    if (temp == NULL) {
        printf("\n Antrian Kosong");
        return;
    }

    printQueue(temp);

    temp = head->next;
    free(head);
    head = temp;
}

void printQueue(pelanggan* temp) {
    menu* buffer = NULL;
    pesanan* tempList = temp->head;

    printf("                         Pelanggan %d\n", temp->id);
    printf(" Nama    : %s\n", temp->nama);
    printf(" Meja    : %d\n\n", temp->meja);
    printf(" Pesanan : \n");
    printf("==============================================================\n");
    printf(" +-----+------------------------+--------------+-------------+ \n");
    printf(" | Qty |          Nama          | Harga Satuan |    Total    | \n");
    printf(" +-----+------------------------+--------------+-------------+ \n");
    while (tempList != NULL) {
        if (tempList->type == 1)
            buffer = searchMenu(foodRoot, tempList->id);
        else
            buffer = searchMenu(drinkRoot, tempList->id);

        printf(" | %-3d | %-22s | Rp.%8d  | Rp.%8d | \n", tempList->qty, buffer->nama, buffer->price, buffer->price * tempList->qty);
        tempList = tempList->next;
    }
    printf(" +-----+------------------------+--------------+-------------+ \n");
    printf(" |                   Jumlah                    | Rp.%8d | \n", temp->jumlah);
    printf(" +-----+------------------------+--------------+-------------+ \n");
}

void search() {
    int pil;
    pelanggan* buffer;
    printf("==============================================================\n");
    if (head == NULL) {
        printf("\n Antrian Kosong");
        return;
    }

    printf(" Cari dengan : \n");
    printf("  1. ID \n");
    printf("  2. Nama\n");
    printf(" Pilih : ");
    fflush(stdin);
    scanf("%d", &pil);

    printf("==============================================================\n");

    if (pil == 1) {
        int id;
        printf(" Masukan ID : ");
        fflush(stdin);
        scanf("%d", &id);
        buffer = searchByID(id);
    } else {
        char nama[22];
        printf(" Mauskan Nama : ");
        fflush(stdin);
        scanf("%[^\n]", nama);
        buffer = searchByName(nama);
    }
    printf("==============================================================\n");
    printQueue(buffer);
    printf("==============================================================\n");
}

pelanggan* searchByID(int id) {
    pelanggan* temp = head;
    while (temp != NULL) {
        if (temp->id == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

pelanggan* searchByName(char nama[]) {
    pelanggan* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->nama, nama) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void viewQueue() {
    pelanggan* now = head;

    printf("==============================================================\n");
    printf(" Lihat Antrian :\n");
    printf(" +----+------------------------+------+-------------+\n");
    printf(" | ID |          Nama          | Meja |    Total    |\n");
    printf(" +----+------------------------+------+-------------+\n");
    do {
        if (now == NULL)
            printf(" |    |    Antrian Kososng     |      |             |\n");
        else {
            printf(" | %2d | %-22s | %4d | Rp.%8d |\n", now->id, now->nama, now->meja, now->jumlah);
            now = now->next;
        }
    } while (now != NULL);
    printf(" +----+------------------------+------+-------------+\n");
}