#include <stdio.h>
#define MAXINPUT 1000
/*
Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
through 9, a through f, and A through F.
*/
int htois(char s[]);
int lower(int c);
int main(){
        int c;
        char in[MAXINPUT];
        int i=0;
        while( (c=getchar())!=EOF && i<MAXINPUT)
                in[i++]=c;
        printf("%i",htois(in));
        return 0;
}
int htois(char s[]){
        int n=0;
        for(int i=0;s[i]!='\0';s++){
                int c=lower(s[i]);
                if(s[i]>='0' && s[i]<='9')
                        n=n*16+(s[i]-'0');
                else if(c>='a' && c<='f')
                        n=n*16+(c-'a'+10);
        }
        return n;
}
int lower(int c){
        if (c >= 'A' && c <= 'Z')
                return c + 'a' - 'A';
        return c;
 }
