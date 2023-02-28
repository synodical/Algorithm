import java.io.*;
import java.lang.reflect.Parameter;
import java.util.*;

public class Solution {
    static int n, tc, start;
    static int[] arr;
    static int[] sum;
    static List<Integer> adj[];
    static class Pair {
        int node;
        int cnt;

        public Pair(int node, int cnt) {
            this.node = node;
            this.cnt = cnt;
        }
    }
    static boolean[] visited;
    static final int MAX = 101;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {

//        tc = Integer.parseInt(br.readLine());

        for (int t = 1; t <= 10; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            adj = new ArrayList[MAX + 1];
            visited = new boolean[MAX + 1];
            for (int i = 0; i <= MAX; i++) {
                adj[i] = new ArrayList<>();
            }
            start = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n / 2; i++) {
                int from = Integer.parseInt(st.nextToken());
                int to = Integer.parseInt(st.nextToken());
                adj[from].add(to);
            }
            bw.write("#" + t + " ");
            bfs(start);
        }
        bw.flush();
        bw.close();
    }

    static void bfs(int start) throws IOException {
        Queue<Pair> q = new ArrayDeque<>();
        q.add(new Pair(start, 0));
        visited[start] = true;
        int max = 0;
        List<Integer> maxNode = new ArrayList<>();
        while (!q.isEmpty()) {
            Pair cur = q.poll();
            if (max == cur.cnt) {
                maxNode.add(cur.node);
            }
            if (max < cur.cnt) {
                max = cur.cnt;
                maxNode = new ArrayList<>();
                maxNode.add(cur.node);
            }
            for (int i = 0; i < adj[cur.node].size(); i++) {
                int nxt = adj[cur.node].get(i);
                if (visited[nxt]) continue;
                visited[nxt] = true;
                q.add(new Pair(nxt, cur.cnt + 1));
            }
        }
        bw.write(Collections.max(maxNode) + "\n");

    }

}