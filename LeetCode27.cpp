#include <vector>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.size() == 0) return 0;
		if (nums.size() == 1) return nums[0] == val ? 0 : 1;
		vector<int>::iterator it_a, it_b;
		it_a = nums.begin();
		it_b = nums.end() - 1;
		while (it_a != it_b)
		{
			while (it_a != it_b && *it_a != val) it_a++;
			if (it_a == it_b && *it_a != val) return it_a - nums.begin() + 1;
			if (it_a == it_b && *it_a == val) return it_a - nums.begin();
			while (it_a != it_b && *it_b == val) it_b--;
			if (it_a == it_b) return it_a - nums.begin();
			int tmp = *it_a;
			*it_a = *it_b;
			*it_b = tmp;
			if (it_a + 1 == it_b)
			{
				if (*it_b == val) return it_a - nums.begin() + 1;
				else return it_b - nums.begin() + 1;
			}
			it_a++;
			it_b--;
		}
		return *it_a == val ? it_a - nums.begin() : it_a - nums.begin() + 1;
	}
};

int main()
{
	Solution s;
	vector<int> nums = { 2,2,3 };
	int rst = s.removeElement(nums, 2);


	system("pause");
	return 0;
}