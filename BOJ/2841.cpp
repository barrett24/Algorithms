#pragma warning(disable: 4996)

#include <iostream>
#include <stack>
using namespace std;

int N, M;
int str, prt, ans;
stack<int> s[7];

int main() {
	scanf("%d%d", &N, &M);

	while (N--) {
		scanf("%d%d", &str, &prt);//��, ����
		while (!s[str].empty() && s[str].top() > prt) {
			++ans;		//������ �հ��� �� ��
			s[str].pop();
		}
		if (s[str].empty() || s[str].top() != prt) {
			s[str].push(prt);	//�� ������
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
} 