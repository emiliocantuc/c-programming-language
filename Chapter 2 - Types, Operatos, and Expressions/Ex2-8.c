#include <stdio.h>
/*
Write a function rightrot(x,n) that returns the value of the integer x rotated
to the right by n positions.
*/
unsigned rightrot(unsigned x,int n);
int main(){
        unsigned a=1;
        printf("%u\n",rightrot(a,2));
}
unsigned rightrot(unsigned x,int n){
        int s=(sizeof(x)*8)-1; //left shift equivalent of 1 right shift.
        for(int i=0;i<n;i++){
                if(x & 1 == 1)
                        x=(x>>1)|(1<<s);
                else
                        x=x>>1;
        }
        return x;
}
