#include "console.h"
// #include "func.h"

ListPenyanyi l;
// Queue q;
void startSpotify(Queue *q, Stack *history, ListPlaylist *Playlist){
    ADVWORD();
    boolean p;
    stringCopy(currentWord.TabWord, "DEFAULT");
    loadSpotify(q, history, Playlist, &p);
}
/*Implementation of console.h goes here*/
int loadSpotify(Queue *q, Stack *history, ListPlaylist *Playlist, boolean *success){
    // printf("LOADED\n");
    int i = 0, j = 0, k = 0;
    FILE *file;
    // (*l).Penyanyi.Count = 0;
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
    l.count = IjumlahPenyanyi;
    // printf("Jumlah Penyanyi: %d\n", l.count);
    for(i=0; i<IjumlahPenyanyi; i++){

        // (&p + i*sizeof(Penyanyi));
        readFileWord(file);
        IjumlahAlbum = wordToInt(currentWord);
        l.A[i].album.Count = IjumlahAlbum;
        // printf("%d\n", IjumlahAlbum);
        readFileLine(file);
        stringCopy(l.A[i].nama_penyanyi.TabWord, currentLine.TabWord);
        // printf("%c\n", currentChar);
        // printf("%s\n", l.list_penyanyi[i].nama_penyanyi.TabWord);
        for(j=0; j<IjumlahAlbum; j++){
            readFileWord(file);
            IjumlahLagu = wordToInt(currentWord);
            // printf("%d\n", IjumlahLagu);
            l.A[i].album.Elements[j].daftar_lagu.Count = IjumlahLagu;
            readFileLine(file);
            stringCopy(l.A[i].album.Elements[j].nama_album.TabWord, currentLine.TabWord);
            // printf("%s\n", l.list_penyanyi[i].list_album[j].nama_album.TabWord);
            for(k=0; k<IjumlahLagu; k++){
                readFileLine(file);
                stringCopy(l.A[i].album.Elements[j].daftar_lagu.Elements[k].TabWord, currentLine.TabWord);
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
    queueElType ID;
    llinfotype LD;
    // printf("\n");
    if(!IsEOF()){ // READ FOR CURRENT SONG
        // printf("AAAAA");
        readFileLineIgnoreMark(file);
        stringCopy(CurrentSinger, currentLine.TabWord);
        readFileLineIgnoreMark(file);
        stringCopy(CurrentAlbum, currentLine.TabWord);
        readFileLineIgnoreMark(file);
        stringCopy(CurrentSong, currentLine.TabWord);
        // if(feof(file)){
        //     fclose(file);
        //     printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n");
        //     return 0;
        // }
    }
    if(!IsEOF()){ // READ FOR QUEUE
        readFileWord(file);
        int idx = wordToInt(currentWord);
        // printf("%d\n", idx);
        for(i=0; i<idx; i++){
            readFileLineIgnoreMark(file);
            stringCopy(ID.nama_penyanyi, currentLine.TabWord);
            readFileLineIgnoreMark(file);
            stringCopy(ID.nama_album, currentLine.TabWord);
            readFileLineIgnoreMark(file);
            stringCopy(ID.nama_lagu, currentLine.TabWord);
            enqueue(q, ID);
        }
    }
    if(!IsEOF()){ // READ FOR HISTORY
        readFileWord(file);
        int idx = wordToInt(currentWord);
        for(i=0; i<idx; i++){
            readFileLineIgnoreMark(file);
            stringCopy(ID.nama_penyanyi, currentLine.TabWord);
            readFileLineIgnoreMark(file);
            stringCopy(ID.nama_album, currentLine.TabWord);
            readFileLineIgnoreMark(file);
            stringCopy(ID.nama_lagu, currentLine.TabWord);
            Push(history, ID);
        }
    }
    if(!IsEOF()){ // READ FOR PLAYLIST
        readFileWord(file);
        int idx_playlist = wordToInt(currentWord);
        for(i=0; i<idx_playlist; i++){
            readFileWord(file);
            int idxsong = wordToInt(currentWord);
            // printf("%d\n", idxsong);
            readFileLineIgnoreMark(file);
            stringCopy(Playlist->A[i].namaPlaylist.TabWord, currentLine.TabWord);
            for(j=0; j<idxsong; j++){
                readFileLineIgnoreMark(file);
                stringCopy(LD.nama_penyanyi, currentLine.TabWord);
                // printf("%s\n", currentLine.TabWord);
                readFileLineIgnoreMark(file);
                stringCopy(LD.nama_album, currentLine.TabWord);
                // printf("%s\n", currentLine.TabWord);
                readFileLineIgnoreMark(file);
                stringCopy(LD.nama_lagu, currentLine.TabWord);
                // printf("%s\n", currentLine.TabWord);
                llInsVLast(&(Playlist->A[i]), LD);
            }
            
        }
        Playlist->Neff = idx_playlist;
    }
    fclose(file);
    *success = true;
    printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n");
    return 0;
}
/*Dibaca save file input yang berisi list game yang dapat dimainkan, histori, dan scoreboard game*/
void listSpotify(ListPlaylist *Playlist){
    // printf(">> ");
    STARTWORD();      // TURN THIS OFF IF YOU WANT TO USE THE DRIVER
    // STARTWORD(); // TURN THIS ON IF YOU WANT TO USE THE DRIVER
    // ADVWORD();
    // printf("%s\n", currentWord.TabWord);

    if (stringComp(currentWord.TabWord, "DEFAULT")){
        // IF DEFAULT PROCESS GHOSTRULE.TXT
        // stringCopy(currentWord.TabWord, "ghostrule.txt");
        // loadSpotify(l);
        // printf("PPPP");
        
        // printf("Daftar Penyanyi :\n");
        // printf("Daftar Penyanyi :\n");
        // printf("Daftar Penyanyi :\n");
        // printf("Daftar Penyanyi :\n");
        // printf("PPPP\n");
        // printf("%s\n", l.A->album.Elements[0].daftar_lagu.Elements[0].TabWord);
        // printf("%d\n", l.count);
        // printf("%d\n", l.count);
        // fflush(stdout);
        showPenyanyi(l);
        // printf("PPPPP");
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
            // START();
            STARTWORD();
            // printf("%s\n", currentWord.TabWord);
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
        char penyanyi[100] = "";
        stringMakeEmpty(penyanyi);
        // START();
        STARTLINE();
        // printf("%s\n", currentLine.TabWord);
        // ADVWORD();
        stringCopy(penyanyi, currentLine.TabWord);
        // scanf("%s", penyanyi);
        int idx_penyanyi = showAlbum(charToLine(penyanyi), l);

        if(idx_penyanyi >= l.count){
            printf("Penyanyi tidak ditemukan\n");
            return;
        }
        // printf("%s\n", penyanyi);
        printf("Daftar Album oleh %s:\n", penyanyi);


        // printf("%d\n", l.count);
        // pilih lagu
        printf("Masukkan nama Album yang dipilih : ");
        char album[100] = "";
        stringMakeEmpty(album);
        // ADVWORD();
        // START();
        STARTLINE();
        // ADVWORD();
        int idx_album;
        for(int i = 0; i < l.A[idx_penyanyi].album.Count; i++){
            if(stringComp(l.A[idx_penyanyi].album.Elements[i].nama_album.TabWord, album)){
                idx_album = i;
                break;
            }
        }
        // printf("%d\n", idx_album);
        // printf("%d\n", l.A[idx_penyanyi].album.Count);
        // if(idx_album > l.A[idx_penyanyi].album.Count-1){
        //     printf("Album tidak ditemukan\n");
        //     return;
        // }

        stringCopy(album, currentLine.TabWord);
        // scanf("%s", album);

        printf("Daftar Lagu Album %s oleh %s\n", album, penyanyi);
        showLagu(charToWord(album), idx_penyanyi, l);
        return;
    }
    else if (stringComp(currentWord.TabWord, "PLAYLIST")){
        printf("Daftar Playlist yang kamu miliki:\n");
        if(Playlist->Neff == 0){
            printf("Kamu tidak memiliki playlist.\n");
            return;
        }
        for(int i=0; i<Playlist->Neff; i++){
            printf("\t%d. %s\n", i+1, Playlist->A[i].namaPlaylist.TabWord);
        }
        return;
    }
    else{
        printf("Input salah. Masukkan \"DEFAULT\" atau \"PLAYLIST\".\n");
        return;
    }
}

void playSpotify(Stack *S, Queue *Q, ListPlaylist *Playlist){ //Masih bingung cara testing, jadi ini belum di test. Kayaknya globalvar juga belum diinclude
    STARTWORD();
    // printf("%s\n", currentWord.TabWord);
    if (stringComp(currentWord.TabWord, "SONG")){//Apabila input berupa play song
        // boolean cekvalid = false;
        // printf("Daftar Penyanyi: \n");
        // showPenyanyi(l); //Menunjukkan nama penyanyi
        // char playlagu[100];

        // //menginput nama penyanyi
        // char singer[100];
        // char penyanyix[100];
        // printf("\nMasukkan Nama Penyanyi yang dipilih: ");
        // // scanf("%s", &singer); 
        // STARTLINE();
        // stringCopy(singer, currentLine.TabWord);
        // int singeridx = -1;
        // for(int i=0; i<l.Penyanyi.Count; i++){ //Melakukan pengecekkan input penyanyi
        //     if (stringComp(singer, l.Penyanyi.Elements[i].nama_penyanyi.TabWord)){
        //         singeridx = i;
        //         cekvalid = true;
        //         stringCopy(penyanyix, singer);
        //         break;
        //     }
        // }
        // if (cekvalid){
        //     printf("Daftar Album oleh %s: \n" , singer);
        //     int idx_penyanyi = showAlbum(charToLine(singer[100]), l);//menunjukkan daftar album
        //     char album[100];
        //     char albumx[100];
        //     printf("\nMasukkan Nama Album yang dipilih: ");
        //     boolean cekans = false;
        //     scanf("%s", &album);//input nama album
        //     int albumidx = -1;
        //     for(int j= 0 ; j < l.Penyanyi.Elements[singeridx].album.Count ; j ++){//melakukan pengecekkan input album
        //         if(stringComp(album, l.Penyanyi.Elements[singeridx].album.Elements[j].nama_album.TabWord)){
        //             albumidx = j;
        //             cekans = true;
        //             stringCopy(albumx, album);
        //             break;
        //         }
        //     }
        //     if (cekans){
        //         printf("\nMasukkan ID lagu yang dipilih: ");
        //         showLagu(charToWord(singer), idx_penyanyi, l);
        //         int ID;
        //         boolean cekID = false;
        //         int IDidx = -1;
        //         scanf("%d", &ID);//input ID Lagu
        //         for(int k=0; k < l.Penyanyi.Elements[singeridx].album.Elements[albumidx].daftar_lagu.Count; k++){//mengecek ID lagu
        //             if((ID-1) == k){
        //                 cekID = true;
        //                 IDidx = k;
        //                 break;
        //             }
        //         }
        //         if(cekID){
        //             char lagux[100];
        //             stringCopy(lagux, l.Penyanyi.Elements[singeridx].album.Elements[albumidx].daftar_lagu.Elements[IDidx].TabWord);
        //             sprintf(playlagu, "%s - %s - %s" , penyanyix, albumx, lagux); //menyimpan nama penyanyi, album, dan lagu yang diputar
        //             printf("Memutar lagu \"%s\" oleh \"%s\".\n", lagux, penyanyix);
        //             if(!queueisEmpty(*Q)){ //Mengosongkan queue
        //                 for(int i = 0; i<queuelength(*Q) ; i++){
        //                     dequeue(Q, &Q->buffer[i]);
        //                 }
        //             }
        //             while(!stackIsEmpty(*S)){ //Mengosongkan stack
        //                 Pop(S,&S->T[S->TOP]);
        //             }
        //             Push(S, playlagu); //Memasukkan lagu yang di play ke dalam stack
        //         }else{
        //             printf("Nama Lagu belum valid.\n");
        //         }
        //     }else{
        //         printf("Nama Album belum valid.\n");
        //     }
        // }else{
        //     printf("Nama Penyanyi belum valid.\n");
        // }
        // printf("asdadasd");
        // ADVWORD();
        // stringCopy(currentWord.TabWord, "DEFAULT");
        printf("Daftar Penyanyi :\n");
        showPenyanyi(l);

        // pilih album
        printf("Pilih penyanyi untuk melihat album mereka: ");
        char penyanyi[100] = "";
        stringMakeEmpty(penyanyi);
        // START();
        STARTLINE();
        // printf("%s\n", currentLine.TabWord);
        // ADVWORD();
        stringCopy(penyanyi, currentLine.TabWord);
        // scanf("%s", penyanyi);

        // printf("%s\n", penyanyi);
        printf("Daftar Album oleh %s:\n", penyanyi);
        int idx_penyanyi = showAlbum(charToLine(penyanyi), l);


        // pilih lagu
        printf("Masukkan nama Album yang dipilih : ");
        char album[100] = "";
        stringMakeEmpty(album);
        // ADVWORD();
        // START();
        STARTLINE();
        // ADVWORD();
        int idx_album;

        stringCopy(album, currentLine.TabWord);
        for(int i = 0; i < l.A[idx_penyanyi].album.Count; i++){
            if(stringComp(l.A[idx_penyanyi].album.Elements[i].nama_album.TabWord, album)){
                idx_album = i;
                break;
            }
        }
        // scanf("%s", album);
        printf("Daftar Lagu Album %s oleh %s\n", album, penyanyi);
        showLagu(charToWord(album), idx_penyanyi, l);
        printf("Masukkan ID lagu yang dipilih: ");
        STARTWORD();
        int idx_lagu = wordToInt(currentWord);
        if(idx_lagu > l.A[idx_penyanyi].album.Elements[idx_album].daftar_lagu.Count){
            printf("Tidak ada lagu dengan ID %s\n", idx_lagu);
            return;
        }
        stringCopy(CurrentSong, l.A[idx_penyanyi].album.Elements[idx_album].daftar_lagu.Elements[idx_lagu-1].TabWord);
        stringCopy(CurrentAlbum, album);
        stringCopy(CurrentSinger, penyanyi);
        printf("Memutar lagu \"%s\" oleh \"%s\"\n", l.A[idx_penyanyi].album.Elements[idx_album].daftar_lagu.Elements[idx_lagu-1].TabWord, penyanyi);
        // printf("Current Song: %s\n", CurrentSong);
        CreateQueue(Q);
        stackCreateEmpty(S); 
        stringCopy(CurrentPlaylist, "");  
    }
    else if(stringComp(currentWord.TabWord, "PLAYLIST")){//Apabila input berupa play playlist
        int IDPlaylist;
        printf("Masukkan ID Playlist: ");
        STARTWORD();
        IDPlaylist = wordToInt(currentWord);
    //     scanf("%d" , &IDPlaylist); //Input ID Playlist
        if(IDPlaylist <= Playlist->Neff){ //Melakukan cek terhadap ID yang diinput
            printf("Memutar playlist \"%s\".\n", Playlist->A[IDPlaylist-1].namaPlaylist.TabWord);
            stringCopy(CurrentPlaylist, Playlist->A[IDPlaylist-1].namaPlaylist.TabWord);
            // if(!queueisEmpty(*Q)){//Apabila sesuai akan mengosongkan queue
            //     for(int i = 0; i<queuelength(*Q) ; i++){
            //         dequeue(Q, Q->buffer);
            //     }
            // }
            CreateQueue(Q);
            stackCreateEmpty(S);
            // while(!stackIsEmpty(*S)){//Stack juga dikosongkan
            //     Pop(S,S->T[S->TOP]);
            // }
            lladdress P = llFirst(Playlist->A[IDPlaylist-1]); //Masih ga yakin disini
            llinfotype LD;
            Stack temp;
            stackCreateEmpty(&temp);
            // Push(S, P->info);//Memasukkan lagu pertama dari playlist yang dipilih ke stack
            stringCopy(CurrentSinger, P->info.nama_penyanyi);
            stringCopy(CurrentAlbum, P->info.nama_album);
            stringCopy(CurrentSong, P->info.nama_lagu);
            P = llNext(P);
            while (P != llNil)
            {
                stringCopy(LD.nama_penyanyi, (P)->info.nama_penyanyi);
                stringCopy(LD.nama_album, (P)->info.nama_album);
                stringCopy(LD.nama_lagu, (P)->info.nama_lagu);
                enqueue(Q, LD);//Memasukkan sisa lagu yang di playlist yang dipilih ke dalam queue
                Push(&temp, LD);
                P = llNext(P);
            }
            while(!stackIsEmpty(temp)){
                Pop(&temp, &LD);
                Push(S, LD);
            }
            stringCopy(CurrentPlaylist, Playlist->A[IDPlaylist-1].namaPlaylist.TabWord);
            // printf("%s", CurrentPlaylist);
        }else{
            printf("ID Playlist belum valid.\n");
        }
    }
    else{
        printf("Input salah. Masukkan \"SONG\" atau \"PLAYLIST\".\n");
    }
}

void queueSpotify(Queue *q, ListPlaylist *Playlist){
    STARTWORD();
    // ADVWORD();
    // printf("%s\n", currentWord.TabWord);
    if(stringComp(currentWord.TabWord, "SONG")){

            // show list default aja kali ya?
        //showListDefault(l);

        // list sudah terdefinisi
        
        printf("Daftar Penyanyi :\n");
        showPenyanyi(l);

        /*printf("Ingin melihat album yang ada?(Y/N): ");
        char pilihan[10];

        scanf("%s", pilihan);
        Word word_pilihan = charToWord(pilihan);
        
        printf("%s\n", word_pilihan.TabWord);

        // comparing string
        if(stringComp(word_pilihan.TabWord, "N")){
            return;
        }
        */

        // pilih album
        printf("Pilih penyanyi untuk melihat album mereka: ");
        STARTLINE();
        char penyanyi[100] = "";
        // scanf("%s", penyanyi);
        // printf("%s\n", penyanyi);
        stringCopy(penyanyi, currentLine.TabWord);

        // printf("%s\n", penyanyi);
        printf("Daftar Album oleh %s:\n", penyanyi);
        int idx_penyanyi = showAlbum(charToLine(penyanyi), l);


        // pilih lagu
        printf("Masukkan nama Album yang dipilih : ");
        char album[100] = "";
        // scanf("%s", album);
        STARTLINE();
        // printf("%s\n", album);
        // printf("%s\n", currentLine.TabWord);
        stringCopy(album, currentLine.TabWord);
        // printf("%s\n", album);
        int idx_album;

        stringCopy(album, currentLine.TabWord);
        for(int i = 0; i < l.A[idx_penyanyi].album.Count; i++){
            if(stringComp(l.A[idx_penyanyi].album.Elements[i].nama_album.TabWord, album)){
                idx_album = i;
                break;
            }
        }
        int nama_album;
        printf("Daftar Lagu Album %s oleh %s\n", album, penyanyi);
        showLagu(charToWord(album), idx_penyanyi, l);

        printf("Masukkan ID lagu yang dipilih : ");
        queueElType ID;
        // scanf("%d", &ID);
        
        STARTWORD();
        ID.idx_lagu = wordToInt(currentWord);

        if(ID.idx_lagu > l.A[idx_penyanyi].album.Elements[idx_album].daftar_lagu.Count){
            printf("Tidak ada lagu dengan ID %s\n", ID.idx_lagu);
            return;
        }
    
        ID.idx_album = idx_album;
        ID.idx_penyanyi = idx_penyanyi;
        // printf("%d\n", idx_penyanyi);
        // printf("%d\n", idx_album);
        // printf("%d\n", ID.idx_lagu);
        // printf("%s\n", ID.nama_penyanyi.TabWord);
        stringCopy(ID.nama_lagu, l.A[idx_penyanyi].album.Elements[idx_album].daftar_lagu.Elements[ID.idx_lagu-1].TabWord);
        stringCopy(ID.nama_album, album);
        stringCopy(ID.nama_penyanyi, penyanyi);

        // printf("%s\n", ID.nama_penyanyi);
        // printf("%s\n", ID.nama_album);
        // printf("%s\n", ID.nama_lagu);
        // printf("%s\n", ID.nama_penyanyi.TabWord);
        // printf("%d\n", ID);
        enqueue(q, ID);
        printf("Berhasil menambahkan lagu %s dari album %s oleh %s ke queue\n", ID.nama_lagu, ID.nama_album, ID.nama_penyanyi); //queue masih nyimpan ID saja
        // displayQueue(*q);
    }

    else if(stringComp(currentWord.TabWord, "PLAYLIST")){
        lladdress P;
        
        printf("Masukkan ID playlist: ");
        STARTWORD();
        int IDPlaylist = wordToInt(currentWord);
        if(IDPlaylist > Playlist->Neff){
            printf("Tidak ada playlist dengan ID %s\n", IDPlaylist);
            return;
        }
        P = (Playlist->A[IDPlaylist-1].linkedlistFirst);
        while(P != NULL){
            enqueue(q, P->info);
            P = P->next;
        }
        printf("Berhasil menambahkan playlist \"%s\" ke queue\n", Playlist->A[IDPlaylist-1].namaPlaylist.TabWord);
    }

    else if(stringComp(currentWord.TabWord, "SWAP")){
        int x, y;
        STARTWORD();
        x = wordToInt(currentWord) - 1;
        STARTWORD();
        y = wordToInt(currentWord) - 1;
        STARTWORD();
        if(!stringComp(currentWord.TabWord, "")){
            printf("Input berupa \"QUEUE SWAP <x> <Y>\"\n");
            return;
        }
        if(x > queueIDX_TAIL(*q)){
        printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", x+1);
        }
        else{
            if(y > queueIDX_TAIL(*q)){
                printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", y+1);
            }
            else{
                
                int lagux =  queueIDX_HEAD(*q)+x;
                int laguy = queueIDX_HEAD(*q)+y;
                printf("Lagu \"%s\" telah berhasil ditukar dengan \"%s\"\n", q->buffer[lagux].nama_lagu, q->buffer[laguy].nama_lagu);
                queueElType temp = q->buffer[laguy];  //isi ID lagu yang disimpan
                q->buffer[laguy] = q->buffer[lagux];
                q->buffer[lagux] = temp;
            }
        }
    }

    else if(stringComp(currentWord.TabWord, "REMOVE")){
        int id;
        queueElType val;
        Queue temp; //nyimpan queue sementara
        Queue before;
        CreateQueue(&temp);
        CreateQueue(&before);
        STARTWORD();
        id = wordToInt(currentWord) - 1;
        if(id > queueIDX_TAIL(*q)){
            printf("Lagu urutan ke %d tidak ada\n", id);
        }
        else{
            printf("Lagu \"%s\" oleh \"%s\" telah dihapus dari queue!\n", q->buffer[id + (*q).queueidxHead].nama_lagu, q->buffer[id + (*q).queueidxHead].nama_penyanyi);
            for(int i = queueIDX_HEAD(*q); i < id; i++){ //dequeue index awal sebelum id yang di delete, simpan di temp
                dequeue(q, &val);
                enqueue(&temp, val);
            }
            dequeue(q, &val); //dequeue id yang di delete
            for(int i = queueIDX_HEAD(*q); i <= queueIDX_TAIL(*q); i++){ //dequeue index setelah id yang di delete, simpan di before
                dequeue(q, &val);
                //enqueue(&before, val);
                enqueue(&temp, val);
            }
            for(int i = queueIDX_HEAD(temp); i <= queueIDX_TAIL(temp); i++){ //masukin val sebelum id yang di delete
                dequeue(&temp, &val);
                enqueue(q, val);
            }
            // for(int i = 0; i<queueIDX_TAIL(before)-queueIDX_HEAD(before);i++){ //masukin val setelah id yang di delete
            //     dequeue(&temp, &val);
            //     enqueue(q, val);
            // }
            
        }
    }

    else if(stringComp(currentWord.TabWord, "CLEAR")){
        // int temp, length; // ini dump nilai queue aja
        // length = queuelength(*q);
        // for(int i = 0; i < length; i++){
        //     dequeue(q, &temp);
        // }
        CreateQueue(q);
        printf("Queue berhasil dikosongkan!\n");
    }
}

void songSpotify(Queue *q, Stack *history){
    STARTWORD();
    if(stringComp(currentWord.TabWord, "NEXT")){
        stackinfotype ID; //menyimpan ID lagu 
        // int id_lagu = history->T[history->TOP].idx_lagu;
        // char *nama = history->T[history->TOP].nama_penyanyi;
        if(queueisEmpty(*q)){
            printf("Queue kosong, memutar kembali lagu ");
            printf("\"%s\"\n", CurrentSong);
        }
        else{
            stringCopy(ID.nama_penyanyi, CurrentSinger);
            stringCopy(ID.nama_album, CurrentAlbum);
            stringCopy(ID.nama_lagu, CurrentSong);
            Push(history, ID); //push ID lagu yang sedang diputar ke stack
            dequeue(q, &ID);
            stringCopy(CurrentSinger, ID.nama_penyanyi);
            stringCopy(CurrentAlbum, ID.nama_album);
            stringCopy(CurrentSong, ID.nama_lagu);
            printf("Memutar lagu selanjutya\n");
            printf("\"%s\" oleh \"%s\"\n", ID.nama_lagu, ID.nama_penyanyi);
        }
    }
    else if(stringComp(currentWord.TabWord, "PREVIOUS")){
        stackinfotype prev, temp;
        Queue tempq;
        CreateQueue(&tempq);
        // int id_lagu = history->T[history->TOP].idx_lagu;
        // char *nama = history->T[history->TOP].nama_penyanyi;
        if(stackIsEmpty(*history)){ //stack yang berisi 1 elemen dihitung riwayat kosong
            printf("Riwayat lagu kosong, memutar kembali lagu "); //memutar lagu yang berada di TOP
            printf("\"%s\"\n", CurrentSong);
        }

        else{
            // Pop(history, &prev);
            stringCopy(prev.nama_penyanyi, CurrentSinger);
            stringCopy(prev.nama_album, CurrentAlbum);
            stringCopy(prev.nama_lagu, CurrentSong);
            for(int i = queueIDX_HEAD(*q); i <= queueIDX_TAIL(*q); i++){ //kosongkan queue yang *q kecuali yang dienqueue sebelumnya
                dequeue(q, &temp);
                enqueue(&tempq, temp);
            }
 //masukkan ID yang sudah di pop dari stack ke *q
            
            enqueue(q, prev);
            //enqueue(q, prev); //masukkan ID yang sudah di pop dari stack ke *q //masukkan ID yang sudah di pop dari stack ke *q
            for(int i = queueIDX_HEAD(tempq); i <= queueIDX_TAIL(tempq); i++){ //enqeue kembali ID lagu yang berada di *q sebelumnya
                dequeue(&tempq, &temp);
                enqueue(q, temp);
            }
            Pop(history, &prev); //pop ID lagu yang berada di stack
            stringCopy(CurrentSinger, prev.nama_penyanyi);
            stringCopy(CurrentAlbum, prev.nama_album);
            stringCopy(CurrentSong, prev.nama_lagu);
            printf("Memutar lagu sebelumnya\n");
            printf("\"%s\" oleh \"%s\"\n", CurrentSong, CurrentSinger);
        }
    }
}

void playlistSpotify(ListPlaylist *Playlist){
    STARTWORD();
    if(stringComp(currentWord.TabWord, "CREATE")){
        int cnt;
        lList ll;
        llCreateEmpty(&ll);
        do
        {
            printf("Masukkan nama playlist yang ingin dibuat : ");
            STARTLINE();
            cnt=0;
            for (int i=0; i<currentLine.Length; i++)
            {
                if(currentLine.TabWord[i] != ' ') cnt++;
            }
            if(cnt<3) printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n");
        } while (cnt<3);
        


        ll.linkedlistFirst=NULL;
        ll.namaPlaylist=currentLine;
        lpInsertLast(Playlist, ll);
        printf("Playlist %s berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n", currentLine.TabWord);
    }

    else if(stringComp(currentWord.TabWord, "ADD")){
        // printf("Daftar Penyanyi :");
        // showPenyanyi(l);
        // printf("Masukkan Nama Penyanyi yang dipilih :");
        // STARTLINE();
        // Line x=currentLine;
        // printf("Daftar Album oleh %s :", x.TabWord);
        // showAlbum(x, l);
        // printf("Masukkan Judul Album yang dipilih");
        // char t[100];
        // gets(t);
        // Word y;
        // y.Length=strlen(t);
        // for (int i=0; i<strlen(t); i++) y.TabWord[i]=t[i];
        // int idx;
        // printf("Daftar Lagu Album %s oleh %s :",t,x);
        // boolean diff=false;
        // for (int i=0; i<l.Penyanyi.Count; i++)
        // {
        //     if(strlen(x)!=l.Penyanyi.Elements[i].nama_penyanyi.Length) continue;
        //     for(int j=0; j<l.Penyanyi.Elements[i].nama_penyanyi.Length; j++)
        //     {
        //         if(l.Penyanyi.Elements[i].nama_penyanyi.TabWord[j]!=x[j]) diff=true;
        //     }
        //     if (diff=false)
        //     {
        //         idx=i;
        //         break;
        //     }
        // }
        // printf("Daftar Lagu Album %s oleh %s :",t,x);
        // showLagu(y, idx, l);
        // printf("Masukkan ID Lagu yang dipilih : ");
        // int id;
        // scanf("%d",&id);
        STARTWORD();
        if(stringComp(currentWord.TabWord, "SONG")){
            printf("Daftar Penyanyi :\n");
            showPenyanyi(l);

            // pilih album
            printf("Pilih penyanyi untuk melihat album mereka: ");
            char penyanyi[100] = "";
            stringMakeEmpty(penyanyi);
            // START();
            STARTLINE();
            // printf("%s\n", currentLine.TabWord);
            // ADVWORD();
            stringCopy(penyanyi, currentLine.TabWord);
            // scanf("%s", penyanyi);

            // printf("%s\n", penyanyi);
            printf("Daftar Album oleh %s:\n", penyanyi);
            int idx_penyanyi = showAlbum(charToLine(penyanyi), l);


            // pilih lagu
            printf("Masukkan nama Album yang dipilih : ");
            char album[100] = "";
            stringMakeEmpty(album);
            // ADVWORD();
            // START();
            STARTLINE();
            // ADVWORD();
            int idx_album;

            stringCopy(album, currentLine.TabWord);
            for(int i = 0; i < l.A[idx_penyanyi].album.Count; i++){
                if(stringComp(l.A[idx_penyanyi].album.Elements[i].nama_album.TabWord, album)){
                    idx_album = i;
                    break;
                }
            }
            // scanf("%s", album);
            printf("Daftar Lagu Album %s oleh %s\n", album, penyanyi);
            showLagu(charToWord(album), idx_penyanyi, l);
            printf("Masukkan ID lagu yang dipilih : ");
            STARTWORD();
            int idx_lagu = wordToInt(currentWord);
            if(idx_lagu > l.A[idx_penyanyi].album.Elements[idx_album].daftar_lagu.Count){
                printf("Tidak ada lagu dengan ID %s\n", idx_lagu);
                return;
            }
            llinfotype newSong;
            // lList newSong;
            // llCreateEmpty((*newSong).linkedlistFirst);
            stringCopy(newSong.nama_penyanyi, penyanyi);
            stringCopy(newSong.nama_album, album);
            stringCopy(newSong.nama_lagu, l.A[idx_penyanyi].album.Elements[idx_album].daftar_lagu.Elements[idx_lagu-1].TabWord);

            printf("Daftar Playlist Pengguna :\n");
            for (int i = 0; i < Playlist->Neff; i++) {
                printf("%d. %s\n", i + 1, Playlist->A[i].namaPlaylist.TabWord);
            }
            printf("Masukkan ID Playlist yang dipilih : ");
            int playlistID;
            // scanf("%d", &playlistID);
            STARTWORD();
            playlistID = wordToInt(currentWord);
            int idx2 = playlistID - 1;
            
            llInsVLast(&(Playlist->A[idx2]), newSong);
            // lpInsertLast(Playlist, *ll);
            

            // lList *chosenPlaylist = &((*Playlist).A[idx2]);
            // llInsertLast(&((*chosenPlaylist).linkedlistFirst), newSong);
            printf("Lagu dengan judul %s pada album %s oleh penyanyi %s berhasil ditambahkan ke dalam playlist %s.\n", newSong.nama_lagu, newSong.nama_album, newSong.nama_penyanyi, Playlist->A[idx2].namaPlaylist.TabWord);
        }

        else if(stringComp(currentWord.TabWord, "ALBUM")){
            // printf("Daftar Penyanyi :\n");
            // showPenyanyi(l);
            // printf("Masukkan Nama Penyanyi yang dipilih :");
            // STARTLINE();
            // Line x=currentLine;
            // printf("Daftar Album oleh %s :", x);
            // showAlbum(x, l);
            // printf("Masukkan Judul Album yang dipilih");
            // char t[100];
            // gets(t);
            // Word y;
            // y.Length=strlen(t);
            printf("Daftar Penyanyi :\n");
            showPenyanyi(l);

            // pilih album
            printf("Pilih penyanyi untuk melihat album mereka: ");
            char penyanyi[100] = "";
            stringMakeEmpty(penyanyi);
            // START();
            STARTLINE();
            // printf("%s\n", currentLine.TabWord);
            // ADVWORD();
            stringCopy(penyanyi, currentLine.TabWord);
            // scanf("%s", penyanyi);

            // printf("%s\n", penyanyi);
            printf("Daftar Album oleh %s:\n", penyanyi);
            int idx_penyanyi = showAlbum(charToLine(penyanyi), l);


            // pilih lagu
            printf("Masukkan nama Album yang dipilih : ");
            char album[100] = "";
            stringMakeEmpty(album);
            // ADVWORD();
            // START();
            STARTLINE();
            // ADVWORD();
            int idx_album;

            stringCopy(album, currentLine.TabWord);
            if(idx_album > l.A[idx_penyanyi].album.Count){
                printf("Tidak ada lagu dengan ID %s\n", idx_album);
                return;
            }
            for(int i = 0; i < l.A[idx_penyanyi].album.Count; i++){
                if(stringComp(l.A[idx_penyanyi].album.Elements[i].nama_album.TabWord, album)){
                    idx_album = i;
                    break;
                }
            }

            // for (int i=0; i<strlen(album); i++) y.TabWord[i]=t[i];
            printf("Daftar Playlist Pengguna :\n");
            for (int i = 0; i < Playlist->Neff; i++) {
                printf("%d. %s\n", i + 1, Playlist->A[i].namaPlaylist.TabWord);
            }
            printf("Masukkan ID Playlist yang dipilih : ");
            int playlistID;
            // scanf("%d", &playlistID);
            STARTWORD();
            playlistID = wordToInt(currentWord);
            // int idx;
            // boolean diff=false;
            // for (int i=0; i<l.Penyanyi.Count; i++)
            // {
            //     if(strlen(penyanyi)!=l.Penyanyi.Elements[i].nama_penyanyi.Length) continue;
            //     for(int j=0; j<l.Penyanyi.Elements[i].nama_penyanyi.Length; j++)
            //     {
            //         if(l.Penyanyi.Elements[i].nama_penyanyi.TabWord[j]!=[j]) diff=true;
            //     }
            //     if (diff=false)
            //     {
            //         idx=i;
            //         break;
            //     }
            // }
            int idx2 = playlistID - 1;

            llinfotype LD;
            // llElmtList newAlbum;
            // llCreateEmpty(&(newAlbum));
            // llInsVLast(&newAlbum, album);
            // lList *chosenPlaylist = &(Playlist->A[idx2]);
            // llInsertLast(&(chosenPlaylist->linkedlistFirst), &newAlbum);

            for(int i=0; i<l.A[idx_penyanyi].album.Elements[idx_album].daftar_lagu.Count; i++){
                stringCopy(LD.nama_penyanyi, penyanyi);
                stringCopy(LD.nama_album, album);
                stringCopy(LD.nama_lagu, l.A[idx_penyanyi].album.Elements[idx_album].daftar_lagu.Elements[i].TabWord);
                llInsVLast(&(Playlist->A[idx2]), LD);
            }

            printf("Album dengan judul %s berhasil ditambahkan ke dalam playlist %s.\n", album, Playlist->A[idx2].namaPlaylist.TabWord);
        }
    }

    else if(stringComp(currentWord.TabWord, "SWAP")){
        int playlistID, id1, id2, i;
        STARTWORD();
        playlistID = wordToInt(currentWord);
        STARTWORD();
        id1 = wordToInt(currentWord) - 1;
        STARTWORD();
        id2 = wordToInt(currentWord) - 1;
        STARTWORD();
        if(!stringComp(currentWord.TabWord, "")){
            printf("Input berupa \"PLAYLIST SWAP <id> <x> <y>\"\n");
            return;
        }
        if (playlistID < 1 || playlistID > Playlist->Neff) {
            printf("Tidak ada playlist dengan playlist ID %d\n", playlistID);
            return;
        }
        if(id1 < 0 || id1 > llNbElmt(Playlist->A[playlistID - 1])){
            printf("Tidak ada lagu dengan urutan %d di playlist %s\n", id1+1, Playlist->A[playlistID - 1].namaPlaylist.TabWord);
            return;
        }
        if(id2 < 0 || id2 > llNbElmt(Playlist->A[playlistID - 1])){
            printf("Tidak ada lagu dengan urutan %d di playlist %s\n", id2+1, Playlist->A[playlistID - 1].namaPlaylist.TabWord);
            return;
        }
        // printf("AAAAA");
        lList *playlist = &(Playlist->A[playlistID - 1]);
        lladdress currentNode1 = NULL;
        lladdress prevNode1 = NULL;
        lladdress currentNode2 = NULL;
        lladdress prevNode2 = NULL;
        lladdress tempNode = playlist->linkedlistFirst;

        // Traverse the playlist to find both songs with the given IDs
        // while (tempNode != NULL) {
        //     if (tempNode.count == id1) {
        //         currentNode1 = tempNode;
        //         prevNode1 = prevNode2;
        //     }
        //     if (tempNode.count == id2) {
        //         currentNode2 = tempNode;
        //         prevNode2 = prevNode1;
        //     }

        //     prevNode1 = tempNode;
        //     tempNode = tempNode.next;
        // }
        for(i=0; i<id1; i++){
            prevNode1 = tempNode;
            tempNode = tempNode->next;
        }
        currentNode1 = tempNode;
        for(i=0; i<id2; i++){
            prevNode2 = tempNode;
            tempNode = tempNode->next;
        }
        currentNode2 = tempNode;
        if (prevNode1 != NULL) {
            prevNode1->next = currentNode2;
        } else {
            playlist->linkedlistFirst = currentNode2;
        }

        if (prevNode2 != NULL) {
            prevNode2->next = currentNode1;
        } else {
            playlist->linkedlistFirst = currentNode1;
        }

        lladdress temp = currentNode1->next;
        currentNode1->next = currentNode2->next;
        currentNode2->next = temp;

        printf("Berhasil menukar lagu dengan nama %s dengan %s di playlist %s\n", currentNode1->info.nama_lagu, currentNode2->info.nama_lagu, playlist->namaPlaylist.TabWord);
    }

    else if(stringComp(currentWord.TabWord, "REMOVE")){
        /* Command PLAYLIST REMOVE digunakan untuk menghapus lagu dengan urutan n pada playlist dengan index id. */
        int playlistID, id;
        STARTWORD();
        playlistID = wordToInt(currentWord);
        STARTWORD();
        id = wordToInt(currentWord)-1;
        if (playlistID < 1 || playlistID > Playlist->Neff) {
            printf("Tidak ada playlist dengan playlist ID %d\n", playlistID);
            return;
        }
        lList *playlist = &(Playlist->A[playlistID - 1]);
        lladdress currentNode = playlist->linkedlistFirst;
        lladdress prevNode = NULL;

        // while (currentNode != NULL && currentNode != id) {
        //     prevNode = currentNode;
        //     currentNode = currentNode->next;
        // }
        if (id < 0 || id > llNbElmt(*playlist)) {
            printf("Tidak ada lagu dengan urutan %d di playlist %s\n", id+1, playlist->namaPlaylist.TabWord);
            return;
        }
        for(int i=0; i<id; i++){
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
        if (prevNode != NULL) {
            prevNode->next = currentNode->next;
        } else {
            playlist->linkedlistFirst = currentNode->next;
        }
        printf("Lagu %s oleh %s telah dihapus dari playlist %s!\n", currentNode->info.nama_lagu, currentNode->info.nama_penyanyi, playlist->namaPlaylist.TabWord);
        free(currentNode); 
    }

    else if(stringComp(currentWord.TabWord, "DELETE")){
        /* Command PLAYLIST DELETE digunakan untuk melakukan penghapusan suatu existing playlist dalam daftar playlist pengguna. Tampilkan pesan error apabila masukkan pengguna tidak valid pada setiap permintaan masukkan. */
        // printf("Daftar Playlist Pengguna : ");
        // for (int i = 0; i < Playlist->Neff; i++) {
        //     printf("%d. %s\n", i + 1, Playlist->A[i].namaPlaylist.TabWord);
        // }
        // printf("Masukkan ID Playlist yang dipilih : ");
        int playlistID;
        // scanf("%d", &playlistID);
        stringCopy(currentWord.TabWord, "PLAYLIST");
        listSpotify(Playlist);
        printf("Masukkan ID Playlist yang dipilih : ");
        STARTWORD();
        playlistID = wordToInt(currentWord);
        if (playlistID < 1 || playlistID > Playlist->Neff)
        {
            printf("Tidak ada playlist dengan ID %d dalam daftar playlist pengguna. Silakan coba lagi.\n", playlistID);
        }
        else{
            int idx2 = playlistID - 1;
            printf("Playlist ID %d dengan judul %s berhasil dihapus.\n", playlistID, Playlist->A[idx2].namaPlaylist.TabWord);
            lpDeleteAt(Playlist, idx2);
        }
    }
    
}

void statusSpotify(Queue *q, Stack *s){
    // queueElType val;
    // Queue q2;
    int i, counter = 1;
    if (queueisEmpty(*q)){
        if(stringComp(CurrentSong, "")){
            printf ("Now Playing: ");
            printf("No songs have been played yet. Please search for a song to begin playback.\n");
        }
        else{
            printf ("Now Playing: ");
            printf("%s - %s - %s\n", CurrentSong, CurrentAlbum, CurrentSinger);
        }
        printf("Queue: ");
        printf("Your queue is empty.\n");
    }
    else if (!queueisEmpty(*q) && stringComp(CurrentPlaylist, "")){
        if(stringComp(CurrentSong, "")){
            printf ("Now Playing: ");
            printf("No songs have been played yet. Please search for a song to begin playback.\n");
        }
        else{
            printf ("Now Playing: ");
            printf("%s - %s - %s\n", CurrentSong, CurrentAlbum, CurrentSinger);
        }
        printf("Queue:\n");
        for (i = queueIDX_HEAD(*q); i <= (queueIDX_TAIL(*q)) ; i++){
            // dequeue(q, &val); // dequeue nama_penyanyi, nama_album, CurrentSong
            // enqueue(&q2, val); // enqueue nama_penyanyi, nama_album, CurrentSong
            printf("%d. %s - %s - %s\n", counter, q->buffer[i].nama_penyanyi, q->buffer[i].nama_album, q->buffer[i].nama_lagu);
            counter++;
        }
    }
    else if (!stringComp(CurrentSong, "") && !queueisEmpty(*q) && !stringComp(CurrentPlaylist, "")) {
        printf("Current Playlist: %s\n", CurrentPlaylist);
        printf ("Now Playing: ");
        printf("%s - %s - %s\n", CurrentSong, CurrentAlbum, CurrentSinger);

        printf("Queue:\n");
        for (i = queueIDX_HEAD(*q); i <= (queueIDX_TAIL(*q)) ; i++){
            // dequeue(q, &val); // dequeue nama_penyanyi, nama_album, CurrentSong
            // enqueue(&q2, val); // enqueue nama_penyanyi, nama_album, CurrentSong
            printf("%d. %s - %s - %s\n", counter, q->buffer[i].nama_penyanyi, q->buffer[i].nama_album, q->buffer[i].nama_lagu);
            counter++;
        }
    }
}

int saveSpotify(Queue *q, Stack *history, ListPlaylist *Playlist) {
    FILE *file;
    Word fileName;
    char buffer[100];

    int numPenyanyi = l.count;

    /*if (numPenyanyi == 0) {
        printf("Tidak ada data.\n");
        return 1;
    }*/
    printf("Masukkan nama file penyimpanan: ");
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
        int numAlbum = l.A[i].album.Count;
        fprintf(file, "%d ", numAlbum);
        fprintf(file, "%s\n", l.A[i].nama_penyanyi.TabWord);

        for (int j = 0; j < numAlbum; j++) {
            int numLagu = l.A[i].album.Elements[j].daftar_lagu.Count;
            fprintf(file, "%d ", numLagu);
            fprintf(file, "%s\n", l.A[i].album.Elements[j].nama_album.TabWord);

            for (int k = 0; k < numLagu; k++) {
                fprintf(file, "%s\n", l.A[i].album.Elements[j].daftar_lagu.Elements[k].TabWord);
            }
        }
    }
    queueElType ID;
    llinfotype LD;
    // printf("\n");
    if(!stringComp(CurrentSong, "")){ // READ FOR CURRENT SONG
        // printf("AAAAA");
        // readFileLineIgnoreMark(file);
        // stringCopy(CurrentSinger, currentLine.TabWord);
        // readFileLineIgnoreMark(file);
        // stringCopy(CurrentAlbum, currentLine.TabWord);
        // readFileLineIgnoreMark(file);
        // stringCopy(CurrentSong, currentLine.TabWord);
        fprintf(file, "%s;", CurrentSinger);
        fprintf(file, "%s;", CurrentAlbum);
        fprintf(file, "%s\n", CurrentSong);
        // if(feof(file)){
        //     fclose(file);
        //     printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n");
        //     return 0;
        // }
    }
    if(!queueisEmpty(*q)){ // READ FOR QUEUE
        // readFileWord(file);
        // int idx = wordToInt(currentWord);
        // printf("%d\n", idx);
        int idx = queuelength(*q);
        fprintf(file, "%d\n", idx);
        for(i=(*q).queueidxHead; i<=(*q).queueidxTail; i++){
            // readFileLineIgnoreMark(file);
            // stringCopy(ID.nama_penyanyi, currentLine.TabWord);
            // readFileLineIgnoreMark(file);
            // stringCopy(ID.nama_album, currentLine.TabWord);
            // readFileLineIgnoreMark(file);
            // stringCopy(ID.nama_lagu, currentLine.TabWord);
            // enqueue(q, ID);
            fprintf(file, "%s;", q->buffer[i].nama_penyanyi);
            fprintf(file, "%s;", q->buffer[i].nama_album);
            fprintf(file, "%s\n", q->buffer[i].nama_lagu);
        }
    }
    if(!stackIsEmpty(*history)){ // READ FOR HISTORY
        // readFileWord(file);
        // int idx = wordToInt(currentWord);
        int idx = stackTop(*history)+1;
        fprintf(file, "%d\n", idx);
        for(i=0; i<idx; i++){
            // readFileLineIgnoreMark(file);
            // stringCopy(ID.nama_penyanyi, currentLine.TabWord);
            // readFileLineIgnoreMark(file);
            // stringCopy(ID.nama_album, currentLine.TabWord);
            // readFileLineIgnoreMark(file);
            // stringCopy(ID.nama_lagu, currentLine.TabWord);
            // Push(history, ID);
            fprintf(file, "%s;", history->T[i].nama_penyanyi);
            fprintf(file, "%s;", history->T[i].nama_album);
            fprintf(file, "%s\n", history->T[i].nama_lagu);
        }
    }
    if(!lpIsEmpty(*Playlist)){ // READ FOR PLAYLIST
        // readFileWord(file);
        // int idx_playlist = wordToInt(currentWord);
        int idx_playlist = Playlist->Neff; 
        fprintf(file, "%d\n", idx_playlist);
        for(i=0; i<idx_playlist; i++){
            // readFileWord(file);
            // int idxsong = wordToInt(currentWord);;
            // printf("%d\n", idxsong);
            // readFileLineIgnoreMark(file);
            int countll = llNbElmt(Playlist->A[i]);
            fprintf(file, "%d ", countll);
            fprintf(file, "%s\n", Playlist->A[i].namaPlaylist.TabWord);

            // stringCopy(Playlist->A[i].namaPlaylist.TabWord, currentLine.TabWord);
            for(j=0; j<countll; j++){
                // readFileLineIgnoreMark(file);
                // stringCopy(LD.nama_penyanyi, currentLine.TabWord);
                // // printf("%s\n", currentLine.TabWord);
                // readFileLineIgnoreMark(file);
                // stringCopy(LD.nama_album, currentLine.TabWord);
                // // printf("%s\n", currentLine.TabWord);
                // readFileLineIgnoreMark(file);
                // stringCopy(LD.nama_lagu, currentLine.TabWord);
                // // printf("%s\n", currentLine.TabWord);
                // llInsVLast(&(Playlist->A[i]), LD);
                fprintf(file, "%s;", Playlist->A[i].linkedlistFirst->info.nama_penyanyi);
                fprintf(file, "%s;", Playlist->A[i].linkedlistFirst->info.nama_album);
                fprintf(file, "%s\n", Playlist->A[i].linkedlistFirst->info.nama_lagu);
            }
            
        }
        // Playlist->Neff = idx_playlist;
    }
    fclose(file);
    printf("Save file berhasil disimpan.\n");
    return 0;
}

void quitSpotify(Queue *q, Stack *history, ListPlaylist *Playlist){
    printf("Apakah kamu ingin menyimpan data sesi sekarang?\n");
    printf(">> ");
    // ADVWORD();
    STARTWORD();
    // ADVWORD();
    // printf("Input: %c\n", currentWord.TabWord[0]);
    
    if (currentWord.TabWord[0] == 'y' || currentWord.TabWord[0] == 'Y'){
        printf("Menyimpan...\n");
        saveSpotify(q, history, Playlist);
    }
    printf("Kamu keluar dari WayangWave.\n");
    printf("Dadah ^_^/\n");
    fclose(stdin);
    exit(0);
}
 /*Keluar dari sesi aplikasi WayangWave (SPOTIFY)*/ 
void helpSpotifyBeforeLoad(){
    printf("1. \"START;\" untuk memulai WayangWave dengan file default\n");
    printf("2. \"LOAD <nama file>.txt;\" untuk memulai WayangWave dengan file yang telah di save\n");
}

void helpSpotifyAfterLoad(){
    printf("1. \"LIST\":\n");
    printf("   \"LIST DEFAULT;\" untuk melihat daftar lagu default yang tersedia\n");
    printf("   \"LIST PLAYLIST;\" untuk melihat playlist yang tersedia\n");
    printf("2. \"PLAY\":\n");
    printf("   \"PLAY SONG;\" untuk memutar lagu\n");
    printf("   \"PLAY PLAYLIST;\" untuk memutar playlist\n");
    printf("3. \"QUEUE\":\n");
    printf("   \"QUEUE SONG;\" untuk menambahkan lagu ke queue\n");
    printf("   \"QUEUE PLAYLIST;\" untuk menambahkan playlist ke queue\n");
    printf("   \"QUEUE SWAP <x> <y>;\" untuk menukar posisi lagu dalam queue\n");
    printf("   \"QUEUE REMOVE <id>;\" untuk menghapus lagu dalam queue\n");
    printf("   \"QUEUE CLEAR;\" untuk menghapus semua lagu dalam queue\n");
    printf("   \"SONG\":\n");
    printf("   \"SONG NEXT;\" untuk memutar lagu selanjutnya\n");
    printf("   \"SONG PREVIOUS;\" untuk memutar lagu sebelumnya\n");
    printf("4. \"PLAYLIST\":\n");
    printf("   \"PLAYLIST CREATE <nama playlist>;\" untuk membuat playlist baru\n");
    printf("   \"PLAYLIST ADD SONG;\" untuk menambahkan lagu ke playlist\n");
    printf("   \"PLAYLIST ADD ALBUM;\" untuk menambahkan album ke playlist\n");
    printf("   \"PLAYLIST SWAP <id_playlist> <x> <y>;\" untuk menukar posisi lagu dalam playlist\n");
    printf("   \"PLAYLIST REMOVE <id>;\" untuk menghapus lagu dalam playlist\n");
    printf("   \"PLAYLIST DELETE <id>;\" untuk menghapus playlist\n");
    printf("5. \"STATUS;\" untuk melihat status lagu yang sedang diputar dan queue\n");
    printf("6. \"SAVE;\" untuk menyimpan data sesi sekarang\n");
    printf("7. \"QUIT;\" untuk keluar dari WayangWave\n");
    printf("8. \"HELP;\" untuk melihat bantuan\n");
}

// char *c;
// c = address
// string = array of char
// char di string itu bersebelahan
// char c[]
// c[i] = *(&c + i*sizeof(c)) 
// c[0] = *(&c)
// [h][e][l][l][o][ ][w][o][r][l][d][!]