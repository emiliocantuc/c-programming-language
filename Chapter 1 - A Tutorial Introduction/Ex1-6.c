#include <stdio.h>
main(){
        int c;
        while (c = (getchar() != EOF)) //prints 1,1,1...
                //putchar(c);
                printf("%d\n",c);
}
