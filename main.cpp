#include <iostream>

using namespace std;

const int MAX_DEPTH = 16000;

double value[MAX_DEPTH + 1][MAX_DEPTH + 1]; // value[a][b]: a heads, b total
bool run_away[MAX_DEPTH + 1][MAX_DEPTH + 1];

double divide(int a, int b)
{
	return a / (b + 0.0);
}

int main()
{
	for (int h = 0; h < MAX_DEPTH + 1; h++)
	{
		value[h][MAX_DEPTH] = divide(h, MAX_DEPTH);
		run_away[h][MAX_DEPTH] = true;
	}

	for (int total = MAX_DEPTH - 1; total >= 1; total--)
	{
		for (int h = 0; h <= total; h++)
		{
			run_away[h][total] = false;
			value[h][total] = 0.5 * value[h][total + 1] + 0.5 * value[h + 1][total + 1];
			if (divide(h, total) > value[h][total])
			{
				run_away[h][total] = true;
				value[h][total] = divide(h, total);
			}
		}
	}

	run_away[0][0] = false;
	value[0][0] = 0.5 * value[0][1] + 0.5 * value[1][1];

	cout << value[0][0] << endl;
	return 0;
}