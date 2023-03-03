import java.io.*;
import java.util.*;
public class Main {
    static int R,C,T, ans, h;

    static int[][] arr;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static class Pair {
        int x;
        int y;
        int dust;
        Pair(int x, int y, int dust) {
            this.x = x;
            this.y = y;
            this.dust = dust;
        }
    }
    static Queue<Pair> q= new ArrayDeque<>();
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        R= Integer.parseInt(st.nextToken());
        C= Integer.parseInt(st.nextToken());
        T= Integer.parseInt(st.nextToken());
        arr = new int[R][C];
        Pair robot = null;
        for(int i =0; i< R;i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<C; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());

                if (arr[i][j] == -1) {
                    if (robot == null) robot = new Pair(i, j, 0);
                }
            }
        }
        while(T-- > 0) {
            for(int i =0; i< R;i++) {
                for(int j=0; j<C; j++) {
                    if(arr[i][j] > 0) q.add(new Pair(i, j, arr[i][j]));
                }
            }
            bfs();
//            print();
//            System.out.println();

            rotate(robot);
//            print();
//            System.out.println();
        }
        System.out.println(getAll());

    }
    private static void rotate(Pair robot) {
        int X = robot.x;
        // 다 돌리고 로봇위치만 -1?
        for (int x = X-2; x >= 0; x--) { //1
            arr[x + 1][0] = arr[x][0];
        }
        for (int y = 0; y < C-1; y++) { //2
            arr[0][y] = arr[0][y + 1];
        }
        for (int x = 0; x < X; x++) { // 3
            arr[x][C - 1] = arr[x + 1][C - 1];
        }
        for (int y = C - 2; y > 0; y--) { // 4
            arr[X][y + 1] = arr[X][y];
        }
        arr[X][1] = 0;
        X += 1; // 아래 회전
        for (int x = X+1; x < R-1; x++) {
             arr[x][0] = arr[x + 1][0];
        }
        for (int y = 0; y < C-1; y++) {
            arr[R-1][y] = arr[R-1][y + 1];
        }
        for (int x = R-2; x >= X; x--) {
             arr[x + 1][C - 1] = arr[x][C - 1];
        }
        for (int y = C-2; y > 0; y--) {
            arr[X][y+1] = arr[X][y];
        }
        arr[X][1] = 0;

    }

    static int[] dx= {-1,0,1,0};
    static int[] dy= {0,1,0,-1};
    static void bfs() {

        while(!q.isEmpty()) {
            Pair cur = q.poll();
            if (cur.dust < 5) continue;
            int cnt = 0; // 확산 가능한 칸의 수
            int amount = (int) Math.floor(cur.dust / 5);
            for (int i =0;i<4;i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx >= 0 && nx < R && ny >= 0 && ny < C && arr[nx][ny] != -1) {
                    arr[nx][ny] += amount;
                    cnt++;
                }

            }
//            if (cnt == 0) continue;
            arr[cur.x][cur.y] -= amount*cnt;
        }
    }

    static int getAll() {
        for(int i =0; i< R;i++) {
            for(int j=0; j<C; j++) {
                if (arr[i][j] == -1) continue;
                ans += arr[i][j];
            }
        }
        return ans;
    }
    static void print() {
        for(int i =0; i< R;i++) {
            for(int j=0; j<C; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }
}

/*
2 3 4 3 2 5 3 3
4 5 2 1 0 4 2 0
4 1 3 2 4 4 3 0
-1 0 0 0 0 0 0 1
-1 0 0 0 0 0 0 1
4 1 3 2 4 4 3 0
4 5 2 1 0 4 2 0
2 3 4 3 2 5 3 3


 */