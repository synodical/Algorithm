import java.io.*;
import java.util.*;

public class Main {
    static int n, k;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        ArrayDeque<Integer> dq = new ArrayDeque<>();
        for (int i = 1; i <= n; i++) {
            dq.addLast(i);
        }
        while (true) {
            if (dq.size() == 1) {
                break;
            }
            dq.pollFirst();
            int cur = dq.pollFirst();
            dq.addLast(cur);
        }
        System.out.println(dq.pollFirst());
    }
}