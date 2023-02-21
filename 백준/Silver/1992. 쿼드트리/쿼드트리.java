import java.io.*;
import java.util.*;

public class Main {
    static int n, cnt;
    static int[][] arr;
    static StringBuilder sb = new StringBuilder();

    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        n = Integer.parseInt(br.readLine());
        arr = new int[n][n];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < n; j++) {
                arr[i][j] = s.charAt(j) - '0';
            }
        }
        sol(0, 0, n);
        System.out.println(sb);
    }

    static void sol(int r, int c, int size) {
        if (size == 2) {
            int res = arr[r][c] + arr[r][c + 1] + arr[r + 1][c] + arr[r + 1][c + 1];
            if (res == 4) {
                sb.append("1");
            } else if (res == 0) {
                sb.append("0");
            } else {
                sb.append("(" + arr[r][c] + arr[r][c + 1] + arr[r + 1][c] + arr[r + 1][c + 1] + ")");
            }
            return;
        }
        boolean flag = true;
        for (int i = r; i < r + size-1; i++) {
            for (int j = c; j < c + size-1; j++) {
                if (arr[i][j] != arr[i][j + 1]) {
                    flag = false;
                }
                if (arr[i][j] != arr[i+1][j]) {
                    flag = false;
                }
            }
        }
        if (flag) {
            sb.append(arr[r][c]);
        }
        else {
            sb.append("(");
            sol(r, c, size / 2);
            sol(r, c + size / 2, size / 2);
            sol(r + size / 2, c, size / 2);
            sol(r + size / 2, c + size / 2, size / 2);
            sb.append(")");
        }
    }
}

/*

8
00000000
00000000
00001111
00001111
00011111
00111111
00111111
00111111

 */