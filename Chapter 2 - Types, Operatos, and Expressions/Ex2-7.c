#include <stdio.h>
/*
Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y, leaving the other bits unchanged.
*/
unsigned elimbits(unsigned x, int p, int n);
unsigned getbits(unsigned x,int p,int n);
unsigned invert(unsigned x,int p,int n);
int main(){
        unsigned a=1;
        printf("%u\n",invert(a,4,3));
}
unsigned getbits(unsigned x,int p,int n){
        return (x >> (p+1-n)) & ~(~0 << n);
}
unsigned elimbits(unsigned x, int p, int n){
        return x ^ (getbits(x,p,n)<<p+1-n);
}
unsigned invert(unsigned x,int p,int n){
        return elimbits(x,p,n) | ((~getbits(x,p,n)^(~0<<n))<<p+1-n);
}
