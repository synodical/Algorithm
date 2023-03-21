import java.io.*;
import java.util.*;

public class Main {
    static int n, init;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        init = Integer.parseInt(br.readLine());
        String s = br.readLine();
        int a = 0;
        int b = 1;
        int maxLen = 0;
        n = init;

        HashSet<Character> set = new HashSet<>();
        set.add(s.charAt(a));
        while (b > a && b < s.length()) {
            if (set.contains(s.charAt(b))) {
                b++;
            } else {
                if (set.size() < n) {
                    set.add(s.charAt(b));
                    b++;
                } else {
                    maxLen = Math.max(maxLen, b - a);
//                    System.out.println(a + " " + b + " " +maxLen);
                    a = a+ 1;
                    b = a + 1;
                    set.clear();
                    if (b <= s.length()) {
//                        break;
                    }
                    set.add(s.charAt(a));
                    set.add(s.charAt(b));
                }
            }
        }
        maxLen = Math.max(maxLen, b - a);
        System.out.println(maxLen);
    }
}

/*
2
ueeyyy

2
abbcaccba

5
aaaaa

2
aaabb

2
ababcc

* */