#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {

		//这种情况下反转与不反转是一样的
		if (head == nullptr || head->next == nullptr || m == n)
			return head;

		ListNode* start = NULL;
		ListNode* start_succ;

		ListNode* slow = head;
		ListNode* fast = head->next;
		ListNode* tempNode;
		int index = 1;
		while (index < m)
		{
			if (index == m - 1)
				start = slow;
			slow = slow->next;
			++index;
		}

		start_succ = slow;
		fast = slow->next;

		//现在slow指在m的位置
		while (index < n)
		{
			tempNode = fast->next;
			fast->next = slow;
			slow = fast;
			fast = tempNode;
			++index;
		}

		if (start != NULL)
			start->next = slow;
		else
			head = slow;
		start_succ->next = fast;

		//这里不对
		//head可能已经改变了
		//有很多种情况
		//206不会出现这种情况么？
		return head;
	}
};

int main()
{
	ListNode* head = new ListNode(1);

	ListNode* tempNode = head;
	ListNode* node = new ListNode(2);
	tempNode->next = node;
	tempNode = tempNode->next;

	node = new ListNode(3);
	tempNode->next = node;
	tempNode = tempNode->next;

	node = new ListNode(4);
	tempNode->next = node;
	tempNode = tempNode->next;

	node = new ListNode(5);
	tempNode->next = node;

	Solution s;
	int m = 2;
	int n = 4;
	ListNode* newHead = s.reverseBetween(head, m, n);
	while (newHead != NULL)
	{
		cout << newHead->val << "\t";
		newHead = newHead->next;
	}
	cout << endl;
	system("pause");
	return 0;
}