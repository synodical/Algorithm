import java.io.*;
import java.util.*;

public class Main {
    static int n, k;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        ArrayDeque<Integer> stack = new ArrayDeque<>(); // stack으로 쓸 거임
        int[] arr = new int[n+1];
        int[] ans = new int[n+1];
        if (n == 1) {
            System.out.print(0);
            return;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        stack.addFirst(0);
        for (int i = 1; i < n; i++) {
            while (!stack.isEmpty() && arr[stack.peekFirst()] < arr[i]) {
                stack.pollFirst();
            }
            if (!stack.isEmpty()) ans[i] = stack.peekFirst()+1;
            stack.addFirst(i);
        }
        for (int i = 0; i < n; i++) {
            System.out.print(ans[i] + " ");
        }
    }
}

/*
10
10 9 7 5 3 1 2 4 6 8

* */