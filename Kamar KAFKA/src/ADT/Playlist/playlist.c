#include "playlist.h"
#include "../ListDinamis/arraydin.h"
#include "../ListDinamis/arraydin.c"
#include "../LinkedList/listlinier.h"
#include "../LinkedList/listlinier.c"
#include "../func/func.h"
#include "../func/func.c"
#include "../command/console.h"
#include "../command/console.c"
#include "boolean.h"
#include <string.h>

ArrayDin Playlist;

void createPlaylist()
{
    int cnt;
    do
    {
        printf("Masukkan nama playlist yang ingin dibuat :");
        STARTLINE();
        cnt=0;
        for (int i=0; i<currentLine.Length; i++)
        {
            if(currentLine.TabWord[i]==' ') cnt++;
        }
        if(cnt<3) printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.");
    } while (cnt<3);
    lList ll;
    ll.linkedlistFirst=NULL;
    ll.namaPlaylist=currentLine;
    InsertLast(&Playlist, ll);
    printf("Playlist %s berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!", currentLine.TabWord);
}

void addSongtoPlaylist()
{
    printf("Daftar Penyanyi :");
    showPenyanyi(l);
    printf("Masukkan Nama Penyanyi yang dipilih :");
    STARTLINE();
    Line x=currentLine;
    printf("Daftar Album oleh %s :", x);
    showAlbum(x, l);
    printf("Masukkan Judul Album yang dipilih");
    char t[100];
    gets(t);
    Word y;
    y.Length=strlen(t);
    for (int i=0; i<strlen(t); i++) y.TabWord[i]=t[i];
    int idx;
    printf("Daftar Lagu Album %s oleh %s :",t,x);
    boolean diff=false;
    for (int i=0; i<l.Penyanyi.Count; i++)
    {
        if(strlen(x)!=l.Penyanyi.Elements[i].nama_penyanyi.Length) continue;
        for(int j=0; j<l.Penyanyi.Elements[i].nama_penyanyi.Length; j++)
        {
            if(l.Penyanyi.Elements[i].nama_penyanyi.TabWord[j]!=x[j]) diff=true;
        }
        if (diff=false)
        {
            idx=i;
            break;
        }
    }
    printf("Daftar Lagu Album %s oleh %s :",t,x);
    showLagu(y, idx, l);
    printf("Masukkan ID Lagu yang dipilih : ");
    int id;
    scanf("%d",&id);
    printf("Daftar Playlist Pengguna :");
    for (int i = 0; i < Playlist.Neff; i++) {
        printf("%d. %s\n", i + 1, Playlist.A[i].namaPlaylist.TabWord);
    }
    printf("Masukkan ID Playlist yang dipilih : ");
    int playlistID;
    scanf("%d", &playlistID);
    int idx2 = playlistID - 1;
    llElmtList newSong;
    llCreateEmpty((*newSong).linkedlistFirst);
    llInsVLast((*newSong).linkedlistFirst, y.TabWord);


    lList *chosenPlaylist = &((*Playlist).A[idx2]);
    llInsertLast(&((*chosenPlaylist).linkedlistFirst), newSong);
    printf("Lagu dengan judul %s pada album %s oleh penyanyi %s berhasil ditambahkan ke dalam playlist %s.", y.TabWord, l.Penyanyi.Elements[idx].album.Elements[y].nama_album.TabWord, l.Penyanyi.Elements[idx].nama_penyanyi.TabWord, Playlist.A[idx2].namaPlaylist.TabWord);
}

void addAlbumtoPlaylist()
{
    printf("Daftar Penyanyi :\n");
    showPenyanyi(l);
    printf("Masukkan Nama Penyanyi yang dipilih :");
    STARTLINE();
    Line x=currentLine;
    printf("Daftar Album oleh %s :", x);
    showAlbum(x, l);
    printf("Masukkan Judul Album yang dipilih");
    char t[100];
    gets(t);
    Word y;
    y.Length=strlen(t);
    for (int i=0; i<strlen(t); i++) y.TabWord[i]=t[i];
    printf("Daftar Playlist Pengguna :");
    for (int i = 0; i < Playlist.Neff; i++) {
        printf("%d. %s\n", i + 1, Playlist.A[i].namaPlaylist.TabWord);
    }
    printf("Masukkan ID Playlist yang dipilih : ");
    int playlistID;
    scanf("%d", &playlistID);
    int idx;
    boolean diff=false;
    for (int i=0; i<l.Penyanyi.Count; i++)
    {
        if(strlen(x)!=l.Penyanyi.Elements[i].nama_penyanyi.Length) continue;
        for(int j=0; j<l.Penyanyi.Elements[i].nama_penyanyi.Length; j++)
        {
            if(l.Penyanyi.Elements[i].nama_penyanyi.TabWord[j]!=x[j]) diff=true;
        }
        if (diff=false)
        {
            idx=i;
            break;
        }
    }
    int idx2 = playlistID - 1;

    llElmtList newAlbum;
    llCreateEmpty(&(newAlbum.linkedlistFirst));
    llInsVLast(newAlbum.linkedlistFirst, y.TabWord);
    lList *chosenPlaylist = &(Playlist.A[idx2]);
    llInsertLast(&(chosenPlaylist->linkedlistFirst), &newAlbum);

    printf("Album dengan judul %s berhasil ditambahkan ke dalam playlist %s.", l.Penyanyi.Elements[idx].album.Elements[y].nama_album.TabWord, Playlist.A[idx2].namaPlaylist.TabWord);
}

