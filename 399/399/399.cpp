#include<iostream>
#include<map>
#include<vector>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
	//�����ڽӾ����ҵ�nodeA��nodeB��·�������·����
	//���򷵻�1
	//���򷵻�0
	//·������path�path���Ԫ���ǽڵ�ı��
	int find(vector<vector<double>> matrix, int nodeA, int nodeB, vector<int> &path)
	{
		stack<int> nums;
		stack<int> nodes;
		int tempNode = nodeA;
	}

	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		//����ת������ͼ�����·������
		//�����Ų��ҹ����ڽӾ���

		//��������:�ȸ����ţ��ٹ����ڽӾ���
		//1.�ȸ�����
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

		//2.�����ڽӾ���
		//��ʼ��һ��nodeNum.size()�ķ���ÿ��Ԫ�ؾ�Ϊ0
		vector<vector<double>> matrix(nodeNum.size(), vector<double>(nodeNum.size(), 0));
		int start_node;
		int end_node;
		
		for (int i = 0; i < equations.size(); ++i)
		{
			//���������֪equations[i].size()һ��Ϊ2����һ�������ҵ����
			auto it = nodeNum.find(equations[i][0]);
			start_node = it->second;

			it = nodeNum.find(equations[i][1]);
			end_node = it->second;
			
			matrix[start_node][end_node] = values[i];
			//Ӧ�ò������values[i]Ϊ0�������
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
				//û��·�������޷�����������Ϣ��ֵ
				r.push_back(value);
			}
			else
			{
				//��·��
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