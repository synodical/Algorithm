class Solution {
    int[] answer = new int[2];
    int[][] arr;
    public int[] solution(int[][] input) {
        arr = new int[input.length][input.length];
        for(int i =0;i<input.length; i++) {
            for(int j =0;j<input[0].length;j++) {
                arr[i][j] = input[i][j];
            }
        }
        sol(0,0,arr.length);
        
        return answer;
    }
    void sol(int r, int c, int size) {
        boolean flag = true;
        if(size == 2) {
            int res = arr[r][c] + arr[r][c + 1] + arr[r + 1][c] + arr[r + 1][c + 1];
            if (res == 4 || res == 0) {
                answer[arr[r][c]]++;
            } else {
                answer[arr[r][c]]++;
                answer[arr[r][c+1]]++;
                answer[arr[r+1][c]]++;
                answer[arr[r+1][c+1]]++;
            }
            return;
        }
        for(int i = r; i < r+size; i++) {
            for(int j = c; j < c+size; j++) {
                if(arr[r][c] != arr[i][j]) {
                    flag = false;
                }
            }
        }
        if(flag) {
            answer[arr[r][c]]++;
            return;
        } else {
            sol(r, c, size / 2);
            sol(r, c + size / 2, size / 2);
            sol(r + size / 2, c, size / 2);
            sol(r + size / 2, c + size / 2, size / 2);
        }
    }
}