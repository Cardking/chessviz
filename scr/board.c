#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "board.h"

void startpoz(Cells cell[]) {
    int i = 0;
    for (i = 0; i <= 64 ; ++i) {
        cell[i].name = NONE;
        cell[i].col = 3;
	cell[i].moves = 0;
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
    if ((pos2[2] > 64) || (pos2[2] < 1)){
        pos2[2] = 0;
    }
    if ((pos1[2] > 64) || (pos1[2] < 1)){
        pos1[2] = 0;
    }
    if (pos1[2] == pos2[2]){
        pos1[2] = 66;
    }
    if (buf[5] == '#'){
        pos2[3] = '#';
    } else {
        pos2[3] = ' ';
    }
    return 0;
}
binar move(Cells* cell,char* pos1, char* pos2){
    if (pos1[2] == 66){
        printf ("\nErr: %c%c = %c%c",pos1[0],pos1[1],pos2[0],pos2[1]);
    }
    if ((pos1[2] == 0) || (pos2[2] == 0)){
        printf ("\nHaven't this cell");
        return -1;
    }
    if ( pos_check(cell,pos1,pos2)){
        return -1;
    }
    if (p_check(cell,pos1,pos2) == -1){
        return -1;
    }
    cell[(int)pos2[2]].name = cell[(int)pos1[2]].name;
    cell[(int)pos2[2]].col = cell[(int)pos1[2]].col;
    cell[(int)pos2[2]].moves += 1;
    cell[(int)pos1[2]].name = NONE;
    cell[(int)pos1[2]].col = 3;
    cell[(int)pos1[2]].moves = 0;
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

binar p_check(Cells* cell,char pos1[],char pos2[]){
    if (cell[(int)pos1[2]].name != P){
        return 2;
    }
    int x[3] = {0},y[3] = {0};
    int flag = 0;
    x[1] = (pos1[2] - 1)/8;
    y[1] = (pos1[2] - x[1]*8);
    x[2] = (pos2[2] - 1)/8;
    y[2] = (pos2[2] - x[2]*8);
    if (cell[(int)pos1[2]].moves == 0){
        flag = 1;
    }
    if (cell[(int)pos1[2]].col == WH){
        if ((x[1] == x[2]) && (y[2]-y[1] <= flag + 1) && 
        (y[2]-y[1] > 0) && cell[(int)pos2[2]].name == NONE){
            if ((flag == 1) && (y[2]-y[1] == 2)){
                return cell[(int)pos2[2]-1].name == NONE ? 0:-1;
            }
            return 0;
        }
        if ((y[2]-y[1] == 1) && ((x[1]-x[2] == 1) || (x[1]-x[2] == -1)) &&
        cell[(int)pos2[2]].col == BL){
            return 0;
        }
        return -1;
    }
    if (cell[(int)pos1[2]].col == BL){
        if ((x[1] == x[2]) && (y[1]-y[2] <= flag + 1) && 
        (y[1]-y[2] > 0) && cell[(int)pos2[2]].name == NONE){
            if ((flag == 1) && (y[1]-y[2] == 2)){
                return cell[(int)pos2[2]+1].name == NONE ? 0:-1;
            }
            return 0;
        }
        if ((y[1]-y[2] == 1) && ((x[1]-x[2] == 1) || (x[1]-x[2] == -1)) &&
        cell[(int)pos2[2]].col == WH){
            return 0;
        }
        return -1;
    }
    return -1;
}

binar line_check(Cells* cell,char pos1[],char pos2[]){
    int x[3] = {0},y[3] = {0};
    int i = 0;
    x[1] = (pos1[2] - 1)/8;
    y[1] = (pos1[2] - x[1]*8);
    x[2] = (pos2[2] - 1)/8;
    y[2] = (pos2[2] - x[2]*8);
	if ((y[1] == y[2]) && (x[1]>x[2])){
		for(i = x[1] - 1; i>x[2];--i){
			if(cell[(i*8)+y[1]].name != NONE)
				return -1;
		}
		return 0;
	}
	if ((y[1] == y[2]) && (x[1]<x[2])){
		for(i = x[1] + 1; i<x[2];++i){
			if(cell[(i*8)+y[1]].name != NONE)
				return -1;
		}
		return 0;
	}
	if ((x[1] == x[2]) && (y[1]>y[2])){
		for(i = y[1] - 1; i>y[2];--i){
			if(cell[(x[1]*8)+i].name != NONE)
				return -1;
		}
		return 0;
	}
	if ((x[1] == x[2]) && (y[1]<y[2])){
		for(i = y[1] + 1; i<y[2];++i){
			if(cell[(x[1]*8)+i].name != NONE)
				return -1;
		}
		return 0;
	}
	return -1;
}

binar diag_check(Cells* cell,char pos1[],char pos2[]){
    int x[3] = {0},y[3] = {0};
    int i = 0,j = 0;
    x[1] = (pos1[2] - 1)/8;
    y[1] = (pos1[2] - x[1]*8);
    x[2] = (pos2[2] - 1)/8;
    y[2] = (pos2[2] - x[2]*8);
	if(((x[1]-x[2]) == (y[2]-y[1])) && (x[1]>x[2])){
		for(i = x[1]-1,j = y[1]+1;i>x[2];--i,++j){
			if(cell[(i*8)+j].name != NONE)
				return -1;
		}
		return 0;
	}
	if(((x[1]-x[2]) == (y[2]-y[1])) && (x[1]<x[2])){
		for(i = x[1]+1,j = y[1]-1;i<x[2];++i,--j){
			if(cell[(i*8)+j].name != NONE)
				return -1;
		}
		return 0;
	}
	if(((x[1]-x[2]) == (y[1]-y[2])) && (x[1]>x[2])){
		for(i = x[1]-1,j = y[1]-1;i>x[2];--i,--j){
			if(cell[(i*8)+j].name != NONE)
				return -1;
		}
		return 0;
	}
	if(((x[1]-x[2]) == (y[1]-y[2])) && (x[1]<x[2])){
		for(i = x[1]+1,j = y[1]+1;i<x[2];++i,++j){
			if(cell[(i*8)+j].name != NONE)
				return -1;
		}
		return 0;
	}
	return -1;
}

binar n_check(Cells* cell,char pos1[],char pos2[]){
    int x[3] = {0},y[3] = {0};
    int dx = 0,dy = 0;
    x[1] = (pos1[2] - 1)/8;
    y[1] = (pos1[2] - x[1]*8);
    x[2] = (pos2[2] - 1)/8;
    y[2] = (pos2[2] - x[2]*8);
    dx = x[1] - x[2];
    dy = y[1] - y[2];
	if (dx == 2){
		if ((dy == -1) || (dy == 1)){
			return 0;
		}
	}
	if (dx == 1){
		if ((dy == -2) || (dy == 2)){
			return 0;
		}
	}
	if (dx == -2){
		if ((dy == -1) || (dy == 1)){
			return 0;
		}
	}
	if (dx == -1){
		if ((dy == -2) || (dy == 2)){
			return 0;
		}
	}
	return -1;
}

binar k_check(Cells* cell,char pos1[],char pos2[]){
    int x[3] = {0},y[3] = {0};
    int dx = 0,dy = 0;
    x[1] = (pos1[2] - 1)/8;
    y[1] = (pos1[2] - x[1]*8);
    x[2] = (pos2[2] - 1)/8;
    y[2] = (pos2[2] - x[2]*8);
    dx = x[1] - x[2];
    dy = y[1] - y[2];
	if (dx == 1){
		if ((dy == -1) || (dy == 0) || (dy == 1)){
			return 0;
		}
	}
	if (dx == 0){
		if ((dy == -1) || (dy == 1)){
			return 0;
		}
	}
	if (dx == -1){
		if ((dy == -1) || (dy == 0) || (dy == 1)){
			return 0;
		}
	}
	return -1;
}
// R,N,B,K,Q,P
binar move_check(Cells* cell,char pos1[],char pos2[]){
	char logic = 0;
	switch (cell[(int)pos1[2]].name){
	case R:
		return (binar)(line_check(cell,pos1,pos2));
	case N:
		return (binar)(n_check(cell,pos1,pos2));
	case B:
		return (binar)(diag_check(cell,pos1,pos2));
	case K:
		return (binar)(k_check(cell,pos1,pos2));
	case Q:
		logic = line_check(cell,pos1,pos2) == 0 ||
		diag_check(cell,pos1,pos2) == 0;
		if(logic == 1){
			return 0;
		}
		if(logic == 0){
			return -1;
		}
		return -1;
	case P:
		return (binar)(p_check(cell,pos1,pos2));
	default:
		return -1;
	}
}
