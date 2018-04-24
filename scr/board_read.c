#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#define EFILE !(feof)

char move_read(FILE* in, char buf1[], char buf2[],char buf_name[],int* move_num){
	char c = 0, move_num_a[8] = {0};
	int i = 0, err = 0;
	buf_name[0] = P;
	buf_name[1] = P;
	while ((c < '1' || c > '9') && !(feof(in)) ){
		fscanf (in,"%c",&c);
	}
	move_num_a[0] = c;
	i = 1;
	fscanf (in,"%c",&c);
	while ((c != '.') && !(feof(in))){
		move_num_a[i] = c;
		++i;
		fscanf (in,"%c",&c);
	}
	*move_num = atoi (move_num_a);
	while (!(c >= 'a' && c <= 'h') && !(c >= 'A' && c <= 'Z') && !(feof(in))){
		fscanf (in,"%c",&c);
	}
	if ((c >= 'A' && c <= 'Z') && !(feof(in))){
		switch ((int)c){
		case 'R':
			buf_name[0] = R;
			break;
		case 'N':
			buf_name[0] = N;
			break;
		case 'B':
			buf_name[0] = B;
			break;
		case 'K':
			buf_name[0] = K;
			break;
		case 'Q':
			buf_name[0] = Q;
			break;
		default:
			buf_name[0] = Q;
			err = 2;
			break;
		}
		if (err == 2){
			return 4;
		}
		fscanf (in,"%c",&c);
	}
	if ((c >= 'a' && c <= 'h') && !(feof(in))){
		buf1[0] = c;
	} else { 
		return 3; // Err: Unknown number of slot
	}
	fscanf (in,"%c",&c);
	if ((c >= '1' && c <= '8') && !(feof(in))){
		buf1[1] = c;
	} else {
		return 3;
	}
	fscanf (in,"%c",&c);
	if (c != '-' && c != 'x'){
		return 3;
	}
	if (c == '-'){
		buf1[2] = '-';
	}
	if (c == 'x'){
		buf1[2] = 'x';
	}
	fscanf (in,"%c",&c);
	if ((c >= 'a' && c <= 'h') && !(feof(in))){
		buf1[3] = c;
	} else {
		return 3;
	}
	fscanf (in,"%c",&c);
	if ((c >= '1' && c <= '8') && !(feof(in))){
		buf1[4] = c;
	} else {
		return 3;
	}
	fscanf (in,"%c",&c);
	if ((c == '#') && !(feof(in))){
		buf1[5] = '#';
		return 0;
	} else {
		buf1[5] = '\0';
	}
	while (!(c >= 'a' && c <= 'h') && !(c >= 'A' && c <= 'Z') && !(feof(in))){
		fscanf (in,"%c",&c);
	}
	if ((c >= 'A' && c <= 'Z') && !(feof(in))){
		switch ((int)c){
		case 'R':
			buf_name[1] = R;
			break;
		case 'N':
			buf_name[1] = N;
			break;
		case 'B':
			buf_name[1] = B;
			break;
		case 'K':
			buf_name[1] = K;
			break;
		case 'Q':
			buf_name[1] = Q;
			break;
		default:
			buf_name[1] = Q;
			err = 2;
			break;
		}
		if (err == 2){
			return 4;
		}
		fscanf (in,"%c",&c);
	}
	if ((c >= 'a' && c <= 'h') && !(feof(in))){
		buf2[0] = c;
	} else { 
		return 3; // Err: Unknown number of slot
	}
	fscanf (in,"%c",&c);
	if ((c >= '1' && c <= '8') && !(feof(in))){
		buf2[1] = c;
	} else {
		return 3;
	}
	fscanf (in,"%c",&c);
	if (c != '-' && c != 'x'){
		return 3;
	}
	if (c == '-'){
		buf2[2] = '-';
	}
	if (c == 'x'){
		buf2[2] = 'x';
	}
	fscanf (in,"%c",&c);
	if ((c >= 'a' && c <= 'h') && !(feof(in))){
		buf2[3] = c;
	} else {
		return 3;
	}
	fscanf (in,"%c",&c);
	if ((c >= '1' && c <= '8') && !(feof(in))){
		buf2[4] = c;
	} else {
		return 3;
	}
	fscanf (in,"%c",&c);
	if ((c == '#') && !(feof(in))){
		buf2[5] = '#';
		return 0;
	} else {
		buf2[5] = '\0';
	}						
	return 0;	
}
