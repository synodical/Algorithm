import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
    static class Pair {
        int x;
        int y;
        int size;

        public Pair(int x, int y, int size) {
            this.x = x;
            this.y = y;
            this.size = size;
        }
    }

    static int[][] map;
    static int N, W, H, min;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            st = new StringTokenizer(br.readLine(), " ");
            N = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());
            H = Integer.parseInt(st.nextToken());

            map = new int[H][W];

            for (int i = 0; i < H; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < W; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            min = Integer.MAX_VALUE;
            sol(0, map);
            System.out.println("#" + t + " " + min);
        }
    }

    private static void sol(int cnt, int[][] arr2) {
        if (cnt == N) {
            int sum = 0;
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if (arr2[i][j] > 0) sum++;
                }
            }
            min = Math.min(min, sum);
            return;
        }

        int[][] copy = new int[H][W];
        for (int i = 0; i < W; i++) {
            int startX = -1;
            for (int j = 0; j < H; j++) {
                if (arr2[j][i] != 0) {
                    startX = j;
                    break;
                }
            }
            if (startX == -1) {
                sol(cnt + 1, arr2);
            } else {
                getCopy(arr2, copy);
                bomb(copy, startX, i);
                fallDown(copy);
                sol(cnt + 1, copy);
            }
        }
    }

    private static void fallDown(int[][] copy) {
        for (int i = 0; i < W; i++) { // w는 열
            Queue<Integer> q = new ArrayDeque<>();
            for (int j = H - 1; j >= 0; j--) {
                if (copy[j][i] > 0) q.add(copy[j][i]);
                copy[j][i] = 0;
            }
            for (int j = H - 1; j >= 0; j--) {
                if (q.isEmpty()) break;
                copy[j][i] = q.poll();
            }
        }
    }

    private static void bomb(int[][] copy, int r, int c) {
        Queue<Pair> q = new LinkedList<>();
        if (copy[r][c] > 1) {
            q.offer(new Pair(r, c, copy[r][c]));
        }
        copy[r][c] = 0;

        while (!q.isEmpty()) {
            Pair p = q.poll();

            for (int i = 0; i < 4; i++) {
                int nx = p.x;
                int ny = p.y;
                for (int j = 1; j < p.size; j++) {
                    nx += dx[i];
                    ny += dy[i];
                    if (nx >= 0 && nx < H && ny >= 0 && ny < W && copy[nx][ny] != 0) {
                        if (copy[nx][ny] > 1) {
                            q.offer(new Pair(nx, ny, copy[nx][ny]));
                        }
                        copy[nx][ny] = 0;
                    }
                }
            }
        }
    }

    private static void getCopy(int[][] map, int[][] newMap) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                newMap[i][j] = map[i][j];
            }
        }
    }

}