//∫œ≤¢≈≈–Ú¡¥±Ì

#include <iostream>

using namespace std;

struct ListNode
{
public:
	int value;
	struct ListNode* next;
};

class Solution
{
public:
	ListNode* Merge(ListNode* pLeft,ListNode* pRight)
	{
		if(pLeft == NULL)
		{
			cout<<"Left is NULL"<<endl;
			return pRight;
		}
		else if(pRight == NULL)
		{
			cout<<"Right is NULL"<<endl;
		}
		
		ListNode* left = pLeft;
		ListNode* right = pRight;
		
		ListNode* head = NULL;
		if(left->value < right->value)
		{
			head = left;
			left = left->next;
			cout <<head->value <<"in list" <<endl;
		}
		else
		{
			head = right;
			right = right->next;
			cout<<head->value<<"in list" <<endl;
		}
		
		ListNode *curr = head;
		  
		while(left != NULL && right != NULL)
        {
            cout <<"left = " <<left->value <<", right = " <<right->value <<endl;

            if(left->value < right->value)
            {
                cout <<left->value <<"in list" <<endl;

                curr->next = left;
                curr = curr->next;

                left = left->next;
            }
            else
            {
                cout <<right->value <<"in list" <<endl;

                curr->next = right;
                curr = curr->next;

                right = right->next;
            }
        }

        if(left != NULL)
        {
            curr->next = left;
        }
        else
        {
            curr->next = right;
        }


        return head;
	}
};

//µ›πÈ

ListNode* Merge_Recursive(ListNode* pLeft, ListNode* pRight)
{
	if (NULL == pLeft)
	{
		return pRight;
	}
	else if (NULL == pRight)
	{
		return pLeft;
	}

	ListNode* pHead = NULL;

	if (pLeft->value < pRight->value)
	{
		pHead = pLeft;
		pHead->next = Merge_Recursive(pLeft->next, pRight);
	}
	else
	{
		pHead = pRight;
		pHead->next = Merge_Recursive(pLeft, pRight->next);
	}

	return pHead;
}

int main()
{
    ListNode left, right[3];

    left.value = 5;
    left.next = NULL;

    right[0].value = 1;
    right[0].next = &right[1];
    right[1].value = 2;
    right[1].next = &right[2];
    right[2].value = 4;
    right[2].next = NULL;


    Solution solu;
    ListNode *head = solu.Merge(&left, right);
    while(head != NULL)
    {
        cout <<head->value;
        head = head->next;
    }


    return 0;
}