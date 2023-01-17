# [Gold IV] Luxury River Cruise - 5829 

[문제 링크](https://www.acmicpc.net/problem/5829) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

깊이 우선 탐색(dfs), 그래프 이론(graphs), 그래프 탐색(graph_traversal)

### 문제 설명

<p>Farmer John is taking Bessie and the cows on a cruise! They are sailing on a network of rivers with N ports (1 <= N <= 1,000) labeled 1..N, and Bessie starts at port 1. Each port has exactly two rivers leading out of it which lead directly to other ports, and rivers can only be sailed one way.</p><p>At each port, the tour guides choose either the "left" river or the "right" river to sail down next, but they keep repeating the same choices over and over. More specifically, the tour guides have chosen a short sequence of M directions (1 <= M <= 500), each either "left" or "right", and have repeated it K times (1 <= K <= 1,000,000,000). Bessie thinks she is going in circles -- help her figure out where she ends up!</p>

### 입력 

 <ul><li>Line 1: Three space-separated integers N, M, and K.</li><li>Lines 2..N+1: Line i+1 has two space-separated integers, representing the number of the ports that port i's left and right rivers lead to, respectively.</li><li>Line N+2: M space-separated characters, either 'L' or 'R'. 'L' represents a choice of  'left' and 'R' represents a choice of 'right'.</li></ul>

### 출력 

 <ul><li>Line 1: A single integer giving the number of the port where Bessie's cruise ends.</li></ul>

