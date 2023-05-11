import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int n, m, f;
    static int[] dp;
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        dp = new int[n + 3];
        dp[1] = 1;
        dp[2] = 3; //
        // dp 3 = dp1 + 1+2 or 2+1 조합?? -> 5 = dp1 *2 + dp2
        // dp 4 = dp3 + dp2*2
        // dp 5 = dp
        for (int i = 3; i < n + 1; i++) {
            dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 10_007;
        }
        System.out.println(dp[n]);
    }
}