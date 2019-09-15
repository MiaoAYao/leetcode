#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

 struct TreeNode {
	int val;
    TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		queue<TreeNode*> q;
		q.push(root);
		TreeNode* empty = NULL;

		string result;
		TreeNode* tempNode;
		int num = 1;
		while (num != 0)
		{
			int tempNum = 0;
			for (int i = 0; i < num; ++i)
			{
				tempNode = q.front();
				q.pop();
				if (tempNode == NULL)
				{
					result += "null,";
				}
				else
				{
					result += to_string(tempNode->val) + ",";
					if (tempNode->left != NULL)
						q.push(tempNode->left);
					else
						q.push(empty);

					if (tempNode->right != NULL)
						q.push(tempNode->right);
					else
						q.push(empty);

					tempNum += 2;
				}
				
			}
			num = tempNum;
		}
		return result;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		stringstream ss(data);
		string sn;

		TreeNode* tempNode;
		queue<TreeNode*> q;

		TreeNode* root;
		getline(ss, sn, ',');
		//返回的是一棵空树
		if (sn == "null")
		{
			return NULL;
		}
		else
		{
			tempNode = new TreeNode(stoi(sn));
			root = tempNode;
		}
		
		q.push(root);
		int num = 1;
		while (num != 0)
		{
			int tempNum = 0;
			for (int i = 0; i < num; ++i)
			{
				tempNode = q.front();
				q.pop();

				
				getline(ss, sn, ',');
				cout << sn << endl;
				if (sn != "null")
				{
					TreeNode *tempLeft = new TreeNode(stoi(sn));
					tempNode->left = tempLeft;
					q.push(tempLeft);
					++tempNum;
				}

				getline(ss, sn, ',');
				cout << sn << endl;
				if (sn != "null")
				{
					TreeNode *tempRight = new TreeNode(stoi(sn));
					tempNode->right = tempRight;
					q.push(tempRight);
					++tempNum;
				}
			}
			num = tempNum;
		}
		return root;
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* node = root;
	TreeNode* tempNode;
	tempNode = new TreeNode(2);
	node->left = tempNode;
	tempNode = new TreeNode(3);
	node->right = tempNode;
	node = node->left;

	tempNode = new TreeNode(4);
	node->left = tempNode;
	node = node->left;

	tempNode = new TreeNode(5);
	node->left = tempNode;
	node = node->left;

	tempNode = new TreeNode(6);
	node->left = tempNode;

	Codec codec;
	cout << codec.serialize(root) << endl;
	codec.deserialize(codec.serialize(root));
	system("pause");
	return 0;
}

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));