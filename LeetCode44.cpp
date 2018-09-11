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
				if (tmp == lenp) return true; //��startp��ʼ����pattern����'*'���ţ�����ƥ��
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
			while (nextp < lenp && p[nextp] == '*') //Ѱ��pattern�г���'*"��ĵ�һ������'*'���ַ�
				nextp++;
			if (nextp == lenp) return true;
			int nexts = starts;
			while (nexts < lens)
			{
				while (nexts < lens && p[nextp] != '?' && p[nextp] != s[nexts]) nexts++; //Ѱ��s�е�p[nextp]���ַ�������ַ�֮ǰ�������ַ����Ѿ���'*'��ƥ��
				if (nexts == lens) //sû�ҵ�p[nextp]����ô'*'ֻ��ƥ����ַ���
					return search(s, p, lens, lenp, starts, startp + 1);
				else if (search(s, p, lens, lenp, nexts + 1, nextp + 1)) //s���ҵ�p[nextp]����ô��nexts+1��ʼ��֮ǰ��ƥ��ɹ�
					return true;
				else
					nexts++; //����Ѱ��s�е�p[nextp]���ַ�
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