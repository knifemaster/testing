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

};
