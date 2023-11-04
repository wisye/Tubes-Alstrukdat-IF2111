#include "console.h"
// #include "func.h"

ListDefault l;

/*Implementation of console.h goes here*/
int loadSpotify(){
    // printf("LOADED\n");
    FILE *file;
    // Word fileName;
    // char buffer[100];
    // char *temp;
    // stringCopy(temp, currentWord.TabWord);

    ADVWORD();

    if(stringComp(currentWord.TabWord, "DEFAULT")){
        stringCopy(currentWord.TabWord, "ghostrule.txt"); //DEFAULT LIST
        currentWord.Length = stringLen(currentWord.TabWord);
    }

    if(stringComp(currentWord.TabWord, "LOAD")){
        printf("Input berupa LOAD <nama file>.txt\n");
        return 1;
    }

    // STARTWORD();
    char fullPath[80] = "save/"; //../../save/<nama file.txt>
    int i = 5, j = 0;
    while (i < (currentWord.Length + 5)){
        fullPath[i] = currentWord.TabWord[j];
        i ++;
        j ++;
    }

    // printf("%s\n", fullPath);
    // closePita();
    // STARTWORD();

    file = fopen(fullPath, "r");
    if (file == NULL) {
        printf("Save file tidak ditemukan. WayangWave gagal dijalankan.\n");
        return 1;
    }
    
    // fgets(buffer, 1000, file);
    // fscanf(file, "%s", buffer);
    // fscanf(file, "%s", buffer);
    // fscanf(file, "%s", buffer);
    // fscanf(file, "%s", buffer); // FSCANF IS TAKING 1 WORD IF USING %S
    readFileLine(file); //READING THE FIRST LINE OF THE FILE
    // printf("%s\n", currentWord.TabWord);
    // printf("%d\n", currentWord.Length);

    // char jumlahPenyanyi[10];
    // fgets(jumlahPenyanyi, 10, file);
    // printf("%b\n", jumlahPenyanyi[0]);
    int IjumlahPenyanyi = wordToInt(currentWord);
    int IjumlahAlbum;
    // j=1;
    // for(i=currentWord.Length-1; i>=0; i--){
    //     IjumlahPenyanyi += (currentWord.TabWord[i]-'0') * j;
    //     j *= 10;
    // }
    printf("%d\n", IjumlahPenyanyi);
    
    for(i=0; i<IjumlahPenyanyi; i++){
        readFileLine(file);
        IjumlahAlbum;
        printf("%s\n", currentWord.TabWord);
        // break;
    }

    // for(int k=0; k<40; k++) {
    //     readFileLine(file);
    //     printf("%s\n", currentWord.TabWord);
    // }

    // printf("%s", buffer);

    // printf("\n");
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
    // ADVWORD();
    // printf("Input: %c\n", currentWord.TabWord[0]);
    
    if (currentWord.TabWord[0] == 'y' || currentWord.TabWord[0] == 'Y'){
        printf("Menyimpan...\n");
        // saveSpotify();
    }
    printf("Kamu keluar dari WayangWave.\n");
    printf("Dadah ^_^/\n");
    fclose(stdin);
    exit(0);
}
 /*Keluar dari sesi aplikasi WayangWave (SPOTIFY)*/ 
void listSpotify(){
    // printf(">> ");
    ADVWORD();      // TURN THIS OFF IF YOU WANT TO USE THE DRIVER
    // STARTWORD(); // TURN THIS ON IF YOU WANT TO USE THE DRIVER
    // ADVWORD();
    // printf("%s\n", currentWord.TabWord);

    if (stringComp(currentWord.TabWord, "DEFAULT")){
        // IF DEFAULT PROCESS GHOSTRULE.TXT
        // stringCopy(currentWord.TabWord, "ghostrule.txt");
        loadSpotify();

        printf("Daftar Penyanyi :\n");
        showPenyanyi(l);

        printf("Ingin melihat album yang ada?(Y/N): ");
        char pilihan;
        STARTWORD();
        // ADVWORD();
        // printf("%s\n", charToWord(currentWord.TabWord[0]));

        // scanf("%s", pilihan); UBAH JADI CHAR, BUKAN WORD
        for(;;){
            if(currentWord.TabWord[0] == 'Y' || currentWord.TabWord[0] == 'y' || currentWord.TabWord[0] == 'N' || currentWord.TabWord[0] == 'n'){
                break;
            }
            printf("Input salah. Masukkan Y atau N: ");
            STARTWORD();
            // ADVWORD();
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
        // ADVWORD();
        stringCopy(penyanyi, currentWord.TabWord);
        // scanf("%s", penyanyi);

        // printf("%s\n", currentWord.TabWord);
        printf("Daftar Album oleh %s:\n", penyanyi);
        int idx_penyanyi = showAlbum(charToWord(penyanyi), l);


        // pilih lagu
        printf("Masukkan nama Album yang dipilih : ");
        char album[100];
        // ADVWORD();
        STARTWORD();
        // ADVWORD();
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


