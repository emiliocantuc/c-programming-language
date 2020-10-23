#include <stdio.h>
#define MAXINPUT 1000
/*
Write an alternative version of squeeze(s1,s2) that deletes each character in
s1 that matches any character in the string s2.
*/
void squeeze(char s1[],char s2[]);
int main(){
        char s1[MAXINPUT]="hello";
        char s2[MAXINPUT]="bye";
        printf("%s\n",s1);
        squeeze(s1,s2);
        printf("%s\n",s1);
}
void squeeze(char s1[],char s2[]){
        int i,j,found;
        for(i=j=0;s1[i]!='\0';i++){
                found=0;
                for(int k=0;s2[k]!='\0';k++){
                        if(s1[i]==s2[k]){
                                found=1;
                                break;
                        }
                }
                if(!found)
                        s1[j++]=s1[i];
        }
        s1[j]='\0';
}
