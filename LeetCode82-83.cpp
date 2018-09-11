#include <iostream>
#include <math.h>

struct ListNode {
	ListNode *next;
	int val;
	ListNode(int v):next(NULL), val(v){}
};

class Solution {
public:
	ListNode * constructNode(int arr[], int n)
	{
		ListNode *head = new ListNode(0);
		ListNode *p = head;
		for (int i = 0; i < n; ++i)
		{
			ListNode *tmp = new ListNode(*(arr+i));
			p->next = tmp;
			p = p->next;
		}
		return head->next;
	}

	void destructNode(ListNode *head)
	{
		while (!head)
		{
			ListNode *tmp = head;
			head = head->next;
			delete tmp;
		}
	}

	//--------------------------------------------------------
	// LeetCode 82
	/*ListNode * deleteDuplicates(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *p = head, *q = head->next;
		ListNode* h = head;
		while (q)
		{
			if (p->val == q->val)
			{
				while (q)
				{
					if (p->val == q->val) q = q->next; 
					else break;
				}
				if (!q)
				{
					if (head == p)
					{
						while (p != q)
						{
							ListNode* r = p;
							p = p->next;
							delete r;
						}
						return NULL;
					}
					ListNode* tmp = h;
					while (tmp)
					{
						if(tmp->next != p) tmp = tmp->next;
						else break;
					}
					while (p != q)
					{
						ListNode* r = p;
						p = p->next;
						delete r;
					}
					tmp->next = q;
					return head;
				}
				else if (p == head)
				{
					while (p != q)
					{
						ListNode* r = p;
						p = p->next;
						delete r;
					}
					q = q->next;
					h = head = p;
				}
				else
				{
					ListNode* tmp = h;
					while (tmp->next != p) tmp = tmp->next;
					tmp->next = q;
					while (p != q)
					{
						ListNode* r = p;
						p = p->next;
						delete r;
					}
					q = q->next;
					h = tmp;
					tmp = NULL;
				}
			}
			else
			{
				while (q)
				{
					if (p->val != q->val)
					{
						p = p->next;
						q = q->next;
					}
					else break;
				}
				if (!q)
				{
					return head;
				}
			}
		}
		return head;
	}*/

	//--------------------------------------------------------
	// LeetCode 83
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *p = head, *q = head->next;
		while (q)
		{
			int count = 0;
			bool flag = false;
			while (q)
			{
				if (p->val != q->val)
				{
					if (flag) break;
					p = p->next;
					q = q->next;
				}
				else
				{
					q = q->next;
					++count;
					flag = true;
				}
			}
			if (!q)
			{
				ListNode *h = p;
				p = p->next;
				for (int i = 0; i<count; ++i)
				{
					ListNode *t = p;
					p = p->next;
					delete t;
				}
				h->next = NULL;
				return head;
			}
			else
			{
				ListNode *h = p;
				p = p->next;
				for (int i = 0; i<count; ++i)
				{
					ListNode *t = p;
					p = p->next;
					delete t;
				}
				h->next = q;
				p = q;
				q = q->next;
			}
		}
		return head;
	}
};



//--------------------------------------------------------
// LeetCode 2
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode *p = l1, *q = l2;
	ListNode *dummyhead = new ListNode(0);
	ListNode *t = dummyhead;
	int carry = 0;
	while (p || q)
	{
		int v1 = (p != NULL) ? p->val : 0;
		int v2 = (q != NULL) ? q->val : 0;
		int sum = carry + v1 + v2;
		carry = sum / 10;
		t->next = new ListNode(sum % 10);
		t = t->next;
		if (p->next) p = p->next;
		if (q->next) q = q->next;
	}
	if (carry)
	{
		t->next = new ListNode(1);
	}
	return dummyhead->next;
}

int main()
{
	Solution s;
	int arr[] = { 1,1,1,2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	ListNode *head = s.constructNode(arr, n);
	//head = s.deleteDuplicates(head);
	int arr1[] = { 2,4,3 };
	int n_arr1 = sizeof(arr1) / sizeof(arr1[0]);
	ListNode *l1 = s.constructNode(arr1, n_arr1);
	int arr2[] = { 5,6,4 };
	int n_arr2 = sizeof(arr2) / sizeof(arr2[0]);
	ListNode *l2 = s.constructNode(arr2, n_arr2);
	head = addTwoNumbers(l1, l2);
	s.destructNode(head);

	return 0;
}