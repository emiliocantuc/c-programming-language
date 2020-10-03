#include <stdio.h>
#define MAXLINE 1000 /* maximum PRINTABLE input line length */
 int my_getline(char s[], int lim);
 int remove_trailing(char c[],int len);
 int main(){
         int len; /* current line length */
         char line[MAXLINE]; /* current input line */
         while ((len = my_getline(line, MAXLINE)) > 0){
                len=remove_trailing(line,len);
                printf("%s\n",line);
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
 int remove_trailing(char c[],int len){
         int i;
         for(i=len-2;c[i]==' '||c[i]=='\t';i--);
         printf("%d",i);
         c[i+1]='\n';
         c[i+2]='\0';
         return i;
 }
