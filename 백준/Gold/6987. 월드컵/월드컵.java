import java.io.*;
import java.util.*;

public class Main {
    static int n, cnt, r, c;
    static boolean flag;
    static int[] home = {0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
    static int[] away = {1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5};
    static int[] win;
    static int[] tie;
    static int[] lose;

    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int t = 0; t < 4; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            win = new int[6];
            tie = new int[6];
            lose = new int[6];
            int total = 0;
            int a = 0, b = 0, c = 0;
            for (int i = 0; i < 18; i++) {
                int input = Integer.parseInt(st.nextToken());
                if (i % 3 == 0) {
                    win[a++] = input; // win i번째 index == i번째가 이긴 횟수
                } else if (i % 3 == 1) {
                    tie[b++] = input;
                } else {
                    lose[c++] = input;
                }
                total += input;
            }
            if (total > 30) {
                System.out.print("0 ");
                continue;
            }

            sol(0);
            if (flag) System.out.print(1+" ");
            else System.out.print(0+ " ");
            flag = false;

        }
    }
    static void sol(int cnt) {
        if (cnt == 15) {
            flag = true;
            return;
        }
        // 홈 팀이 이기는 경우
        if (win[home[cnt]] > 0 && lose[away[cnt]] > 0) {
            win[home[cnt]]--;
            lose[away[cnt]]--;
            sol(cnt + 1);
            win[home[cnt]]++;
            lose[away[cnt]]++;
        }
        if (lose[home[cnt]] > 0 && win[away[cnt]] > 0) {
            lose[home[cnt]]--;
            win[away[cnt]]--;
            sol(cnt + 1);
            lose[home[cnt]]++;
            win[away[cnt]]++;
        }
        if (tie[home[cnt]] > 0 && tie[away[cnt]] > 0) {
            tie[home[cnt]]--;
            tie[away[cnt]]--;
            sol(cnt + 1);
            tie[home[cnt]]++;
            tie[away[cnt]]++;
        }
    }
}

/*
5 0 0 3 0 2 2 0 3 0 0 5 4 0 1 1 0 4
4 1 0 3 0 2 4 1 0 1 1 3 0 0 5 1 1 3
5 0 0 4 0 1 2 2 1 2 0 3 1 0 4 0 0 5
5 0 0 3 1 1 2 1 2 2 0 3 0 0 5 1 0 4


 */