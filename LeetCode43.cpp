#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
	string multiply(string num1, string num2)
	{
		if (num1 == "0" || num2 == "0") return "0";
		int len1 = static_cast<int>(num1.size());
		int len2 = static_cast<int>(num2.size());
		vector<int> rst(len1 + len2, 0);
		for (int i = len1 - 1; i >= 0; --i)
		{
			for (int j = len2 - 1; j >= 0; --j)
			{
				int curMti = (num1[i] - '0') * (num2[j] - '0');
				int p1 = i + j;
				int p2 = p1 + 1;
				int sum = curMti + rst[p2];
				rst[p2] = sum % 10;
				rst[p1] += sum / 10;
			}
		}
		string s_rst;
		for (auto num : rst)
		{
			if (num != 0 || !s_rst.empty())
				s_rst += num + '0';
		}
		return s_rst;
	}
};

int main()
{
	Solution s;
	string num1 = "123";
	string num2 = "456";
	string rst = s.multiply(num1, num2);
	cout << rst << endl;
	system("pause");
	return 0;
}