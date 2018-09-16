#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 100
int N;
int G[MAX + 1][MAX + 1];
int CAN_GO[MAX + 1][MAX + 1];
int visit[MAX + 1];
void BFS(int n);
void print();

int main() {
	scanf_s("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf_s("%d", &G[i][j]);
			CAN_GO[i][j] = 0;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			visit[j] = 0;

		BFS(i);

		for (int j = 1; j <= N; j++)
			CAN_GO[i][j] = visit[j];
	}
	print();
	return 0;
}

void BFS(int n) {
	for (int i = 1; i <= N; i++) {
		if (G[n][i] && !visit[i]) {
			visit[i] = 1;
			BFS(i);
		}
	}
}
void print() {
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			printf("%d ", CAN_GO[i][j]);
		printf("\n");
	}
}