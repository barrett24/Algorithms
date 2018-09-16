#include <iostream>
#include <algorithm>
using namespace std;

double score[1001];
int n;
int main()
{
	double sum = 0;
	double max = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> score[i];
		if (max < score[i])
			max = score[i];
	}
	for (int i = 1; i <= n; i++)
		sum += (score[i] / max) * 100.00;

	printf("%.2f", sum / n);
}