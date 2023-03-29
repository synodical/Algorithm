import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static int n;
    static int[][] arr;
    static int[][][] dp;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        arr = new int[n+1][n+1];
        dp = new int[n+1][n+1][3];
        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        dp[1][2][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j] == 1) {
                    continue;
                }
                dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];
                dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][2];
                if (arr[i - 1][j] == 0 && arr[i][j - 1] == 0) {
                    dp[i][j][2] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
                }
            }
        }
        System.out.println(dp[n][n][0] +dp[n][n][1] + dp[n][n][2]);

    }
}