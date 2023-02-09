import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {
    static int[][] arr = new int[5][5];
    static int[][] visit = new int[5][5];



    static void checkVisit(int cur) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (arr[i][j] == cur) {
                    visit[i][j] = 1;
                    return;
                }
            }
        }
    }

    static int sol(int cur) {
        checkVisit(cur);
        int[] row = new int[5];
        int[] col = new int[5];
        int rows =0;
        int cols=0;
        int dia1=0;
        int dia2 = 0;

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                row[i] += visit[i][j];
                col[i] += visit[j][i];
            }
        }
        for (int i = 0; i < 5; i++) {
            if (row[i] == 5) {
                rows++;
            }
            if (col[i] == 5) {
                cols++;
            }
        }
        for (int i = 0; i < 5; i++) {
            dia1 += visit[i][i];
            dia2 += visit[4 - i][i];
        }
        dia1 = dia1 == 5 ? 1 : 0;
        dia2 = dia2 == 5 ? 1 : 0;

        if (rows + cols + dia2 + dia1 >= 3) {
            return cur;
        }

        return 0;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < 5; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 5; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 0; i < 5; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 5; j++) {
                int a = Integer.parseInt(st.nextToken());
                int ans = sol(a);
                if (ans != 0) {
                    System.out.println((i)*5 + (j+1));
                    return;
                }
            }
        }
    }
}
/*

1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
6 7 8 9 10
3 13 18 23 5
17 21 1 2 4
11 12 14 15 16
19 20 22 24 25

* */