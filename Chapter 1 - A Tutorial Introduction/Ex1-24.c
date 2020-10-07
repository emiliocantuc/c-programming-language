#include <stdio.h>
#define MAXINPUT 1000
/*
Write a program to check a C program for rudimentary syntax errors like
unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
double, escape sequences, and comments. (This program is hard if you do it in full
generality.)
*/
int checkSyntax(char c[],int len); //returns 1 if syntax correct, 0 otherwise.
int main(){
        int c;
        int len=0;
        char in[MAXINPUT];
        while ((c=getchar())!=EOF && len<MAXINPUT){
                in[len++]=c;
        }
        if(checkSyntax(in,len))
                printf("Correct syntax\n");
        else
                printf("Incorrect syntax\n");
        return 0;
}
int checkSyntax(char c[],int len){
        int parentheses,brackets,braces,singleQ,doubleQ;
        parentheses=brackets=braces=singleQ=doubleQ=0;
        int oneLineComment,multiComment,inQuote;
        oneLineComment=multiComment=inQuote=0;
        for(int i=0;i<len;i++){
                if(oneLineComment && c[i]=='\n')
                        oneLineComment=0;
                else if(multiComment && c[i]=='*' && c[i+1]=='/')
                        multiComment=0;
                else if(c[i]=='/' && c[i+1]=='/' && !oneLineComment && !inQuote)
                        oneLineComment=1;
                else if(c[i]=='/' && c[i+1]=='*' && !multiComment && !inQuote)
                        multiComment=1;
                else if(c[i]=='\"'){
                        inQuote=!inQuote;
                        doubleQ++;
                }
                else if(oneLineComment || multiComment || inQuote)
                        continue;
                else if(c[i]=='(')
                        parentheses++;
                else if(c[i]==')')
                        parentheses--;
                else if(c[i]=='[')
                        brackets++;
                else if(c[i]==']')
                        brackets--;
                else if(c[i]=='{')
                        braces++;
                else if(c[i]=='}')
                        braces--;
                else if(c[i]=='\'')
                        singleQ++;
        }
        return (singleQ%2== 0 && doubleQ%2==0 && parentheses==0 && brackets==0 && braces==0);
}
