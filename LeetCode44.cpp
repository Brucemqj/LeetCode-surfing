#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
	bool search(string s, string p , int lens, int lenp, int starts, int startp)
	{
		if (starts >= lens && startp >= lenp) return true;
		if (starts >= lens) 
		{
			if (p[startp] == '*' )
			{
				int tmp = startp + 1;
				while (tmp < lenp && p[tmp] == '*') tmp++;
				if (tmp == lenp) return true; //从startp开始所有pattern都是'*'符号，可以匹配
			}
			return false;
		}
		if ((starts >= lens && startp < lenp) || (starts < lens && startp >= lenp))
			return false;
		if (starts == lens && startp == lenp) return true;
		if (p[startp] == '?' || p[startp] == s[starts])
			return search(s, p, lens, lenp, starts + 1, startp + 1);
		if (p[startp] == '*')
		{
			int nextp = startp;
			while (nextp < lenp && p[nextp] == '*') //寻找pattern中出现'*"后的第一个不是'*'的字符
				nextp++;
			if (nextp == lenp) return true;
			int nexts = starts;
			while (nexts < lens)
			{
				while (nexts < lens && p[nextp] != '?' && p[nextp] != s[nexts]) nexts++; //寻找s中的p[nextp]的字符，这个字符之前的所有字符都已经被'*'所匹配
				if (nexts == lens) //s没找到p[nextp]，那么'*'只能匹配空字符了
					return search(s, p, lens, lenp, starts, startp + 1);
				else if (search(s, p, lens, lenp, nexts + 1, nextp + 1)) //s中找到p[nextp]，那么从nexts+1开始，之前都匹配成功
					return true;
				else
					nexts++; //继续寻找s中的p[nextp]的字符
			}		
		}
		return false;
	}

	bool isMatch(string s, string p)
	{
		int lens = static_cast<int>(s.size());
		int lenp = static_cast<int>(p.size());
		return search(s, p, lens, lenp, 0, 0);
	}
};

int main()
{
	Solution sol;
	string s = "babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaab";
	string p = "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a";
	bool rst = sol.isMatch(s, p);
	cout << rst << endl;
	system("pause");
	return 0;
}