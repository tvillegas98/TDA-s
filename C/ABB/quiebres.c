#include "ab.h"
#include <stdbool.h>

size_t _ab_quiebres(const ab_t* ab, bool IZQ, bool DER){
    if(!ab) return 0;

    if(ab->der && !ab->izq && IZQ){
        return 1 + _ab_quiebres(ab->der, false, true);
    }else if(ab->izq && !ab->der && DER){
        return 1 + _ab_quiebres(ab->izq, true, false);
    }

    return _ab_quiebres(ab->izq, true, false) + _ab_quiebres(ab->der, false, true);
}

size_t ab_quiebres(const ab_t* ab) {
    if(!ab) return 0;

    if(ab->izq || ab->der){
        return _ab_quiebres(ab->izq, true, false) + _ab_quiebres(ab->der, false, true);
    }

    return 0;
}