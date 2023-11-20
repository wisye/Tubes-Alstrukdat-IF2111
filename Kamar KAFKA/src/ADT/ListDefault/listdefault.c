#include "listdefault.h"

ListDefault ldMakeList(){
    // MapAlbum A;
    // mapCreateEmptyAlbum(&A);
    // MapPenyanyi P;
    // mapCreateEmpty(&P);
    ListDefault L;
    mapCreateEmpty(&L.Penyanyi);
    return L;
}