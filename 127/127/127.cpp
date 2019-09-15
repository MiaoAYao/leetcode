// 127.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

bool compare(string &w1, string &w2)
{
	//有超过一个字母不同
	if (w1.size() != w2.size())
		return false;

	int num = 0;
	for (int i = 0; i < w1.size(); ++i)
	{
		if (w1[i] != w2[i])
			num++;
		if (num > 1)
			return false;
	}
	//两个单词相同
	if (num == 0)
		return false;

	//两个单词只有一个字母不同
	return true;
}

bool search(string &word, string &endWord, vector<string> &wordList, vector<int> &flag, vector<int> &wordTree)
{
	vector<int> temp;
	for (int i = 0; i < wordList.size(); ++i)
	{
		if (flag[i] == 0)
		{
			if ((compare(word, wordList[i])))
			{
				if (wordList[i] == endWord)
				{
					return true;
				}
				wordTree.push_back(i);
				flag[i] = 1;
			}
		}
	}

	return false;
}

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

		vector<int> flag;
		for (int i = 0; i < wordList.size(); ++i)
		{
			flag.push_back(0);
		}

		//广度优先搜索
		int length = 2;
		vector<int> wordTree;
		wordTree.push_back(-1);
		//已经在第二层找到endWord
		if (search(beginWord, endWord, wordList, flag, wordTree))
		{
			return length;
		}
		else
		{
			while (true)
			{
				if (wordTree.front() == -1)
				{
					wordTree.erase(wordTree.begin());

					//没有找到endWord
					if (wordTree.size() == 0)
						return 0;

					++length;
					wordTree.push_back(-1);
				}

				if (search(wordList[wordTree.front()], endWord, wordList, flag, wordTree))
				{
					return length;
				}
				else
				{
					wordTree.erase(wordTree.begin());
				}
			}
		}
	}
};

int main()
{
	string beginWord = "hit";
	string endWord = "cog";
	vector<string> wordList = { "hot","dot","dog","lot","log","cog" };

	Solution s;
	cout << s.ladderLength(beginWord, endWord, wordList) << endl;
}

