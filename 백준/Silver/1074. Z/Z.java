import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static int n, r, c;
    static int size;
    static int ans = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        size = (int) Math.pow(2, n);
        sol(0, 0, size, 0);
    }
    static void sol(int x, int y, int size, int cur) {
        if (size == 1) {
            if (r == x && c == y) {
                BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
                System.out.println(ans + cur);
                return;
            }
            ans++;
            return;
        }
        int half = size / 2;
        if (r < x+half && c < y+half) {
            sol(x, y, half, cur+0);
        } else if (r < x+half && c >= y+half) {
            sol(x, y + half, half, cur+half * half);
        } else if (r >= x+half && c < y+half) {
            sol(x + half, y, half, cur+half * 2 *half);
        } else  {
            sol(x + half, y + half, half, cur+half * half * 3);
        }
//        sol(x, y, half);
//        sol(x, y + half, half);
//        sol(x + half, y, half);
//        sol(x + half, y + half, half);
    }
}

/*
5 2 26
332

10 0 1023

2 3 1
11

5 0 31

2 0 3

 */