void swapPlaylist()
{
    int playlistID, id1, id2;
    if (playlistID < 1 || playlistID > Playlist.Neff) {
        printf("Tidak ada playlist dengan playlist ID %d", playlistID);
    }

    lList *playlist = &Playlist.A[playlistID - 1];
    lladdress currentNode1 = NULL;
    lladdress prevNode1 = NULL;
    lladdress currentNode2 = NULL;
    lladdress prevNode2 = NULL;
    lladdress tempNode = playlist.linkedlistFirst;

    // Traverse the playlist to find both songs with the given IDs
    while (tempNode != NULL) {
        if (tempNode.count == id1) {
            currentNode1 = tempNode;
            prevNode1 = prevNode2;
        }
        if (tempNode.count == id2) {
            currentNode2 = tempNode;
            prevNode2 = prevNode1;
        }

        prevNode1 = tempNode;
        tempNode = tempNode.next;
    }
    if (prevNode1 != NULL) {
        prevNode1.next = currentNode2;
    } else {
        playlist.linkedlistFirst = currentNode2;
    }

    if (prevNode2 != NULL) {
        prevNode2.next = currentNode1;
    } else {
        playlist.linkedlistFirst = currentNode1;
    }

    lladdress temp = currentNode1.next;
    currentNode1.next = currentNode2.next;
    currentNode2.next = temp;

    printf("Berhasil menukar lagu dengan nama %s dengan %s di playlist %s", album1.Elements[id1].TabWord, album1.Elements[id2].TabWord, playlist.namaPlaylist.TabWord);
}
void removePlaylist()
{
    /* Command PLAYLIST REMOVE digunakan untuk menghapus lagu dengan urutan n pada playlist dengan index id. */
    int playlistID, id;
    if (playlistID < 1 || playlistID > Playlist.Neff) {
        printf("Tidak ada playlist dengan playlist ID %d", playlistID);
    }
    lList *playlist = &Playlist.A[playlistID - 1];
    lladdress currentNode = playlist.linkedlistFirst;
    lladdress prevNode = NULL;

    while (currentNode != NULL && currentNode.count != id) {
        prevNode = currentNode;
        currentNode = currentNode.next;
    }
    if (prevNode != NULL) {
        prevNode.next = currentNode.next;
    } else {
        playlist.linkedlistFirst = currentNode.next;
    }
    free(currentNode); 
    printf("Lagu %s oleh %s telah dihapus dari playlist %s!", currentNode.Penyanyi.nama_penyanyi.TabWord, currentNode.Penyanyi.album.Elements[0].nama_album.TabWord, playlist.namaPlaylist.TabWord);
}

void deletePlaylist()
{
 /* Command PLAYLIST DELETE digunakan untuk melakukan penghapusan suatu existing playlist dalam daftar playlist pengguna. Tampilkan pesan error apabila masukkan pengguna tidak valid pada setiap permintaan masukkan. */
    printf("Daftar Playlist Pengguna : ");
    for (int i = 0; i < Playlist.Neff; i++) {
        printf("%d. %s\n", i + 1, Playlist.A[i].namaPlaylist.TabWord);
    }
    printf("Masukkan ID Playlist yang dipilih : ");
    int playlistID;
    scanf("%d", &playlistID);
    if (playlistID < 1 || playlistID > Playlist.Neff)
    {
        printf("Tidak ada playlist dengan ID %d dalam daftar playlist pengguna. Silakan coba lagi.", playlistID);
    }
    else{
        DeleteAt(&Playlist, playlistID);
        int idx2 = playlistID - 1;
        printf("Playlist ID %d dengan judul %s berhasil dihapus.", playlistID, Playlist.A[idx2].namaPlaylist.TabWord);
    }
}

void deletePlaylist()
{

}
