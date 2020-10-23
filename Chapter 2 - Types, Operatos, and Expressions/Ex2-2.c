#include <stdio.h>
/*
Write a loop equivalent to the for loop above without using && or ||.
*/
int main(){
        int lim=10;
        char s[lim];
        int c,i;
        /**for (i=0;i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
                s[i] = c;*/
        for(i=0;i<lim-1;++i){
                if((c=getchar())!='\n'){
                        if(c!=EOF){
                                s[i]=c;
                        }
                }
        }
        s[i]='\0';
        printf("%s\n",s);
        return 0;
}
