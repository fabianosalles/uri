#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0

void dlog(char *text){
    if (DEBUG)
        printf("%s\n", text);
}

char *encrypt(char *text){
    int length = strlen(text);
    char *result = calloc(sizeof(char), length+1);
    strcpy(result, text);
    
    dlog(result);
    /* 1. shift letters */
    for(int i=0; i<length-1; i++){
        if (isalpha(result[i])){
            result[i] += 3;     
        }   
    }
    dlog(result);
    
    /* 2. reverse line */    
    char x;
    int k;
    for(int i=0; i<length/2; i++){
        k = length -1 - i;        
        x = result[i];
        result[i] = result[k];
        result[k] = x;        
    }
    dlog(result);

    /* 3. move one position to the lef for half on (truncated) */
    for(int i=length/2; i<length; i++){
        result[i]-=1;
    }
    dlog(result);

}

int main(void){
    printf("%s\n", encrypt("Texto #3"));
    printf("%s\n", encrypt("abcABC1"));
    printf("%s\n", encrypt("vxpdylY .ph"));
    printf("%s\n", encrypt("vv.xwfxo.fd"));
    return 0;
}