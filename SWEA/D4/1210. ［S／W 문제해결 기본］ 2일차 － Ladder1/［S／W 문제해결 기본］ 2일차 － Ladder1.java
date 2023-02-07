import java.io.*;
import java.util.*;

class Pair {
    int x;
    int y;
    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }
}
public class Solution {
    static int[][] arr = new int[100][100];
    static boolean[][] visit = new boolean[100][100];
    static List<Pair> start = new ArrayList<>();
    public static int sol() {
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                visit[i][j] = false;
            }
        }
        ArrayDeque<Pair> q = new ArrayDeque<>();
        for (int i = 0; i < 100; i++) {
            if (arr[99][i] == 2) {
                q.add(new Pair(99, i));
            }
        }

        while (!q.isEmpty()) {
            int x = q.peekFirst().x;
            int y = q.peekFirst().y;
            q.removeFirst();
            visit[x][y] = true;
            if (arr[x][y] == 1 && x == 0) {
                q.clear();
                return y;
            }
            if (y-1 >= 0 && arr[x][y-1] == 1 && !visit[x][y-1]) {
                q.add(new Pair(x, y - 1));
            } else if (y + 1 < 100 && arr[x][y + 1] == 1 && !visit[x][y+1]) {
                q.add(new Pair(x, y + 1));
            } else if (x>=1 && arr[x-1][y] == 1&& !visit[x-1][y]) {
                q.add(new Pair(x-1, y));
            }
        }
        return 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int t = 1; t <= 10; t++) {
            int tcn = Integer.parseInt(br.readLine());
            for (int i = 0; i < 100; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < 100; j++) {
                    int a = Integer.parseInt(st.nextToken());
                    arr[i][j] = a;
                }
            }
            System.out.println("#" + tcn + " " +sol());
        }
    }
}