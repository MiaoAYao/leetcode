#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* p1 = l1;
		ListNode* p2 = l2;

		//特殊情况
		if (p1 == NULL && p2 == NULL)
			return p1;
		else if (p1 == NULL && p2 != NULL)
			return p2;
		else if (p1 != NULL && p2 == NULL)
			return p1;


		//一般情况，l1和l2均不为NULL
		int h_val = 0;
		//为减少使用的内存，更改p1的值，作为最终结果
		while (true)
		{
			int sum = p1->val + p2->val + h_val;
			h_val = sum / 10;
			p1->val = sum % 10;

			if (p1->next == NULL || p2->next == NULL)
				break;

			p1 = p1->next;
			p2 = p2->next;	
		}

		if (p1->next == NULL && p2->next != NULL)
			p1->next = p2->next;
		
		while (h_val != 0)
		{
			if (p1->next == NULL)
			{
				ListNode* tempNode = new ListNode(h_val);
				p1->next = tempNode;
				break;
			}
			else
			{
				p1 = p1->next;
				int sum = p1->val + h_val;
				p1->val = sum % 10;
				h_val = sum / 10;
			}
		}
		
		return l1;
	}
};

int main()
{
	ListNode* l1 = new ListNode(2);
	ListNode* temp = l1;
	ListNode* t = new ListNode(4);
	temp->next = t;
	temp = temp->next;
	t = new ListNode(3);
	temp->next = t;

	ListNode* l2 = new ListNode(5);
	temp = l2;
	t = new ListNode(6);
	temp->next = t;
	temp = temp->next;
	t = new ListNode(4);
	temp->next = t;

	Solution s;
	ListNode* r = s.addTwoNumbers(l1, l2);
	temp = r;
	while (temp != NULL)
	{
		cout << temp->val << "\t";
		temp = temp->next;
	}
	system("pause");
	return 0;
}