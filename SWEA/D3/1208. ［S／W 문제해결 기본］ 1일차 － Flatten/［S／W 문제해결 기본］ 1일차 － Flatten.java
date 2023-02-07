import java.io.*;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.StringTokenizer;

public class Solution {
    static Integer[] boxes = new Integer[100];
    static int[] sorted = new int[100];
    public static int dump(int d) {
        Arrays.sort(boxes, Collections.reverseOrder());
        while (d-- >= 0) {
            Arrays.sort(boxes, Collections.reverseOrder());
            boxes[0] -= 1;
            boxes[99] += 1;

        }
        return (boxes[0] - boxes[99] + 2);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int t = 1; t <= 10; t++) {
            int d = Integer.parseInt(br.readLine());

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < 100; i++) {

                int a = Integer.parseInt(st.nextToken());
                boxes[i] = a;
            }
            System.out.println("#" + t + " " +dump(d));
        }
    }
}