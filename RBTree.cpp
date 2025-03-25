#include <iostream>
#include <memory>

enum class Color { RED, BLACK };

template<typename T>
class RBTree {
    private:
        struct Node {
            T data;
            Color color;
            std::shared_ptr<Node> left;
            std::shared_ptr<Node> right;
            std::shared_ptr<Node> parent;

            Node (T val, Color c = Color::RED)
                : data(val), color(c), left(nullptr), right(nullptr), parent(nullptr) {}

        };
        
        std::shared_ptr<Node> root;
        std::shared_ptr<Node> nil;

        void leftRotate(std::shared_ptr<Node> x) {
            auto y = x->right;
            x->right = y->left;
            if (y->left != nil) {
                y->left->parent = x;
            }

            y->parent = x->parent;
            if (x->parent == nil) {
                root = y;
            } else if (x == x->parent->left) {
                x->parent->left = y;
            } else {
                x->parent->right = y;
            }
            y->left = x;
            x->parent = y;
        }


        void rightRotate(std::shared_ptr<Node> y) {
            auto x = y->left;
            y->left = x->right;
            if (x->right != nil) {
                x->right->parent = y;
            }
            x->parent = y->parent;
            if (y->parent == nil) {
                root = x;
            } else if (y == y->parent->left) {
                y->parent->left = x;
            } else {
                y->parent->right = x;
            }
            x->right = y;
            y->parent = x;
        }


};
