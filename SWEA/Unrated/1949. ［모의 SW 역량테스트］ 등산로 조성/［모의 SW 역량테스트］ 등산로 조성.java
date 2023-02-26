import java.io.*;
import java.lang.reflect.Parameter;
import java.util.*;

public class Solution {
    static int n, tc, k;
    static int[][] arr;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};
    static boolean[][] visit;
    static int curAns = 0;
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
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        tc = Integer.parseInt(br.readLine());

        for (int t = 0; t < tc; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());
            int maxH = 0;
            List<Pair> maxList = new ArrayList<>();
            arr = new int[n][n];
            visit = new boolean[n][n];

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                    if (maxH < arr[i][j]) {
                        maxList = new ArrayList<>();
                        maxList.add(new Pair(i, j));
                        maxH = arr[i][j];
                    } else if (maxH == arr[i][j]) {
                        maxList.add(new Pair(i, j));
                    }
                }
            }

            // maxList r개 중 하나를 골라서 완탐 dfs 진행
            int ans = 0;
            for (Pair cur : maxList) {
                sol(cur.x, cur.y, 1);
                ans = Math.max(curAns, ans);
            }
            bw.write("#" + (t + 1) + " " + ans + "\n");
            curAns = 0;
            isCut = false;
        }
        bw.flush();
        bw.close();
    }

    static boolean isCut = false;

    static void sol(int x, int y, int cnt) {
        // 최대 K만큼 깎을 수 있다 -> 되도록 1만 깎아도 됨
        curAns = Math.max(cnt, curAns);
        visit[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || visit[nx][ny]) {
                continue;
            }
            if (arr[nx][ny] < arr[x][y]) {
                sol(nx, ny, cnt + 1);
            } else if (arr[nx][ny] - k < arr[x][y]) {
                if (isCut) continue;
                isCut = true;
                int cur = arr[nx][ny];
                arr[nx][ny] = arr[x][y] - 1;
                sol(nx, ny, cnt + 1);
                arr[nx][ny] = cur;
                isCut = false;
            }
        }
        visit[x][y] = false;

    }
}

/*
3 2
1 2 1
2 1 2
1 2 1

1
4 4
8 3 9 5
4 6 8 5
8 1 5 1
4 9 5 5

 */