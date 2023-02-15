import java.io.*;
import java.util.*;

public class Solution {
    static int t, n;
    static int[][] arr;
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
    static int bfs(int xx, int yy) {
        int cnt = 0;
        ArrayDeque<Pair> q = new ArrayDeque<>();
        q.add(new Pair(xx, yy));
        while (!q.isEmpty()) {
            Pair p = q.removeFirst();
            cnt++;
            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                    continue;
                }
                if (arr[p.x][p.y] + 1 == arr[nx][ny]) {
                    q.push(new Pair(nx, ny));
                }
            }
        }
        return cnt;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        t = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= t; tc++) {
            n = Integer.parseInt(br.readLine());
            arr = new int[n][n];
            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            int ans = 0;
            int ansRoom = Integer.MAX_VALUE;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int cur = bfs(i, j);
                    if (cur > ans) {
                        ans = cur;
                        ansRoom = arr[i][j];
                    }
                    else if (cur == ans) {
                        ansRoom = Math.min(arr[i][j], ansRoom);
                    }

                }
            }
            bw.write("#" + tc + " " + ansRoom + " " + (ans) + "\n");
        }
        bw.flush();
        bw.close();
    }

}

/*

1
2
1 3
4 2

1
2
1 2
3 4

 */