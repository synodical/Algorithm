import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int n;
    static int[][] arr;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};
    static int[][] dp; // i행 j열에 도달했을때 비용
    static class Pair {
        int x;
        int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    public static void main(String[] args) throws IOException {
        int t = 1;
        while (true) {
            n = Integer.parseInt(br.readLine());
            if (n == 0) break;
            arr = new int[n][n];
            dp = new int[n][n];
            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            sol(0, 0);
            System.out.println("Problem " + t + ": " + dp[n-1][n-1]);
            t++;
        }
    }
    public static void sol(int x, int y) {
        Queue<Pair> q = new ArrayDeque<>();
        q.add(new Pair(x, y));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        dp[0][0] = arr[0][0];
        while (!q.isEmpty()) {
            Pair cur = q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (dp[nx][ny] > dp[cur.x][cur.y] + arr[nx][ny]) {
                    dp[nx][ny] = dp[cur.x][cur.y] + arr[nx][ny];
                    q.add(new Pair(nx, ny));
                }
            }
        }
    }
}