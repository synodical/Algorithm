#include<iostream>
using namespace std;

int parent[10001];
bool visited[10001];
int T, N, A, B, u, v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            visited[i] = false;
            parent[i] = i;
        }

        // edge
        for (int i = 0; i < N - 1; i++){
            cin >> A >> B;
            parent[B] = A;
        }

        cin >> u >> v;
        visited[u] = true;

        while (u != parent[u]) {
            u = parent[u];
            visited[u] = true;
        }
        while (true) {
            if (visited[v]) {
                cout << v << '\n';
                break;
            }
            v = parent[v];
        }

    }
}