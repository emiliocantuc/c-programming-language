#include <stdio.h>
//copy input and replace multiblanks with single blank
 main(){
         int c,blank;
         blank=0;
         while ((c = getchar()) != EOF){
                 if(c!=' '){
                        putchar(c);
                        blank==0;
                 }
                else{
                        if(blank==0)
                                putchar(c);
                        ++blank;
                }
        }

 }
