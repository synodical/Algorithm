import javax.naming.spi.DirObjectFactory;
import java.io.*;
import java.util.*;

public class Main {
    static int t;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        t = Integer.parseInt(st.nextToken());
        int[][] arr = new int[100][100];
        int ans = 0;
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            for (int i = a; i < a + 10; i++) {
                for (int j = b; j < b + 10; j++) {
                    if (arr[i][j] != 1) {
                        ans++;
                        arr[i][j] = 1;
                    }
                }
            }
        }
        System.out.println(ans);
    }

}