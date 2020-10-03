#include <stdio.h>
#define MAXLINE 1000 /* maximum PRINTABLE input line length */
 int my_getline(char s[], int lim);
 void reverse(char c[],int len);
 void my_copy(char to[],char from[]);
 int main(){
         int len; /* current line length */
         char line[MAXLINE]; /* current input line */
         while ((len = my_getline(line, MAXLINE)) > 0){
                reverse(line,len);
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
 void reverse(char c[],int len){
         char temp[len];
         my_copy(temp,c);
         int k=0;
         for(int i=len-2;i>=0;i--)
                c[i]=temp[k++];
 }
 void my_copy(char to[], char from[]){
         int i;
         i = 0;
         while ((to[i] = from[i]) != '\0')
                ++i;
 }
