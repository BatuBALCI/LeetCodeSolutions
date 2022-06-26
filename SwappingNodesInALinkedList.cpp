#include <tuple>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

class List {
public:
	static ListNode* insertAnywhere(ListNode* head, int value, int nodeLocation)
	{
		auto dummyHead = head;
		auto dummyHeadHold = head;
		auto node = new ListNode(value);
		for (int i = 1; i < nodeLocation; i++)
		{
			dummyHeadHold = dummyHead;
			if (dummyHead != nullptr)
				dummyHead = dummyHead->next;
		}
		if (head == dummyHead) {
			node->next = head;
			head = node;
		}
		else
		{
			dummyHeadHold->next = node;
			node->next = dummyHead;
		}
		return head;
	}
	static std::tuple<ListNode*, int> deleteSelectedAndGetDeletedValue(ListNode* head, int nodeLocation)
	{
		int value = 0;
		auto dummyHead = head;
		auto dummyHeadHold = head;
		for (int i = 1; i < nodeLocation; i++)
		{
			dummyHeadHold = dummyHead;
			if (dummyHead != nullptr)
				dummyHead = dummyHead->next;
		}
		if (dummyHead == dummyHeadHold)
		{
			if (dummyHead != nullptr) {
				head = dummyHead->next;
				value = dummyHead->val;
			}
		}
		else {
			dummyHeadHold->next = dummyHead ? dummyHead->next : nullptr;
			value = dummyHead ? dummyHead->val : 0;
		}
		dummyHead = nullptr;
		delete dummyHead;
		return { head, value };
	}
};

class Solution {
public:
	ListNode* swapNodes(ListNode* head, int k) {
		int count = 0;
		auto dummyHead = head;
		while (true)
		{
			if (dummyHead == nullptr)
				break;
			count++;
			dummyHead = dummyHead->next;
		}
		int place;
		if (k - 1 == count / 2)
			place = k;
		else if (k - 1 >= count / 2.0)
			place = count - k + 2;
		else
			place = count - k;

		std::tuple<ListNode*, int> result = List::deleteSelectedAndGetDeletedValue(head, k);
		result = List::deleteSelectedAndGetDeletedValue(List::insertAnywhere(std::get<0>(result), std::get<1>(result), count - k + 1), place);

		return List::insertAnywhere(std::get<0>(result), std::get<1>(result), k);
	}
};