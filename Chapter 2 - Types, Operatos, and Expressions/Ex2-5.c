#include <stdio.h>
#define MAXINPUT 1000
/*
Write the function any(s1,s2), which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
(The standard library function strpbrk does the same job but returns a pointer to the
location.)
*/
int any(char s1[],char s2[]);
int main(){
        char s1[MAXINPUT]="hello";
        char s2[MAXINPUT]="bye";
        printf("%i\n",any(s1,s2));
}
int any(char s1[],char s2[]){
        for(int i=0;s1[i]!='\0';i++){
                for(int k=0;s2[k]!='\0';k++){
                        if(s1[i]==s2[k])
                                return i;
                }
        }
        return -1;
}
