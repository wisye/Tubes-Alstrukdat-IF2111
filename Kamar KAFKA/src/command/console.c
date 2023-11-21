#include "console.h"
// #include "func.h"

ListDefault l;
// Queue q;
void startSpotify(){
    ADVWORD();
    stringCopy(currentWord.TabWord, "DEFAULT");
    loadSpotify();
}
/*Implementation of console.h goes here*/
int loadSpotify(){
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
    l.Penyanyi.Count = IjumlahPenyanyi;
    for(i=0; i<IjumlahPenyanyi; i++){

        // (&p + i*sizeof(Penyanyi));
        readFileWord(file);
        IjumlahAlbum = wordToInt(currentWord);
        l.Penyanyi.Elements[i].album.Count = IjumlahAlbum;
        // printf("%d\n", IjumlahAlbum);
        readFileLine(file);
        stringCopy(l.Penyanyi.Elements[i].nama_penyanyi.TabWord, currentLine.TabWord);
        // printf("%c\n", currentChar);
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
void listSpotify(){
    // printf(">> ");
    ADVWORD();      // TURN THIS OFF IF YOU WANT TO USE THE DRIVER
    // STARTWORD(); // TURN THIS ON IF YOU WANT TO USE THE DRIVER
    // ADVWORD();
    // printf("%s\n", currentWord.TabWord);

    if (stringComp(currentWord.TabWord, "DEFAULT")){
        // IF DEFAULT PROCESS GHOSTRULE.TXT
        // stringCopy(currentWord.TabWord, "ghostrule.txt");
        // loadSpotify(l);

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


        stringCopy(album, currentLine.TabWord);
        // scanf("%s", album);

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

void playSpotify(Stack *S, Queue *Q){ //Masih bingung cara testing, jadi ini belum di test. Kayaknya globalvar juga belum diinclude
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
        for(int i = 0; i < l.Penyanyi.Elements[idx_penyanyi].album.Count; i++){
            if(stringComp(l.Penyanyi.Elements[idx_penyanyi].album.Elements[i].nama_album.TabWord, album)){
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
        stringCopy(CurrentSong, l.Penyanyi.Elements[idx_penyanyi].album.Elements[idx_album].daftar_lagu.Elements[idx_lagu-1].TabWord);
        stringCopy(CurrentAlbum, album);
        stringCopy(CurrentSinger, penyanyi);
        printf("Memutar lagu \"%s\" oleh \"%s\"\n", l.Penyanyi.Elements[idx_penyanyi].album.Elements[idx_album].daftar_lagu.Elements[idx_lagu-1].TabWord, penyanyi);
        // printf("Current Song: %s\n", CurrentSong);
        CreateQueue(Q);
        stackCreateEmpty(S);   
    }
    // else if(stringComp(currentWord.TabWord, "PLAYLIST")){//Apabila input berupa play playlist
    //     int IDPlaylist;
    //     printf("\nMasukkan ID Playlist: ");
    //     scanf("%d" , &IDPlaylist); //Input ID Playlist
    //     if(IDPlaylist <= Length(listPlaylist)){ //Melakukan cek terhadap ID yang diinput
    //         printf("Memutar playlist \"%s\".\n", listPlaylist.A[IDPlaylist-1].namaPlaylist.TabWord);
    //         stringCopy(CurrentPlaylist, listPlaylist.A[IDPlaylist-1].namaPlaylist.TabWord);
    //         if(!queueisEmpty(*Q)){//Apabila sesuai akan mengosongkan queue
    //             for(int i = 0; i<queuelength(*Q) ; i++){
    //                 dequeue(Q, Q->buffer[i]);
    //             }
    //         }
    //         while(!stackIsEmpty(*S)){//Stack juga dikosongkan
    //             Pop(S,S->T[S->TOP]);
    //         }
    //         lladdress P = llFirst(listPlaylist.A[IDPlaylist-1]); //Masih ga yakin disini
    //         Push(S, llInfo(P));//Memasukkan lagu pertama dari playlist yang dipilih ke stack
    //         stringCopy(CurrentSong, llInfo(P));
    //         P = llNext(P);
    //         while (P != llNil)
    //         {
    //             enqueue(Q, llinfo(P));//Memasukkan sisa lagu yang di playlist yang dipilih ke dalam queue
    //             P = llNext(P);
    //         }
            
    //     }else{
    //         printf("ID Playlist belum valid.\n");
    //     }
    // }
}

void queueSpotify(Queue *q){
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
        for(int i = 0; i < l.Penyanyi.Elements[idx_penyanyi].album.Count; i++){
            if(stringComp(l.Penyanyi.Elements[idx_penyanyi].album.Elements[i].nama_album.TabWord, album)){
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
        ID.idx_album = idx_album;
        ID.idx_penyanyi = idx_penyanyi;
        // printf("%s\n", penyanyi);
        // printf("%s\n", ID.nama_penyanyi.TabWord);
        stringCopy(ID.nama_lagu, l.Penyanyi.Elements[idx_penyanyi].album.Elements[idx_album].daftar_lagu.Elements[ID.idx_lagu-1].TabWord);
        stringCopy(ID.nama_album, album);
        stringCopy(ID.nama_penyanyi, penyanyi);

        // printf("%s\n", ID.nama_penyanyi.TabWord);
        // printf("%d\n", ID);
        enqueue(q, ID);
        printf("Berhasil menambahkan lagu %s dari album %s oleh %s ke queue\n", ID.nama_lagu, ID.nama_album, ID.nama_penyanyi); //queue masih nyimpan ID saja
        // displayQueue(*q);
    }

    else if(stringComp(currentWord.TabWord, "SWAP")){
        int x, y;
        STARTWORD();
        x = wordToInt(currentWord) - 1;
        STARTWORD();
        y = wordToInt(currentWord) - 1;
        if(x > queueIDX_TAIL(*q)){
        printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", x);
        }
        else{
            if(y > queueIDX_TAIL(*q)){
                printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", y);
            }
            else{
                int lagux =  queueIDX_HEAD(*q)+x;
                int laguy = queueIDX_HEAD(*q)+y;

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
            for(int i = queueIDX_HEAD(*q); i < id; i++){ //dequeue index awal sebelum id yang di delete, simpan di temp
                dequeue(q, &val);
                enqueue(&temp, val);
            }
            for(int i = queueIDX_HEAD(*q); i < queueIDX_TAIL(*q); i++){ //dequeue index setelah id yang di delete, simpan di before
                dequeue(q, &val);
                enqueue(&before, val);
            }
            for(int i = 0; i < queueIDX_TAIL(temp)-queueIDX_HEAD(temp); i++){ //masukin val sebelum id yang di delete
                dequeue(&temp, &val);
                enqueue(q, val);
            }
            for(int i = 0; i<queueIDX_TAIL(before)-queueIDX_HEAD(before);i++){ //masukin val setelah id yang di delete
                dequeue(&temp, &val);
                enqueue(q, val);
            }
        }
    }

    else if(stringComp(currentWord.TabWord, "CLEAR")){
        // int temp, length; // ini dump nilai queue aja
        // length = queuelength(*q);
        // for(int i = 0; i < length; i++){
        //     dequeue(q, &temp);
        // }
        CreateQueue(q);
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
    if(stringComp(currentWord.TabWord, "PREVIOUS")){
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
        for(int i = 0; i < l.Penyanyi.Elements[idx_penyanyi].album.Count; i++){
            if(stringComp(l.Penyanyi.Elements[idx_penyanyi].album.Elements[i].nama_album.TabWord, album)){
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
        llinfotype newSong;
        // lList newSong;
        // llCreateEmpty((*newSong).linkedlistFirst);
        stringCopy(newSong.nama_penyanyi, penyanyi);
        stringCopy(newSong.nama_album, album);
        stringCopy(newSong.nama_lagu, l.Penyanyi.Elements[idx_penyanyi].album.Elements[idx_album].daftar_lagu.Elements[idx_lagu-1].TabWord);

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
            printf("%s\n", CurrentSong);
        }
        printf("Queue: ");
        printf("Your queue is empty.\n");
    }
    else if (!queueisEmpty(*q)){
        if(stringComp(CurrentSong, "")){
            printf ("Now Playing: ");
            printf("No songs have been played yet. Please search for a song to begin playback.\n");
        }
        else{
            printf ("Now Playing: ");
            printf("%s\n", CurrentSong);
        }
        printf("Queue:\n");
        for (i = queueIDX_HEAD(*q); i <= (queueIDX_TAIL(*q)) ; i++){
            // dequeue(q, &val); // dequeue nama_penyanyi, nama_album, CurrentSong
            // enqueue(&q2, val); // enqueue nama_penyanyi, nama_album, CurrentSong
            printf("%d. %s - %s - %s\n", counter, q->buffer[i].nama_penyanyi, q->buffer[i].nama_album, q->buffer[i].nama_lagu);
            counter++;
        }
    }
    else if (!stringComp(CurrentSong, "") && !queueisEmpty(*q)) {
        printf ("Now Playing: ");
        printf("%s\n", CurrentSong);

        printf("Queue:\n");
        for (i = queueIDX_HEAD(*q); i <= (queueIDX_TAIL(*q)) ; i++){
            // dequeue(q, &val); // dequeue nama_penyanyi, nama_album, CurrentSong
            // enqueue(&q2, val); // enqueue nama_penyanyi, nama_album, CurrentSong
            printf("%d. %s - %s - %s\n", counter, q->buffer[i].nama_penyanyi, q->buffer[i].nama_album, q->buffer[i].nama_lagu);
            counter++;
        }
    }
    else if(!stackIsEmpty(*s) && !queueisEmpty(*q) && CurrentPlaylist != NULL){
        printf("Current Playlist: %s\n", CurrentPlaylist);
        printf ("Now Playing: ");
        printf("%s\n", CurrentSong);

    

        printf("Queue:\n");
        for (int i = 0; i < queuelength(*q) ; i++){
            // dequeue(q, &val); // dequeue nama_penyanyi, nama_album, CurrentSong
            // enqueue(&q2, val); // enqueue nama_penyanyi, nama_album, CurrentSong
            printf("%d. %s - %s - %s\n", counter, q->buffer[i].nama_penyanyi, q->buffer[i].nama_album, q->buffer[i].nama_lagu);
            counter++;
        }
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

void quitSpotify(){
    printf("Apakah kamu ingin menyimpan data sesi sekarang?\n");
    printf(">> ");
    // ADVWORD();
    STARTWORD();
    // ADVWORD();
    // printf("Input: %c\n", currentWord.TabWord[0]);
    
    if (currentWord.TabWord[0] == 'y' || currentWord.TabWord[0] == 'Y'){
        printf("Menyimpan...\n");
        saveSpotify();
    }
    printf("Kamu keluar dari WayangWave.\n");
    printf("Dadah ^_^/\n");
    fclose(stdin);
    exit(0);
}
 /*Keluar dari sesi aplikasi WayangWave (SPOTIFY)*/ 
void helpSpotify(){
    printf("ajshdkashdjkahdjs\n");
}

// char *c;
// c = address
// string = array of char
// char di string itu bersebelahan
// char c[]
// c[i] = *(&c + i*sizeof(c)) 
// c[0] = *(&c)
// [h][e][l][l][o][ ][w][o][r][l][d][!]