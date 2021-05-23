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
    printf("\nLanjutkan? (y/t) : ");
    fflush(stdin);
    scanf("%c", &pil);

    if (pil == 'y') return 1;
    else return 0;
}

void clear() {
#ifdef _WIN32
    std : system("cls");
#else
std: system("clear");
#endif
}   