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
		if (target < candidates[start]) return; //С�ڵ�һ������ô�������н⣬ֱ����ֹ
		while (start < n && candidates[start] <= target) //�ڶ���������ֹ����Ҫ������
		{
			validOneVec.push_back(candidates[start]); //�����һ�����ܵĽ�
			searchAll(candidates, n, start + 1, target - candidates[start], validOneVec, rst); //����һ��start��ʼѰ��target - candidates[start]Ϊ0�Ľ�
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