#include "console.h"
// #include "func.h"

ListDefault l;

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
void listSpotify(){
    STARTWORD();
    ADVWORD();
    if (stringComp(currentWord.TabWord, "DEFAULT")){
        printf("Daftar Penyanyi :\n");
        showPenyanyi(l);

        printf("Ingin melihat album yang ada?(Y/N): ");
        char pilihan[10];

        scanf("%s", pilihan);
        Word word_pilihan = charToWord(pilihan);
        
        printf("%s\n", word_pilihan.TabWord);

        // comparing string
        if(stringComp(word_pilihan.TabWord, "N")){
            return;
        }

        // pilih album
        printf("Pilih penyanyi untuk melihat album mereka: ");
        char penyanyi[100];
        scanf("%s", penyanyi);

        printf("%s\n", penyanyi);
        printf("Daftar Album oleh %s:\n", penyanyi);
        int idx_penyanyi = showAlbum(charToWord(penyanyi), l);


        // pilih lagu
        printf("Masukkan nama Album yang dipilih : ");
        char album[100];
        scanf("%s", album);

        printf("Daftar Lagu Album %s oleh %s\n", album, penyanyi);
        showLagu(charToWord(album), idx_penyanyi, l);
    }
    else if (stringComp(currentWord.TabWord, "PLAYLIST")){
        printf("PLAYLIST\n");
    }
    else{
        printf("invalid command\n");
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