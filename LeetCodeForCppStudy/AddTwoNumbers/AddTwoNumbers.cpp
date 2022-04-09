/*
	两个非空的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。
	请你将两个数相加，并以相同形式返回一个表示和的链表
	你可以假设除了数字0之外，这两个数都不会以0开头。

	实例1
	输入：l1 = [2,4,3], l2 = [5,6,4]
	输出：[7,0,8]
	解释：342 + 465 = 807
	实例2
	输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
	输出：[8,9,9,9,0,0,0,1]
*/
#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int v) : val(v), next(nullptr) {}
	ListNode(int v, ListNode* pNext) : val(v), next(pNext) {}
}; 

void ListNodePrint(const string& title, const ListNode* pLN)
{
	cout << title.c_str() << "=[ ";

	if (pLN) {
		ListNode* pNext = pLN->next;
		cout << pLN->val;
		while (pNext) {
			cout << "," << pNext->val;
			pNext = pNext->next;
		}
	}

	cout << " ]" << endl;
}

/*
	版本一：利用int相加
	1. 先讲ListNode转化成int
	2. 将两个ListNode相加之后结果（int）再转化成ListNode
	缺点：
	这个方式是取巧的，但是当ListNode表达是一个很大的数，
	超过了int的范围，这个时候计算的结果就是错误的
*/
int ListNode2int(const ListNode* pLN)
{
	int realval = 0, times = 1;
	if (pLN) {
		ListNode* pNext = pLN->next;
		realval = pLN->val;
		int times = 10;
		while (pNext)
		{
			realval += pNext->val * times;
			pNext = pNext->next;
			times *= 10;
		}
	}
	return realval;
}

ListNode* int2ListNode(const int ival)
{
	int mod = ival;
	ListNode* pLN = new ListNode(mod % 10, nullptr);
	ListNode* pNextListNode = pLN;
	while (mod / 10 != 0)
	{
		mod = mod / 10;
		pNextListNode->next = new ListNode(mod % 10, nullptr);
		pNextListNode = pNextListNode->next;
	}

	return pLN;
}

void test()
{
	ListNode* pLN1 = int2ListNode(342);
	ListNode* pLN2 = int2ListNode(465);
	ListNodePrint("LN1", pLN1);
	ListNodePrint("LN2", pLN2);
}

/*
	版本二
	1. 按照链表的一位位的相加
	2. 若超过则按照加法逻辑往前进1
	细节：
	1. 若计算到两个链表的最高位的时候，注意向前进1的情况
	2. 三个链表都要向下迭代，不要因为判断条件忘记某一个的迭代
*/

ListNode* Add(ListNode* pLN1, ListNode* pLN2)
{
	ListNode* pSumLN = new ListNode();
	ListNode* pLN = pSumLN;
	int forward = 0;

	while (pLN1 || pLN2 || pLN)
	{
		int sum = forward + (pLN1 ? pLN1->val : 0) + (pLN2 ? pLN2->val : 0);
		pLN->val = sum % 10;
		forward = sum / 10;

		pLN1 = pLN1 ? pLN1->next : nullptr;
		pLN2 = pLN2 ? pLN2->next : nullptr;

		if (pLN1 || pLN2 || forward > 0) {
			pLN->next = new ListNode();
		}
		pLN = pLN->next;
	}

	return pSumLN;
}
void test2()
{
	ListNode* pLN1 = int2ListNode(99999);
	ListNode* pLN2 = int2ListNode(99);
	ListNodePrint("LN1", pLN1);
	ListNodePrint("LN2", pLN2);

	ListNode* pSumLN = Add(pLN1, pLN2);
	ListNodePrint("SUM", pSumLN);
}

int main()
{
	test2();
}
