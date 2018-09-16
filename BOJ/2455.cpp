#include <iostream>
using namespace std;

int People = 0;
int MAX=0;

int main() {
	int C = 4;
	int in, out;
	while (C--) {
		cin >> out >> in;
		People += in;
		People -= out;
		if (People > MAX)
			MAX = People;
	}
	cout << MAX << endl;
	return 0;
}