import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    static int t, n,w, h;
    static int[][] arr;
    static boolean[][] visited;
    static int ans = Integer.MAX_VALUE;
    static class Pair {
        int x; int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    static class Edge extends Pair {
        int island;

        public Edge(int island, int x, int y) {
            super(x, y);
            this.island = island;
        }
    }

    static List<Edge> edges = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        arr = new int[n][n];
        visited = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        // 섬의 개수 구하고 테두리 육지의 위치 저장
        int islandNum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 1 && !visited[i][j]) {
                    bfs(islandNum, i, j);
                    islandNum++;
                }
            }
        }
        List<Pair> islands[] = new ArrayList[islandNum];
        for (int i = 0; i < islandNum; i++) {
            islands[i] = new ArrayList<>();
            int prevX = 0; int prevY = 0;
            for (Edge edge : edges) {
                if (edge.island == i) {
                    if (prevX == edge.x && prevY == edge.y) {
                        continue;
                    }
                    prevX = edge.x;
                    prevY = edge.y;
                    islands[i].add(new Pair(edge.x, edge.y));
                }
            }
        }
        for (int j = 0; j < edges.size(); j++) {
            for (int k = 0; k < edges.size(); k++) {
                if (edges.get(j).island != edges.get(k).island) {
                    int x0 = edges.get(k).x, x1 = edges.get(j).x;
                    int y0 = edges.get(k).y, y1 = edges.get(j).y;
                    int dist = Math.abs(x0 - x1) + Math.abs(y0 - y1) - 1;
                    ans = Math.min(ans, dist);
                }
            }
        }
        System.out.println(ans);
//        for (int i = 0; i < (1 << islandNum); i++) {
//            int tmp =0;
//            for (int j = 0; j < islandNum; j++) {
//                if ((i & (1 << j)) != 0) tmp++;
//            }
//            if (tmp == 2) {
//                List<Integer> selected = new ArrayList<>();
//                for (int j = 0; j < islandNum; j++) {
//                    if ((i & (1 << j)) != 0) {
//                        selected.add(j);
//                    }
//                }
//                List<Pair> island0 = new ArrayList<>();
//                List<Pair> island1 = new ArrayList<>();
//
//                for (Edge e : edges) {
//                    if (e.island == selected.get(0)) {
//                        island0.add(new Pair(e.x, e.y));
//                    } else if (e.island == selected.get(1)) {
//                        island1.add(new Pair(e.x, e.y));
//                    }
//                }
//
//                for (int k = 0; k < island0.size(); k++) {
//                    for (int j = 0; j < island1.size(); j++) {
//                        int x0 = island0.get(k).x, x1 = island1.get(j).x;
//                        int y0 = island0.get(k).y, y1 = island1.get(j).y;
//                        int dist = Math.abs(x0 - x1) + Math.abs(y0 - y1) - 1;
//                        ans = Math.min(ans, dist);
//                    }
//                }
//            }
//        }
//        System.out.println(ans);
    }

    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};

    static void bfs(int curIsland, int xx, int yy) {
        Queue<Pair> q = new ArrayDeque<>();
        q.add(new Pair(xx, yy));
        visited[xx][yy] = true;
        while (!q.isEmpty()) {
            Pair cur = q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) {
                    continue;
                }
                if (arr[nx][ny] == 0) {
                    edges.add(new Edge(curIsland, cur.x, cur.y));
                    continue;
                }
                visited[nx][ny] = true;
                q.add(new Pair(nx, ny));
            }
        }
    }
}


/*
5
1 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 1

5
1 0 0 0 0
1 0 0 0 1
1 1 1 0 1
0 0 0 0 0
0 0 0 1 0

5
1 1 1 0 0
1 0 1 0 0
1 1 1 0 0
0 0 0 0 1
0 0 0 0 1

4
1 1 1 1
1 1 0 1
1 0 0 1
1 1 1 1


 */