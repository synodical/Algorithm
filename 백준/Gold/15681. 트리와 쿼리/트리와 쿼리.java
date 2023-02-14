import java.io.*;
import java.util.*;

public class Main {
    static int n, r, q;
    static List<Integer> tree[];
    static boolean[] visited;
    static int[] child; // child[i] = a -> i의 자식의 개수는 a이다.

    static int sol(int cur) {
        visited[cur] = true;
        child[cur] = 1;
        for (int i = 0; i < tree[cur].size(); i++) {
            if (visited[tree[cur].get(i)]) continue;
            sol(tree[cur].get(i));
            child[cur] += child[tree[cur].get(i)];
        }
        return 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());
        q = Integer.parseInt(st.nextToken());
        tree = new ArrayList[n + 1];
        visited = new boolean[n + 1];
        child = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            tree[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            tree[u].add(v);
            tree[v].add(u);
        }
        sol(r);
        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            System.out.println(child[x]);
        }
    }
}