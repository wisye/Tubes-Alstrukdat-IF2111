#include <stdio.h>

#include "album.h"
#include "../Mesinkata/mesinkata.h"

int main(){
    // how to run?
    // gcc albumDriver.c ../Mesinkata/mesinkata.c ../Mesinkarakter/mesinkarakter.c album.c
    
    SetAlbum s;
    albumCreateEmpty(&s);

    Line w;
    w = charToLine("ini string pertama");

    setInsert(&s, w);
    
    w = charToLine("ini string kedua");

    setInsert(&s, w);
    
    for(int i=0; i<s.Count; i++){
        printf("%s\n", s.Elements[i].TabWord);
    }
    return 0;
}