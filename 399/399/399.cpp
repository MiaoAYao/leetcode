#include<iostream>
#include<map>
#include<vector>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
	//根据邻接矩阵，找到nodeA到nodeB的路径（最短路径）
	//有则返回1
	//无则返回0
	//路径存在path里，path里的元素是节点的编号
	int find(vector<vector<double>> matrix, int nodeA, int nodeB, vector<int> &path)
	{
		stack<int> nums;
		stack<int> nodes;
		int tempNode = nodeA;
	}

	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		//将其转化成了图中最短路径问题
		//给点编号并且构建邻接矩阵

		//暴力方法:先给点编号，再构建邻接矩阵
		//1.先给点编号
		map<string, int> nodeNum;
		int index = 0;
		for (int i = 0; i < equations.size(); ++i)
		{
			for (int j = 0; j < equations[i].size(); ++j)
			{
				auto it = nodeNum.find(equations[i][0]);
				if(it == nodeNum.end())
				{
					nodeNum.insert(pair<string, int>(equations[i][0], index));
					index++;
				}
			}
		}

		//2.构建邻接矩阵
		//初始化一个nodeNum.size()的方阵，每个元素均为0
		vector<vector<double>> matrix(nodeNum.size(), vector<double>(nodeNum.size(), 0));
		int start_node;
		int end_node;
		
		for (int i = 0; i < equations.size(); ++i)
		{
			//根据输入可知equations[i].size()一定为2，且一定可以找到编号
			auto it = nodeNum.find(equations[i][0]);
			start_node = it->second;

			it = nodeNum.find(equations[i][1]);
			end_node = it->second;
			
			matrix[start_node][end_node] = values[i];
			//应该不会出现values[i]为0的情况吧
			matrix[end_node][start_node] = 1.0 / values[i];
		}

		//
		vector<double> r;
		for (int i = 0; i < queries.size(); ++i)
		{
			double value = -1.0;
			auto it = nodeNum.find(queries[i][0]);
			if (it == nodeNum.end())
			{
				r.push_back(value);
				continue;
			}
			start_node = it->second;
			
			it = nodeNum.find(queries[i][1]);
			if (it == nodeNum.end())
			{
				r.push_back(value);
				continue;
			}
			end_node = it->second;

			vector<int> path;
			int flag = find(matrix, start_node, end_node, path);
			if (flag == 0)
			{
				//没有路径，即无法根据已有信息求值
				r.push_back(value);
			}
			else
			{
				//有路径
				value = 0;
				for (int m = 0; m < path.size() - 1; ++m)
				{
					value += matrix[path[i]][path[i + 1]];
				}
				r.push_back(value);
			}
		}
	}
};

int main()
{
	system("pause");
	return 0;
}