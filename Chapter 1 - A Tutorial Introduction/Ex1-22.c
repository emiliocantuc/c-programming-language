#include <stdio.h>
#define MAXINPUT 1000
/*
Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column.
*/
void fold(char s[],int len,int n);
int main(){
        int c;
        int len=0;
        char in[MAXINPUT];
        while ((c=getchar())!=EOF && len<MAXINPUT){
                in[len++]=c;
        }
        fold(in,len,10);
        return 0;
}
//Will just print lines, won't return array of lines
void fold(char c[],int len,int n){
        int k;
        int i=n;
        do{
                int j=i;
                while((c[j]!=' ' && j>i-n))
                        j--;
                if(j<=i-n){ //if no blanks or tabs before spef. column
                        for(k=i-n;k<i;k++)
                                putchar(c[k]);
                        putchar('-');
                        i+=n;
                }else{
                        for(k=i-n;k<j;k++)
                                putchar(c[k]);
                        k++;
                        i=j+n+1;
                }
                putchar('\n');

        }while(i<len);
        for(;k<len;k++)
                putchar(c[k]);
}
