import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        int[] dy = {1, 0, -1, 0};
        int[] dx = {0, 1, 0, -1};
        for (int t = 1; t <= tc; t++) {
            int n = sc.nextInt();
            int[][] arr = new int[n][n];
            int x = 0, y = 0;
            int i = 0;
            int cnt = 1;
            while (true) {
                arr[x][y] = cnt;
                if (cnt == n * n) {
                    break;
                }
                cnt++;
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] != 0) {
                    i = (i + 5) % 4;
                }
                nx = x + dx[i];
                ny = y + dy[i];
                x = nx;
                y = ny;
            }
            System.out.println("#" + t);
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    System.out.print(arr[j][k] + " ");
                }
                System.out.println();
            }
        }
    }
}