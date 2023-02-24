import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Parameter;
import java.util.*;

public class Main {
    static int n, m, v;
    static List<Integer>[] adj;
    static boolean[] visited;
    static boolean[] visited2;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        v = Integer.parseInt(st.nextToken());
        adj = new ArrayList[n + 1];
        visited = new boolean[n + 1];
        visited2 = new boolean[n + 1];

        for (int i = 0; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adj[a].add(b);
            adj[b].add(a);
        }
        for (int i = 0; i <= n; i++) {
            Collections.sort(adj[i]);
        }
        
        dfs(v);
        System.out.println();
        bfs(v);
    }

    static void bfs(int start) {
        Queue<Integer> q = new ArrayDeque<>();
        q.add(start);
        visited[start] = true;
        while (!q.isEmpty()) {
            int cur = q.poll();
            System.out.print(cur + " ");
            for (int i = 0; i < adj[cur].size(); i++) {
                int nxt = adj[cur].get(i);
                if (!visited[nxt]) {
                    visited[nxt] = true;
                    q.add(nxt);
                }
            }
        }
    }

    static void dfs(int cur) {
        visited2[cur] = true;
        System.out.print(cur + " ");
        for (int i = 0; i < adj[cur].size(); i++) {
            int nxt = adj[cur].get(i);
            if (!visited2[nxt]) {
//                visited[nxt] = true;
                dfs(nxt);
            }
        }
    }
}