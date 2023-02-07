import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

// nPr
// N개 중에 R개를 뽑아 순서있게 늘어 놓기
public class Main {
    static int N, R, totalCount;
    static int[] result, numbers;
    // result: 순열로 뽑힌 숫자들이 들어있는 배열
    // numbers: 전체 데이터가 들어있는 배열
    static boolean[] isSelected;
    // 순열에 사용된 숫자인지 체크하기 위한 배열
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        R = sc.nextInt();
        numbers = new int[N];
        result = new int[R]; // 최종 뽑힌 순열
        isSelected = new boolean[N];
        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = i + 1;
        }
        perm(0);
        System.out.println(sb.toString());
    }
    // 현재까지 뽑힌 숫자 개수를 입력받아 체크한 뒤 종료하거나 숫자를 뽑음
    // cnt = 이제까지 뽑은 순열을 구성하는 숫자 개수
    private static void perm(int cnt) throws IOException {
        if (cnt == R) { // 다 뽑음
            totalCount++;
            for (int i = 0; i < result.length; i++) {
                sb.append(result[i]).append(" ");
            }
            sb.append("\n");
            return;
        }
        for (int i = 0; i < N; i++) { // 전체 숫자를 대상으로 뽑기 (0~N)
            if (isSelected[i]) continue;
            isSelected[i] = true;
            result[cnt] = numbers[i]; // i번째 값을 선택

            perm(cnt + 1); // 다음 숫자 뽑으러 보냄 (다음 사람한테 보냄)
            isSelected[i] = false; // 사용했던 위치 해제
        }

    }
}