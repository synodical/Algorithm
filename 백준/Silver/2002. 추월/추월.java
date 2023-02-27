import java.io.*;
import java.util.*;
public class Main {
    static int t, n, m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        HashMap<String, Integer> mp = new HashMap<String, Integer>();
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            mp.put(s, i);
        }
        String [] arr = new String[n];
        for (int i = 0; i < n; i++) {
            arr[i] = br.readLine();
        }
        int ans = 0;
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if (mp.get(arr[i]) > mp.get(arr[j])) {
                    ans++;
                    break;
                }
            }
        }
        System.out.println(ans);
    }
}