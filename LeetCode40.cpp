#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
	vector< vector<int> > combinationSum2(vector<int>& candidates, int target)
	{
		sort(candidates.begin(), candidates.end());
		int n = static_cast<int>(candidates.size());
		vector<int> validOneVec;
		vector< vector<int> > rst;
		searchAll(candidates, n, 0, target, validOneVec, rst);
		return rst;
	}

private:
	void searchAll(vector<int>& candidates, const int& n, int start, int target, vector<int>& validOneVec, vector< vector<int> >& rst)
	{
		if (0 == target)
		{
			rst.push_back(validOneVec);
			return;
		}
		if (target < candidates[start]) return; //小于第一个，那么不可能有解，直接终止
		while (start < n && candidates[start] <= target) //第二个条件防止不必要的搜索
		{
			validOneVec.push_back(candidates[start]); //放入第一个可能的解
			searchAll(candidates, n, start + 1, target - candidates[start], validOneVec, rst); //从下一个start开始寻找target - candidates[start]为0的解
			validOneVec.pop_back();
			while (start + 1 < n && candidates[start] == candidates[start + 1]) ++start;
			++start;
		}
	}
};

int main()
{
	Solution s;
	vector<int> candi = { 10,1,2,7,6,1,5 };
	int target = 8;
	vector< vector<int> > rst = s.combinationSum2(candi, target);
	system("pause");
	return 0;
}