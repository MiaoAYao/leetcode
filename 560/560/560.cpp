#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		vector<int> tempNums;
		int r = 0;
		//≥ı ºªØ
		for (int i = 0; i < nums.size(); ++i)
		{
			tempNums.push_back(nums[i]);
			if (nums[i] == k)
				++r;
		}

		int size = tempNums.size();
		while (size != 0)
		{
			int index = nums.size() - size + 1;
			for (int i = 0; i < size - 1; ++i)
			{
				tempNums[i] = tempNums[i] + nums[index];
				++index;
				if (tempNums[i] == k)
					++r;
			}
			--size;
		}

		return r;
	}
};

int main()
{
	vector<int> nums = { 100,1,2,3,4 };
	int k = 6;
	Solution s;
	cout << s.subarraySum(nums, k) << endl;
	system("pause");
	return 0;
}