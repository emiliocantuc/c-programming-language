#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define MAXWORDLEN 20
 /* print histogram of length of words in input */
 main(){
         int occur[MAXWORDLEN];
         int c,state,len;
         state = OUT;
         len=0;
         for(int i=0;i<MAXWORDLEN;i++)
                occur[i]=0;
         while ((c = getchar()) != EOF) {
                 if (c == ' ' || c == '\n' || c == '\t'){
                        state = OUT;
                        //printf("%d\n",len+1);
                        ++occur[len+1];
                 }
                 else if (state == OUT) {
                         len=0;
                         state = IN;
                 }
                 else if(state == IN){
                         ++len;
                 }
         }
         for(int i=0;i<MAXWORDLEN;i++){ //print horizontal histogram
                 printf("%d\t",i);
                 for(int j=0;j<occur[i];j++)
                        printf(".");
                 printf("%d\n",occur[i]);
         }


 }
