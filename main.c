# Map_Matrix
Read a file contains a map with a matrix


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

char Map[SIZE+1][SIZE+1];

void ReadMap(FILE *in);

void PrintMap(void){
    int r=0;
    while(Map[r][0]!='\0'){
     printf("%s\n",Map[r]);
     r+=1;
    }
}

int main()
{
    FILE *fp;
    fp=fopen("Map.txt","r");
    if(fp==NULL){
        fprintf(stderr,"Cannot open the file");
        exit(EXIT_FAILURE);
    }
    ReadMap(fp);
    fclose(fp);
    PrintMap();

    return 0;
}


void ReadMap(FILE *in){
    char buff[SIZE+2];
    int r=0;

    while(fgets(buff,SIZE,in)!=NULL){
        buff[strlen(buff)-1]='\0';
        strcpy(Map[r],buff);
        r+=1;
    }
}

