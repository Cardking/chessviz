#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "board.h"
#include "board_read.h"

int main(int argc, char *argv[])
{
    FILE* in = fopen(argv[1],"r");
    if (in == NULL){
	printf ("\nErr: No such file\n");
	return 1;
    }
    Cells cell[65];
    char pos1[4] = {0}, pos2[4] = {0}, error = 0,move_color = 0;
    char buf[12] = {0}, buf2[12] = {0}, buf_name[3] = {0} ;
    int move_num = 0;
    startpoz (cell);
    move_color = WH;
    system("clear");
    printf ("\n\t\t MOVE: WH");
    drbo (cell);
    getchar ();
    while (1){       
        error = move_read(in,buf,buf2,buf_name,&move_num);
        if (error != 0){
            printf ("\n%hhu  str#: (%d)  Err: problem with reading data\n",error,move_num);
            return 1;
        } 
        decode(buf,move_num,pos1,pos2);	
        printf ("%d.\t%c%c%c%c%c%c\n",move_num,pos1[0],pos1[1],buf[2],pos2[0],pos2[1],pos2[3]);
        if (move_color == BL && cell[(int)pos1[2]].col != BL){
            printf ("\nErr: Wrong color\n");
            return 1;
        }
        if (move_color == WH && cell[(int)pos1[2]].col != WH){
            printf ("\nErr: Wrong color\n");
            return 1;
        }
        if (move_check(cell,pos1,pos2) == 0){
             move(cell,pos1,pos2);
        } else {
            printf ("\nErr: wrong move doing\n");
            return 1;
        }
        system("clear");
        if (move_color == WH){
            printf ("\n\t\t MOVE: WH");
        }
        if (move_color == BL){
            printf ("\n\t\t MOVE: BL");
        }
        drbo (cell);
        printf ("%d.\t%c%c%c%c%c%c\n",move_num,pos1[0],pos1[1],buf[2],pos2[0],pos2[1],pos2[3]);
        if (buf[5] == '#' || buf2[5] == '#'){
            printf ("\nEnd  of game\n");
            return 0;
        }
        getchar();
        move_color = BL;
        decode(buf2,move_num,pos1,pos2);
        printf ("%d.\t%c%c%c%c%c%c\n",move_num,pos1[0],pos1[1],buf2[2],pos2[0],pos2[1],pos2[3]);
        if (move_color == BL && cell[(int)pos1[2]].col != BL){
            printf ("\nErr: Wrong color\n");
            return 1;
        }
        if (move_color == WH && cell[(int)pos1[2]].col != WH){
            printf ("\nErr: Wrong color\n");
            return 1;
        }     
        if (move_check(cell,pos1,pos2) == 0){
            move(cell,pos1,pos2);
        } else {
            printf ("\nErr: wrong move doing\n");
            return 1;
        }
        system("clear");
        if (move_color == WH){
            printf ("\n\t\t MOVE: WH");
        }
        if (move_color == BL){
            printf ("\n\t\t MOVE: BL");
        }
        drbo (cell);
        printf ("%d.\t%c%c%c%c%c%c\n",move_num,pos1[0],pos1[1],buf2[2],pos2[0],pos2[1],pos2[3]);
        if (buf[5] == '#' || buf2[5] == '#'){
            printf ("\nEnd  of game\n");
        return 0;
        }
        getchar();
        move_color = WH;
    }
    return 0;
}
