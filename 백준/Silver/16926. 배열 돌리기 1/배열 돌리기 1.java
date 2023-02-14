import java.io.*;
import java.util.*;

public class Main {
    class Pair {
        int x;
        int y;
        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    static int n, m, r;
    static int[][] arr;
    static int[][] copy;
    static ArrayDeque<Pair> q[];
    static void rotate(int sy, int sx, int dy, int dx) {
        Queue<Integer> q = new LinkedList<>();
        for (int i = sx; i < dx; i++) {
            q.add(arr[sy][i]);
        }
        for (int i = sy; i < dy; i++) {
            q.add(arr[i][dx]);
        }
        for (int i = dx; i > sx; i--) {
            q.add(arr[dy][i]);
        }
        for (int i = dy; i > sy; i--) {
            q.add(arr[i][sx]);
        }
        for (int i = 0; i < r; i++) {
            q.add(q.poll());
        }
        for (int i = sx; i < dx; i++) {
            arr[sy][i] = q.poll();
        }
        for (int i = sy; i < dy; i++) {
            arr[i][dx] = q.poll();
        }
        for (int i = dx; i > sx; i--) {
            arr[dy][i] = q.poll();
        }
        for (int i = dy; i > sy; i--) {
            arr[i][sx] = q.poll();
        }


    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());
        arr = new int[n][m];
        copy = new int[n][m];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int sy = 0, sx = 0, dy = n - 1, dx = m - 1;
        while (sy < dy && sx < dx) {
            rotate(sy, sx, dy, dx);
            sy++;
            sx++;
            dy--;
            dx--;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bw.write(arr[i][j] + " ");
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}