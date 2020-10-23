#include <stdio.h>
/*
Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y, leaving the other bits unchanged.
*/
unsigned elimbits(unsigned x, int p, int n);
unsigned getbits(unsigned x,int p,int n);
unsigned setbits(unsigned x,int p,int n,unsigned y);
int main(){
        unsigned a=100;
        unsigned b=28;
        printf("%d\n",setbits(a,4,3,b));
}
unsigned getbits(unsigned x,int p,int n){
        return (x >> (p+1-n)) & ~(~0 << n);
}
unsigned elimbits(unsigned x, int p, int n){
        return x ^ (getbits(x,p,n)<<p+1-n);
}
unsigned setbits(unsigned x,int p,int n,unsigned y){
        return elimbits(x,p,n) | (getbits(y,p,n)<<p+1-n);
}
