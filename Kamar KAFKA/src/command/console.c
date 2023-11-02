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

    // printf("\n");
    fclose(file);

    printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n");
    return 0;
}

int saveSpotify(){
    FILE *file;
    Word fileName;
    char buffer[1000];

    STARTWORD();
    char fullPath[80] = "save/"; 
    int i = 5, j = 0;
    while (i < (currentWord.Length + 5)) {
        fullPath[i] = currentWord.TabWord[j];
        i++;
        j++;
    }

    int fullPathLength = 0;
    while (fullPath[fullPathLength] != '\0') {
        fullPathLength++;
    }

    if (fullPathLength < 4 || fullPath[fullPathLength - 4] != '.' || fullPath[fullPathLength - 3] != 't' || fullPath[fullPathLength - 2] != 'x' || fullPath[fullPathLength - 1] != 't') {
        printf("Save file gagal disimpan. Nama file harus berakhir dengan '.txt'.\n");
        return 1;
    }

    file = fopen(fullPath, "w"); 
    if (file == NULL) {
        printf("Save file gagal disimpan.\n");
        return 1;
    }

    // Contoh data yang ingin Anda simpan (ganti dengan data yang sesuai)
    char dataToSave[] = "Data yang ingin disimpan.\n";
    fputs(dataToSave, file);

    fclose(file);

    printf("Save file berhasil disimpan.\n");
    return 0;
}

/*Dibaca save file input yang berisi list game yang dapat dimainkan, histori, dan scoreboard game*/
void quitSpotify(){
    char input;
    printf("Apakah kamu ingin menyimpan data sesi sekarang?\n");
    scanf("%c", &input);
    if (input == 'Y' || input == 'y') {
        printf("WHY IS THIS NOT WORKING\n");
        // saveSpotify();
    }
    printf("Kamu keluar dari WayangWave.\n");
    printf("Dadah ^_^/\n");
    exit(0);
}
/*Keluar dari sesi aplikasi WayangWave (SPOTIFY)*/