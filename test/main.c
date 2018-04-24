#include <stdio.h>
#include <stdlib.h>
#define CTEST_MAIN
#include "ctest.h"
#include "board.h"
#include "board_read.h"




CTEST(board, decode)
{
    // Given
    char buf[12]="a1-a3";
    char pos1[4] = "", pos2[4] = "";

    // When
    const int result = decode(buf,1,pos1,pos2);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(board, move_a2_a4)
{
    // Given
    Cells cell[65];
    startpoz(cell);

    // When
    const int result = move(cell,"a22","a44");

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(board, move_a2_a5)
{
    // Given
    Cells cell[65];
    startpoz(cell);

    // When
    const int result = move(cell,"a22","a55");

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(board, move_00_00)
{
    // Given
    Cells cell[65];
    startpoz(cell);

    // When
    const int result = move(cell,"000","000");

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(board, pos_check_a2_a3)
{
    // Given
    Cells cell[65];
    startpoz(cell);
    char pos1[4] = "a2",pos2[4] = "a3";
    pos1[2] = 2;
    pos2[2] = 3;
    // When
    const int result = pos_check(cell,pos1,pos2);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(board, pos_check_a3_a2)
{
    // Given
    Cells cell[65];
    startpoz(cell);
    char pos1[4] = "a3",pos2[4] = "a2";
    pos1[2] = 3;
    pos2[2] = 2;
    // When
    const int result = pos_check(cell,pos1,pos2);

    // Then
    const int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(board, p_check_a2_a3)
{
    // Given
    Cells cell[65];
    startpoz(cell);
    char pos1[4] = "a2",pos2[4] = "a3";
    pos1[2] = 2;
    pos2[2] = 3;
    // When
    const int result = p_check(cell,pos1,pos2);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(board, p_check_a2_b2)
{
    // Given
    Cells cell[65];
    startpoz(cell);
    char pos1[4] = "a2",pos2[4] = "b2";
    pos1[2] = 2;
    pos2[2] = 10;
    // When
    const int result = p_check(cell,pos1,pos2);

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(board, p_check_a3_a2)
{
    // Given
    Cells cell[65];
    startpoz(cell);
    char pos1[4] = "a3",pos2[4] = "a2";
    pos1[2] = 3;
    pos2[2] = 2;
    // When
    const int result = p_check(cell,pos1,pos2);

    // Then
    const int expected = 2;
    ASSERT_EQUAL(expected, result);
}

CTEST(board, line_check_a2_a3)
{
    // Given
    Cells cell[65];
    startpoz(cell);
    char pos1[4] = "a2",pos2[4] = "a3";
    pos1[2] = 2;
    pos2[2] = 3;
    // When
    const int result = line_check(cell,pos1,pos2);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(board, line_check_a2_b2)
{
    // Given
    Cells cell[65];
    startpoz(cell);
    char pos1[4] = "a2",pos2[4] = "b2";
    pos1[2] = 2;
    pos2[2] = 10;
    // When
    const int result = line_check(cell,pos1,pos2);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(board, line_check_a2_b3)
{
    // Given
    Cells cell[65];
    startpoz(cell);
    char pos1[4] = "a2",pos2[4] = "b3";
    pos1[2] = 2;
    pos2[2] = 11;
    // When
    const int result = line_check(cell,pos1,pos2);

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(board, diag_check_a2_b3)
{
    // Given
    Cells cell[65];
    startpoz(cell);
    char pos1[4] = "a2",pos2[4] = "b3";
    pos1[2] = 2;
    pos2[2] = 11;
    // When
    const int result = diag_check(cell,pos1,pos2);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(board, diag_check_b3_a2)
{
    // Given
    Cells cell[65];
    startpoz(cell);
    char pos1[4] = "b3",pos2[4] = "a2";
    pos1[2] = 11;
    pos2[2] = 2;
    // When
    const int result = diag_check(cell,pos1,pos2);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(board, diag_check_a2_a3)
{
    // Given
    Cells cell[65];
    startpoz(cell);
    char pos1[4] = "a2",pos2[4] = "a3";
    pos1[2] = 2;
    pos2[2] = 3;
    // When
    const int result = diag_check(cell,pos1,pos2);

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(board, n_check_a2_a3)
{
    // Given
    Cells cell[65];
    startpoz(cell);
    char pos1[4] = "a2",pos2[4] = "a3";
    pos1[2] = 2;
    pos2[2] = 3;
    // When
    const int result = n_check(cell,pos1,pos2);

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(board, n_check_a1_b3)
{
    // Given
    Cells cell[65];
    startpoz(cell);
    char pos1[4] = "a1",pos2[4] = "b3";
    pos1[2] = 1;
    pos2[2] = 11;
    // When
    const int result = n_check(cell,pos1,pos2);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(board, k_check_a2_a3)
{
    // Given
    Cells cell[65];
    startpoz(cell);
    char pos1[4] = "a2",pos2[4] = "a3";
    pos1[2] = 2;
    pos2[2] = 3;
    // When
    const int result = k_check(cell,pos1,pos2);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(board, k_check_a2_a4)
{
    // Given
    Cells cell[65];
    startpoz(cell);
    char pos1[4] = "a2",pos2[4] = "a4";
    pos1[2] = 2;
    pos2[2] = 4;
    // When
    const int result = k_check(cell,pos1,pos2);

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(board, move_check_a2_a3)
{
    // Given
    Cells cell[65];
    startpoz(cell);
    char pos1[4] = "a2",pos2[4] = "a3";
    pos1[2] = 2;
    pos2[2] = 3;
    // When
    const int result = move_check(cell,pos1,pos2);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(board, move_check_a2_a7)
{
    // Given
    Cells cell[65];
    startpoz(cell);
    char pos1[4] = "a2",pos2[4] = "a7";
    pos1[2] = 2;
    pos2[2] = 7;
    // When
    const int result = move_check(cell,pos1,pos2);

    // Then
    const int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(board_read, move_read_correct)
{
    // Given
    FILE* file = fopen("test_read.txt","w");
    fprintf(file,"1. a1-a3 a7-a6\n");
    fclose(file);
    file = fopen("test_read.txt","r");
    char buf1[12] = {0}, buf2[12] = {0}, buf3[12] = {0};
    int a = 0;
    // When
    const int result = move_read(file,buf1,buf2,buf3,&a);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(board_read, move_read_incorrect)
{
    // Given
    FILE* file = fopen("test_read.txt","w");
    fprintf(file,"1. Ha1-a3 a7-a6\n");
    fclose(file);
    file = fopen("test_read.txt","r");
    char buf1[12] = {0}, buf2[12] = {0}, buf3[12] = {0};
    int a = 0;
    // When
    const int result = move_read(file,buf1,buf2,buf3,&a);

    // Then
    const int expected = 4;
    ASSERT_EQUAL(expected, result);
}

CTEST(board_read, move_read_incorrect2)
{
    // Given
    FILE* file = fopen("test_read.txt","w");
    fprintf(file,"1. a1*a3 a7-a6\n");
    fclose(file);
    file = fopen("test_read.txt","r");
    char buf1[12] = {0}, buf2[12] = {0}, buf3[12] = {0};
    int a = 0;
    // When
    const int result = move_read(file,buf1,buf2,buf3,&a);

    // Then
    const int expected = 3;
    ASSERT_EQUAL(expected, result);
}

int main(int argc, const char** argv)
{
    printf ("\n\n");
    return ctest_main(argc, argv);
}
