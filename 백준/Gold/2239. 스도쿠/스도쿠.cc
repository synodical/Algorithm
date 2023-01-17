#include <iostream>
#include <string>
#include <queue>
using namespace std;
using ll = long long;

int sudoku[9][9], cnt = 0;
bool row[9][9] = {false, }; // i번째에 row에 sudoku값 j가 존재
bool column[9][9] = {false, }; // i번째에 col에 sudoku값 j가 존재
bool square[9][9] = {false, };

int sq_index(int r, int c) {
    return (r / 3) * 3 + (c / 3);
}

void backtrack(int cnt) {
    if (cnt == 81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sudoku[i][j];
            }
            cout << '\n';
        }
        exit(0);
    }
    int x = cnt / 9;
    int y = cnt % 9;
    
    if (sudoku[x][y] == 0) {
        for (int i = 1; i <= 9; i++) { // 0에 들어갈 수
            if (!row[x][i] && !column[y][i] && !square[sq_index(x, y)][i]) {
                row[x][i] = true;
                column[y][i] = true;
                square[sq_index(x, y)][i] = true;
                sudoku[x][y] = i;
                                
                backtrack(cnt + 1);
                                
                row[x][i] = false; // backtracking
                column[y][i] = false;
                square[sq_index(x, y)][i] = false;
                sudoku[x][y] = 0;
            }
        }
    }
    else backtrack(cnt + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 9; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 9; j++) {
            sudoku[i][j] = s[j] - '0';
            if (sudoku[i][j] != 0) {
                row[i][ sudoku[i][j] ] = true;
                column[j][ sudoku[i][j] ] = true;
                square[ sq_index(i, j) ][ sudoku[i][j] ] = true;
            }
        }
    }
    backtrack(0);
    return 0;
}

 
