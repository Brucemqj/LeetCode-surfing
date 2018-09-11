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
			//����ʹ�±�0��n-1��n���������ŵľ���1~n��Щ��
			while (nums[i] > 0 && nums[i] < len && nums[nums[i] - 1] != nums[i]) //��������nums[i] = 5��Ӧ�÷����±�Ϊnums[i]-1��4��λ�ã�ǰ���Ǵ�λ��û�з���ȷ����5.
			{
				int tmp = nums[nums[i] - 1];
				nums[nums[i] - 1] = nums[i];
				nums[i] = tmp;
			}
		}
		for (int i = 0; i < len; ++i)
		{
			if (nums[i] != i + 1) //���ֲ��ڶ�Ӧλ����
				return i + 1;
		}
		return len + 1; //���ڶ�Ӧλ���򷵻ص�n+1����
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