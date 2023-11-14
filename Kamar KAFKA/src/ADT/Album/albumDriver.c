#include <stdio.h>

#include "album.h"
#include "../Mesinkata/mesinkata.h"

int main(){
    SetAlbum s;
    albumCreateEmpty(&s);

    Word w;
    w = charToWord("ini string pertama");

    setInsert(&s, w);
    
    w = charToWord("ini string kedua");

    setInsert(&s, w);
    
    for(int i=0; i<s.Count; i++){
        printf("%s\n", s.Elements[i].TabWord);
    }
    return 0;
}