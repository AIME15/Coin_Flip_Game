#include <iostream>
#include <cmath>

using namespace std;

const int MAX_DEPTH = 100000; // at MAX_DEPTH flips you are forced to quit
const double P = 0.5; // probability of heads

double value[MAX_DEPTH + 1];

double ans;

double divide(int a, int b)
{
	return a / (b + 0.0);
}

void compute(int depth)
{
	for (int h = 0; h < depth + 1; h++)
	{
		value[h] = max(divide(h, depth), (double) 0.5);
	}

	for (int total = depth - 1; total >= 1; total--)
	{
		// if (total % 1000 == 0)
		// 	cout << total << endl;
		for (int h = 0; h <= total; h++)
		{
			value[h] = (1 - P) * value[h] + P * value[h + 1];
			if (divide(h, total) > value[h])
			{
				value[h] = divide(h, total);
			}
		}
	}

	double ans = (1 - P) * value[0] + P * value[1];

	cout << ans << endl;
}

int main()
{
	compute(MAX_DEPTH);
}