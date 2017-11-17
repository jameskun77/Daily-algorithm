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

	ListNode* pLeftTmp = pLeft;
	ListNode* pRightTmp = pRight;
	int leftLen = getNodeLen(pLeftTmp);
	int rightLen = getNodeLen(pRightTmp);

	if (leftLen < rightLen)
	{
		int diff = rightLen - leftLen;
		while ( diff > 0 && pRightTmp != NULL)
		{
			pRightTmp = pRightTmp->pNext;
			diff--;
		}
	}
	else
	{
		int diff = leftLen - rightLen;
		while (diff > 0 && pLeftTmp != NULL)
		{
			pLeftTmp = pLeftTmp->pNext;
			diff--;
		}
	}

	while (pLeftTmp != NULL && pRightTmp != NULL)
	{
		if (pRightTmp == pLeftTmp)
		{
			break;
		}

		pLeftTmp = pLeftTmp->pNext;
		pRightTmp = pRightTmp->pNext;
	}

	return ((pRightTmp == pLeftTmp) ? pLeftTmp : NULL);
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