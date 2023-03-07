import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static class Pair implements Comparable<Pair> {
        int cnt;
        int x;
        int y;

        public Pair(int cnt, int x, int y) {
            this.cnt = cnt;
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Pair o) {
            int dist = this.cnt - o.cnt;
            if (dist == 0) {
                int cur = this.x - o.x;
                if (cur == 0) {
                    return this.y - o.y;
                }
                return cur;
            }
            return dist;
        }
    }
    static int n;
    static int[][] arr;
    static List<Pair> fishes;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        arr = new int[n][n];
        fishes = new ArrayList<>();
        int sx = 0, sy = 0;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] == 9) {
                    sx = i;
                    sy = j;
                } else if (arr[i][j] != 0 && arr[i][j] != 9) fishes.add(new Pair(0, i, j));
            }
        }
        Collections.sort(fishes);
        sol(sx, sy);

    }
    static void sol(int x, int y) {
        int time = 0;
        int size = 2;
        int eatenFish = 0;
        while (true) {
            Pair near = getNearest(size, x, y);
            if (near == null) {
                break;
            }
            time += near.cnt;
            arr[near.x][near.y] = 9;
            arr[x][y] = 0;
            for (Pair p : fishes) {
                if (p.x == near.x && p.y == near.y) {
                    fishes.remove(p);
                    break;
                }
            }
            eatenFish++;
            if (size == eatenFish) {
                size++;
                eatenFish = 0;
            }
            x = near.x;
            y = near.y;

        }
        System.out.println(time);
    }

    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};
    static Pair getNearest(int size, int x, int y) {
        Queue<Pair> q = new ArrayDeque<>();
        List<Pair> canEat = new ArrayList<>();
        boolean[][] visit = new boolean[n][n];

        visit[x][y] = true;

        int cnt = 0;
        q.add(new Pair(0, x, y));
        while (!q.isEmpty()) {
            Pair cur = q.poll();

            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                    continue;
                }
                if (visit[nx][ny]) continue;
                visit[nx][ny] = true;
                if (size < arr[nx][ny]) continue;
                else if (size > arr[nx][ny] && arr[nx][ny] != 0) {
                    canEat.add(new Pair(cur.cnt + 1, nx, ny));
                }
                q.add(new Pair(cur.cnt+1, nx, ny));
//                cnt++;
            }
        }
        Collections.sort(canEat);
        if (canEat.size() == 0) return null;
        return canEat.get(0);
    }

    static void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println();
    }
}