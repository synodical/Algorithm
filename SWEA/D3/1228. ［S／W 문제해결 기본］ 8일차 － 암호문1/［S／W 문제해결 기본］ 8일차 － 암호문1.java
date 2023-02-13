import java.io.*;
import java.util.*;

public class Solution {
    static int n, k;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int t = 1; t <= 10; t++) {
            n = Integer.parseInt(br.readLine());
            List<String> arr = new ArrayList<>();
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                String s = st.nextToken();
                arr.add(s);
            }
            int cmd = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < cmd; i++) {
                char c = (st.nextToken()).charAt(0);
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                for (int j = 0; j < y; j++) {
                    String s = st.nextToken();
                    arr.add(x++, s);
                }
            }
            System.out.print("#" + t);
            for (int i = 0; i < 10; i++) {
                System.out.print(" "+arr.get(i));
            }
            System.out.println();
        }
    }
}