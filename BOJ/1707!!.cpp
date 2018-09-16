#include <iostream>
#include <vector>
using namespace std;
vector <int> A[20001];
int color[20001];
int K, V, E, u, v;

void DFS(int x, int c) {
	color[x] = c;
	for (int i = 0; i < A[x].size(); i++) {
		int y = A[x][i];
		if (color[y] == 0) {
			DFS(y, 3 - c);
		}
	}
}

int main() {
	cin >> K;
	while (K--) {
		cin >> V >> E;
		bool ans = true;
		for (int i = 1; i <= 20000; i++) {
			A[i].clear();
			color[i] = 0;
		}
		while (E--) {
			cin >> u >> v;
			A[u].push_back(v);
			A[v].push_back(u);
		}
		for (int i = 1; i <= V; i++) {
			if (color[i] == 0)
				DFS(i, 1);
		}
		for (int i = 1; i <= V; i++) {
			for (int j = 0; j < A[i].size(); j++) {
				int temp = A[i][j];
				if (color[i] == color[temp])
					ans = false;
			}
		}
		printf("%s\n", ans ? "YES" : "NO");
	}
	return 0;
}