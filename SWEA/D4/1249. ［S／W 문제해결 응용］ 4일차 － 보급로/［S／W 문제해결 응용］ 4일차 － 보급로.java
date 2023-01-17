import java.util.ArrayList;
import java.util.*;
import java.io.FileInputStream;

class Pair {
    Integer x;
    Integer y;
    public Pair(Integer x, Integer y) {
        this.x = x;
        this.y = y;
    }
    public Integer getX() {
        return x;
    }
    public Integer getY() {
        return y;
    }
}
public class Solution {
    static int INF = 987654321;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};

    static Queue<Pair> q = new LinkedList<Pair>();
    static int[][] arr = new int[100][100];
    static int[][] cost = new int[100][100];

    static int n = 0;

    public static void bfs() {
        while (!q.isEmpty()) {
            Pair p = q.poll();
            int x = p.getX();
            int y = p.getY();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                    continue;
                }
                if (cost[nx][ny] > cost[x][y] + arr[nx][ny]) {
                    cost[nx][ny] = cost[x][y] + arr[nx][ny];
                    q.add(new Pair(nx, ny));
                }
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        for (int t = 1; t <= tc; t++) {
            n = sc.nextInt();
            sc.nextLine();
            for (int a[] : cost) {
                Arrays.fill(a, INF);
            }
            for (int i = 0; i < n; i++) {
                String s = sc.nextLine();
                for (int j = 0; j < n; j++) {
                    int c = s.charAt(j) - '0';
                    arr[i][j] = c;
                }
            }
            cost[0][0] = arr[0][0];
            q.add(new Pair(0, 0));
            bfs();
            System.out.println("#" + t + " " + cost[n-1][n-1]);
        }
    }

}