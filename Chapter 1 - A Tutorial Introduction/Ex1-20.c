#include <stdio.h>
#define MAXLINE 1000
/*
Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter?
*/
int my_getline(char s[], int lim);
void detab(char s[],int len,int tabStop);
void my_copy(char to[],char from[]);
int main(){
        int len; /* current line length */
        char line[MAXLINE]; /* current input line */
        while ((len = my_getline(line, MAXLINE)) > 0){
               detab(line,len,4);
               printf("%s",line);
        }
        return 0;
}
/* my_getline: read a PRINTABLE line into s, return total length */
int my_getline(char s[],int lim){
        int c, i;
        for (i=0;(c=getchar())!=EOF && c!='\n'; ++i)
               if(i < lim-1)
                       s[i] = c;
        if (c == '\n') {
               s[i] = c;
               ++i;
        }
        s[i] = '\0';
        return i;
}
void detab(char c[],int len,int tabStop){
        char temp[len];
        my_copy(temp,c);
        int i;
        int k=0;
        for(i=0;temp[k]!='\0';k++){
                if(temp[k]!='\t')
                        c[i++]=temp[k];
                else{
                        for(int j=0;j<tabStop;j++)
                                c[i++]=' ';
                }
        }
        c[i]='\0';
}
void my_copy(char to[], char from[]){
        int i;
        i = 0;
        while ((to[i] = from[i]) != '\0')
               ++i;
}
