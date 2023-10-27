#include "console.h"

/*Implementation of console.h goes here*/
int loadSpotify(){
    FILE *file;
    Word fileName;
    char buffer[1000];

    STARTWORD();
    char fullPath[80] = "save/"; //../../save/<nama file.txt>
    int i = 5, j = 0;
    while (i < (currentWord.Length + 5)){
        fullPath[i] = currentWord.TabWord[j];
        i ++;
        j ++;
    }

    // printf("%s\n", fullPath);

    file = fopen(fullPath, "r");
    if (file == NULL) {
        printf("Save file tidak ditemukan. WayangWave gagal dijalankan.\n");
        return 1;
    }
    fgets(buffer, 1000, file);

    // while (fgets(buffer, 100, file) != NULL) {
    //         printf("%s", buffer);
    // }

    printf("\n");
    fclose(file);

    printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n");
    return 0;
}
/*Dibaca save file input yang berisi list game yang dapat dimainkan, histori, dan scoreboard game*/
void quitSpotify(){
    char input;
    printf("Apakah kamu ingin menyimpan data sesi sekarang?\n");
    scanf("%c", &input);
    if (input == 'Y' || input == 'y') {
        saveSpotify();
    }
    printf("Kamu keluar dari WayangWave.\n");
    printf("Dadah ^_^/\n");
}
/*Keluar dari sesi aplikasi WayangWave (SPOTIFY)*/