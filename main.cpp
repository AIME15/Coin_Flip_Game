#include <iostream>
#include <cmath>

using namespace std;

const int MAX_DEPTH = 10000; // at MAX_DEPTH flips you are forced to quit
const double P = 0.5; // probability of heads

double value[MAX_DEPTH + 1][MAX_DEPTH + 1]; // value[a][b]: a heads, b total
bool run_away[MAX_DEPTH + 1][MAX_DEPTH + 1]; // do you quit

double divide(int a, int b)
{
	return a / (b + 0.0);
}

void compute(int depth)
{
	for (int h = 0; h < depth + 1; h++)
	{
		value[h][depth] = max(divide(h, depth), 0.5);
		run_away[h][depth] = true;
	}

	for (int total = depth - 1; total >= 1; total--)
	{
		for (int h = 0; h <= total; h++)
		{
			run_away[h][total] = false;
			value[h][total] = (1 - P) * value[h][total + 1] + P * value[h + 1][total + 1];
			if (divide(h, total) > value[h][total])
			{
				run_away[h][total] = true;
				value[h][total] = divide(h, total);
			}
		}
	}

	run_away[0][0] = false;
	value[0][0] = (1 - P) * value[0][1] + P * value[1][1];
}

void print_run_away()
{
	for (int total = 0; total <= 20; total++)
	{
		for (int h = 0; h <= total; h++)
		{
			cout << run_away[h][total] << " ";
		}
		cout << endl;
	}
}

void find_threshold_h()
{
	for (int total = 0; total <= 20; total++)
	{
		for (int h = 0; h <= total; h++)
		{
			if (run_away[h][total])
			{
				cout << divide(h, total) << endl;
				break;
			}
		}
	}
}

void print_value()
{
	cout << value[0][0] << endl;
}

int main()
{
	for (int i = 10; i <= 10000; i += 500)
	{
		compute(i);
		print_value();
	}
	// compute();
	// print_run_away();
	// find_threshold_h();
	print_value();
	return 0;
}