#include <stdio.h>
#include <string.h>

#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define WHITE   "\033[1;37m"
#define NONE 6
enum {R,N,B,K,Q,P};
enum {WH, BL};

typedef char binar;
typedef struct { 
    char name: 4, col: 3;
	char moves;
} Cells;

void drbo (Cells cell[]);
void startpoz (Cells cell[]);
binar decode(char* buf,unsigned int move_num, char* pos1, char* pos2);
binar move(Cells* cell,char* pos1, char* pos2);
binar pos_check(Cells* cell, const char* pos1, const char* pos2);

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
//	int i = 0;
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

void startpoz(Cells cell[]) {
    int i = 0;
    for (i = 0; i < 64 ; ++i) {
        cell[i].name = NONE;
        cell[i].col = 3;
    }
    cell[8].name = R;	
    cell[8].col = BL;
    cell[16].name = N;	
    cell[16].col = BL;
    cell[24].name = B;	
    cell[24].col = BL;
    cell[32].name = Q;	
    cell[32].col = BL;
    cell[40].name = K;	
    cell[40].col = BL;
    cell[48].name = B;	
    cell[48].col = BL;
    cell[56].name = N;	
    cell[56].col = BL;
    cell[64].name = R;	
    cell[64].col = BL;
    for (i = 7; i <= 7 + (7 * 8); i += 8) {
        cell[i].name = P;
        cell[i].col = BL;
    }
    cell[1].name = R;	
    cell[1].col = WH;
    cell[9].name = N;	
    cell[9].col = WH;
    cell[17].name = B;	
    cell[17].col = WH;
    cell[25].name = Q;	
    cell[25].col = WH;
    cell[33].name = K;	
    cell[33].col = WH;
    cell[41].name = B;	
    cell[41].col = WH;
    cell[49].name = N;	
    cell[49].col = WH;
    cell[57].name = R;	
    cell[57].col = WH;
    for (i = 2; i <= 2 + (7 * 8); i += 8) {
        cell[i].name = P;
        cell[i].col = WH;
    }
}

void drbo(Cells cell[]) {
//  char simb = 0;
    int i = 0, j = 0;
    printf("\n\n    _______________________________");
    for (i = 8; i >= 1; --i) {
        printf("\n   | ");
        for (j = i; j < i + (8 * 7) + 1;j += 8) {
            switch (cell[j].col) {
            case WH: 
                printf("%s",YELLOW); 
                break;
            case BL: 
                printf("%s",RED); 
                break;
            default: 
                break;
            }
            if (cell[j].col == WH) {
                switch (cell[j].name) {
                case R:
                    printf("%c",'R');
                    break;
                case N:
                    printf("%c",'N');
                    break;
                case B:
                    printf("%c",'B');
                    break;
                case Q:
                    printf("%c",'Q');
                    break;
                case K:
                    printf("%c",'K');
                    break;
                case P:
                    printf("%c",'P');
                    break;
                default:
                    break;
                }
            } else {
                if (cell[j].col == BL) {
                    switch (cell[j].name) {
                    case R:
                        printf("%c",'r');
                        break;
                    case N:
                        printf("%c",'n');
                        break;
                    case B:
                        printf("%c",'b');
                        break;
                    case Q:
                        printf("%c",'q');
                        break;
                    case K:
                        printf("%c",'k');
                        break;
                    case P:
                        printf("%c",'p');
                        break;
                    default:
                        break;
                    }
                } else { 
                    printf(" ");
                }
            }
            if (j != i + (8 * 7)) {
                printf("\033[0m");
                printf(" | ");
            }
        }
        printf("\033[0m |\n");
        printf(" %d |___|___|___|___|___|___|___|___| ",i);
    }
    printf("\n     A   B   C   D   E   F   G   H\n");
}

binar decode(char* buf,unsigned int move_num, char* pos1, char* pos2){
	unsigned int i = 0;
	move_num = 1;
	for (; i<2; i++){
		pos1[i] = buf[i];
	}
	i++;
	for (;i<5 ; ++i){
		pos2[i-3] = buf[i];
	}
	pos1[2] = (pos1[0] - 'a')*8 + (pos1[1] - '0');
	pos2[2] = (pos2[0] - 'a')*8 + (pos2[1] - '0');
	return 0;
}
binar move(Cells* cell,char* pos1, char* pos2){
	if ( pos_check(cell,pos1,pos2)){
		return -1;
	}
	cell[(int)pos2[2]].name = cell[(int)pos1[2]].name;
	cell[(int)pos2[2]].col = cell[(int)pos1[2]].col;
	cell[(int)pos1[2]].name = NONE;
	cell[(int)pos1[2]].col = 3;
	return 0;
}

binar pos_check(Cells* cell, const char* pos1, const char* pos2){
//	printf ("\npos1 == ( %hu, %hu ) , pos2 == ( %hu, %hu )\n",cell[(int)pos1[2]].name,
//	pos1[2], cell[(int)pos2[2]].name, pos2[2]);
	if (cell[(int)pos1[2]].name != NONE && 
	(cell[(int)pos2[2]].col != cell[(int)pos1[2]].col ||
	cell[(int)pos1[2]].col == 3)){
		return 0;
	}
	return 1;
} 
