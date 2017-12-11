//两个链表的第一个公共节点

#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	struct ListNode* pNext;
};

int getNodeLen(ListNode* pNode)
{
	int len = 0;
	while (NULL != pNode)
	{
		len++;
		pNode = pNode->pNext;
	}

	return len;
}

ListNode* findFirstCommonNode(ListNode* pLeft, ListNode* pRight)
{
	if (NULL == pLeft || NULL == pRight)
	{
		cout << "invalided input. " << endl;
	}

	ListNode* pLongNode = pLeft;
	ListNode* pShortNode = pRight;

	int diff = getNodeLen(pLongNode) - getNodeLen(pShortNode);

	if (diff < 0)
	{
		pLongNode = pRight;
		pShortNode = pLeft;
		diff = getNodeLen(pLongNode) - getNodeLen(pShortNode);
	}

	while (diff > 0 && pLongNode !=NULL)
	{
		pLongNode = pLongNode->pNext;
		diff--;
	}

	while (NULL != pLongNode && NULL != pShortNode)
	{
		if (pLongNode == pShortNode)
		{
			break;
		}

		pLongNode = pLongNode->pNext;
		pShortNode = pShortNode->pNext;
	}

	return (pLongNode == pShortNode) ? pLongNode : NULL;


}

int main()
{
	ListNode common[2];
	common[0].val = 6;
	common[0].pNext = &common[1];
	common[1].val = 7;
	common[1].pNext = NULL;

	ListNode left[3];
	left[0].val = 1;
	left[0].pNext = &left[1];
	left[1].val = 2;
	left[1].pNext = &left[2];
	left[2].val = 3;
	left[2].pNext = &common[0];

	ListNode right[2];
	right[0].val = 4;
	right[0].pNext = &right[1];
	right[1].val = 5;
	right[1].pNext = &common[0];

	ListNode* pCommon = findFirstCommonNode(left, right);

	cout << "Common Node value: ";
	cout << pCommon->val << endl;
}