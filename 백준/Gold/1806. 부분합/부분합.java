import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        int a = 0, b = 0;
        int sum = arr[0];
        int min_length = 100000;
        while (true) {
            if (sum >= s) {
                sum -= arr[a];
                min_length = Math.min(min_length, b - a +1);
                a++;
            }
            if (b == n) {
                break;
            }
            if(sum < s) {
                if (b == n -1) {
                    break;
                }
                sum += arr[++b];
//                b++;
            }

        }
        if (min_length == 100000) {
            System.out.println(0);
        } else System.out.println(min_length);
    }
}
/*
10 21
11 2 5 6 8 9 2 3 10 9 10

10 10
1 1 1 1 1 1 1 1 1 10

10 10
3 3 3 3 3 3 3 3 3 3

*/