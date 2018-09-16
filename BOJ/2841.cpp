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
		scanf("%d%d", &str, &prt);//줄, 프랫
		while (!s[str].empty() && s[str].top() > prt) {
			++ans;		//한줄의 손가락 뗄 때
			s[str].pop();
		}
		if (s[str].empty() || s[str].top() != prt) {
			s[str].push(prt);	//줄 누를때
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
} 