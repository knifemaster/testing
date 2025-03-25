#include <iostream>
#include <memory>
#include <algorithm>


template<typename T>
class AVLTree {
    private:
        struct Node {
            T data;
            int height;
            std::shared_ptr<Node> left;
            std::shared_ptr<Node> right;
        
            Node(T val) : data(val), height(1), left(nullptr), right(nullptr) {}
        };

        std::shared_ptr<Node> root;

        int getHeight(std::shared_ptr<Node> node) {
            return node ? node->height : 0;
        }

        void updateHeight(std::shared_ptr<Node> node) {
            if (node) {
                node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
            }
        }

        int getBalance(std::shared_ptr<Node> node) {
            return node ? getHeight(node->left) - getHeight(node->right) : 0;
        }

        std::shared_ptr<Node> rightRotate(std::shared_ptr<Node> y) {
            auto x = y->left;
            auto T2 = x->right;

            x->right = y;
            y->left = T2;

            updateHeight(y);
            updateHeight(x);

            return x;
        }

        std::shared_ptr<Node> leftRotate(std::shared_ptr<Node> x) {
            auto y = x->right;
            auto T2 = y->left;

            y->left = x;
            x->right = T2;

            updateHeight(x);
            updateHeight(y);

            return y;
        }

        std::shared_ptr<Node> balance(std::shared_ptr<Node> node) {
            if (!node) return nullptr;

            updateHeight(node);
            int balanceFactor = getBalance(node);

            if (balanceFactor > 1) {
                if (getBalance(node->left) < 0) {
                    node->left = leftRotate(node->left); 
                }
                return rightRotate(node);
            }        
            else if (balanceFactor < -1) {
                if (getBalance(node->right) > 0) {
                    node->right = rightRotate(node->right);  // Большое правое вращение
                }
                return leftRotate(node);
            }

            return node;
        }

        
        std::shared_ptr<Node> insertNode(std::shared_ptr<Node> node, T val) {
            if (!node) {
                return std::make_shared<Node>(val);
            }

            if (val < node->data) {
                node->left = insertNode(node->left, val);
            } else if (val > node->data) {
                node->right = insertNode(node->right, val);
            } else {
                return node;  // Дубликаты не допускаются
            }

            return balance(node);
        }

        bool searchNode(std::shared_ptr<Node> node, T val) {
            if (!node) return false;
            if (val == node->data) return true;
            if (val < node->data) return searchNode(node->left, val);
            return searchNode(node->right, val);
        }

        void printTree(std::shared_ptr<Node> node) {
            if (node) {
                printTree(node->left);
                std::cout << node->data << " (h=" << node->height << ")\n";
                printTree(node->right);
            }
        }


    public:
        AVLTree() : root(nullptr) {}

        void insert(T val) {
            root = insertNode(root, val);
        }

        bool search(T val) {
            return searchNode(root, val);
        }

        void print() {
            printTree(root);
        }

};
