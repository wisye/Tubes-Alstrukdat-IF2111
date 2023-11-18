#include <stdio.h>

void startSpotify()
{
    int i = 0, j = 0, k = 0;
    FILE *file;

    file = fopen("save/config.txt");

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

    printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.");
}