#include "console.h"
// #include "func.h"

ListDefault l;

/*Implementation of console.h goes here*/
int loadSpotify(){
    // printf("LOADED\n");
    int i = 0, j = 0, k = 0;
    FILE *file;
    // Word fileName;
    char buffer[100];
    // char *temp;
    // stringCopy(temp, currentWord.TabWord);

    ADVWORD();

    if(stringComp(currentWord.TabWord, "DEFAULT")){
        stringCopy(currentWord.TabWord, "config.txt"); //DEFAULT LIST
        currentWord.Length = stringLen(currentWord.TabWord);
    }

    if(stringComp(currentWord.TabWord, "LOAD")){
        printf("Input berupa LOAD <nama file>.txt\n");
        return 1;
    }

    // STARTWORD();
    char fullPath[80] = "save/"; //../../save/<nama file.txt>
    i = 5;
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
    readFileWord(file); //READING THE FIRST LINE OF THE FILE
    // printf("%s\n", currentWord.TabWord);
    // printf("%d\n", currentWord.Length);

    // char jumlahPenyanyi[10];
    // fgets(jumlahPenyanyi, 10, file);
    // printf("%b\n", jumlahPenyanyi[0]);
    int IjumlahPenyanyi = wordToInt(currentWord);
    int IjumlahAlbum;
    int IjumlahLagu;
    // j=1;
    // for(i=currentWord.Length-1; i>=0; i--){
    //     IjumlahPenyanyi += (currentWord.TabWord[i]-'0') * j;
    //     j *= 10;
    // }
    // printf("%d\n", IjumlahPenyanyi);
    l.Penyanyi.Count = IjumlahPenyanyi;
    for(i=0; i<IjumlahPenyanyi; i++){

        // (&p + i*sizeof(Penyanyi));
        readFileWord(file);
        IjumlahAlbum = wordToInt(currentWord);
        l.Penyanyi.Elements[i].album.Count = IjumlahAlbum;
        // printf("%d\n", IjumlahAlbum);
        readFileLine(file);
        stringCopy(l.Penyanyi.Elements[i].nama_penyanyi.TabWord, currentLine.TabWord);
        // printf("%s\n", l.list_penyanyi[i].nama_penyanyi.TabWord);
        for(j=0; j<IjumlahAlbum; j++){
            readFileWord(file);
            IjumlahLagu = wordToInt(currentWord);
            // printf("%d\n", IjumlahLagu);
            l.Penyanyi.Elements[i].album.Elements[j].daftar_lagu.Count = IjumlahLagu;
            readFileLine(file);
            stringCopy(l.Penyanyi.Elements[i].album.Elements[j].nama_album.TabWord, currentLine.TabWord);
            // printf("%s\n", l.list_penyanyi[i].list_album[j].nama_album.TabWord);
            for(k=0; k<IjumlahLagu; k++){
                readFileLine(file);
                stringCopy(l.Penyanyi.Elements[i].album.Elements[j].daftar_lagu.Elements[k].TabWord, currentLine.TabWord);
                // printf("%d:%s\n",k, l.list_penyanyi[i].list_album[j].list_lagu[k].TabWord);
            }
        }
        // printf("%s\n", currentWord.TabWord);
        // printf("%s\n", l.list_penyanyi->nama_penyanyi.TabWord);
        // break;
    }

    // printf("%s", l.list_penyanyi[2].list_album[1].nama_album.TabWord);
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
        stringMakeEmpty(penyanyi);
        STARTLINE();
        // ADVWORD();
        stringCopy(penyanyi, currentLine.TabWord);
        // scanf("%s", penyanyi);

        // printf("%s\n", penyanyi);
        printf("Daftar Album oleh %s:\n", penyanyi);
        int idx_penyanyi = showAlbum(charToWord(penyanyi), l);


        // pilih lagu
        printf("Masukkan nama Album yang dipilih : ");
        char album[100];
        stringMakeEmpty(album);
        // ADVWORD();
        STARTLINE();
        // ADVWORD();
        // printf("%s\n", currentLine.TabWord);
        stringCopy(album, currentLine.TabWord);

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

int saveSpotify() {
    FILE *file;
    Word fileName;
    char buffer[100];

    int numPenyanyi = l.Penyanyi.Count;

    /*if (numPenyanyi == 0) {
        printf("Tidak ada data.\n");
        return 1;
    }*/

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
        printf("Save file gagal: Tidak dapat membuat file.\n");
        return 1;
    }

    fprintf(file, "%d\n", numPenyanyi);

    for (int i = 0; i < numPenyanyi; i++) {
        int numAlbum = l.Penyanyi.Elements[i].album.Count;
        fprintf(file, "%d ", numAlbum);
        fprintf(file, "%s\n", l.Penyanyi.Elements[i].nama_penyanyi.TabWord);

        for (int j = 0; j < numAlbum; j++) {
            int numLagu = l.Penyanyi.Elements[i].album.Elements[j].daftar_lagu.Count;
            fprintf(file, "%d ", numLagu);
            fprintf(file, "%s\n", l.Penyanyi.Elements[i].album.Elements[j].nama_album.TabWord);

            for (int k = 0; k < numLagu; k++) {
                fprintf(file, "%s\n", l.Penyanyi.Elements[i].album.Elements[j].daftar_lagu.Elements[k].TabWord);
            }
        }
    }

    fclose(file);
    printf("Save file berhasil disimpan.\n");
    return 0;
}

