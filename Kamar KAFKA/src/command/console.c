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

void saveSpotify(){
    char NamaFile[100];
    scanf("%s" , &NamaFile);
    const char* validtxt = ".txt";
    const char* data = "...";//Ini buat isi file  = (Isi File)
    char fullPath[100]; 
    FILE* file;
    int NamaFileLength = 0;
    int extensionLength = 0;

    while (NamaFile[NamaFileLength] != '\0') {
        NamaFileLength++;
    }

    while (validtxt[extensionLength] != '\0') {
        extensionLength++;
    }

    int valid = 1;
    int j;

    if (NamaFileLength < extensionLength) {
        valid = 0;
    } else {
        for (int i = NamaFileLength - extensionLength, j = 0; i < NamaFileLength; i++, j++) {
            if (NamaFile[i] != validtxt[j]) {
                valid = 0;
                break;
            }
        }
    }

    if (!valid) {
        printf("Nama file tidak valid. Nama file harus berakhir dengan '.txt'.\n");
        return;
    }

    snprintf(fullPath, sizeof(fullPath), "save/%s", NamaFile);

    file = fopen(fullPath, "w");

    if (file == NULL) {
        printf("Gagal membuka file untuk penyimpanan.\n");
        return;
    }

    fprintf(file, "%s", data);

    fclose(file);
    printf("Save file berhasil disimpan.\n");
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