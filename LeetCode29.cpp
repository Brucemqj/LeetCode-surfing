#include <string>
#include <iostream>
#include <time.h>

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == INT_MIN && divisor == -1) return INT_MAX;
		bool isNegative = false;
		if ((dividend^divisor) >> 31) isNegative = true;
		long long da = abs(static_cast<double>(dividend)), db = abs(static_cast<double>(divisor));
		int rst = 0;
		while (da >= db)
		{
			long long c = db;
			for (int i = 0; da >= c; ++i, c <<= 1)
			{
				da -= c;
				rst += 1 << i;
			}
		}
		return isNegative ? - rst: rst;
	}
};


int main()
{
	Solution s;
	time_t start, end;
	start = time(NULL);
	int rst = s.divide(2147483648, 1);
	end = time(NULL);

	cout << (1 << 32 - 1) << endl;
	cout << rst << endl;
	cout << end - start << endl;
	system("pause");
	return 0;
}