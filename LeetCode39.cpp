#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
	//DFS in leeTCode40, just need chang a little 
	void findValid(vector<int>& candidates, int start, int target, vector<int>& v_rst, vector< vector<int> >& rst)
	{
		if (target == 0)
		{
			rst.push_back(v_rst);
			return;
		}
		if (target < candidates[0]) return;
		while (start < static_cast<int>(candidates.size()) && candidates[start] <= target) //不可交换条件判断的顺序
		{
			v_rst.push_back(candidates[start]);
			//change here to complete LeetCode40 by 
			//findValid(candidates, start + 1, target - candidates[start], v_rst, rst)
			findValid(candidates, start, target - candidates[start], v_rst, rst); 
			v_rst.pop_back();
			//对LeetCode40，此处还需加上判断出现重复数字时应该跳过，否则结果会有重复
			++start;
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector< vector<int> > rst;
		vector<int> v_rst;
		vector<int>::const_iterator con_iter = candidates.begin();
		findValid(candidates, 0, target, v_rst, rst);
		return rst;
	}
};

int main()
{
	Solution s;
	vector<int> candidates = { 2,3,6,7 };
	int target = 7;
	vector< vector<int> > rst = s.combinationSum(candidates, target);
	system("pause");
	return 0;
}