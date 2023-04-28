import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int n;
    static int[][] arr;
    static int ans = 0;
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        arr = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        sol(0, arr);
        System.out.println(ans);
    }

    public static void sol(int idx, int[][] copy) {
        if (idx == 5) {
            int tmp = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    tmp = Math.max(tmp, copy[i][j]);
                }
            }
            ans = Math.max(ans, tmp);
            return;
        }
        int[][] board = new int[n][n];

        for (int dir = 0; dir < 4; dir++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    board[i][j] = copy[i][j];
                }
            }
            move(dir, board);
//            print(board);
            sol(idx + 1, board);
        }
    }

    public static void move(int dir, int[][] board) {
        if (dir == 0) { // 위
            for (int j = 0; j < n; j++) {
                int index = 0; // 넣을 자리
                int prev = 0; // 이전 한칸의 블록의 값
                for (int i = 0; i < n; i++) {
                    if (board[i][j] == 0) continue;
                    if (prev == board[i][j]) {
                        board[index - 1][j] = prev * 2;
                        prev = 0;
                        board[i][j] = 0;
                    } else {
                        prev = board[i][j];
                        board[i][j] = 0; // 앞으로 당기기
                        board[index][j] = prev;
                        index++;
                    }
                }
            }
        } else if (dir == 1) { // 오른
            for (int i = 0; i < n; i++) {
                int index = n-1; // 넣을 자리
                int prev = 0; // 이전 한칸의 블록의 값
                for (int j = n-1; j >=0; j--) {
                    if (board[i][j] == 0) continue;
                    if (prev == board[i][j]) {
                        board[i][index + 1] = prev * 2;
                        prev = 0;
                        board[i][j] = 0;
                    } else {
                        prev = board[i][j];
                        board[i][j] = 0; // 앞으로 당기기
                        board[i][index] = prev;
                        index--;
                    }
                }
            }
        } else if (dir == 2) { // 아래
            for (int j = 0; j < n; j++) {
                int index = n-1; // 넣을 자리
                int prev = 0; // 이전 한칸의 블록의 값
                for (int i = n-1; i >= 0; i--) {
                    if (board[i][j] == 0) continue;
                    if (prev == board[i][j]) {
                        board[index + 1][j] = prev * 2;
                        prev = 0;
                        board[i][j] = 0;
                    } else {
                        prev = board[i][j];
                        board[i][j] = 0; // 앞으로 당기기
                        board[index][j] = prev;
                        index--;
                    }
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                int index = 0; // 넣을 자리
                int prev = 0; // 이전 한칸의 블록의 값
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == 0) continue;
                    if (prev == board[i][j]) {
                        board[i][index-1] = prev * 2;
                        prev = 0;
                        board[i][j] = 0;
                    } else {
                        prev = board[i][j];
                        board[i][j] = 0; // 앞으로 당기기
                        board[i][index] = prev;
                        index++;
                    }
                }
            }
        }
    }

    public static void print(int[][] copy) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(copy[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }
}