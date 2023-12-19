#include "secret.h"
 
const int MAXN = 1e3+1;
int SRQ[MAXN][MAXN];
int Arrl[MAXN];
int globul;
 
void initTree(int l, int r){
    if (l == r)return;
    int mid = (l+r)>>1;
    SRQ[mid][mid] = Arrl[mid];
    SRQ[mid+1][mid+1] = Arrl[mid+1];
    for (int i = mid-1; i >= l; i--){
        SRQ[mid][i] = Secret(Arrl[i], SRQ[mid][i+1]);
    }
    for (int i = mid+2; i <= r; i++){
        SRQ[mid+1][i] = Secret(SRQ[mid+1][i-1], Arrl[i]);
    }
    initTree(l, mid);
    initTree(mid+1, r);
}
 
int followInit(int l, int r, int wL, int wR){
    int mid = (l+r)>>1;
    if (mid >= wL && mid < wR)return Secret(SRQ[mid][wL], SRQ[mid+1][wR]);
    if (mid == wR){
        return SRQ[mid][wL];
    }
    if (l == r)return SRQ[0][0];
    if (mid < wL){
        return followInit(mid+1, r, wL, wR);
    }
    return followInit(l, mid, wL, wR);
}
 
void Init(int N, int A[]){
    for (int i = 0; i < N; i++){
        Arrl[i] = A[i];
    }
    globul = N;
    initTree(0, N-1);
}
 
int Query(int L, int R){
    return followInit(0, globul-1, L, R);
}
