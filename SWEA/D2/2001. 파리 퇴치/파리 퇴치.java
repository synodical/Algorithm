import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Solution {
    static int t = 0;
    static int n, m;
    static int[] dx = {0, 1, 1, 0};
    static int[] dy = {0, 0, 1, 1};
    static int[][] arr;
    static int sol(int x, int y) {
        int sum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                int nx = x + i;
                int ny = y + j;
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                sum += arr[nx][ny];
            }
        }

        return sum;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        t = Integer.parseInt(st.nextToken());


        for (int tc = 1; tc <= t; tc++) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            arr = new int[n][n];
            int ans = 0;
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    ans = Math.max(ans, sol(i, j));
                }
            }
            System.out.println("#" + tc + " " + ans);
        }

    }
}