
import java.io.*;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    static int[] Parent = new int[10001];
    static int[] Level = new int[10001];

    private static int getParent(int n1, int cnt) {
        if (Parent[n1] == n1) return n1;
        else return Parent[n1] = getParent(Parent[n1], cnt + 1);
    }
    private static int getLevel(int n1) {
        int cnt = 0;
        while (true) {
            if (Parent[n1] == n1) break;
            n1 = Parent[n1];
            cnt++;
        }
        return cnt;
    }
    private static void setLevel(int n1) {
        if (Parent[n1] == 0) Level[n1] = 0;
        else { // 부모가 존재
            Level[n1] = Level[Parent[n1]] + 1;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(br.readLine());
        for (int tc = 0; tc < t; tc++) {
            int n = Integer.parseInt(br.readLine());
            for (int i = 1; i <= n; i++) { // 초기화
                Level[i] = 0;
                Parent[i] = i;
            }
            StringTokenizer st;
            for (int i = 0; i < n - 1; i++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                Parent[b] = a;
            }

            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            for (int i = 1; i <= n; i++) {
                Level[i] = getLevel(i);
            }
            while (true) {
                if (Level[x] == Level[y]) {
                    break;
                } else if (Level[x] < Level[y]) {
                    y = Parent[y];
                } else {
                    x = Parent[x];
                }
            }

            while (true) {
                if (x == y) {
                    bw.write(x + "\n");
                    break;
                }
                x = Parent[x];
                y = Parent[y];
            }
        }
        bw.flush();
        bw.close();
        br.close();
    }


}
