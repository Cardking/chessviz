#ifndef BOARD_H
#define BOARD_H

#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define WHITE  "\033[1;37m"
#define NONE 6
enum {R,N,B,K,Q,P};
enum {WH, BL};

typedef char binar;
typedef struct { 
    char name: 4, col: 3;
	int moves;
} Cells;

void drbo (Cells cell[]);
void startpoz (Cells cell[]);
binar decode(char* buf,unsigned int move_num, char* pos1, char* pos2);
binar move(Cells* cell,char* pos1, char* pos2);
binar pos_check(Cells* cell, const char* pos1, const char* pos2);
binar p_check(Cells* cell,char pos1[],char pos2[]);
binar line_check(Cells* cell,char pos1[],char pos2[]);
binar diag_check(Cells* cell,char pos1[],char pos2[]);
binar n_check(Cells* cell,char pos1[],char pos2[]);
binar k_check(Cells* cell,char pos1[],char pos2[]);
binar move_check(Cells* cell,char pos1[],char pos2[]);

#endif
