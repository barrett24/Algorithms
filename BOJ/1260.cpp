#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int n;
int visit[1001];
int G[1001][1001];

void dfs(int start) {
	printf("%d", start);
	for (int i = 1; i <= n; i++) {
		if (G[start][i] && visit[i] == 0) {
			visit[i] = 1;
			dfs(i);
		}
	}
}
void bfs(int start) {
	queue<int> que;
	for (int i = 0; i <= n; i++)
		visit[i] = 0;
	que.push(start);
	visit[start] = 1;
	while (!que.empty()) {
		int num = que.front();
		que.pop();

		printf("%d", num);
		for (int i = 1; i <= n; i++) {
			if (G[num][i] && visit[i] == 0) {
				visit[i] = 1;
				que.push(i);
			}
		}
	}
	printf("\n");
}
int main() {
	int m, start;
	int a, b;

	scanf_s("%d %d %d", &n, &m, &start);

	for (int i = 0; i < m; i++) {
		scanf_s("%d %d", &a, &b);
		G[a][b] = G[b][a] = 1;
	}
	visit[start] = 1;
	dfs(start);
	printf("\n");
	bfs(start);
	return 0;
}