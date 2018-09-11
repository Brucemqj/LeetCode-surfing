#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
	int trapDP(vector<int>& height)
	{
		int len = static_cast<int>(height.size());
		if (len <= 1) return 0;
		vector<int> leftMax(len, 0);
		vector<int> rightMax(len, 0);
		int leftM = 0, rightM = 0;
		for (int i = 0; i < len; ++i)
		{
			if (height[i] > leftM) leftM = height[i];
			leftMax[i] = leftM;
		}
		for (int i = len - 1; i > 0; --i)
		{
			if (height[i] > rightM) rightM = height[i];
			rightMax[i] = rightM;
		}
		int curWater = 0;
		for (int i = 0; i < len; ++i)
		{
			curWater += (leftMax[i] < rightMax[i]) ? leftMax[i] - height[i] : rightMax[i] - height[i];
		}
		return curWater;
	}

	int trap(vector<int>& height)
	{
		int len = static_cast<int>(height.size());
		if (len <= 1) return 0;
		int curWater = 0;
		int i = 0;
		while(i < len - 1) //之所以不是小于len，排除i在最后一个时只有leftPillar，不可能trap water
		{
			if (height[i] == 0)
			{
				++i;
			}
			else
			{
				int left = i;
				int leftPillar = height[left];
				int maxFromleftPillar = 0;
				int maxIndex = 0;
				while (i + 1 < len && height[i + 1] < leftPillar)
				{
					if (height[i + 1] > maxFromleftPillar)
					{
						maxIndex = i + 1;
						maxFromleftPillar = height[maxIndex];
					}
					++i;
				}
				if (i + 1 == len) //未找到比左边柱子高（或一样高的）
				{
					if (maxIndex == 0) return curWater; //没找到左边柱子后面最大的柱子，说明从左边柱子是倒数第二个，不能trap water 了
					for (int j = left + 1; j < maxIndex; ++j)
					{
						curWater += maxFromleftPillar - height[j];
					}
					i = maxIndex;
				}
				else //找到一个比左边柱子高（或一样高的），位于i+1
				{
					for (int j = left + 1; j < i + 1; ++j)
					{
						curWater += leftPillar - height[j];
					}
					i = i + 1;
				}
			}
		}
		return curWater;
	}
};

int main()
{
	Solution s;
	vector<int> height = { 0,2,0,2 };
	int rst1 = s.trapDP(height);
	int rst2 = s.trap(height);
	cout << rst1 << "--" << rst2 << endl;
	system("pause");
	return 0;
}