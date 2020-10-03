#include <stdio.h>
 #define MAXLINE 1000 /* maximum PRINTABLE input line length */
 int my_getline(char s[], int lim);
 void my_copy(char to[], char from[]);
 /* print the longest input line */
 int main(){
         int len; /* current line length */
         int max; /* maximum length seen so far */
         char line[MAXLINE]; /* current input line */
         char longest[MAXLINE]; /* longest line saved here */
         max = 0;
         while ((len = my_getline(line, MAXLINE)) > 0)
                if (len > max) {
                         max = len;
                         my_copy(longest, line);
                 }
         if (max > 0) /* there was a line */
         printf("len: %d, line: %s", max,longest);
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
 /* my_copy: my_copy 'from' into 'to'; assume to is big enough */
 void my_copy(char to[], char from[]){
         int i;
         i = 0;
         while ((to[i] = from[i]) != '\0')
                ++i;
 }
