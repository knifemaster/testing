#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>


struct ListNode {
	int val;
	ListNode *next;
	//shared_ptr<ListNode> next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}

};

static int recurse_depth = 0;


ListNode* swapPairs(ListNode* head) {

	
	
	if (head == nullptr) {
		return new ListNode(0);
	}

	//std::cout << "value " << head->val << std::endl;
	//ListNode* h = head->next->next;
	
	//if (recurse_depth % 2 == 0) {
	ListNode* temp_next = head->next;
	ListNode* temp_head = head;
		
	head = head->next;
	head->next = temp_head;

	//	h = temp_next;	
	//}
	//recurse_depth += 1;

	auto h = temp_next->next;

	while (h != nullptr) {
		std::cout << "recurse depth" << recurse_depth << std::endl;
		//std::cout << head->val << std::endl;
		if (h != nullptr) {
			return swapPairs(head->next);
		}
	}
	
	return new ListNode(1);

}

ListNode* createListNode(ListNode* head) {
	ListNode* node = new ListNode(head->val, head);

	return node;

}

std::vector<ListNode*> vec_nodes;

int main() {

	ListNode * l1node = new ListNode(1);
	ListNode * l2node = new ListNode(2);
	ListNode * l3node = new ListNode(3);
	ListNode * l4node = new ListNode(4);

	
	l1node->next = l2node;
	l2node->next = l3node;
	l3node->next = l4node;
	l4node->next = nullptr;

	swapPairs(l1node);


	std::cout << l1node->next->next->next->val << std::endl;
	return 0;

}
