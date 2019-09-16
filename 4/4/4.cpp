#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int p1 = 0;
		int p2 = 0;
		int s1 = nums1.size();
		int s2 = nums2.size();

		//��¼��λ��
		int med = 0;
		//��λ��ǰ�����
		int med_succ;
		//�ҵ���ô��������
		int num = (s1 + s2) / 2;

		for (int i = 0; i <= num; ++i)
		{
			med_succ = med;

			//����������߶������һ�������
			//���nums1�е�ֵ�Ѿ�ȡ��
			if (p1 == s1)
			{
				med = nums2[p2];
				++p2;
			}
			else if (p2 == s2)
			{
				med = nums1[p1];
				++p1;
			}
			else
			{
				if (nums1[p1] < nums2[p2])
				{
					med = nums1[p1];
					++p1;
				}
				else
				{
					med = nums2[p2];
					++p2;
				}
			}
		}

		if ((s1 + s2) % 2 == 0)
		{
			return (med + med_succ) / 2.0;
		}
		else
		{
			return med;
		}
	}
};

int main()
{
	vector<int> nums1 = { 1,2 };
	vector<int> nums2 = { 3,4 };
	Solution s;
	cout << s.findMedianSortedArrays(nums1, nums2) << endl;
	system("pause" );
	return 0;
}