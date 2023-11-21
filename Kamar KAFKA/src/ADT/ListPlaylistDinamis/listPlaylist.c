#include <stdio.h>
#include <stdlib.h>
#include "listPlaylist.h"
#include "../boolean.h"

/*
 * Fungsi untuk melakukan print suatu ListPlaylist.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void lpPrintArrayDin(ListPlaylist array) {
	// KAMUS
	IdxType j;
	// ALGORITMA
	printf("[");
	for (j = 0; j < (array).Neff; j++) {
		printf("%s", (array).A[j].namaPlaylist.TabWord);
		if (j != (array).Neff -1) {
			printf(", ");
		}
	}
	printf("]\n");
}

void PrintPlaylist(ListPlaylist array) {
	// KAMUS
	IdxType j;
	// ALGORITMA
    if(array.Neff == 0){
		printf("Daftar playlist yang kamu miliki: ");
        printf("Kamu tidak memiliki playlist.\n");
    } else {
		printf("Daftar playlist yang kamu miliki:\n");
        for (j = 0; j < (array).Neff; j++) {
            printf("%d. %s\n", j+1, (array).A[j].namaPlaylist.TabWord);
			llPrintInfo(array.A[j]);
        }
    }
	

}
/*
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ListPlaylist kosong dengan ukuran InitialSize
 */
ListPlaylist MakeArrayDin(){
	// KAMUS
	ListPlaylist array;
	// ALGORITMA
	array.A = (ElType*) malloc (InitialSize*sizeof(ElType));
	array.Neff = 0; array.Capacity = InitialSize;
	return array;
}

/*
 * Destruktor
 * I.S. ListPlaylist terdefinisi
 * F.S. array->A terdealokasi
 */
void lpDeallocateArrayDin(ListPlaylist *array) {
	// KAMUS
	// ALGORITMA
	free((*array).A); (*array).Neff = 0;
}

/*
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean lpIsEmpty(ListPlaylist array) {
	// KAMUS
	// ALGORITMA
	return array.Neff == 0;
}

/*
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int lpLength(ListPlaylist array) {
	// KAMUS
	// ALGORITMA
	return array.Neff;
}

/*
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType lpGet(ListPlaylist array, IdxType i) {
	// KAMUS
	// ALGORITMA
	return array.A[i];
}

/*
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int lpGetCapacity(ListPlaylist array) {
	// KAMUS
	// ALGORITMA
	return array.Capacity;
}

/*
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void lpInsertAt(ListPlaylist *array, ElType el, IdxType i) {
	// KAMUS
	// ALGORITMA
	    int j;
    if ((*array).Neff < (*array).Capacity)
    {
        for (j = (*array).Neff; j >= i + 1; j--)
        {
            (*array).A[j] = (*array).A[j - 1];
        }
        (*array).A[i] = el;
        (*array).Neff += 1;
    }
    else
    {
        ElType *temp = (ElType *)malloc((*array).Capacity* sizeof(ElType));
        for (j = 0; j < (*array).Capacity; j++)
        {
            temp[j] = (*array).A[j];
        }
        free((*array).A);
        (*array).A = (ElType *)malloc(((*array).Capacity * 2 ) *sizeof(ElType));
        for (j = 0; j < i; j++)
        {
            (*array).A[j] = temp[j];
        }
        (*array).A[i] = el;
        for (j = i; j < (*array).Capacity; j++)
        {
            (*array).A[j + 1] = temp[j];
        }
        free(temp);
        (*array).Capacity *= 2;
        (*array).Neff += 1;
    }
}

/*
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void lpInsertLast(ListPlaylist *array, ElType el) {
	// KAMUS
	// ALGORITMA
	lpInsertAt(array, el,(*array).Neff);
}

/*
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void lpInsertFirst(ListPlaylist *array, ElType el) {
	// KAMUS
	// ALGORITMA
	lpInsertAt(array, el, 0);
}

/*
 * Fungsi untuk menghapus elemen di index ke-i ListPlaylist
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void lpDeleteAt(ListPlaylist *array, IdxType i) {
	// KAMUS
	// ALGORITMA
    int j;
    ElType e = lpGet(*array, i);
    if ((*array).Neff > ((*array).Capacity / 4))
    {
        (*array).Neff -= 1;
        for (j = i; j < (*array).Neff; j++)
        {
            (*array).A[j] = (*array).A[j + 1];
        }
    } 
    else
    {
        int Bcapacity = InitialSize;
        if (Bcapacity < ((*array).Capacity / 2)) Bcapacity = (*array).Capacity / 2;
        ElType *temp = (ElType *)malloc(Bcapacity * sizeof(ElType));
        for (j = 0; j < i; j++)
        {
            temp[j] = (*array).A[j];
        }
        (*array).Neff -= 1;
        for (j = i; j < (*array).Neff; j++)
        {
            temp[j] = (*array).A[j + 1];
        }
        free((*array).A);
        (*array).A = (ElType *)malloc(Bcapacity * sizeof(ElType));
        for (j = 0; j < (*array).Neff; j++)
        {
            (*array).A[j] = temp[j];
        }
        (*array).Capacity = Bcapacity;
        free(temp);
    }
}

/*
 * Fungsi untuk menghapus elemen terakhir ListPlaylist
 * Prekondisi: array tidak kosong
 */
void lpDeleteLast(ListPlaylist *array) {
	// KAMUS
	// ALGORITMA
	lpDeleteAt(array, (*array).Neff-1);
}

/*
 * Fungsi untuk menghapus elemen pertama ListPlaylist
 * Prekondisi: array tidak kosong
 */
void lpDeleteFirst(ListPlaylist *array) {
	// KAMUS
	// ALGORITMA
	lpDeleteAt(array, 0);
}


	
/*
 * Fungsi untuk melakukan reverse suatu ListPlaylist.
 * Prekondisi: array terdefinisi
 */
void lpReverseArrayDin(ListPlaylist *array) {
	// KAMUS
	IdxType j;
	ElType *temp = (ElType*) malloc ((*array).Capacity * sizeof(ElType));
	// ALGORITMA
	for (j = 0; j < (*array).Neff; j++) {
		temp[j] = (*array).A[(*array).Neff - (1+j)];
	}
	for (j = 0; j < (*array).Neff; j++) {
		(*array).A[j] = temp[j];
	}
	free(temp);
}

// void lpPrintIsiPlaylist(ListPlaylist array){

// }	
/*
 * Fungsi untuk melakukan copy suatu ListPlaylist.
 * Prekondisi: array terdefinisi
 */
ListPlaylist lpCopyArrayDin(ListPlaylist array) {
	// KAMUS
	ListPlaylist newArray;
	IdxType j;
	// ALGORITMA
	newArray.A = (ElType*) malloc (array.Capacity * sizeof(ElType));
	newArray.Capacity = array.Capacity; newArray.Neff = array.Neff;
	for (j = 0; j < newArray.Neff; j++) {
		newArray.A[j] = array.A[j];
	}
	return newArray;
}

/*
 * Fungsi untuk melakukan search suatu ListPlaylist.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */

// SearchArrayDin GATAU BUTUH APA ENGGA, COBA CEK DONG WISYE CUZ MASI MERAH -ELEN

IdxType lpSearchArrayDin(ListPlaylist array, Line el) {
	// KAMUS
	IdxType j = 0; 
	// ALGORITMA
	while ((stringComp(array.A[j].namaPlaylist.TabWord, el.TabWord)) && (j <= (array).Neff)) {
		j++;
	}
	if (j > (array).Neff) {
		j = -1;
	}
	return j;
}
