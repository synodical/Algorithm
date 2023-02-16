import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
    static int total;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int t = Integer.parseInt(br.readLine());
        for (int tc = 0; tc < t; tc++) {
            int[] kyu = new int[9];
            boolean[] b = new boolean[18];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < 9; i++) {
                kyu[i] = Integer.parseInt(st.nextToken());
                b[kyu[i] - 1] = true;
            }
            int[] in = new int[9];
            int start = 0;
            for (int i = 0; i < 18; i++) {
                if (!b[i]) in[start++] = i + 1;
            }
            int kyuWin =0;
            Arrays.sort(in);

            do {
//                System.out.println(Arrays.toString(in));
                int kyuScore = 0;
                int inScore = 0;
                for (int i = 0; i < 9; i++) {
                    if (kyu[i] > in[i]) {
                        kyuScore += (kyu[i] + in[i]);
                    } else if (kyu[i] < in[i]) {
                        inScore += (kyu[i] + in[i]);
                    }
                }
                if (kyuScore > inScore) {
                    kyuWin++;
                }
            } while (np(in));
            bw.write("#" + (tc + 1) + " " + kyuWin + " " + (362880 - kyuWin) + "\n");
            total = 0;
        }
        bw.flush();
        bw.close();
    }
    private static boolean np(int numbers[]) {
        total++;
        int N = numbers.length;

        int i = N - 1;
        while (i > 0 && numbers[i - 1] >= numbers[i])
            --i;

        if (i == 0)
            return false;

        int j = N - 1;
        while (numbers[i - 1] >= numbers[j])
            --j;
        swap(numbers, i - 1, j);

        int k = N - 1;
        while (i < k) {
            swap(numbers, i++, k--);
        }
        return true;
    }

    private static void swap(int numbers[], int i, int j) {
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
}