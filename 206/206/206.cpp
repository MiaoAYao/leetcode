#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
//class Solution {
//public:
//	ListNode* reverseList(ListNode* head) {
//
//		//链表为空，没必要反转
//		if (head == nullptr)
//			return head;
//
//		//链表不为空
//		ListNode* pred = NULL;
//		ListNode* present = head;
//		ListNode* succ = present->next;
//		//如果只有一个节点，不会进入以下循环
//		while (true)
//		{
//			succ = present->next;
//			present->next = pred;
//			if (succ == nullptr)
//				break;
//			pred = present;
//			present = succ;
//		}
//		return present;
//	}
//};


//递归方式
class Solution {
public:
	ListNode* reverse(ListNode* head, ListNode* &newHead)
	{
		if (head->next != nullptr)
		{
			ListNode* tempNode = reverse(head->next, newHead);
			tempNode->next = head;
		}
		else
		{
			newHead = head;
		}
		return head;
	}

	ListNode* reverseList(ListNode* head) {
		if (head == nullptr)
			return head;
		ListNode* newHead;
		reverse(head, newHead);
		head->next = nullptr;
		return newHead;
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
	ListNode* newHead = s.reverseList(head);
	while (newHead != NULL)
	{
		cout << newHead->val << "\t";
		newHead = newHead->next;
	}
	cout << endl;
	system("pause");
	return 0;
}