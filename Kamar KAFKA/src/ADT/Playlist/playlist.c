#include "playlist.h"
#include "../List Dinamis/arraydin.h"
#include "../List Dinamis/arraydin.c"
#include "../LinkedList/listlinier.h"
#include "../LinkedList/listlinier.c"
#include "../func/func.h"
#include "../func/func.c"
#include "../command/console.h"
#include "../command/console.c"
#include <string.h>

ArrayDin Playlist;

void createPlaylist()
{
    int cnt = 0;
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

    ll.namaPlaylist = currentLine;
    InsertLast(&Playlist, ll);
    printf("Playlist %s berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!", currentLine.TabWord);
}

void addSongtoPlaylist()
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
    printf("%s", Playlist);
    lList playlistSong;
    llCreateEmpty(&playlistSong);
    llInsVLast(&playlistSong, y.TabWord);
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
    printf("%s", Playlist);
    lList playlistSong;
    llCreateEmpty(&playlistSong);
    llInsVLast(&playlistSong, x.TabWord);
}

void swapPlaylist()
{

}
void removePlaylist()
{
    /* Command PLAYLIST REMOVE digunakan untuk menghapus lagu dengan urutan n pada playlist dengan index id. */

    
}

void deletePlaylist()
{

}