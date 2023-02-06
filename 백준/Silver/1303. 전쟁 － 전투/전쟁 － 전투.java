import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

class Pos {
    int first;
    int second;

    public int getFirst() {
        return first;
    }

    public int getSecond() {
        return second;
    }

    public Pos(int first, int second) {
        this.first = first;
        this.second = second;
    }
}
public class Main {
    static int n, m;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};
    static char[][] arr = new char[101][101];
    static boolean[][] visit = new boolean[101][101];

    static Deque<Pos> q = new ArrayDeque<Pos>();
    static int bfs(int ii, int jj) {
        int cnt = 0;
        q.add(new Pos(ii, jj));
        visit[ii][jj] = true;
        while (!q.isEmpty()) {
            cnt++;
            Pos cur = q.pop();
            int x = cur.first;
            int y = cur.second;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || visit[nx][ny]) {
                    continue;
                }
                if (arr[x][y] != arr[nx][ny]) {
                    continue;
                }
                visit[nx][ny] = true;
                q.add(new Pos(nx, ny));
            }
        }
        return cnt * cnt;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < m; j++) {
                char c = s.charAt(j);
                arr[i][j] = c;
            }
        }
        int w = 0, b = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visit[i][j]) {
                    if (arr[i][j] == 'W') {
                        w += bfs(i, j);
                    }
                    else if (arr[i][j] == 'B') {
                        b += bfs(i, j);
                    }
                }
            }
        }
        bw.write(w + " " + b);
        bw.flush();
        bw.close();
        br.close();
    }
}