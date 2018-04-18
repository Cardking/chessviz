#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "board.h"

int main()
{
    Cells cell[65];
    char pos1[4] = {0}, pos2[4] = {0};
    char buf[12] = {0};
    unsigned int move_num = 0;
    int i = 0;
//  printf ("\n%i\n",sizeof (cell[1]) ); 
//  return 0;
    startpoz (cell);
//  int i = 0;
    while (1){
        drbo (cell);
        scanf("%s",buf);
        while (!(buf[i] <= 'h' && buf[i] >= 'a')){
            printf("%c",buf[i]);
            ++i;	
            }
        decode(buf,move_num,pos1,pos2);
        move(cell,pos1,pos2);
        printf("\t%c%c=%hhd %c%c=%hhd\n",pos1[0],pos1[1],pos1[2],pos2[0],pos2[1],pos2[2]);
        system("clear");
    }
    return 0;
}
