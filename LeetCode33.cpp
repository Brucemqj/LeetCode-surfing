#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
	int search(vector<int> &nums, int target)
	{
		int len = static_cast<int>(nums.size());
		if (len == 0) return -1;
		int left = 0, right = len - 1;
		while (left <= right)
		{
			int med = (left + right) >> 1;
			if (nums[med] == target) return med;
			if (nums[med] > nums[right])
			{
				if (target >= nums[left] && target < nums[med]) right = med - 1;
				else left = med + 1;
			}
			else
			{
				if (target > nums[med] && target <= nums[right]) left = med + 1;
				else right = med - 1;
			}	
		}
		return -1;
	}
};

int main()
{
	Solution s;
	vector<int> nums = { 1,3 };
	int rst = s.search(nums, 3);
	cout << rst << endl;
	system("pause");
	return 0;
}