#include <stdio.h>
#define MAXINPUT 1000
/*
Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest.
*/
void removeComments(char c[],int len);
void my_copy(char to[],char from[]);
int main(){
        int c;
        int len=0;
        char in[MAXINPUT];
        while ((c=getchar())!=EOF && len<MAXINPUT){
                in[len++]=c;
        }
        removeComments(in,MAXINPUT);
        printf("%s",in);
        return 0;
}
void removeComments(char c[],int len){
        char temp[len];
        my_copy(temp,c);
        int quote=0;
        int i=0; //c index
        for(int k=0;temp[k]!=EOF;k++){
                if(temp[k]=='\"' || temp[k]=='\''){
                        quote=!quote;
                        c[i++]=temp[k];
                }else if(!quote && temp[k]=='/' && temp[k+1]=='/'){
                        for(;temp[k]!='\n';k++);
                        k--;
                }else if(!quote && temp[k]=='/' && temp[k+1]=='*'){
                        for(k=k+2;temp[k]!='*' && temp[k+1]!='/';k++);
                        k++;
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
