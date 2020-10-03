#include <stdio.h>
 #define MAXLINE 1000 /* maximum PRINTABLE input line length */
 int my_getline(char s[], int lim);
 /* print the longest input line */
 int main(){
         int len; /* current line length */
         char line[MAXLINE]; /* current input line */
         while ((len = my_getline(line, MAXLINE)) > 0)
                if (len > 80)
                        printf("%s",line);
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
