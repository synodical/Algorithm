import java.io.*;
import java.util.StringTokenizer;

public class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int t;
    static int[] dp, arr;
    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= t; tc++) {
            int n = Integer.parseInt(br.readLine());
            dp = new int[n];
            arr = new int[n];
            int ans = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
                dp[i] = 1;
            }
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (arr[j] < arr[i]) {
                        dp[i] = Math.max(dp[i], dp[j] + 1);
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                ans = Math.max(dp[i], ans);
            }
            bw.write("#" + tc + " " + ans + "\n");
        }
        bw.flush();
        bw.close();
    }
}