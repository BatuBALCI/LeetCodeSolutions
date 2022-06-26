struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};

class List {
public:
	ListNode* head;

	List() : head(nullptr) {}

	void addFromFront(int value)
	{
		auto node = new ListNode(value);
		node->next = head;
		head = node;
	}
	void addFromBehind(int value)
	{
		auto node = new ListNode(value);
		auto dummyHead = this->head;
		if (head == nullptr)
			head = node;
		else {
			while (true)
			{
				if (dummyHead->next == nullptr) {
					dummyHead->next = node;
					break;
				}
				dummyHead = dummyHead->next;
			}
		}
	}
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		List batu;
		int addition = 0;
		do {
			int result = 0;
			if (l1 != nullptr) {
				result = l1->val;
				l1 = l1->next;
			}
			if (l2 != nullptr) {
				result = result + l2->val;
				l2 = l2->next;
			}

			batu.addFromBehind((result + addition) % 10);
			addition = (result + addition) / 10;

		} while ((l1 != nullptr || l2 != nullptr) || addition != 0);

		return batu.head;
	}
};
