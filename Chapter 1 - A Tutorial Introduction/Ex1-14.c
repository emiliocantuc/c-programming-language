#include <stdio.h>
 /* print histogram of frecuency of characters in input.
    will only consider digits 0-9, and letter. */
 main(){
         int digits[10],upper[26],lower[26]; //define arrays for digits, upper and lowercase letters.
         int c;
         for(int i=0;i<10;i++)
                digits[i]=0;
         for(int i=0;i<26;i++)
                 upper[i]=lower[i]=0;
         while ((c = getchar()) != EOF) {
                 if(c>='0' && c<='9')
                        ++digits[c-'0'];
                 else if(c>='A' && c<='Z')
                        ++upper[c-'A'];
                 else if(c>='a' && c<='z')
                        ++lower[c-'a'];
         }
         for(int i=0;i<10;i++){ //print horizontal histograms
                 printf("%d\t",i);
                 for(int j=0;j<digits[i];j++)
                        printf(".");
                 printf("%d\n",digits[i]);
         }
         for(int i=0;i<26;i++){
                 printf("%c\t",'A'+i);
                 for(int j=0;j<upper[i];j++)
                        printf(".");
                 printf("%d\n",upper[i]);
                 printf("%c\t",'a'+i);
                 for(int j=0;j<lower[i];j++)
                        printf(".");
                 printf("%d\n",lower[i]);
         }


 }
