#include <iostream>
using namespace std;

int N, K;
int ans=0, sum=0;

int main() {
	cin >> N >> K;
	int* arr = new int[N];
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = N; i >= 1; i--) {
		if (arr[i] < K) {
			while (sum <= K) {
				sum += arr[i];
				ans++;
			}
			sum -= arr[i];
			ans--;
		}
	}
	cout << ans << endl;
	return 0;
}

