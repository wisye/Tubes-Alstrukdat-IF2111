#include "console.h"
// #include "func.h"

// ListDefault l;

/*Implementation of console.h goes here*/
int loadSpotify(){
    FILE *file;
    // Word fileName;
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

    // while (fgets(buffer, 1000, file) != NULL) {
    //         printf("%s", buffer);
    // }

    // printf("%s", buffer);

    printf("\n");
    fclose(file);

    printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n");
    return 0;
}
/*Dibaca save file input yang berisi list game yang dapat dimainkan, histori, dan scoreboard game*/
void quitSpotify(){
    printf("Apakah kamu ingin menyimpan data sesi sekarang?\n");
    printf(">> ");
    // ADVWORD();
    STARTWORD();
    ADVWORD();
    // printf("Input: %c\n", currentWord.TabWord[0]);
    
    if (currentWord.TabWord[0] == 'y' || currentWord.TabWord[0] == 'Y'){
        printf("asdasjkhdksjahd\n");
        // saveSpotify();
    }
    printf("Kamu keluar dari WayangWave.\n");
    printf("Dadah ^_^/\n");
    fclose(stdin);
    exit(0);
}
 /*Keluar dari sesi aplikasi WayangWave (SPOTIFY)*/ 
void listSpotify(ListDefault l){
    printf(">> ");
    STARTWORD();
    ADVWORD();
    // printf("%s\n", currentWord.TabWord);
    if (stringComp(currentWord.TabWord, "DEFAULT")){
        printf("Daftar Penyanyi :\n");
        showPenyanyi(l);

        printf("Ingin melihat album yang ada?(Y/N): ");
        char pilihan;
        STARTWORD();
        ADVWORD();
        // printf("%s\n", charToWord(currentWord.TabWord[0]));

        // scanf("%s", pilihan); UBAH JADI CHAR, BUKAN WORD
        for(;;){
            if(currentWord.TabWord[0] == 'Y' || currentWord.TabWord[0] == 'y' || currentWord.TabWord[0] == 'N' || currentWord.TabWord[0] == 'n'){
                break;
            }
            printf("Input salah. Masukkan Y atau N: ");
            STARTWORD();
            ADVWORD();
        }
        pilihan = currentWord.TabWord[0];
        
        // printf("%c\n", pilihan);

        // comparing string
        if(pilihan == 'N' || pilihan == 'n'){
            return;
        }

        // pilih album
        printf("Pilih penyanyi untuk melihat album mereka: ");
        char penyanyi[100];
        STARTWORD();
        ADVWORD();
        stringCopy(penyanyi, currentWord.TabWord);
        // scanf("%s", penyanyi);

        // printf("%s\n", currentWord.TabWord);
        printf("Daftar Album oleh %s:\n", penyanyi);
        int idx_penyanyi = showAlbum(charToWord(penyanyi), l);


        // pilih lagu
        printf("Masukkan nama Album yang dipilih : ");
        char album[100];
        ADVWORD();
        STARTWORD();
        ADVWORD();
        // printf("%s\n", currentWord.TabWord);
        stringCopy(album, currentWord.TabWord);

        printf("Daftar Lagu Album %s oleh %s\n", album, penyanyi);
        showLagu(charToWord(album), idx_penyanyi, l);
        return;
    }
    else if (stringComp(currentWord.TabWord, "PLAYLIST")){
        printf("PLAYLIST\n");
        return;
    }
    else{
        printf("invalid command\n");
        return;
    }
}

// EXTRA
boolean stringComp(char *x, char *y){
    int i = 0;
    while ((x[i] != '\0') && (y[i] != '\0')){
        if (x[i] != y[i]){
            return false;
        }
        i ++;
    }
    return true;
}

void stringCopy(char *x, char *y){
    int i = 0;
    while (y[i] != '\0' && y[i] != MARK){
        // printf("%c", x[i]);
        x[i] = y[i];
        i++;
    }
}

Word charToWord(char str[]){
    Word w;
    
    int len = 0;
    while(str[len]){
        len++;
    }

    w.Length = len;

    int i;
    for(i=0; i<len;i++){
        w.TabWord[i] = str[i];
        // printf("%c\n", w.TabWord[i]);
    }

    w.TabWord[i] = '\0';

    // printf("%s\n", w.TabWord);
    return w;
}

void showPenyanyi(ListDefault l){
    int len = l.NEFF;

    int i=0;
    for(i=0; i<len; i++){
        printf("\t%d. %s\n", i+1, l.list_penyanyi[i].nama_penyanyi.TabWord);
    }
}

int showAlbum(Word w, ListDefault l){
    int len = l.NEFF;

    // cari indeks penyanyi di list

    int i;
    for(i=0; i<len; i++){
        // printf("ini cek --> %s %s\n", w.TabWord, l.list_penyanyi[i].nama_penyanyi.TabWord);
        if(stringComp(w.TabWord, l.list_penyanyi[i].nama_penyanyi.TabWord)){
            break;
        }
    }

    // printf("indeks penyanyi %d\n", i);
    // print semua album
    int j;
    for(j=0; j < l.list_penyanyi[i].NEFF; j++){
        printf("\t%d. %s\n", j+1, l.list_penyanyi[i].list_album[j].nama_album.TabWord);
    }
    return i;
}

void showLagu(Word w, int idx_penyanyi, ListDefault l){
    int len = l.list_penyanyi[idx_penyanyi].NEFF; // cek dia ada berapa album

    int i;
    for(i=0; i<len; i++){
        // printf("ini cek --> %s %s\n", w.TabWord, l.list_penyanyi[i].nama_penyanyi.TabWord);
        if(stringComp(w.TabWord, l.list_penyanyi[idx_penyanyi].list_album[i].nama_album.TabWord)){
            break;
        }
    }

    int j;
    for(j=0; j < l.list_penyanyi[idx_penyanyi].list_album[i].NEFF; j++){
        printf("\t%d. %s\n", j+1, l.list_penyanyi[idx_penyanyi].list_album[i].list_lagu[j].TabWord);
    }
}