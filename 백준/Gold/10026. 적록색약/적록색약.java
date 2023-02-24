import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Parameter;
import java.util.*;

public class Main {
    static int n, m, v;
    static boolean[][] visited;
    static char[][] arr;
    static int ans = 0;
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

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(br.readLine());
        visited = new boolean[n][n];
        arr = new char[n][n];

        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < n; j++) {
                arr[i][j] = s.charAt(j);
            }
        }
        int personR = 0;
        int personG = 0;
        int personB = 0;
        int person = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 'R') {
                    if (visited[i][j]) continue;
                    personR++;
                    bfs(new Pair(i, j), 'R', false);
                } else if (arr[i][j] == 'G') {
                    if (visited[i][j]) continue;
                    personG++;
                    bfs(new Pair(i, j), 'G', false);
                } else {
                    if (visited[i][j]) continue;
                    personB++;
                    bfs(new Pair(i, j), 'B', false);
                }
            }
        }
        System.out.println(personR + personB + personG);
        for (int i = 0; i < visited.length; i++) {
            for (int j = 0; j < visited[i].length; j++) {
                visited[i][j] = false;
            }
        }
        personR = 0; personG = 0; personB = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 'R' || arr[i][j] == 'G') {
                    if (visited[i][j]) continue;
                    personR++;
                    bfs(new Pair(i, j), 'R', true);
                } else {
                    if (visited[i][j]) continue;
                    personB++;
                    bfs(new Pair(i, j), 'B', true);
                }
            }
        }
        System.out.println(personR + personB + personG);

    }

    static void bfs(Pair start, char c, boolean isRG) {
        Queue<Pair> q = new ArrayDeque<>();
        q.add(start);
        visited[start.x][start.y] = true;
        while (!q.isEmpty()) {
            Pair cur = q.poll();
            int x = cur.x;
            int y = cur.y;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (visited[nx][ny]) continue;
                if (isRG) { // 색약이라서 R과 G를 구분하지 못함
                    if (c == 'R' || c == 'G') {
                        if (arr[nx][ny] == 'B') continue;
                    } else { // c가 B
                        if (arr[nx][ny] != 'B') continue;
                    }
                } else { // 색약이 아님
                    if (c != arr[nx][ny]) continue;
                }
                visited[nx][ny] = true;
                q.add(new Pair(nx, ny));
            }
        }
    }


}