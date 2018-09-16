#include <iostream>
#include <string>
using namespace std;
int main() {
	int num, cnt = 0, total = 0;
	string k;
	cin >> num;
	int *arr = new int[num];
	for (int i = 0; i < num; i++)
	{
		cin >> k;
		for (int j = 0; j < k.size(); j++)
		{
			if (k[j] == 'O')
			{
				cnt++;
				total += cnt;
			}
			else if (k[j] == 'X')
			{
				cnt = 0;
				total += cnt;
			}
		}
		arr[i] = total;
		total = 0;
		cnt = 0;
	}
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << '\n';
	}
}
