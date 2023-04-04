import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;

/* 
6
3 2 6 4 5 1
==>3

10
8 2 4 3 6 11 7 10 14 5
==>6
 */

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static void main(String[] args) throws Exception {
		
		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N];
		int[] C = new int[N];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());
		
		C[0] =arr[0];
		
		int end = 1;
		ArrayList<Integer> list = new ArrayList<>();
		list.add(0);
        for (int i=1; i < N; i++) {
        	// 검색 실패: 삽입할 위치 -1
            int insertPosition = Arrays.binarySearch(C, 0, end, arr[i]); 
            
            if (insertPosition>=0) {
            	list.add(insertPosition);
            	continue;
            }
            insertPosition = Math.abs(insertPosition)-1;  
            // 실제 배열에 삽입할 위치
//            if (end-1 > insertPosition) continue;
            C[insertPosition] = arr[i];
            list.add(insertPosition);
            if (end == insertPosition) {
                end++;               
            }
//            System.out.println(Arrays.toString(C) + " " + end);
        }
//        System.out.println(list);
        Stack<Integer> stack = new Stack<>();
        int idx = end-1;
        for (int i=N-1; i>=0 ; i--) {
        	if (list.get(i) == idx) {
        		stack.push(arr[i]);
        		idx--;
        	}
        }
        bw.write(end+"\n");
        while(!stack.isEmpty()) {
        	bw.write(stack.pop() + " ");
        }
        bw.flush();
        bw.close();
        
	}

}
/*

6
1 3 4 5 2 4
*/