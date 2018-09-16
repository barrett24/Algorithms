#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

long long arr[101];
vector<long long> v;

long long gcd(long long a, long long b)
{
	if (!b) return a;
	return gcd(b, a%b);
}

int main()
{
	long long n, g, MAX;
	cin >> n >> arr[0];
	g = arr[0];
	MAX = g;

	for (long long i = 1; i < n; i++) {
		cin >> arr[i];
		g = gcd(arr[i], g);
		MAX = max(arr[i], MAX);
	}

	for (long long j = g; j <= MAX; j += g) {
		long long temp = -1;

		for (int i = 0; i < n; ++i)
		{
			if (i == 0) {
				temp = arr[i] % j;
			}
			else {
				if (temp == arr[i] % j)
					temp = arr[i] % j;
				else
					break;
			}
			if (i + 1 == n) v.push_back(j);
			//cout << j << " " << endl;
		}
	}
	vector<long long>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << ' ';
	}
	return 0;
}