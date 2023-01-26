
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    static int a;
    static String s;
    static String[] text = {"000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010"};
    // text 배열: 일종의 사전. ABC ... 오름차순 정렬
    static String ans = "";
    static boolean idk = false;
    static int idk_index = 0;
    static void sol() {
        for (int i = 0; i < s.length() / 6; i++) {
            // 6글자 단위로 끊어서 읽어야 함
            // 6*i로 증가하는 첫 글자

            List<Integer> fail = new ArrayList<>(0);
            // fail 배열: 사전에 있는 단어와 현재 단어가 다른 글자의 개수를 기록하는 배열
            // contains 사용을 위해 arrarylist 사용
            for (int j = 0; j < 8; j++) {
                fail.add(0);
            } // fail 배열 초기화

            for (int k = 0; k < text.length; k++) {
                // text라는 사전 배열을 순회하며 비교
                for (int j = 0; j < 6; j++) {
                    if (text[k].charAt(j) != s.charAt(6*i+j)) {
                        // text의 단어와 현재 단어가 다르다면 fail[k]++
                        fail.set(k, fail.get(k) + 1); // int array 형인 fail[k]++와 같은 문법
                    }
                }

            }

            if (fail.contains(0)) {
                // fail 배열이 0을 포함한다 ==
                // 현재 보고있는 6글자(6*i + j)와 글자가 하나도 다르지 않은,
                // 즉 완전히 같은 단어가 존재한다
                ans += (char)(65+ fail.indexOf(0));
            } else if (fail.contains(1)) {
                // fail 배열이 1을 포함한다 ==
                // 현재 보고있는 6글자(6*i + j)와 한 글자만 다른 단어가 있다.
                ans += (char)(65+ fail.indexOf(1));
            } else if (!fail.contains(0) && !fail.contains(1)) {
                // text(사전)에 존재하는 모든 단어와 2글자 이상 다 다르다
                // 즉 이 단어를 모른다는 뜻
                idk = true;
                idk_index = i+1;
                // fail 배열이 모두 2 이상인 index
                // 즉 모든 단어를 모르는 현재의 인덱스 i 출력
                break;
            }
        }
        if (idk) {
            System.out.println(idk_index);
        } else {
            System.out.println(ans);
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        // 1st tc
        a = in.nextInt();
        s = in.next();

        sol();

    }
}

