#include <stdio.h>
#define MAXLINE 1000
#define IN 1
#define OUT 0
/*
Write a program entab that replaces strings of blanks by the minimum
number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
When either a tab or a single blank would suffice to reach a tab stop, which should be given
preference?
*/
int my_getline(char s[], int lim);
void entab(char s[],int len,int tabStop);
void my_copy(char to[],char from[]);
int main(){
        int len; /* current line length */
        char line[MAXLINE]; /* current input line */
        while ((len = my_getline(line, MAXLINE)) > 0){
               entab(line,len,4);
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
void entab(char c[],int len,int tabStop){
        char temp[len];
        my_copy(temp,c);
        int state=OUT; //not currently counting spaces
        int i=0; //c index
        int spaces=0; //first space index
        for(int k=0;temp[k]!='\0';k++){
                if(temp[k]==' ' && state==OUT){
                        state=IN;
                        spaces=1;
                }else if(temp[k]==' ' && state==IN){
                        ++spaces;
                }else if(temp[k]!=' ' && state==IN){
                        state=OUT;
                        for(int j=0;j<(spaces/tabStop);j++)
                                c[i++]='\t';
                        for(int j=0;j<(spaces%tabStop);j++)
                                c[i++]=' ';
                        c[i++]=temp[k];
                }else{
                        c[i++]=temp[k];
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
