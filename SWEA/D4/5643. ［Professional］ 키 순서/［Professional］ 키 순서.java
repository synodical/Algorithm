import java.io.*;
import java.util.*;

public class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int t, n, m;
    static int[] in;
    static int[] out;
    static int[][] adj;
    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= t; tc++) {
            n = Integer.parseInt(br.readLine());
            m = Integer.parseInt(br.readLine());
            in = new int[n + 1];
            out = new int[n + 1];
            adj = new int[n + 1][n + 1];
            for (int i = 0; i < m; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                adj[a][b] = 1;
            }
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                int[] res = bfs(i);
                if (res[0] + res[1] == n - 1) {
                    ans++;
                }
            }
            bw.write("#"+ tc + " " + ans + "\n");
        }
        bw.flush();
        bw.close();
    }
    public static int[] bfs(int node) {
        boolean[] visited = new boolean[n + 1];
        Queue<Integer> q = new ArrayDeque<>();
        q.add(node);
        int inCnt = 0, outCnt = 0;
        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int i = 1; i <= n; i++) {
                if (adj[cur][i] == 1) {
                    if (visited[i]) continue;
                    visited[i] = true;
                    outCnt++;
                    q.add(i);
                }
            }
        }
        Arrays.fill(visited, false);
        q.add(node);
        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int i = 1; i <= n; i++) {
                if (adj[i][cur] == 1) {
                    if (visited[i]) continue;
                    visited[i] = true;
                    inCnt++;
                    q.add(i);
                }
            }
        }
        return new int[]{inCnt, outCnt};
    }
}