import java.io.*;
import java.util.*;

public class Solution {
    static int n, k;
    static int[] arr;
    static Map<Character, Character> map = new HashMap<>();



    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        map.put('(', ')');
        map.put('<', '>');
        map.put('[', ']');
        map.put('{', '}');
        for (int t = 1; t <= 10; t++) {
            int tn = Integer.parseInt(br.readLine());
            String s = br.readLine();
            Stack<Character> st = new Stack<>();
            boolean flag = true;
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                if (c == '(' || (c == '{' || (c == '[' || (c == '<')))) {
                    st.push(c);
                } else {
                    if (map.get(st.peek()) == c) {
                        st.pop();
                    } else {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) {
                System.out.println("#" + t + " " + 1);
            } else {
                System.out.println("#" + t + " " + 0);
            }
        }


    }
}