import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int n, m, ans;
    static int[][] arr, copy;
    static class Pair {
        int x;
        int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};
    static boolean[][] visit;
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n][m];
        copy = new int[n][m];
        visit = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                int a = Integer.parseInt(st.nextToken());
                arr[i][j] = a;
                copy[i][j] = a;
            }
        }
        combi();
        System.out.println(ans);
    }
    public static void search() {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visit[i][j] && copy[i][j] == 2) {
                    bfs(i, j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (copy[i][j] == 0) {
                    cnt++;
                }
            }
        }
//        if (cnt >=7) print();
        ans = Math.max(ans, cnt);

        init();
    }

    public static void bfs(int x, int y) {
        Queue<Pair> q = new ArrayDeque<>();
        q.add(new Pair(x, y));
        while (!q.isEmpty()) {
            Pair cur = q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (visit[nx][ny] || copy[nx][ny] == 1) continue;
                visit[nx][ny] = true;
                copy[nx][ny] = 2;
                q.add(new Pair(nx, ny));
            }
        }
    }

    public static void combi() {
        for (int i = 0; i < n * m - 2; i++) {
            for (int j = i + 1; j < n * m - 1; j++) {
                for (int k = j + 1; k < n * m; k++) {
                    if (copy[i / m][i % m] == 0 && copy[j / m][j % m] == 0 && copy[k / m][k % m] == 0) {
                        copy[i / m][i % m] = 1;
                        copy[j / m][j % m] = 1;
                        copy[k / m][k % m] = 1;
//                    print();
                        search();

                        copy[i / m][i % m] = 0;
                        copy[j / m][j % m] = 0;
                        copy[k / m][k % m] = 0;
                    }

                }
            }
        }
    }

    public static void init() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                copy[i][j] = arr[i][j];
                visit[i][j] = false;
            }
        }
    }

    public static void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(copy[i][j]);
            }
            System.out.println();
        }
        System.out.println();
    }
}
