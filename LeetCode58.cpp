#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = static_cast<int>(s.size());
        if(0==len) return 0;
        int count = 0, last = len - 1;
        while(last >= 0 && s.substr(last, 1) == " ") last--;
        while(last>=0)
        {
            if(s.substr(last, 1) == " ") break;
            last--;
            count++;
        }
        return count;
    }
};

int main()
{
	Solution s;
	string st = "hello world";
	int rst = s.lengthOfLastWord(st);
	cout << rst << endl; 
	system("pause");
	return 0;
}
