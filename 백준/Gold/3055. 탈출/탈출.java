import java.io.*;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int r, c;
    static char[][] arr;
    static class Node {
        int x;
        int y;
        int time;
        public Node(int x, int y, int time) {
            this.x = x;
            this.y = y;
            this.time = time;
        }
    }

    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};
    static Queue<Node> water = new ArrayDeque<>();
    static Queue<Node> hedgehogs = new ArrayDeque<>();
    static int[][] visitedHedgehog;
    static int[][] visitedWater;
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        arr = new char[r][c];
        visitedHedgehog = new int[r][c];
        visitedWater = new int[r][c];
        for (int i = 0; i < r; i++) {
            String s = br.readLine();
            for (int j = 0; j < c; j++) {
                arr[i][j] = s.charAt(j);
                if (arr[i][j] == '*') {
                    visitedWater[i][j] = 1;
                    water.add(new Node(i, j, 1));
                }
                else if (arr[i][j] == 'S') {
                    visitedHedgehog[i][j] = 1;
                    hedgehogs.add(new Node(i, j, 1));
                }
            }
        }
        moveWater();
        int ans = moveHedgehog();
        if (ans != -1) System.out.println(ans);
        else System.out.println("KAKTUS");
//        print();
    }
    public static void moveWater() {
        while (!water.isEmpty()) {
            Node p = water.poll();
            for (int i = 0; i < 4; i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                    continue;
                }
                if (visitedWater[nx][ny] != 0) continue;
                if (arr[nx][ny] != 'X' && arr[nx][ny] != 'D') {
                    visitedWater[nx][ny] = p.time + 1;
                    water.add(new Node(nx, ny, p.time + 1));
                }
            }
        }
    }
    public static int moveHedgehog() {
        while (!hedgehogs.isEmpty()) {
            Node curHedgeHog = hedgehogs.poll();
            if (visitedHedgehog[curHedgeHog.x][curHedgeHog.y] >= visitedWater[curHedgeHog.x][curHedgeHog.y]) {
                if (visitedWater[curHedgeHog.x][curHedgeHog.y] != 0) continue;
            }
            for (int i = 0; i < 4; i++) {
                int nx = curHedgeHog.x + dx[i];
                int ny = curHedgeHog.y + dy[i];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                    continue;
                }
                if (visitedHedgehog[nx][ny] > 0) continue;
                if (arr[nx][ny] == 'D') {
//                    if (visitedWater[curHedgeHog.x][curHedgeHog.y] >= curHedgeHog.time)continue;
                    return curHedgeHog.time;
                }
                if (arr[nx][ny] == '.') {
                    visitedHedgehog[nx][ny] = curHedgeHog.time + 1;
                    hedgehogs.add(new Node(nx, ny, curHedgeHog.time + 1));
                }
            }
//            print();
        }
        return -1;
    }
    public static void print() {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                System.out.print(visitedHedgehog[i][j]);
            }
            System.out.println();
        }
        System.out.println();
    }
}

/*

2 2
**
DS

5 3
...
.XD
..X
.S.
.*.

2 3
*.*
D.S

3 3
S..
.D.
...

 */