import java.io.*;
import java.util.*;

public class Solution {
    static int n, k;
    static int[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int t = 1; t <= 10; t++) {
            int tn = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            ArrayDeque<Integer> q = new ArrayDeque<>();
            for (int i = 0; i < 8; i++) {
                int n = Integer.parseInt(st.nextToken());
                q.addLast(n);
            }
            int cnt = 0;
            while (true) {
                int cur = q.pollFirst() - ++cnt;
                if (cnt == 5) {
                    cnt = 0;
                }
                if (cur <= 0) {
                    cur = 0;
                    q.addLast(cur);
                    break;
                }
                q.addLast(cur);
            }
            System.out.print("#" + t + " ");
            for (Integer integer : q) {
                System.out.print(integer + " ");
            }
            System.out.println();
        }


    }
}