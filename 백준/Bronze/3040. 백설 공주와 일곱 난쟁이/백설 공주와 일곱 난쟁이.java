import java.io.*;
import java.lang.reflect.Parameter;
import java.util.*;

public class Main {


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int sum = 0;
        int[] arr = new int[9];
        for (int i = 0; i < 9; i++) {
            sum += arr[i] = Integer.parseInt(br.readLine());
        }
        int sub = sum - 100;
        w1: for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (i == j) continue;
                if (arr[i] + arr[j] == sub) {
                    arr[i] = arr[j] = 0;
                    break w1;
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            if (arr[i] != 0) {
                System.out.println(arr[i]);
            }
        }
    }

}

/*
1
10
11
12
13
14
15
25
9

 */