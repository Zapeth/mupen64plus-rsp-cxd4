#include "vu.h"

INLINE void do_xor(short* VD, short* VS, short* VT)
{
    register int i;

    for (i = 0; i < N; i++)
        VACC_L[i] = VS[i] ^ VT[i];
    vector_copy(VD, VACC_L);
    return;
}

static void VXOR(int vd, int vs, int vt, int e)
{
    short ST[N];

    SHUFFLE_VECTOR(ST, VR[vt], e);
    do_xor(VR[vd], VR[vs], ST);
    return;
}
