import java.io.*;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int n, m;
    static char[][] arr;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};
    static class Node {
        int x;
        int y;
        int move;
        int key;

        public Node(int x, int y, int move, int key) {
            this.x = x;
            this.y = y;
            this.move = move;
            this.key = key;
        }
    }
    static Queue<Node> q = new ArrayDeque<>();
    static boolean[][][] visit;
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new char[n][m];
        visit = new boolean[n][m][1 << 6];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = s.charAt(j);
                if (arr[i][j] == '0') {
                    q.add(new Node(i, j, 0, 0));
                    arr[i][j] = '.';
                    visit[i][j][0] = true;
                }
            }
        }
        bw.write(bfs() + "");
        bw.flush();
        bw.close();
    }

    public static int bfs() {
        while (!q.isEmpty()) {
            Node cur = q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (visit[nx][ny][cur.key] || arr[nx][ny] == '#') continue;

                if (arr[nx][ny] == '1') {
                    return cur.move + 1;
                }
                if ('a' <= arr[nx][ny] && arr[nx][ny] <= 'f') {
                    int tmp = (1 << (arr[nx][ny] - 'a'));
                    tmp |= cur.key;
                    visit[nx][ny][tmp] = true;
                    q.add(new Node(nx, ny, cur.move + 1, tmp));
                } else if ('A' <= arr[nx][ny] && arr[nx][ny] <= 'F') {
                    if ((cur.key & (1 << (arr[nx][ny] - 'A'))) != 0) {
                        visit[nx][ny][cur.key] = true;
                        q.add(new Node(nx, ny, cur.move + 1, cur.key));
                    }
                } else if (arr[nx][ny] == '.') {
                    visit[nx][ny][cur.key] = true;
                    q.add(new Node(nx, ny, cur.move + 1, cur.key));
                }
            }
        }
        return -1;
    }
}