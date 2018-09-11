#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
	int firstMissingPositive(vector<int>& nums)
	{
		int len = static_cast<int>(nums.size());
		if (len == 0) return 1;
		for (int i = 0; i < len; ++i)
		{
			//调整使下标0到n-1的n个数尽量放的就是1~n这些数
			while (nums[i] > 0 && nums[i] < len && nums[nums[i] - 1] != nums[i]) //举例，对nums[i] = 5，应该放在下标为nums[i]-1即4的位置，前提是此位置没有放正确的数5.
			{
				int tmp = nums[nums[i] - 1];
				nums[nums[i] - 1] = nums[i];
				nums[i] = tmp;
			}
		}
		for (int i = 0; i < len; ++i)
		{
			if (nums[i] != i + 1) //数字不在对应位置上
				return i + 1;
		}
		return len + 1; //都在对应位置则返回第n+1个数
	}
};

int main()
{
	Solution s;
	vector<int> nums = { 1,2,0 };
	int rst = s.firstMissingPositive(nums);
	cout << rst << endl;
	system("pause");
	return 0;
}