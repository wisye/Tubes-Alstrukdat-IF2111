// #include "func.h"
// #include "../ADT_H/boolean.h"
// #include "../ADT_H/mesinkata.h"
// #include "../ADT_H/list.h"
// #include "../ADT_H/queue.h"
// #include "../ADT_H/stack.h"
// #include "../ADT_H/moreADT.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include "../ADT_H/boolean.h"
#include "../ADT/Mesinkarakter/mesinkarakter.h"
#include "../ADT/Mesinkata/mesinkata.h"
#include "../ADT/List/list.h"
#include "../ADT/Queue/queue.h"
#include "../ADT/Stack/stack.h"
#include "../ADT/func/func.h"
#include "../ADT/LinkedList/listlinier.h"
#include "../ADT/Album/album.h"
#include "../ADT/globalvar/globalvar.h"
#include "../ADT/Penyanyi/penyanyi.h"
#include "../ADT/ListDinamis/arraydin.h"
#include "../ADT/ListPlaylistDinamis/listPlaylist.h"
#include <stdio.h>
#include <stdlib.h>


#ifndef CONSOLE_H
#define CONSOLE_H

void startSpotify();
/*Dibaca file konfigurasi default yang berisi daftar penyanyi serta album yang dimiliki*/

int loadSpotify();
/*Dibaca save file input yang berisi list game yang dapat dimainkan, histori, dan scoreboard game*/

void listSpotify();
/*Menampilkan list penyanyi yang ada jika LIST DEFAULT
  Menampilkan list playlist yang ada pada pengguna jika LIST PLAYLIST*/

void playSpotify();
/*Memainkan lagu yang dipilih jika PLAY SONG
  Memainkan lagu berdasar id playlist jika PLAY PLAYLIST*/

void queueSpotify(Queue *q);
/*Menambahkan lagu kedalam queue jika QUEUE SONG
  Menambahkan playlist dalam queue jika QUEUE PLAYLIST
  Menukar lagu pada urutan <x> <y> jika QUEUE SWAP <x> <y>
  Menghapus lagu dari queue jika QUEUE REMOVE id
  Mengosongkan queue jika QUEUE CLEAR*/

void songSpotify();
/*Memutar lagu yang berada di dalam queue SONG NEXT, lagu yang sedang diputar kemudian ditambah kedalam
    daftar riwayat putar lagu, jika queue kosong yang diputar adalah lagu yang sedang diputar
  Memutar lagu yang terakhir kali diputa jika SONG PREVIOUS, lagu yang sedang diputar ditambahkan ke queue
    , jika riwayat lagu kosong yang diputar adalah lagu yang sedang diputar*/

void playlistSpotify();
/*Membuat playlist baru dan ditambahkan pada daftar list pengguna jika PLAYLIST CREATE
  Menambahkan lagu pada playlist yang sudah ada jika PLAYLIST ADD
  Menukar lagu pada urutan ke x y di playlist dengan urutan ke id jika PLAYLIST SWAP <id> <x> <y>
  Menghapus lagu dengan urutan n pada playlist dengan indeks id jika PLAYLIST REMOVE <id> <n>
  Menghapus suatu existing playlist jika PLAYLIST DELETE , tampilkan error jika id tidak valid*/

void statusSpotify();
/*Menampilkan lagu yang sedang dimainkan beserta queue song yang ada dan dari playlist mana lagu itu diputar*/

void saveSpotify();
/*Menyimpan state aplikasi terbaru kedalam suatu file jika SAVE <filename>*/

void quitSpotify();
/*Keluar dari sesi aplikasi WayangWave (SPOTIFY)*/

void helpSpotify();
/*Menampilkan daftar command yang mungkin untuk dieksekusi dengan deskripsinya*/



#endif