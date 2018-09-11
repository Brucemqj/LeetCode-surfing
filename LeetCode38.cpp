#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	string countAndSay(int n)
	{
		if (n <= 0) return "";
		string s = "1";
		int i = 1;
		for (; i < n; ++i)
		{
			int len = static_cast<int>(s.size());
			int count = 1;
			char cmp = s[0];
			string ss = "";
			for (int j = 1; j < len; ++j)
			{
				if (cmp == s[j])
					count++;
				else
				{
					ss += (char)(count + '0');
					ss += cmp;
					count = 1;
					cmp = s[j];
				}
			}
			ss += (count + '0');
			ss += cmp;
			s = ss;
		}
		return s;
	}

//µÝ¹é·½·¨
	string countAndSayRecursive(int n)
	{
		if (n <= 0) return "";
		if (n == 1) return "1";
		string s = countAndSayRecursive(n - 1);
		int count = 1;
		char cmp = s[0];
		string ss = "";
		for (int j = 1; j < s.size(); ++j)
		{
			if (cmp == s[j])
			{
				count++;
			}
			else
			{
				ss += (char)(count + '0');
				ss += cmp;
				count = 1;
				cmp = s[j];
			}
		}
		ss += (count + '0');
		ss += cmp;
		s = ss;
		return s;
	}
};

int main()
{
	Solution sol;
	int n = 3;
	string s1 = sol.countAndSay(n);
	string s2 = sol.countAndSayRecursive(n);
	cout << s1 << "-" << s2 << endl;
	system("pause");
	return 0;
}