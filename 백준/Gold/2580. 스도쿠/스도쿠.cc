//
//  main.cpp
//  algol_hw4
//
//  Created by LeeYeEun on 2021/05/17.
//

#include <iostream>
#define MAX 10
using namespace std;

int sudoku[MAX][MAX]; // 무조건 9*9
bool row[MAX][MAX];  // 가로줄 i에 j x
bool column[MAX][MAX];
bool square[MAX][MAX]; // 사각형 i에 j x

int sq_index(int r, int c) {
    return (r / 3) * 3 + (c / 3);
}

void print_ans() {
    cout << '\n';
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << ' ';
        }
        cout << '\n';
    }
}

void sol(int cnt) {
    if(cnt == 81) {
        print_ans();
        exit(0);
        return;
    }
    int x = cnt / 9;
    int y = cnt % 9;
    if(!sudoku[x][y]) {
        for (int i = 1; i <= 9; i++) {
            if(!row[x][i] && !column[y][i] && !square[sq_index(x, y)][i]) {
                row[x][i] = true;
                column[y][i] = true;
                square[sq_index(x, y)][i] = true;
                sudoku[x][y] = i;
                
                sol(cnt + 1);
                
                row[x][i] = false;
                column[y][i] = false;
                square[sq_index(x, y)][i] = false;
                sudoku[x][y] = 0;
            }
        }
    }
    else sol(cnt + 1);
}

int main() {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
            if (sudoku[i][j] != 0) {
                row[i][ sudoku[i][j] ] = true; // 가로줄 i에 j 있어요
                column[j][ sudoku[i][j] ] = true;
                square[ sq_index(i, j) ][ sudoku[i][j] ] = true;
            }
        }
    }
    sol(0);

    return 0;
}
/*
0 3 5 4 6 9 2 7 8
7 8 2 1 0 5 6 0 9
0 6 0 2 7 8 1 3 5
3 2 1 0 4 6 8 9 7
8 0 4 9 1 3 5 0 6
5 9 6 8 2 0 4 1 3
9 1 7 6 5 2 0 8 0
6 0 3 7 0 1 9 5 2
2 5 8 3 9 4 7 6 0
 
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0

*/
