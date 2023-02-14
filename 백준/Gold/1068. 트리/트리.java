import java.io.*;
import java.util.*;

public class Main {
    static int n, k;
    static int root;
    static List<Integer> tree[];
    static boolean[] visited;
    static int ans = 0;
    static void dfs(int x) {
        visited[x] = true;
        if (tree[x].size() == 0) {
//            ans++;
        }
        int child = 0;
        for (int i = 0; i < tree[x].size(); i++) {
            int cur = tree[x].get(i); // x의 i번째 자손들인 cur
            if (!visited[cur] && cur != k) {
                // k라면 이 노드를 삭제할 것이므로 탐색하지 않는다.
                child++;
                dfs(cur);
            }
        }
        if (child == 0) {
            ans++;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        k = Integer.parseInt(br.readLine());
        tree = new ArrayList[n];
        visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            tree[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            int a = Integer.parseInt(st.nextToken());
            if (a == -1) {
                root = i;
                continue;
            }
            tree[a].add(i); // i의 부모는 a
        }
        if (k == root) {
            System.out.println(0);
        } else {
            dfs(root);
            System.out.println(ans);
        }

    }
}
/*
4
-1 0 1 2
2


* */