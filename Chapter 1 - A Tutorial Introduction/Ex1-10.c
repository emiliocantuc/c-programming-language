#include <stdio.h>
//copy input and replace tab by \t, backspace with \b and backlash with \\.
 main(){
         int c;
         while ((c = getchar()) != EOF){
                 if(c=='\t'){
                        putchar('\\');
                        putchar('t');
                }
                else if(c=='\b'){
                       putchar('\\');
                       putchar('b');
               }
               else if(c=='\\'){
                      putchar('\\');
                      putchar('\\');
              }
              else
                        putchar(c);
        }

 }
