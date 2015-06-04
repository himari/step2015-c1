#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int max=0, i, i0=0, i1=0, j=0;
    char buf[25], dict[235886][25], scan[100];
    FILE *fp;
    
    fp = fopen("/usr/share/dict/words","r");
    if(fp == NULL){
        printf("Cannot open file data\n");
        exit(1);
    }
    
    for(i=0; i<235886; i++){
        fscanf(fp, "%s", dict[i]);
    }
    
    while(1){
        gets(scan);
        if(scan[0] == '\0') break;
        
        while(1){
            for(i=i1; i<100; i++)
            {
                if(scan[i] == ' '|| scan[i]=='\0'){
                    i0 = i;
                    break;
                }
            }
            for(i=i1; i<i0; i++){
                buf[j] = scan[i];
                j++;
            }
            j=0;
            i1=i0+1;
            for(i=0; i<235886; i++){
                if(strcmp(dict[i], buf) == 0) break;
                if(i == 235885){
                    printf("The word %s is not found.\n", buf);
                    exit(0);
                }
            }
            memset(buf, '\0', 25);
            if(scan[i0] == '\0') break;
        }
        i1=0;
    }
    
    return 0;
}
