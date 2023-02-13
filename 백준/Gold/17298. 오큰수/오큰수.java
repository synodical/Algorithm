import java.io.*;
import java.util.*;

public class Main {
    static int n, k;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        ArrayDeque<Integer> stack = new ArrayDeque<>(); // stack으로 쓸 거임\
        int[] arr = new int[n];
        int[] ans = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        stack.addFirst(arr[0]);
        for (int i = 1; i < n; i++) {
            while (!stack.isEmpty()) {
                if (stack.peekFirst() <=arr[i]) {
                    stack.pollFirst();
                } else {
                    break;
                }
            }
            if (!stack.isEmpty()) {
                ans[i] = stack.peekFirst();
            }
            stack.addFirst(arr[i]);
        }
        for (int i = n-1; i >= 0; i--) {
            if (ans[i] == 0) {
                bw.write("-1 ");
            } else {
                bw.write(ans[i] + " ");
            }
        }
        bw.flush();
        bw.close();
    }
}
