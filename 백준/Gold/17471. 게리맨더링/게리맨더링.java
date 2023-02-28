import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int n;
    static int[] population;
    static List<Integer> adj[];
    static int[][] arr;
    static int[] parent;
    static int ans = Integer.MAX_VALUE;
    static boolean[] visit;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        population = new int[n+1];
        adj = new ArrayList[n+1];
        arr = new int[n + 1][n + 1];
        parent = new int[n + 1];
        visit = new boolean[n + 1];
        for (int i = 1; i <= n; i++) {
            population[i] = Integer.parseInt(st.nextToken());
            adj[i] = new ArrayList<>();
        }
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());
            for (int j = 1; j <= num; j++) {
                int a = Integer.parseInt(st.nextToken());
                adj[i].add(a);
                adj[a].add(i); // 양방향
                arr[i][a] = arr[i][a] = 1;
            }
        }

        for (int i = 0; i < (1 << n); i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) cnt++;
            }
            List<Integer> red = new ArrayList<>();
            List<Integer> blue = new ArrayList<>();
            if (cnt > 0 && cnt < (n / 2) + 1) {
                for (int j = 0; j < n; j++) {
                    if ((i & (1 << j)) != 0) red.add(j + 1);
                }
                for (int j = 1; j <= n; j++) {
                    if (!red.contains(j)) {
                        blue.add(j);
                    }
                }
                for (int j = 0; j <= n; j++) {
                    parent[j] = j;
                }

                gary(red);
                gary(blue);
                int redTotal = 0;
                int blueTotal = 0;
                boolean flag = true;
                for (int j = 1; j <= n; j++) {
                    visit[j] = false;
                }

                if (bfs(red, red.get(0)) && bfs(blue, blue.get(0))) {
                    for (int j = 1; j <= n; j++) {
                        if (!visit[j]) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) continue;
                    for (int r : red) {
                        redTotal += population[r];
                    }
                    for (int b : blue) {
                        blueTotal += population[b];
                    }
                    ans = Math.min(ans, Math.abs(redTotal - blueTotal));
                }

            }
            // 선택된 red 완성 (1부터 시작)

        }
        if (ans == Integer.MAX_VALUE) {
            ans = -1;
        }
        System.out.println(ans);

    }

    static int getParent(int n1) {
        if (parent[n1] == n1) return n1;
        else return getParent(parent[n1]);
    }

    static void unionParent(int n1, int n2) {
        int p1 = getParent(n1);
        int p2 = getParent(n2);
        if (p1 < p2) parent[p2] = p1;
        else parent[p1] = p2;
    }

    static void gary(List<Integer> color) {
        for (int cur : color) {
            for (int i = 0; i < adj[cur].size(); i++) {
                int nxt = adj[cur].get(i);
                if (!color.contains(nxt)) continue; // 같은 구역 색깔이 아니라면 합치지 않는다.
                unionParent(cur, nxt);
            }
        }
    }
    static boolean bfs(List<Integer> color, int c) { // dfs check
        Queue<Integer> q = new ArrayDeque<>();
        q.add(c);
        visit[c] = true;
        while (!q.isEmpty()) {
            int cur = q.poll();
            visit[cur] = true;
            for (int i = 0; i < adj[cur].size(); i++) {
                int nxt = adj[cur].get(i);
                if (!color.contains(nxt)) continue; // 같은 구역 색이 아니라면 검사하지 않는다.
                if (visit[nxt]) continue;
                int p1 = getParent(cur);
                int p2 = getParent(nxt);
                if (p1 != p2) return false;
                q.add(nxt);
            }
        }
        return true;
    }
}