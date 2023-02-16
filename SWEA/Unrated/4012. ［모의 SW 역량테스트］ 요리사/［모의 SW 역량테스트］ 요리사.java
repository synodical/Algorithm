import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Solution {
    static boolean[] isSelected;

    static int n, l;
    static int ans;

    static int[][] arr;
    static int[] res;
    static int[][] resA;
    static int[][] resB;
    static class Pair {
        int taste;
        int cal;

        public Pair(int taste, int cal) {
            this.taste = taste;
            this.cal = cal;
        }

    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int t = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= t; tc++) {
            n = Integer.parseInt(br.readLine());
            isSelected = new boolean[n];
            res = new int[n/2];
            arr = new int[n][n];

            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            ans = Integer.MAX_VALUE;
            combi(0, 0);
            bw.write("#" + tc + " " + ans + "\n");
        }
        bw.flush();
        bw.close();
    }

    static void combi(int cnt, int start) {
        if (cnt == n/2) {
            check();
            return;
        }
        for (int i = start; i < n; i++) {
            isSelected[i] = true;
            combi(cnt + 1, i + 1);
            isSelected[i] = false;
        }
    }
    static void check() {
        int a = 0; int b = 0; int res = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i+1; j < n; j++) {
                if (isSelected[i] && isSelected[j]) {
                    a += arr[i][j] + arr[j][i];
                } else if (!isSelected[i] && !isSelected[j]) {
                    b += arr[i][j] + arr[j][i];
                }
            }
        }
        ans = Math.min(Math.abs(a - b), ans);
    }



}

/*
1
6
0 37 26 52 77 20
32 0 15 26 75 16
54 33 0 79 37 90
92 10 66 0 92 3
64 7 89 89 0 21
80 49 94 68 5 0
 */