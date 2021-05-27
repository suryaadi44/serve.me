#include "mainLogic.h"

void header(){
	time_t mentah;
	struct tm* waktu;
	time(&mentah);
	waktu = localtime(&mentah);

	printf("==============================================================\n");
    printf("|           _____                       __  __               |\n");
    printf("|          / ____|                     |  \\/  |              |\n");
    printf("|         | (___   ___ _ ____   _____  | \\  / | ___          |\n");
    printf("|          \\___ \\ / _ \\ '__\\ \\ / / _ \\ | |\\/| |/ _ \\         |\n");
    printf("|          ____) |  __/ |   \\ V /  __/_| |  | |  __/         |\n");
    printf("|         |_____/ \\___|_|    \\_/ \\___(_)_|  |_|\\___|         |\n");                                                                                   
	printf("|                                                            |\n");
	printf("|                    %02d/%02d/%d %02d:%02d:%02d                     |\n", waktu->tm_mday, waktu->tm_mon + 1, waktu->tm_year + 1900, waktu->tm_hour, waktu->tm_min, waktu->tm_sec);
	printf("==============================================================\n");

}

int pause() {
    char pil;
    printf("\n Lanjutkan? (y/t) : ");
    scanf("\n");
    scanf("%c", &pil);

    if (pil == 'y') return 1;
    return 0;
}

int countLine(char file[]){
	FILE* cek;
    int i = 0;
    int cs;

    cek = fopen(file, "r");
    while (!feof(cek)) {               //Loop hingga EOF  1
        cs = fgetc(cek);               //simpan stream char ke c
        if (cs == '\n') i++;          //Jika dideteksi \n , tambah i
    }
    fclose(cek);
    return i;
}

void clear() {
#ifdef _WIN32
    std : system("cls");
#else
std: system("clear");
#endif
}   