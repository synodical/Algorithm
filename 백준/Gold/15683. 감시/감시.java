import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Parameter;
import java.util.*;

public class Main {
    static int n, m, v;
    static boolean[][] visited;
    static int[][] arr;
    static int ans = Integer.MAX_VALUE;
    static int[] dx1 = {-1, 0, 1, 0};
    static int[] dy1 = {0, 1, 0, -1}; // 상 우 하 좌
    static int[][] dx2 = {{-1, 1}, {0, 0}, {-1, 1}, {0, 0}};
    static int[][] dy2 = {{0, 0}, {-1, 1}, {0, 0}, {-1, 1}};
    static int[][] dx3 = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    static int[][] dy3 = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    static int[][] dx4 = {{0, -1, 0}, {-1, 0, 1}, {0, 1, 0}, {1, 0, -1}};
    static int[][] dy4 = {{-1, 0, 1}, {0, 1, 0}, {1, 0, -1}, {0, -1, 0}};
    static int[][] dx5 = {{-1, 0, 1, 0}, {-1, 0, 1, 0}, {-1, 0, 1, 0}, {-1, 0, 1, 0}};
    static int[][] dy5 = {{0, 1, 0, -1}, {0, 1, 0, -1}, {0, 1, 0, -1}, {0, 1, 0, -1}};
    static class Pair {
        int x;
        int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static List<Pair> cctvs = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n][m];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] != 0 && arr[i][j] != 6) {
                    cctvs.add(new Pair(i, j));
                }
            }
        }

        sol(0, arr);
        System.out.println(ans);
    }

    static void sol(int idx, int[][] input) {

        if (idx == cctvs.size()) {
            int curCnt = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (input[i][j] == 0) {
                        curCnt++;
                    }
                }
            }
//            System.out.println(curCnt);
            ans = Math.min(curCnt, ans);
            return;
        }
        Pair cur = cctvs.get(idx);
        for (int dir = 0; dir < 4; dir++) {
            int[][] copy = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    copy[i][j] = input[i][j];
                }
            }
            changeArea(cur, copy, dir);
//            for (int i = 0; i < copy.length; i++) {
//                for (int j = 0; j < copy[0].length; j++) {
//                    System.out.print(copy[i][j]);
//                }
//                System.out.println();
//            }
            sol(idx + 1, copy);
        }
    }

    static boolean checkRange(int nx, int ny) {
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            return false;
        } else if (arr[nx][ny] == 6) {
            return false;
        }
        return true;
    }

    // 현재 cctv의 위치와 현재 2차원 배열, 현재 방향을 입력받으면
    // cctv가 감시한 부분을 -1로 바꾼 결과 배열을 반환하는 함수
    static void changeArea(Pair cur, int[][] input, int dir) {
        if (arr[cur.x][cur.y] == 1) {
            int nx = cur.x;
            int ny = cur.y;
            while (true) {
                nx += dx1[dir];
                ny += dy1[dir];
                if (!checkRange(nx, ny)) break;
//                ccq.add(new Pair(nx, ny));
                if (arr[nx][ny] == 0) input[nx][ny] = -1;
            }
        } else if (arr[cur.x][cur.y] == 2) {
            for (int i = 0; i < dx2[dir].length; i++) {
                int nx = cur.x;
                int ny = cur.y;
                while (true) {
                    nx += dx2[dir][i];
                    ny += dy2[dir][i];
                    if (!checkRange(nx, ny)) break;
                    if (arr[nx][ny] == 0) input[nx][ny] = -1;
//                    ccq.add(new Pair(nx, ny));
                }
            }
        } else if (arr[cur.x][cur.y] == 3) {
            for (int i = 0; i < dx3[dir].length; i++) {
                int nx = cur.x;
                int ny = cur.y;
                while (true) {
                    nx += dx3[dir][i];
                    ny += dy3[dir][i];
                    if (!checkRange(nx, ny)) break;
//                    ccq.add(new Pair(nx, ny));
                    if (arr[nx][ny] == 0) input[nx][ny] = -1;
                }
            }
        } else if (arr[cur.x][cur.y] == 4) {
            for (int i = 0; i < dx4[dir].length; i++) {
                int nx = cur.x;
                int ny = cur.y;
                while (true) {
                    nx += dx4[dir][i];
                    ny += dy4[dir][i];
                    if (!checkRange(nx, ny)) break;
                    if (arr[nx][ny] == 0) input[nx][ny] = -1;
//                    ccq.add(new Pair(nx, ny));
                }
            }
        } else if (arr[cur.x][cur.y] == 5) {
            for (int i = 0; i < dx5[dir].length; i++) {
                int nx = cur.x;
                int ny = cur.y;
                while (true) {
                    nx += dx5[dir][i];
                    ny += dy5[dir][i];
                    if (!checkRange(nx, ny)) break;
                    if (arr[nx][ny] == 0) input[nx][ny] = -1;
//                    ccq.add(new Pair(nx, ny));
                }
            }
        }
        return;
    }
}