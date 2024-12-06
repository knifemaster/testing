#include <iostream>
#include <unordered_map>
#include <string_view>
#include <string>
#include <vector>
#include <memory>
#include <filesystem>

struct TreeNode {

		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

		~TreeNode() {
			std::cout << "destructor for" << val << std::endl;
			delete left;
			delete right;
		}

	bool destruct_trees(TreeNode* root) {
		//root->~TreeNode();
		destruct_trees(root->left);
		destruct_trees(root->right);
		return true;

	}

	bool visit_nodes(TreeNode* node) {
			if (node->left != nullptr) {
				std::cout << node->left->val;
				visit_nodes(node->left);
				// into left node
			}

			if (node-> right != nullptr) {
				std::cout << node->right->val;
				visit_nodes(node->right);
				// into right node
			}
			
			return true;
		}

};

std::vector<int> generate_values(int n) {

	std::vector<int> result;
		
	for (size_t value = 1; value < n; value++) {
		result.push_back(value);
	}

	return result;
}

TreeNode* insert_node_left(TreeNode* node, int val) {
	node->left = new TreeNode(val);

	return node;

}

TreeNode* insert_node_right(TreeNode* node, int val) {
	node->right = new TreeNode(val);
	return node;
}

TreeNode* insert_node(TreeNode* node, int val) {
	if (node->val > val) {
		return insert_node_left(node->left, val);
	}
	else {
		return insert_node_right(node->right, val);
	}

	return node;

}

TreeNode* search(TreeNode* node, int val) {
	if (node == nullptr) {
		return new TreeNode(0, nullptr, nullptr);
	
	}

	if (node->val == val) {
		return node;
	}

	if (node->left != nullptr) {
		return search(node->left, val);

	} 

	if (node->right != nullptr) {
		return search(node->right, val);
	}
	return node;

}

std::vector<TreeNode*> generate_trees(int n) {


	std::vector<TreeNode*> result;
	

	TreeNode* root;
	TreeNode* left;
	TreeNode* right;



	/*
		if (n == 0) {
			root = new TreeNode();
			result.push_back(root);
			return result;
		}

	    if (n == 1) {
			root = new TreeNode(1);
			result.push_back(root);
			return result;
		}

		int mid = n/2;
		TreeNode* left;
		TreeNode* right;
	*/
/*
		if (n > 1) {

			for (size_t index = 1; index <= n; index++) {
				if (mid > left->val) {
					
					//make right tree
				}
				else {
					//make right tree
				}

				
				root = new TreeNode();
				
				root->visit_nodes(root);
				if (root->left != nullptr) {
					// entry to left node
				}
				if (root->right != nullptr) {
					// entry to right node
				}
				
			}
		}
*/
	return result;

}



int main() {

	std::vector<TreeNode*> trees;
	trees = generate_trees(7);

	TreeNode* root = new TreeNode();

	std::vector<int> values = generate_values(7);
	
	for (size_t index = 0; index < values.size(); index++) {
		insert_node(root, values[index]);
	}

	std::cout << "value searched " <<search(root, 5)->val << std::endl;

	
	for (const auto& value : generate_values(3)) {
		std::cout << value << std::endl;
		TreeNode* left = new TreeNode();
		TreeNode* right = new TreeNode();
		TreeNode* tree = new TreeNode(10, left, right);

		delete tree;
	}
	//std::cout << trees[0]->val << std::endl;

	std::string name = "hello world";

	std::unordered_map<int, std::string> m_names;
	
	m_names[1] = "hello";
	m_names[2] = "world";

	std::cout << m_names[1] << m_names[2];
	std::cout << "hello world" <<std::endl;
	

}
