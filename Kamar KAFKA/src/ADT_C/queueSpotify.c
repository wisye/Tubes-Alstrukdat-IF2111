#include "queue.h"
#include "listSpotify.c"
#include "../ADT_H/mesinkata.h"
#include <stdio.h>
#include <stdlib.h>
 
void queueSong(Queue *q, ListDefault l){
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

    printf("Masukkan ID lagu yang dipilih : ");
    int ID;
    scanf("%d", &ID);
    enqueue(&q, ID);
    printf("Berhasil menambahkan lagu \"%s\" oleh \"%s\" ke queue", ID);

}

void queuePlaylist(Queue *q){
    printf("Masukkan ID Playlist: ");
    int ID;
    scanf("%d", &ID);
}

void queueSwap(Queue *q, int x, int y){
    if(x > IDX_TAIL(*q)){
        printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!", x);
    }
    else{
        if(y > IDX_TAIL(*q)){
            prinf("Lagu dengan urutan ke %d tidak terdapat dalam queue!", y);
        }
        else{
            int lagux =  IDX_HEAD(*q)+x;
            int laguy = IDX_HEAD(*q)+y;

            int temp = q->buffer[laguy];  //isi ID lagu yang disimpan
            q->buffer[laguy] = q->buffer[lagux];
            q->buffer[lagux] = temp;
        }
    }

}

void queueRemove(Queue *q, int id){
    int val;
    Queue temp; //nyimpan queue sementara
    Queue before;
    CreateQueue(&temp);
    CreateQueue(&before);
    if(id > TAIL(*q)){
        printf("Lagu urutan ke %d tidak ada\n", id);
    }
    else{
        for(int i = HEAD(*q); i <= id; i++){ //dequeue index awal sebelum id yang di delete, simpan di temp
            dequeue(q, &val);
            enqueue(&temp, val);
        }
        for(int i = HEAD(*q); i <= TAIL(*q); i++){ //dequeue index setelah id yang di delete, simpan di before
            dequeue(q, &val);
            enqueue(&before, val);
        }
        for(int i = 0; i <= TAIL(temp)-HEAD(temp); i++){ //masukin val sebelum id yang di delete
            dequeue(&temp, &val);
            enqueue(q, val);
        }
        for(int i = 0; i<=TAIL(before)-HEAD(before);i++){ //masukin val setelah id yang di delete
            dequeue(&temp, &val);
            enqueue(q, val);
        }
    }
}

void queueClear(Queue *q){
    int temp, idx; // ini dump nilai queue aja
    if (HEAD(*q) > TAIL(*q)){
        idx = HEAD(*q) - TAIL(*q);
    }
    else TAIL(*q) - HEAD(*q);
    for(int i = 0; i < idx; i++){
        dequeue(q, &temp);
    }
}