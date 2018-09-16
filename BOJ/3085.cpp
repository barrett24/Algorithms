#pragma warning(disable: 4996)
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//vector<vector<char>> v;
//int n;
//int search() {
//
//}
//int main() {
//	scanf("%d", &n);
//	v.resize(n);
//	
//	vector<char>::iterator iter = v.begin();
//
//	return 0;
//}
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
char map[50][50];

// ���� map���� ���� �� �ִ� �ִ� ���� ����
int getMaxCandy() {
	int result = 1;
	// �� ������ �ȱ�
	for (int i = 0; i<N; i++) {
		int cnt = 1;
		for (int j = 1; j<N; j++) {
			if (map[i][j] == map[i][j - 1]) cnt++;
			else {
				result = max(result, cnt);
				cnt = 1;
			}
		}
		result = max(result, cnt);
	}
	// �� ������ �ȱ�
	for (int i = 0; i<N; i++) {
		int cnt = 1;
		for (int j = 1; j<N; j++) {
			if (map[j][i] == map[j - 1][i]) cnt++;
			else {
				result = max(result, cnt);
				cnt = 1;
			}
		}
		result = max(result, cnt);
	}
	return result;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i<N; i++) {
		getchar();
		for (int j = 0; j<N; j++)
			map[i][j] = getchar();
	}
	int result = 0;
	// �ٲ� �� �ִ� ��� ��츦 �� �ٲ㺽
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N - 1; j++) {
			// �ڱ� �ٷ� ������ ĵ��� �ٲ�
			swap(map[i][j], map[i][j + 1]);
			result = max(result, getMaxCandy());
			swap(map[i][j], map[i][j + 1]);
			// �ڱ� �ٷ� �Ʒ� ĵ��� �ٲ�
			swap(map[j][i], map[j + 1][i]);
			result = max(result, getMaxCandy());
			swap(map[j][i], map[j + 1][i]);
		}
	}
	printf("%d\n", result);
	return 0;
}