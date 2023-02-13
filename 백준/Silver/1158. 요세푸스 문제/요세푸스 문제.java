import java.io.*;
import java.util.*;

public class Main {
    static int n, k;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        List<Integer> arr = new ArrayList<>();
        ArrayDeque<Integer> d = new ArrayDeque<>();
        for (int i = 1; i <= n; i++) {
            d.addLast(i);
        }
        System.out.print("<");
        while (!d.isEmpty()) {
            for (int i = 0; i < k-1; i++) {
                d.addLast(d.getFirst());
                d.pollFirst();
            }
            System.out.print(d.getFirst());
            d.pollFirst();
            if (d.size() == 0) continue;
            System.out.print(", ");
        }
        System.out.print(">");
    }
}