#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int* arr = new int[N];

	for (int i = 0; i < N; ++i) {
		scanf("%d", arr + i);
	}

	sort(arr, arr + N);

	int time = 0;
	for (int i = 0; i < N; ++i) time += (N - i) * arr[i];

	printf("%d\n", time);

	delete[] arr;

	return 0;
}
