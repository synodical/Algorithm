import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int n, m;
    static class Node {
        int x;
        int y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return "Node{" +
                    "x=" + x +
                    ", y=" + y +
                    '}';
        }
    }
    static class Edge implements Comparable<Edge> {
        int a;
        int b;
        int cost;

        public Edge(int a, int b, int cost) {
            this.a = a;
            this.b = b;
            this.cost = cost;
        }

        @Override
        public int compareTo(Edge o) {
            return this.cost - o.cost;
        }
    }

    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};
    static int[][] arr;
    static boolean[][] visited;
    static int[] parent;
    static PriorityQueue<Edge> pq;
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n][m];
        visited = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int num = 1; // 섬의 번호 넘버링을 위한 변수 num
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && arr[i][j] != 0) {
                    bfs(i, j, num);
                    num++;
                }
            }
        }

        parent = new int[num + 1];
        for (int i = 0; i < num + 1; i++) {
            parent[i] = i;
        }
        // 섬의 번호가 넘버링 됨.
        // 넘버링 된 섬들을 각각의 arraylist에 넣음
        ArrayList<ArrayList<Node>> island = new ArrayList<>();
        for (int i = 1; i < num; i++) {
            island.add(new ArrayList<>());
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 0) continue;
                island.get(arr[i][j]-1).add(new Node(i, j));
            }
        }
        // island 2차원 리스트에는 섬들의 좌표가 들어있음

        int ans = 0;
//        print();
        // 모든 두 섬 간의 가중치의 최소를 구하자.
        pq = new PriorityQueue<>();

        for (ArrayList<Node> list : island) {
            for (Node n : list) {
                for (int i = 0; i < 4; i++) {
                    dfs(n.x, n.y, i, arr[n.x][n.y], -1);
                }
            }
        }
        int bridge = 0;
        // kruskal MST
        while (!pq.isEmpty()) {
            Edge e = pq.poll();
            int p1 = getParent(e.a);
            int p2 = getParent(e.b);
            if (p1 != p2) {
                unionParent(e.a, e.b);
//                System.out.println(e.a+ " " +e.b+ " " +e.cost);
                ans += e.cost;
                bridge++;
            }
        }
        // MST 가 되었는지 확인, cost 1인 edge 필수사항 때문에 MST 안되었다면 -1로 실패 출
        if (ans == 0|| ans >= Integer.MAX_VALUE) ans = -1;
        if (bridge != num - 2) {
            ans = -1;
        }

        bw.write(ans + "\n");
        bw.flush();
        bw.close();
    }

    public static void bfs(int x, int y, int num) {
        Queue<Node> q = new ArrayDeque<>();
        q.add(new Node(x, y));
        visited[x][y] = true;
        arr[x][y] = num;
        while (!q.isEmpty()) {
            Node cur = q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                if (visited[nx][ny] || arr[nx][ny] == 0) continue;
                arr[nx][ny] = num;
                visited[nx][ny] = true;
                q.add(new Node(nx, ny));
            }
        }
    }

    public static void dfs(int x, int y, int dir, int num, int len) {
        if (arr[x][y] != 0 && arr[x][y] != num) {
            if (len >= 2) {
                pq.add(new Edge(num, arr[x][y], len));
            }
            return;
        }
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            return;
        }
        if (arr[nx][ny] == num) return;
        dfs(nx, ny, dir, num, len + 1);
    }

    public static int getParent(int n1) {
        if (parent[n1] == n1) return n1;
        else return getParent(parent[n1]);
    }

    public static void unionParent(int n1, int n2) {
        int p1 = getParent(n1);
        int p2 = getParent(n2);
        if (p1 < p2) {
            parent[p2] = p1;
        } else parent[p1] = p2;
    }

    public static void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }
}