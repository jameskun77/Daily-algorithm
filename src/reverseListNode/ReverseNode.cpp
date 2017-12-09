#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	struct ListNode* next;
};

ListNode* reverseNode(ListNode* node)
{
	ListNode* pReverseHead = NULL;
	ListNode* pCurNode = node;
	ListNode* pPreNode = NULL;

	while (pCurNode != NULL)
	{
		ListNode* next = pCurNode->next;
		if (next == NULL)
		{
			pReverseHead = pCurNode;
		}

		pCurNode->next = pPreNode;

		pPreNode = pCurNode;
		pCurNode = next;
	}

	return pReverseHead;
}

int main()
{
	ListNode list[5];
	list[0].val = 1;
	list[0].next = &list[1];
	list[1].val = 2;
	list[1].next = &list[2];
	list[2].val = 3;
	list[2].next = &list[3];
	list[3].val = 4;
	list[3].next = &list[4];
	list[4].val = 5;
	list[4].next = NULL;


	ListNode *node = list;
	while (node != NULL)
	{
		cout << node->val;
		node = node->next;
	}
	cout << endl;



	
	node = reverseNode(list);
	while (node != NULL)
	{
		cout << node->val;
		node = node->next;
	}
	cout << endl;

	return 0;
}