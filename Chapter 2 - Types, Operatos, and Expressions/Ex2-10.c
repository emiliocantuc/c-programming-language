#include <stdio.h>
#define MAXINPUT 1000
/*
Rewrite the function lower, which converts upper case letters to lower case,
with a conditional expression instead of if-else.
*/
int lower(int c);
int main(){
        char in[MAXINPUT];
        int c;
        int len=0;
        while((c=getchar())!=EOF && len<MAXINPUT)
                in[len++]=lower(c);
        printf("%s",in);
}
int lower(int c){
        return (c>='A' && c<='Z') ? c+'a'-'A':c;
}
/*
int lower(int c){
        if(c>='A' && c<='Z')
                return c + 'a' - 'A';
        else
                return c;
}
*/
