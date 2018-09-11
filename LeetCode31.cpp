#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	void swap(vector<int>& nums, int &i, int &length)
	{
		int p = i, q = length - 1;
		while (q > p)
		{
			int tmp = nums[p];
			nums[p] = nums[q];
			nums[q] = tmp;
			p++;
			q--;
		}
	}

	void nextPermutation(vector<int>& nums) {
		int length = static_cast<int>(nums.size());
		if (length <= 1) return;
		int i = length - 1;
		for (; i >= 1; --i)
		{
			if (nums[i] > nums[i - 1]) break;
		}
		if (i == 0)
		{
			swap(nums, i, length);
			return;
		}
		int j = length - 1;
		while (j >= i && nums[j] <= nums[i - 1]) --j;
		if (j == i - 1) return;
		int tmp = nums[i - 1];
		nums[i - 1] = nums[j];
		nums[j] = tmp;
		swap(nums, i, length);
	}
};


int main()
{
	Solution s;
	vector<int> nums = { 1,5,1 };
	s.nextPermutation(nums);

	vector<int>::const_iterator citer;
	for (citer = nums.begin(); citer != nums.end(); ++citer)
	{
		cout << *citer << endl;
	}
	system("pause");
	return 0;
}