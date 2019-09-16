#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		for (int i = 0; i < nums.size() - 1; ++i)
		{
			for (int j = i + 1; j < nums.size(); ++j)
			{
				if (nums[i] + nums[j] == target)
				{
					result.push_back(i);
					result.push_back(j);
					return result;
				}
			}
		}
		return result;
	}
};

int main()
{
	vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;
	Solution s;
	vector<int> r = s.twoSum(nums, target);
	for (auto it = r.begin(); it != r.end(); ++it)
		cout << *it << "\t";
	cout << endl;
	system("pause");

	return 0;
}