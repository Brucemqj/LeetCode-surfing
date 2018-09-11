#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		if (haystack.empty()) return -1;
		size_t length1 = haystack.size(), length2 = needle.size();
		if (length1 < length2) return 0;
		size_t i(0), j(0);
		int count = 0, occurIndex = 0;
		bool begin = true;
		while (i < length1 && j < length2)
		{
			if (haystack[i] == needle[j])
			{
				if (begin)
				{
					occurIndex = i;
					begin = false;
				}
				i++;
				j++;
				count++;
			}
			else if (static_cast<size_t>(count) == length2) return occurIndex;
			else
			{
				if (!begin)
				{
					begin = true;
					i = occurIndex + 1;
				}
				else
				{
					i++;
				}
				count = 0;
				j = 0;
			}
		}
		return static_cast<size_t>(count) == length2 ? occurIndex : 0;
	}
};


int main()
{
	Solution s;
	string s1 = "mississippi";
	string s2 = "issip";
	int rst = s.strStr(s1, s2);

	cout << rst << endl;
	system("pause");
	return 0;
}