#include <iostream>
using namespace std;
int n, k, cnt=0, c[1001] = { 0 }, ans;
int main() {
	cin >> n >> k;
	for (int i = 2; i <= n; i++)
	{
		for (int j = i; j <= n; j += i)
		{
			if (c[j] == 0) { cnt++; c[j] = 1; }
			if (cnt == k) { ans = j; break; }
		}
		if (cnt == k)break;
	}
	cout << ans << '\n';
}

