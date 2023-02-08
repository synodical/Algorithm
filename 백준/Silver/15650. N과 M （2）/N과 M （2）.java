import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int n, m;
    static int[] numbers;
    static int[] result;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        numbers = new int[n];
        result = new int[m];
        for (int i = 0; i < n; i++) {
            numbers[i] = i + 1;
        }
        combi(0, 0);
    }

    static void combi(int cnt, int start) {
        if (cnt == m) {
            for (int i = 0; i < result.length; i++) {
                System.out.print(result[i] + " ");
            }
            System.out.println();
            return;
        }
        for (int i = start; i < n; i++) {
            result[cnt] = numbers[i];
            combi(cnt + 1, i + 1);
        }

    }
}