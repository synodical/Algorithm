import java.io.*;
import java.util.*;

public class Solution {
    static int h,w,t,n;
    static char[][] arr;
    static char[] cmd;

    static class Pair {
        int x;
        int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.parseInt(br.readLine());
        for (int tc = 0; tc < t; tc++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            h = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());
            arr = new char[h][w];
            int x = 0, y = 0;
            for (int i = 0; i < h; i++) {
                String s = br.readLine();
                for (int j = 0; j < w; j++) {
                    arr[i][j] = s.charAt(j);
                    if (arr[i][j] == '^' || arr[i][j] == '<' || arr[i][j] == '>' || arr[i][j] == 'v') {
                        x = i;
                        y = j;
                    }
                }
            }
            n = Integer.parseInt(br.readLine());
            cmd = new char[n];

            String s = br.readLine();
            for (int i = 0; i < n; i++) {
                cmd[i] = s.charAt(i);
            }

            for (int i = 0; i < n; i++) {
                if (cmd[i] == 'S') {
                    shoot(x, y);
                } else {
                    Pair nxt = go(cmd[i], x, y);
                    x = nxt.x;
                    y = nxt.y;
                }
            }
            System.out.print("#"+ (tc+1) + " ");
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    System.out.print(arr[i][j]);
                }
                System.out.println();
            }
        }
    }

    static boolean checkGo(int x, int y, int nx, int ny) {
        if (nx <0 || nx>=h|| ny<0|| ny>=w) return false;
        return arr[nx][ny] == '.';
    }
    static Pair go(char c, int x, int y) {
        int nx = x, ny = y;
        char cur = '0';
        if (c =='U') {
            nx = x - 1;
            cur = '^';
        } else if (c =='L') {
            ny = y - 1;
            cur = '<';
        } else if (c =='R') {
            ny = y + 1;
            cur = '>';
        } else {
            nx = x + 1;
            cur = 'v';
        }

        if (checkGo(x, y, nx, ny)) {
            arr[nx][ny] = cur;
            arr[x][y] = '.';
            return new Pair(nx, ny);
        } else {
            arr[x][y] = cur;
            return new Pair(x, y);
        }

    }

    static void shoot(int x, int y) {
        if (arr[x][y] == '^') {
            for (int i = x-1; i >= 0; i--) {
                if (arr[i][y] == '*') {
                    arr[i][y] = '.';
                    break;
                } else if (arr[i][y] == '#') {
                    break;
                }
            }
        } else if (arr[x][y] == '<') {
            for (int i = y-1; i >= 0; i--) {
                if (arr[x][i] == '*') {
                    arr[x][i] = '.';
                    break;
                } else if (arr[x][i] == '#') {
                    break;
                }
            }
        } else if (arr[x][y] == '>') {
            for (int i = y+1; i <w; i++) {
                if (arr[x][i] == '*') {
                    arr[x][i] = '.';
                    break;
                } else if (arr[x][i] == '#') {
                    break;
                }
            }
        } else {
            for (int i = x; i < h; i++) {
                if (arr[i][y] == '*') {
                    arr[i][y] = '.';
                    break;
                } else if (arr[i][y] == '#') {
                    break;
                }
            }
        }
    }

}