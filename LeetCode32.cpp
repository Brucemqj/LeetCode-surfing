#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
	int longestValidParentheses(string s) {
		int sLen = static_cast<int>(s.size());
		if (sLen <= 1) return 0;
		int *rst = new int[sLen];
		rst[0] = 0;
		int maxLen = 0;
		for (int i = 1; i < sLen; ++i)
		{
			if (s.substr(i, 1) == ")")
			{
				if (s.substr(i - 1, 1) == "(")
				{
					rst[i] = i - 2 >= 0 ? rst[i - 2] + 2 : 2;
				}
				else if(i-rst[i-1]-1>=0 && s.substr(i - rst[i - 1] - 1, 1) == "(")
				{
					rst[i] = rst[i - 1] + ((i-rst[i-1]-2>=0) ? (rst[i - rst[i - 1] - 2] + 2) : 2);
				}
				else
				{
					rst[i] = 0;
				}
			}
			else rst[i] = 0;
			maxLen = maxLen < rst[i] ? rst[i] : maxLen;
		}
		return maxLen;
	}
};


int main()
{
	Solution s;
	string parentheses = "()(())";
	int rst = s.longestValidParentheses(parentheses);
	cout << rst << endl;
	system("pause");
	return 0;
}