import java.io.*;
import java.util.StringTokenizer;

public class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int t;
    static int[][] adj;
    static final int INF = 1_000_000_000;
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        t = Integer.parseInt(st.nextToken());
        for (int tc = 1; tc <= t; tc++) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            adj = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    adj[i][j] = Integer.parseInt(st.nextToken());
                    if (adj[i][j] == 0) adj[i][j] = INF;
                }
            }
            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        adj[i][j] = Math.min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
            int ans = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    sum += adj[i][j];
                }
                ans = Math.min(ans, sum);
            }
            bw.write("#" + tc + " " + ans +"\n");
        }
        bw.flush();
        bw.close();
    }
}