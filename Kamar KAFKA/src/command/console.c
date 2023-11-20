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
        int nama_album;
        printf("Daftar Lagu Album %s oleh %s\n", album, penyanyi);
        showLagu(charToWord(album), idx_penyanyi, l);

        printf("Masukkan ID lagu yang dipilih : ");
        queueElType ID;
        // scanf("%d", &ID);
        STARTWORD();
        ID.idx_lagu = wordToInt(currentWord);
        // printf("%s\n", penyanyi);
        // printf("%s\n", ID.nama_penyanyi.TabWord);
        stringCopy(ID.nama_album, album);
        stringCopy(ID.nama_penyanyi, penyanyi);
        // printf("%s\n", ID.nama_penyanyi.TabWord);
        // printf("%d\n", ID);
        enqueue(q, ID);
        printf("Berhasil menambahkan lagu ke-%d dari album %s oleh %s ke queue\n", ID.idx_lagu, ID.nama_album, ID.nama_penyanyi); //queue masih nyimpan ID saja
        displayQueue(*q);
    }

    else if(stringComp(currentWord.TabWord, "SWAP")){
        int x, y;
        STARTWORD();
        x = wordToInt(currentWord);
        STARTWORD();
        y = wordToInt(currentWord);
        if(x > queueIDX_TAIL(*q)){
        printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!", x);
        }
        else{
            if(y > queueIDX_TAIL(*q)){
                printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!", y);
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
        id = wordToInt(currentWord);
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


// char *c;
// c = address
// string = array of char
// char di string itu bersebelahan
// char c[]
// c[i] = *(&c + i*sizeof(c)) 
// c[0] = *(&c)
// [h][e][l][l][o][ ][w][o][r][l][d][!]