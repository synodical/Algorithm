import javax.naming.spi.DirObjectFactory;
import java.io.*;
import java.util.*;

public class Main {
    static int n, m, r;
    static int[][] map;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};
    static class Pair {
        int x;
        int y;
        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    static int[][] cmd1 (int[][] arr,int n, int m) {
        int[][] copy = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                copy[n - i - 1][j] = arr[i][j];
            }
        }
        return copy;
    }

    static int[][] cmd2 (int[][] arr, int n, int m) {
        int[][] copy = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                copy[i][m-1-j] = arr[i][j];
            }
        }
        return copy;
    }
    static int[][] cmd3 (int[][] arr,int n, int m) {
        int[][] copy = new int[m][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                copy[j][n-1-i] = arr[i][j];
            }
        }
        return copy;
    }

    static int[][] cmd4 (int[][] arr, int n, int m) {
        int[][] copy = new int[m][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                copy[m-1-j][i] = arr[i][j];
            }
        }
        return copy;
    }

    static int[][] cmd5 (int[][] arr,int n, int m) {
        int[][] copy = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (0 <= i && i < n / 2 && 0 <= j && j < m / 2) { // 1-> 2
                    copy[i][m / 2 + j] = arr[i][j];
                } else if (0 <= i && i < n / 2 && m / 2 <= j && j < m) { // 2->3
                    copy[i + n / 2][j] = arr[i][j];
                } else if (n / 2 <= i && i < n && 0 <= j && j < m / 2) { // 4->1
                    copy[i - n/2][j] = arr[i][j];
                } else { // 3->4
                    copy[i][j - m / 2] = arr[i][j];
                }
            }
        }
        return copy;
    }

    static int[][] cmd6 (int[][] arr, int n, int m) {
        int[][] copy = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                copy[i][j] = arr[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (0 <= i && i < n / 2 && 0 <= j && j < m / 2) { // 1-> 4
                    copy[i + n/2][j] = arr[i][j];
                } else if (0 <= i && i < n / 2 && m / 2 <= j && j < m) { // 2->1
                    copy[i][j - m/2] = arr[i][j];
                } else if (n / 2 <= i && i < n && 0 <= j && j < m / 2) { // 4->3
                    copy[i][j+m/2] = arr[i][j];
                } else { // 3->2
                    copy[i-n/2][j] = arr[i][j];
                }
            }
        }
        return copy;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());
        map = new int[n][m];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        st = new StringTokenizer(br.readLine());
        int[][] arr = map;
        for (int i = 0; i < r; i++) {
            int a = Integer.parseInt(st.nextToken());
            int[][] cur;
            if (a == 1) {
                cur = cmd1(arr, arr.length, arr[0].length);
            } else if (a == 2) {
                cur = cmd2(arr, arr.length, arr[0].length);
            } else if (a == 3) {
                cur = cmd3(arr, arr.length, arr[0].length);
            } else if (a == 4) {
                cur = cmd4(arr, arr.length, arr[0].length);
            } else if (a == 5) {
                cur = cmd5(arr, arr.length, arr[0].length);
            } else {
                cur = cmd6(arr, arr.length, arr[0].length);
            }
            arr = cur;
        }

        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[0].length; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }

    }

}

/*
6 8 4
3 2 6 3 1 2 9 7
9 7 8 2 1 4 5 3
5 9 2 1 9 6 1 8
2 1 3 8 6 3 9 2
1 3 2 8 7 9 2 1
4 5 1 9 8 2 1 3
1 2 3 4


 */