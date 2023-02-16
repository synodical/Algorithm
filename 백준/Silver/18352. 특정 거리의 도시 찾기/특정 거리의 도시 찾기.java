import java.io.*;
import java.lang.reflect.Parameter;
import java.util.*;

public class Main {
    static class Pair implements Comparable<Pair> {
        int cost;
        int node;

        public Pair(int cost, int node) {
            this.cost = cost;
            this.node = node;
        }

        @Override
        public int compareTo(Pair o) {
            return this.cost - o.cost;
        }
    }
    static int n,m,k, x;
    static int[] arr;

    static List<Integer>[] adj;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
        adj = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            adj[u].add(v);
        }
        int[] dist = dijkstra(x);
        boolean flag = false;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == k) {
                System.out.println(i);
                flag = true;
            }
        }
        if (!flag) {
            System.out.println(-1);
        }
    }
    static int[] dijkstra (int start) {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        pq.offer(new Pair(0, start));
        int[] dist = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            dist[i] = Integer.MAX_VALUE;
        }
        dist[start] = 0;

        while (!pq.isEmpty()) {
            Pair p = pq.poll();
            int cur = p.node;
            int curCost = p.cost;
            dist[cur] = curCost;
            for (int i = 0; i < adj[cur].size(); i++) {
                int nxt = adj[cur].get(i);
                int nxtCost = curCost + 1;
                if (dist[nxt] > nxtCost) {
                    dist[nxt] = nxtCost;
                    pq.offer(new Pair(nxtCost, nxt));
                }
            }
        }
        return dist;
    }
}