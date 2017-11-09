#include <iostream>

using namespace std;

struct ListNode
{
	int value;
	struct ListNode* pNext;
};

class Solution
{
public:
	ListNode* findKthToTail(ListNode* pHead, unsigned int k)
	{
		if (NULL == pHead)
		{
			return NULL;
		}

		unsigned int i = 0;
		ListNode* pFirst = pHead;

		while (i < k -1 && pFirst != NULL )
		{
			pFirst = pHead->pNext;
			++ i;
		}

		if (NULL == pHead)
		{
			cout << "list node length less k!" << endl;
		}

		ListNode* pSecond = pHead;
		while (pFirst->pNext != NULL)
		{
			pSecond = pSecond->pNext;
			pFirst = pFirst->pNext;
		}

		return pSecond;
	}
};

int main()
{
	ListNode node[4];

	node[0].value = 1;
	node[0].pNext = &node[1];

	node[1].value = 2;
	node[1].pNext = &node[2];

	node[2].value = 3;
	node[2].pNext = &node[3];

	node[3].value = 4;
	node[3].pNext = NULL;

	Solution solu;

	cout << solu.findKthToTail(&node[0], 4)->value << endl;
}