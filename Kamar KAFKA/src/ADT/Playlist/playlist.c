#include "playlist.h"
// #include "../ListDinamis/arraydin.h"
// #include "../ListDinamis/arraydin.c"
// #include "../LinkedList/listlinier.h"
// #include "../LinkedList/listlinier.c"
// #include "../func/func.h"
// #include "../func/func.c"
// #include "../command/console.h"
// #include "../command/console.c"
// #include "boolean.h"
// #include <string.h>

// ArrayDin Playlist;
/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (lList L){
    return (llFirst(L) == llNil);
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void llCreateEmpty (lList *L){
    llFirst(*L) = llNil;
}

boolean llinfotypeNEQ(llinfotype a, llinfotype b){
    if(a.idx_penyanyi != b.idx_penyanyi){
        return true;
    }
    else if(a.idx_album != b.idx_album){
        return true;
    }
    else if(a.idx_lagu != b.idx_lagu){
        return true;
    }
    else if(!stringComp(a.nama_penyanyi, b.nama_penyanyi)){
        return true;
    }
    else if(!stringComp(a.nama_album, b.nama_album)){
        return true;
    }
    else if(!stringComp(a.nama_lagu, b.nama_lagu)){
        return true;
    }
    else{
        return false;
    }
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
lladdress llAlokasi (llinfotype X){
    lladdress P = (lladdress) malloc(sizeof(llElmtList));
    if(P != llNil){
        llInfo(P) = X;
        llNext(P) = llNil;
    }
    return P;
}
/* Mengirimkan lladdress hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka lladdress tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, llNext(P)=llNil */
/* Jika alokasi gagal, mengirimkan llNil */
void llDealokasi (lladdress *P){
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian lladdress P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
lladdress llSearch (lList L, llinfotype X){
    lladdress P = llFirst(L);
    while(P != llNil && llinfotypeNEQ(llInfo(P), X)){
        P = llNext(P);
    }
    return P;
}
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan lladdress elemen tersebut. */
/* Jika tidak ada, mengirimkan llNil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void llInsVFirst (lList *L, llinfotype X){
    lladdress P = llAlokasi(X);
    if(P != llNil){
        llNext(P) = llFirst(*L);
        llFirst(*L) = P;
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void llInsVLast (lList *L, llinfotype X){
    lladdress P = llAlokasi(X);
    if(P != llNil){
        if(IsEmpty(*L)){
            llFirst(*L) = P;
        }
        else{
            lladdress Last = llFirst(*L);
            while(llNext(Last) != llNil){
                Last = llNext(Last);
            }
            llNext(Last) = P;
        }
    }

}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void llDelVFirst (lList *L, llinfotype *X){
    lladdress P = llFirst(*L);
    *X = llInfo(P);
    llFirst(*L) = llNext(P);
    llNext(P) = llNil;
    llDealokasi(&P);
}
/* I.S. lList L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void llDelVLast (lList *L, llinfotype *X){
    lladdress Last = llFirst(*L);
    lladdress PrecLast = llNil;
    while(llNext(Last) != llNil){
        PrecLast = Last;
        Last = llNext(Last);
    }
    *X = llInfo(Last);
    if(PrecLast == llNil){
        llFirst(*L) = llNil;
    }
    else{
        llNext(PrecLast) = llNil;
    }
    llDealokasi(&Last);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void llInsertFirst (lList *L, lladdress P){
    llNext(P) = llFirst(*L);
    llFirst(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-lladdress P sebagai elemen pertama */
void llInsertAfter (lList *L, lladdress P, lladdress Prec){
    llNext(P) = llNext(Prec);
    llNext(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void llInsertLast (lList *L, lladdress P){
    if(IsEmpty(*L)){
        llFirst(*L) = P;
    }
    else{
        lladdress Last = llFirst(*L);
        while(llNext(Last) != llNil){
            Last = llNext(Last);
        }
        llNext(Last) = P;
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void llDelFirst (lList *L, lladdress *P){
    *P = llFirst(*L);
    llFirst(*L) = llNext(*P);
    llNext(*P) = llNil;
}
/* I.S. lList tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* llFirst element yg baru adalah suksesor elemen pertama yang lama */
void llDelP (lList *L, llinfotype X){
    lladdress P = llFirst(*L);
    lladdress Prec = llNil;
    while(P != llNil && llinfotypeNEQ(llInfo(P), X)){
        Prec = P;
        P = llNext(P);
    }
    if(P != llNil){
        if(Prec == llNil){
            llFirst(*L) = llNext(P);
        }
        else{
            llNext(Prec) = llNext(P);
        }
        llNext(P) = llNil;
        llDealokasi(&P);
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* lList mungkin menjadi kosong karena penghapusan */
void llDelLast (lList *L, lladdress *P){
    lladdress Last = llFirst(*L);
    lladdress PrecLast = llNil;
    while(llNext(Last) != llNil){
        PrecLast = Last;
        Last = llNext(Last);
    }
    *P = Last;
    if(PrecLast == llNil){
        llFirst(*L) = llNil;
    }
    else{
        llNext(PrecLast) = llNil;
    }
}
/* I.S. lList tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void llDelAfter (lList *L, lladdress *Pdel, lladdress Prec){
    *Pdel = llNext(Prec);
    llNext(Prec) = llNext(*Pdel);
    llNext(*Pdel) = llNil;
}
/* I.S. lList tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus llNext(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void llPrintInfo (lList L){
    lladdress P = llFirst(L);
    printf("[");
    while(P != llNil){
        printf("%s - %s - %s", P->info.nama_lagu, P->info.nama_album, P->info.nama_penyanyi);
        if(llNext(P) != llNil){
            printf(",");
        }
        P = llNext(P);
    }
    printf("]\n");
}
/* I.S. lList mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah terkecuali untuk newline di akhir output */
int llNbElmt (lList L){
    int count = 0;
    lladdress P = llFirst(L);
    while(P != llNil){
        count++;
        P = llNext(P);
    }
    return count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk llMax/llMin/rata-rata : lList tidak kosong ***/
// llinfotype llMax (lList L){
//     llinfotype max = llInfo(llFirst(L));
//     lladdress P = llNext(llFirst(L));
//     while(P != llNil){
//         if(llInfo(P) > max){
//             max = llInfo(P);
//         }
//         P = llNext(P);
//     }
//     return max;
// }
// /* Mengirimkan nilai info(P) yang maksimum */
// lladdress llAdrMax (lList L){
//     lladdress P = llFirst(L);
//     lladdress max = P;
//     while(P != llNil){
//         if(llInfo(P) > llInfo(max)){
//             max = P;
//         }
//         P = llNext(P);
//     }
//     return max;
// }
// /* Mengirimkan lladdress P, dengan info(P) yang bernilai maksimum */
// llinfotype llMin (lList L){
//     llinfotype min = llInfo(llFirst(L));
//     lladdress P = llNext(llFirst(L));
//     while(P != llNil){
//         if(llInfo(P) < min){
//             min = llInfo(P);
//         }
//         P = llNext(P);
//     }
//     return min;
// }
// /* Mengirimkan nilai info(P) yang minimum */
// lladdress llAdrMin (lList L){
//     lladdress P = llFirst(L);
//     lladdress min = P;
//     while(P != llNil){
//         if(llInfo(P) < llInfo(min)){
//             min = P;
//         }
//         P = llNext(P);
//     }
//     return min;
// }
// /* Mengirimkan lladdress P, dengan info(P) yang bernilai minimum */
// float llAverage (lList L){
//     float sum = 0;
//     int count = 0;
//     lladdress P = llFirst(L);
//     while(P != llNil){
//         sum += llInfo(P);
//         count++;
//         P = llNext(P);
//     }
//     return sum/count;
// }
/* Mengirimkan nilai rata-rata info(P) */

/****************** PROSES TERHADAP LIST ******************/

void llInversList (lList *L){
    lladdress P = llFirst(*L);
    lladdress Prec = llNil;
    lladdress NextP = llNil;
    while(P != llNil){
        NextP = llNext(P);
        llNext(P) = Prec;
        Prec = P;
        P = NextP;
    }
    llFirst(*L) = Prec;
}
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void llKonkat1 (lList *L1, lList *L2, lList *L3){
    llFirst(*L3) = llFirst(*L1);
    if(IsEmpty(*L1)){
        llFirst(*L3) = llFirst(*L2);
    }
    else{
        lladdress Last = llFirst(*L1);
        while(llNext(Last) != llNil){
            Last = llNext(Last);
        }
        llNext(Last) = llFirst(*L2);
    }
    llCreateEmpty(L1);
    llCreateEmpty(L2);

}
// /* I.S. L1 dan L2 sembarang */
// /* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
// /* Konkatenasi dua buah list : L1 dan L2    */
// /* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
// /* dan L1 serta L2 menjadi list kosong.*/
// /* Tidak ada alokasi/dealokasi pada prosedur ini */
// // void createPlaylist()
// // {
// //     int cnt;
// //     do
// //     {
// //         printf("Masukkan nama playlist yang ingin dibuat :");
// //         STARTLINE();
// //         cnt=0;
// //         for (int i=0; i<currentLine.Length; i++)
// //         {
// //             if(currentLine.TabWord[i]==' ') cnt++;
// //         }
// //         if(cnt<3) printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.");
// //     } while (cnt<3);
// //     lList ll;
// //     ll.linkedlistFirst=NULL;
// //     ll.namaPlaylist=currentLine;
// //     InsertLast(&Playlist, ll);
// //     printf("Playlist %s berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!", currentLine.TabWord);
// // }

// // void addSongtoPlaylist()
// // {
// //     printf("Daftar Penyanyi :");
// //     showPenyanyi(l);
// //     printf("Masukkan Nama Penyanyi yang dipilih :");
// //     STARTLINE();
// //     Line x=currentLine;
// //     printf("Daftar Album oleh %s :", x);
// //     showAlbum(x, l);
// //     printf("Masukkan Judul Album yang dipilih");
// //     char t[100];
// //     gets(t);
// //     Word y;
// //     y.Length=strlen(t);
// //     for (int i=0; i<strlen(t); i++) y.TabWord[i]=t[i];
// //     int idx;
// //     printf("Daftar Lagu Album %s oleh %s :",t,x);
// //     boolean diff=false;
// //     for (int i=0; i<l.Penyanyi.Count; i++)
// //     {
// //         if(strlen(x)!=l.Penyanyi.Elements[i].nama_penyanyi.Length) continue;
// //         for(int j=0; j<l.Penyanyi.Elements[i].nama_penyanyi.Length; j++)
// //         {
// //             if(l.Penyanyi.Elements[i].nama_penyanyi.TabWord[j]!=x[j]) diff=true;
// //         }
// //         if (diff=false)
// //         {
// //             idx=i;
// //             break;
// //         }
// //     }
// //     printf("Daftar Lagu Album %s oleh %s :",t,x);
// //     showLagu(y, idx, l);
// //     printf("Masukkan ID Lagu yang dipilih : ");
// //     int id;
// //     scanf("%d",&id);
// //     printf("Daftar Playlist Pengguna :");
// //     for (int i = 0; i < Playlist.Neff; i++) {
// //         printf("%d. %s\n", i + 1, Playlist.A[i].namaPlaylist.TabWord);
// //     }
// //     printf("Masukkan ID Playlist yang dipilih : ");
// //     int playlistID;
// //     scanf("%d", &playlistID);
// //     int idx2 = playlistID - 1;
// //     llElmtList newSong;
// //     llCreateEmpty((*newSong).linkedlistFirst);
// //     llInsVLast((*newSong).linkedlistFirst, y.TabWord);


// //     lList *chosenPlaylist = &((*Playlist).A[idx2]);
// //     llInsertLast(&((*chosenPlaylist).linkedlistFirst), newSong);
// //     printf("Lagu dengan judul %s pada album %s oleh penyanyi %s berhasil ditambahkan ke dalam playlist %s.", y.TabWord, l.Penyanyi.Elements[idx].album.Elements[y].nama_album.TabWord, l.Penyanyi.Elements[idx].nama_penyanyi.TabWord, Playlist.A[idx2].namaPlaylist.TabWord);
// // }

// // void addAlbumtoPlaylist()
// // {
// //     printf("Daftar Penyanyi :\n");
// //     showPenyanyi(l);
// //     printf("Masukkan Nama Penyanyi yang dipilih :");
// //     STARTLINE();
// //     Line x=currentLine;
// //     printf("Daftar Album oleh %s :", x);
// //     showAlbum(x, l);
// //     printf("Masukkan Judul Album yang dipilih");
// //     char t[100];
// //     gets(t);
// //     Word y;
// //     y.Length=strlen(t);
// //     for (int i=0; i<strlen(t); i++) y.TabWord[i]=t[i];
// //     printf("Daftar Playlist Pengguna :");
// //     for (int i = 0; i < Playlist.Neff; i++) {
// //         printf("%d. %s\n", i + 1, Playlist.A[i].namaPlaylist.TabWord);
// //     }
// //     printf("Masukkan ID Playlist yang dipilih : ");
// //     int playlistID;
// //     scanf("%d", &playlistID);
// //     int idx;
// //     boolean diff=false;
// //     for (int i=0; i<l.Penyanyi.Count; i++)
// //     {
// //         if(strlen(x)!=l.Penyanyi.Elements[i].nama_penyanyi.Length) continue;
// //         for(int j=0; j<l.Penyanyi.Elements[i].nama_penyanyi.Length; j++)
// //         {
// //             if(l.Penyanyi.Elements[i].nama_penyanyi.TabWord[j]!=x[j]) diff=true;
// //         }
// //         if (diff=false)
// //         {
// //             idx=i;
// //             break;
// //         }
// //     }
// //     int idx2 = playlistID - 1;

// //     llElmtList newAlbum;
// //     llCreateEmpty(&(newAlbum.linkedlistFirst));
// //     llInsVLast(newAlbum.linkedlistFirst, y.TabWord);
// //     lList *chosenPlaylist = &(Playlist.A[idx2]);
// //     llInsertLast(&(chosenPlaylist->linkedlistFirst), &newAlbum);

// //     printf("Album dengan judul %s berhasil ditambahkan ke dalam playlist %s.", l.Penyanyi.Elements[idx].album.Elements[y].nama_album.TabWord, Playlist.A[idx2].namaPlaylist.TabWord);
// // }

// // void swapPlaylist()
// // {
// //     int playlistID, id1, id2;
// //     if (playlistID < 1 || playlistID > Playlist.Neff) {
// //         printf("Tidak ada playlist dengan playlist ID %d", playlistID);
// //     }

// //     lList *playlist = &Playlist.A[playlistID - 1];
// //     lladdress currentNode1 = NULL;
// //     lladdress prevNode1 = NULL;
// //     lladdress currentNode2 = NULL;
// //     lladdress prevNode2 = NULL;
// //     lladdress tempNode = playlist.linkedlistFirst;

// //     // Traverse the playlist to find both songs with the given IDs
// //     while (tempNode != NULL) {
// //         if (tempNode.count == id1) {
// //             currentNode1 = tempNode;
// //             prevNode1 = prevNode2;
// //         }
// //         if (tempNode.count == id2) {
// //             currentNode2 = tempNode;
// //             prevNode2 = prevNode1;
// //         }

// //         prevNode1 = tempNode;
// //         tempNode = tempNode.next;
// //     }
// //     if (prevNode1 != NULL) {
// //         prevNode1.next = currentNode2;
// //     } else {
// //         playlist.linkedlistFirst = currentNode2;
// //     }

// //     if (prevNode2 != NULL) {
// //         prevNode2.next = currentNode1;
// //     } else {
// //         playlist.linkedlistFirst = currentNode1;
// //     }

// //     lladdress temp = currentNode1.next;
// //     currentNode1.next = currentNode2.next;
// //     currentNode2.next = temp;

// //     printf("Berhasil menukar lagu dengan nama %s dengan %s di playlist %s", album1.Elements[id1].TabWord, album1.Elements[id2].TabWord, playlist.namaPlaylist.TabWord);
// // }
// // void removePlaylist()
// // {
// //     /* Command PLAYLIST REMOVE digunakan untuk menghapus lagu dengan urutan n pada playlist dengan index id. */
// //     int playlistID, id;
// //     if (playlistID < 1 || playlistID > Playlist.Neff) {
// //         printf("Tidak ada playlist dengan playlist ID %d", playlistID);
// //     }
// //     lList *playlist = &Playlist.A[playlistID - 1];
// //     lladdress currentNode = playlist.linkedlistFirst;
// //     lladdress prevNode = NULL;

// //     while (currentNode != NULL && currentNode.count != id) {
// //         prevNode = currentNode;
// //         currentNode = currentNode.next;
// //     }
// //     if (prevNode != NULL) {
// //         prevNode.next = currentNode.next;
// //     } else {
// //         playlist.linkedlistFirst = currentNode.next;
// //     }
// //     free(currentNode); 
// //     printf("Lagu %s oleh %s telah dihapus dari playlist %s!", currentNode.Penyanyi.nama_penyanyi.TabWord, currentNode.Penyanyi.album.Elements[0].nama_album.TabWord, playlist.namaPlaylist.TabWord);
// // }

// // void deletePlaylist()
// // {
// //  /* Command PLAYLIST DELETE digunakan untuk melakukan penghapusan suatu existing playlist dalam daftar playlist pengguna. Tampilkan pesan error apabila masukkan pengguna tidak valid pada setiap permintaan masukkan. */
// //     printf("Daftar Playlist Pengguna : ");
// //     for (int i = 0; i < Playlist.Neff; i++) {
// //         printf("%d. %s\n", i + 1, Playlist.A[i].namaPlaylist.TabWord);
// //     }
// //     printf("Masukkan ID Playlist yang dipilih : ");
// //     int playlistID;
// //     scanf("%d", &playlistID);
// //     if (playlistID < 1 || playlistID > Playlist.Neff)
// //     {
// //         printf("Tidak ada playlist dengan ID %d dalam daftar playlist pengguna. Silakan coba lagi.", playlistID);
// //     }
// //     else{
// //         DeleteAt(&Playlist, playlistID);
// //         int idx2 = playlistID - 1;
// //         printf("Playlist ID %d dengan judul %s berhasil dihapus.", playlistID, Playlist.A[idx2].namaPlaylist.TabWord);
// //     }
// // }

// // void deletePlaylist()
// // {

// // }
