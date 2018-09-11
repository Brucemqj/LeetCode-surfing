#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
	void createWordmap(map<string, int> &wordsmap, const vector<string>& words)
	{
		int wordsLen = static_cast<int>(words.size());
		if (wordsLen == 0) return;
		vector<string>::const_iterator iter;
		for (iter = words.begin(); iter != words.end(); iter++)
		{
			if (wordsmap.count(*iter) == 0)
			{
				wordsmap[*iter] = 1;
			}
			else
			{
				wordsmap[*iter] += 1;
			}
		}
	}

	vector<int> findSubstring(string s, vector<string>& words) {
		map<string, int> wordsMap;
		vector<int> vrst;
		int wordsLen = static_cast<int>(words.size());
		if (wordsLen == 0)
		{
			vrst.push_back(-1); 
			return vrst;
		}
		createWordmap(wordsMap, words);
		int lenofword = static_cast<int>(words[0].size());
		int sLen = static_cast<int>(s.size());
		int wordNum = wordsLen * lenofword;
		if (wordNum > sLen)
		{
			vrst.push_back(-1); 
			return vrst;
		}
		int i(0), j(0);
		int count = wordsLen;
		map<string, int> tmpM(wordsMap);
		bool mapChanged = false;
		for (; i < sLen; ++i)
		{
			j = i;
			for (; j < wordNum, count > 0; j += lenofword)
			{
				string substr = s.substr(j, lenofword);
				if (tmpM[substr])
				{
					mapChanged = true;
					tmpM[substr] -= 1;
					count--;
				}
				else break;
			}
			if (count == 0) vrst.push_back(i);
			count = wordsLen;
			if (mapChanged) tmpM = wordsMap;
		}
		return vrst;
	}
};

int main()
{
	Solution s;
	string st = "wordgoodgoodgoodbestword";
	vector<string> vs = { "word","good","best","word" };
	vector<int> rst = s.findSubstring(st, vs);

	vector<int>::iterator iter = rst.begin();
	for (; iter != rst.end(); ++iter)
	{
		cout << *iter << endl;
	}
	system("pause");
	return 0;
}