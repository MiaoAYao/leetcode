#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int p = 0;
		set<char> letters;
		int maxLength = -1;
		int tempLength = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			auto it = letters.find(s[i]);
			//之前没出现过这个字母
			if (it == letters.end())
			{
				letters.insert(s[i]);
				++tempLength;
			}
			//之前出现过这个字母
			else
			{
				if (maxLength < tempLength)
					maxLength = tempLength;
				//因为之前出现过这个字母，现在肯定能跳出循环
				while (s[p] != s[i])
				{
					letters.erase(s[p]);
					p++;
					--tempLength;
				}
				p++;
			}
		}

		if (maxLength < tempLength)
			maxLength = tempLength;

		return maxLength;
	}
};

int main()
{
	Solution s;
	string str = "pwwkew";
	cout << s.lengthOfLongestSubstring(str) << endl;
	system("pause");
	return 0;
}
