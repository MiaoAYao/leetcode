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
//		//����Ϊ�գ�û��Ҫ��ת
//		if (head == nullptr)
//			return head;
//
//		//����Ϊ��
//		ListNode* pred = NULL;
//		ListNode* present = head;
//		ListNode* succ = present->next;
//		//���ֻ��һ���ڵ㣬�����������ѭ��
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


//�ݹ鷽ʽ
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