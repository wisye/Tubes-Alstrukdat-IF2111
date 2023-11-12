#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>
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
    while(P != llNil && llInfo(P) != X){
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
    while(P != llNil && llInfo(P) != X){
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
        printf("%d", llInfo(P));
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
llinfotype llMax (lList L){
    llinfotype max = llInfo(llFirst(L));
    lladdress P = llNext(llFirst(L));
    while(P != llNil){
        if(llInfo(P) > max){
            max = llInfo(P);
        }
        P = llNext(P);
    }
    return max;
}
/* Mengirimkan nilai info(P) yang maksimum */
lladdress llAdrMax (lList L){
    lladdress P = llFirst(L);
    lladdress max = P;
    while(P != llNil){
        if(llInfo(P) > llInfo(max)){
            max = P;
        }
        P = llNext(P);
    }
    return max;
}
/* Mengirimkan lladdress P, dengan info(P) yang bernilai maksimum */
llinfotype llMin (lList L){
    llinfotype min = llInfo(llFirst(L));
    lladdress P = llNext(llFirst(L));
    while(P != llNil){
        if(llInfo(P) < min){
            min = llInfo(P);
        }
        P = llNext(P);
    }
    return min;
}
/* Mengirimkan nilai info(P) yang minimum */
lladdress llAdrMin (lList L){
    lladdress P = llFirst(L);
    lladdress min = P;
    while(P != llNil){
        if(llInfo(P) < llInfo(min)){
            min = P;
        }
        P = llNext(P);
    }
    return min;
}
/* Mengirimkan lladdress P, dengan info(P) yang bernilai minimum */
float llAverage (lList L){
    float sum = 0;
    int count = 0;
    lladdress P = llFirst(L);
    while(P != llNil){
        sum += llInfo(P);
        count++;
        P = llNext(P);
    }
    return sum/count;
}
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
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */