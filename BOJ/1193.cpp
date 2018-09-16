#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int i;
	for (i = 1; n > 0; i++)
		n -= i;
	if (i % 2 == 1) {
		cout << i + n - 1 << "/" << 1 - n << endl;
	}
	else if (i % 2 == 0) {
		cout << 1 - n << "/" << i + n - 1 << endl;
	}
	return 0;
}