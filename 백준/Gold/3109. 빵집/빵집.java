import java.io.*;
import java.util.*;

public class Main {
    static int n, cnt, r, c;
    static char[][] arr;
    static StringBuilder sb = new StringBuilder();
    static int[] dx = {-1, 0, 1};
    static int[] dy = {1, 1, 1};
    static boolean flag = false;

    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        arr = new char[r][c];
        for (int i = 0; i < r; i++) {
            String s = br.readLine();
            for (int j = 0; j < c; j++) {
                arr[i][j] = s.charAt(j);
            }
        }
        for (int i = 0; i < r; i++) {
            sol(i, 0);
            flag = false;
        }
        System.out.println(cnt);
    }

    static void sol(int row, int col) { // cur column = idx
//        pipe[row][col] = 1;
        if (col == c-1) {
//            System.out.println(row+ " " + col);
            cnt++;
            flag = true;
            return;
        }
        for (int i = 0; i < 3; i++) {
            int nx = row + dx[i];
            int ny = col + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c || arr[nx][ny] == 'x' || arr[nx][ny] == '1') continue;
            // 해당 출발지에서
            if (flag) continue;
            // 여기까지 왔다는 건 아직 최적의 경로가 등장하지 않았다는 뜻.
            arr[nx][ny] = '1';
            sol(nx, ny);
        }
    }

}

/*
5 5
.x...
..xxx
xxxxx
xxxxx
xxxxx

1

5 9
.x.....x.
.x..x..x.
.x..x..x.
....x....
.x..x..x.

1

15 15
.xxxxxxxxxx....
...x.......xxx.
...x.......x...
..xx.......xx..
...x........xx.
.x.x......x.x..
...x......xx...
.x.x....xxx....
.x....x.x......
.x.....xx.x....
.x..x.xx.......
.....xx........
....x..........
......x........
...............

4

3 3
xx.
...
...

 */