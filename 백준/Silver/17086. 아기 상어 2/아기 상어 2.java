import java.io.*;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static class Node {
        int x;
        int y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int n, m, ans;
    static int[][] arr;
    static int[] dx = {-1, 0, 1, 1, 1, 0, -1, -1};
    static int[] dy = {1, 1, 1, 0, -1, -1, -1, 0};
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] == 1) arr[i][j] = 100;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 0) {
                    int[][] copy = new int[n][m];
                    for (int k = 0; k < n; k++) {
                        if (m >= 0) System.arraycopy(arr[k], 0, copy[k], 0, m);
                    }
                    int tmp = bfs(i, j, copy);
                    ans = Math.max(ans, tmp);
                }
            }
        }
        bw.write(ans+"");
        bw.flush();
    }

    public static int bfs(int x, int y, int[][] copy) {
        Queue<Node> q = new ArrayDeque<>();
        q.add(new Node(x, y));
        while (!q.isEmpty()) {
            Node cur = q.poll();
            for (int i = 0; i < 8; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                if (copy[nx][ny] == 100) {
                    return copy[cur.x][cur.y] + 1;
                }
                if (copy[nx][ny] <= 0) {
                    copy[nx][ny] = copy[cur.x][cur.y] + 1;
                    q.add(new Node(nx, ny));
                }
            }
        }
        return 0;
    }
}