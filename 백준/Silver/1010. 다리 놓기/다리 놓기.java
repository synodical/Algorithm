import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static int t;
    static int[][] dp;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            dp = new int[m+1][n+1];
            int ans = comb(m, n);
            bw.write(ans + "\n");
        }
        bw.flush();
        bw.close();
    }
    public static int comb(int n, int k) {
        for (int i = 0; i < n+1; i++) {
            for (int j = 0; j <= i && j != k + 1; j++) {
                if (i == j || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
            }
        }
        return dp[n][k];
//        if (n == k || k == 0) return 1;
//        return comb(n - 1, k - 1) + comb(n - 1, k);
    }
}