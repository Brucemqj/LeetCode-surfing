#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * buildList(int arr[], int n)
	{
		ListNode *dummy = new ListNode(0);
		ListNode *t = dummy;
		for (int i = 0; i < n; ++i)
		{
			ListNode *tmp = new ListNode(*(arr + i));
			t->next = tmp;
			t = t ->next;
		}
		return dummy->next;
	}

	ListNode * reverseKGroup(ListNode* head, int k) {
		if (k == 1) return head;
		int length = 0;
		ListNode *p = head;
		while (p)
		{
			++length;
			p = p->next;
		}
		if (length < k) return head;
 		int steps = length / k;
		ListNode *curB = NULL, *curE = NULL, *nextB = NULL;
		for (int i = 0; i<steps; ++i)
		{
			if (i == 0)
			{
				reverseOne(head, k, &curB, &nextB);
				curE = head;
				head = curB;
				curB = nextB;
			}
			else
			{
				ListNode *start = curB;
				reverseOne(start, k, &curB, &nextB);
				curE->next = curB;
				curE = start;
				if (!nextB) break;
				curB = nextB;
			}		
		}
		curE->next = nextB;
		return head;
	}
	void reverseOne(ListNode *start, int k, ListNode **curBegin, ListNode **nextBegin)
	{
		*curBegin = start, *nextBegin = start->next;
		ListNode *nextq = start->next->next;
		for (int i = 0; i<k-1; ++i)
		{
			if (i == 0)
			{
				(*curBegin)->next = NULL;
			}
			(*nextBegin)->next = *curBegin;
			*curBegin = *nextBegin;
			*nextBegin = nextq;
			if (!nextq) break;
			nextq = nextq->next;
		}
	}

	void printNode(ListNode *head)
	{
		ListNode *p = head;
		while (p)
		{
			cout << p->val << "-->";
			p = p->next;
		}
		cout << endl;
	}

};

int main()
{
	int arr[] = { 1,2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	Solution s;
	ListNode *head = s.buildList(arr, n);
	head = s.reverseKGroup(head, 2);
	s.printNode(head);

	system("pause");
	return 0;
}
