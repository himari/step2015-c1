#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[15],a;

int main(void){
    int max=0, i=0, j;
    char buf[100], c_max[100];
    FILE *fp;
    
    fp = fopen("/usr/share/dict/words","r");
    if(fp == NULL){
        printf("Cannot open file data\n");
        exit(1);
    }
    
    while(1){
        fscanf(fp, "%s", buf);
        if(feof(fp) != 0) break;
        if(strlen(buf) > max)
        {
            strcpy(c_max, buf);
            max = strlen(buf);
        }
        i++;
    }
    
    char str[15],a;
    printf("type in 16 words maximum");
    scanf("%s", str);
    for(i=0;str[i]!=0;i++){
        for(j=i+1;str[j]!=0;j++){
            if(str[i]>str[j]){
                a = str[i];
                str[i]=str[j];
                str[j]=a;
            }
        }
    }

    printf("longest words is [%s] \n", c_max);
    printf("word count = %d\n", i);
    return 0;
}
