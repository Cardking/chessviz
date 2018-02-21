#include <stdio.h>

#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define WHITE   "\033[1;37m"
#define NONE 10
enum {R,N,B,K,Q,P};
enum {WH, BL};

typedef struct { 
    char name: 4, col: 2;
} Cells;

void drbo (Cells cell[]);
void startpoz (Cells cell[]);

int main()
{
    Cells cell[63];
//  printf ("\n%i\n",sizeof (cell[1]) ); 
//  return 0;
    startpoz (cell);
    drbo (cell);
    scanf("a");
    printf ("\n");
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

