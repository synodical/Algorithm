import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int n, a, b;
    static int[][] arr = new int[101][101];
    static boolean[][] visit = new boolean[101][101];
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};

    static class Pair {
        int x;
        int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int cnt = 0;
    static Queue<Pair> q = new ArrayDeque<>();
    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            q.offer(new Pair(a, b));
//            visit[a][b] = true;
            for (int j = a; j < a + 10; j++) {
                for (int k = b; k < b + 10; k++) {
                    arr[j][k] = 1;
                }
            }
        }
        // bfs 탐색해서 nx ny가 0이면 둘레이다.
        // 아님 말고
        for (Pair cur : q) {
            bfs(cur.x, cur.y);
        }
        System.out.println(cnt);
    }

    static void bfs(int x, int y) {
        if (visit[x][y]) return;
        Queue<Pair> q = new ArrayDeque<>();
        q.offer(new Pair(x, y));
        visit[x][y] = true;
        while (!q.isEmpty()) {
            Pair cur = q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx < 0 || nx >= 101 || ny < 0 || ny >= 101 || visit[nx][ny]) {
                    continue;
                }
                if (arr[nx][ny] == 0) {
                    cnt++;
                }
                if (arr[nx][ny] == 1) {
                    visit[nx][ny] = true;
                    q.offer(new Pair(nx, ny));
                }
            }
        }
    }
}