void playSpotify(Stack *S, Queue *Q){ //Masih bingung cara testing, jadi ini belum di test. Kayaknya globalvar juga belum diinclude
    ADVWORD();

    if (stringComp(currentWord.TabWord, "SONG")){//Apabila input berupa play song
        boolean cekvalid = false;
        printf("Daftar Penyanyi: \n");
        showPenyanyi(l); //Menunjukkan nama penyanyi
        char playlagu[100];

        //menginput nama penyanyi
        char singer[100];
        char penyanyix[100];
        printf("\nMasukkan Nama Penyanyi yang dipilih: ");
        scanf("%s", &singer); 
        int singeridx = -1;
        for(int i=0; i<l.Penyanyi.Count; i++){ //Melakukan pengecekkan input penyanyi
            if (stringComp(singer, l.Penyanyi.Elements[i].nama_penyanyi.TabWord)){
                singeridx = i;
                cekvalid = true;
                stringCopy(penyanyix, singer);
                break;
            }
        }
        if (cekvalid){
            printf("Daftar Album oleh %s: \n" , singer);
            int idx_penyanyi = showAlbum(charToWord(singer[100]), l);//menunjukkan daftar album
            char album[100];
            char albumx[100];
            printf("\nMasukkan Nama Album yang dipilih: ");
            boolean cekans = false;
            scanf("%s", &album);//input nama album
            int albumidx = -1;
            for(int j= 0 ; j < l.Penyanyi.Elements[singeridx].album.Count ; j ++){//melakukan pengecekkan input album
                if(stringComp(album, l.Penyanyi.Elements[singeridx].album.Elements[j].nama_album.TabWord)){
                    albumidx = j;
                    cekans = true;
                    stringCopy(albumx, album);
                    break;
                }
            }
            if (cekans){
                printf("\nMasukkan ID lagu yang dipilih: ");
                showLagu(charToWord(singer), idx_penyanyi, l);
                int ID;
                boolean cekID = false;
                int IDidx = -1;
                scanf("%d", &ID);//input ID Lagu
                for(int k=0; k < l.Penyanyi.Elements[singeridx].album.Elements[albumidx].daftar_lagu.Count; k++){//mengecek ID lagu
                    if((ID-1) == k){
                        cekID = true;
                        IDidx = k;
                        break;
                    }
                }
                if(cekID){
                    char lagux[100];
                    stringCopy(lagux, l.Penyanyi.Elements[singeridx].album.Elements[albumidx].daftar_lagu.Elements[IDidx].TabWord);
                    sprintf(playlagu, "%s - %s - %s" , penyanyix, albumx, lagux); //menyimpan nama penyanyi, album, dan lagu yang diputar
                    printf("Memutar lagu \"%s\" oleh \"%s\".\n", lagux, penyanyix);
                    if(!queueisEmpty(*Q)){ //Mengosongkan queue
                        for(int i = 0; i<queuelength(*Q) ; i++){
                            dequeue(Q, Q->buffer[i]);
                        }
                    }
                    while(!stackIsEmpty(*S)){ //Mengosongkan stack
                        Pop(S,S->T[S->TOP]);
                    }
                    Push(S, playlagu); //Memasukkan lagu yang di play ke dalam stack
                }else{
                    printf("Nama Lagu belum valid.\n");
                }
            }else{
                printf("Nama Album belum valid.\n");
            }
        }else{
            printf("Nama Penyanyi belum valid.\n");
        }
    }
    else if(stringComp(currentWord.TabWord, "PLAYLIST")){//Apabila input berupa play playlist
        int IDPlaylist;
        printf("\nMasukkan ID Playlist: ");
        scanf("%d" , &IDPlaylist); //Input ID Playlist
        if(IDPlaylist <= Length(listPlaylist)){ //Melakukan cek terhadap ID yang diinput
            printf("Memutar playlist \"%s\".\n", listPlaylist.A[IDPlaylist-1].namaPlaylist.TabWord);
            stringCopy(CurrentPlaylist, listPlaylist.A[IDPlaylist-1].namaPlaylist.TabWord);
            if(!queueisEmpty(*Q)){//Apabila sesuai akan mengosongkan queue
                for(int i = 0; i<queuelength(*Q) ; i++){
                    dequeue(Q, Q->buffer[i]);
                }
            }
            while(!stackIsEmpty(*S)){//Stack juga dikosongkan
                Pop(S,S->T[S->TOP]);
            }
            lladdress P = llFirst(listPlaylist.A[IDPlaylist-1]); //Masih ga yakin disini
            Push(S, llInfo(P));//Memasukkan lagu pertama dari playlist yang dipilih ke stack
            stringCopy(CurrentSong, llInfo(P));
            P = llNext(P);
            while (P != llNil)
            {
                enqueue(Q, llinfo(P));//Memasukkan sisa lagu yang di playlist yang dipilih ke dalam queue
                P = llNext(P);
            }
            
        }else{
            printf("ID Playlist belum valid.\n");
        }
    }
}



// char *c;
// c = address
// string = array of char
// char di string itu bersebelahan
// char c[]
// c[i] = *(&c + i*sizeof(c)) 
// c[0] = *(&c)
// [h][e][l][l][o][ ][w][o][r][l][d][!]
