#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
	int findIndex(vector<int>& nums, int target, bool left)
	{
		int len = static_cast<int>(nums.size());
		int lo = 0, hi = len;
		while (lo < hi)
		{
			int mid = (lo + hi) >> 1;
			if (nums[mid] > target || (left && target == nums[mid]))
				hi = mid;
			else
				lo = mid + 1;
		}
		return lo;
	}

	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> rst;
		int len = static_cast<int>(nums.size());
		int leftIndex = findIndex(nums, target, true);
		if (leftIndex == len || nums[leftIndex] != target)
		{
			rst.push_back(-1);
			rst.push_back(-1);
			return rst;
		}
		int rightIndex = findIndex(nums, target, false) - 1;
		rst.push_back(leftIndex);
		rst.push_back(rightIndex);
		return rst;
	}
};


int main()
{
	Solution s;
	vector<int> nums = { 5,7,8,8,8,8 };
	vector<int> rst = s.searchRange(nums, 8);
	cout << rst[0] << ", " << rst[1] << endl;
	system("pause");
	return 0;
}