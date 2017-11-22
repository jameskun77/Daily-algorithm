#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	struct ListNode* pNext;
};

vector<int> printListNodeFromTail(ListNode* pNode)
{
	vector<int> res;
	if (pNode != NULL)
	{
		printListNodeFromTail(pNode->pNext);
		res.push_back(pNode->val);

		cout << pNode->val << endl;
	}

	return res;
}

int main()
{
	ListNode list[4];
	list[0].val = 1;
	list[0].pNext = &list[1];
	list[1].val = 2;
	list[1].pNext = &list[2];
	list[2].val = 3;
	list[2].pNext = &list[3];
	list[3].val = 4;
	list[3].pNext = NULL;

	printListNodeFromTail(list);

}