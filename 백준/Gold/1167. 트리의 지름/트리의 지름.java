import java.io.*;
import java.util.*;

public class Main {
    static int n, k;
    static List<Pair> tree[];
    static boolean[] visited;
    static class Pair {
        int child;
        int weight;

        public Pair(int child, int weight) {
            this.child = child;
            this.weight = weight;
        }
    }
    static int farNode;
    static int ans = 0;
    static void dfs(int cur, int cost) {
        if (visited[cur]) {
            return;
        }
        visited[cur] = true;
        if (ans < cost) {
            ans = cost;
            farNode = cur;
        }
        for (int i = 0; i < tree[cur].size(); i++) {
            Pair p = tree[cur].get(i);
            dfs(p.child, cost + p.weight);
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        n = Integer.parseInt(br.readLine());

        tree = new ArrayList[n+1];
        visited = new boolean[n+1];
        for (int i = 0; i <= n; i++) {
            tree[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            while (true) {
                int c = Integer.parseInt(st.nextToken());
                if (c == -1) {
                    break;
                }
                int wei = Integer.parseInt(st.nextToken());

                tree[x].add(new Pair(c, wei));
                tree[c].add(new Pair(x, wei));
            }
        }
        dfs(1, 0);
        for (int i = 0; i <= n; i++) {
            visited[i] = false;
        }
        ans = 0;
        dfs(farNode, 0);
        System.out.println(ans);
    }
}