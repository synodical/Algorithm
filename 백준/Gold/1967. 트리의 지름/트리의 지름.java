import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Pair {
    int c; int w; // child, weight

    public Pair(int c, int w) {
        this.c = c;
        this.w = w;
    }

    public int getC() {
        return c;
    }

    public int getW() {
        return w;
    }
}
public class Main {
    static int n;
    static List<Pair> tree[];
    static boolean[] visited;
    static int ans = 0;
    static int far_node = 0;

    // 어떤 랜덤한 노드로부터 가장 먼 노드
    // 해당 노드로부터 가장 먼 거리
    static void sol(int cur, int cur_w) {
        if (visited[cur]) return;
        visited[cur] = true;
        if (ans < cur_w) {
            ans = cur_w;
            far_node = cur;
        }
        // 현재 보고 있는 cur node에 연결된 노드를 dfs 탐색
        // cur 에 연결된 노드의 번호와 누적된 가중치 재귀함수 전달
        for (Pair p : tree[cur]) {
            sol(p.getC(), cur_w + p.getW());
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        if (n == 1) {
            System.out.println(0);
            return;
        }
        tree = new ArrayList[n + 1];
        visited = new boolean[n + 1];
        for (int i = 0; i <= n; i++) {
            tree[i] = new ArrayList<Pair>();
        }
        for (int i = 0; i < n - 1; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int p = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            tree[p].add(new Pair(c, w));
            tree[c].add(new Pair(p, w)); // 양방향 그래프

        }
        sol(1, 0);
        for (int i = 0; i <= n; i++) {
            visited[i] = false;
        }
        sol(far_node, 0);
        System.out.println(ans);
    }
}