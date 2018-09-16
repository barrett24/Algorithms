#include <iostream>
#include <queue>
#include <deque>
using namespace std;

deque<pair<int, int>> d;
pair<int, int> p;
int N, temp;

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> temp;
		d.push_back(make_pair(i, temp));//¹øÈ£, °ª
	}

	int pos = 0, target, a;

	p = d.front();
	d.pop_front();

	cout << p.first;
	target = p.second;

	while (!d.empty()) {
		pos = 0;
		if (target>0) {
			while (++pos < target) {
				p = d.front();
				d.pop_front();
				d.push_back(p);
			}
			p = d.front();
			d.pop_front();

		}
		else {//target<0
			while (--pos > target) {
				p = d.back();
				d.pop_back();
				d.push_front(p);
			}
			p = d.back();
			d.pop_back();

		}
		a = p.first;
		target = p.second;
		cout << " " << a;
	}
	return 0;
}