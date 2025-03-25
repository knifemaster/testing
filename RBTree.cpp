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


        void fixInsert(std::shared_ptr<Node> z) {
            while (z->parent->color == Color::RED) {
                if (z->parent == z->parent->parent->left) {
                    auto y = z->parent->parent->right;
                    if (y->color == Color::RED) {
                        z->parent->color = Color::BLACK;
                        y->color = Color::BLACK;
                        z->parent->parent->color = Color::RED;
                        z = z->parent->parent;
                    } else {
                        if (z == z->parent->right) {
                            z = z->parent;
                            leftRotate(z);
                        }
                        z->parent->color = Color::BLACK;
                        z->parent->parent->color = Color::RED;
                        rightRotate(z->parent->parent);
                    }
                } else {
                    auto y = z->parent->parent->left;
                    if (y->color == Color::RED) {
                        z->parent->color = Color::BLACK;
                        y->color = Color::BLACK;
                        z->parent->parent->color = Color::RED;
                        z = z->parent->parent;
                    } else {
                        if (z == z->parent->left) {
                            z = z->parent;
                            rightRotate(z);
                        }
                        z->parent->color = Color::BLACK;
                        z->parent->parent->color = Color::RED;
                        leftRotate(z->parent->parent);
                    }
                }
            }
            root->color = Color::BLACK;
        }


        void insertNode(std::shared_ptr<Node> z) {
            auto y = nil;
            auto x = root;
            while (x != nil) {
                y = x;
                if (z->data < x->data) {
                    x = x->left;
                } else {
                    x = x->right;
                }
            }
            z->parent = y;
            if (y == nil) {
                root = z;
            } else if (z->data < y->data) {
                y->left = z;
            } else {
                y->right = z;
            }
            z->left = nil;
            z->right = nil;
            z->color = Color::RED;
            fixInsert(z);
        }


        std::shared_ptr<Node> searchNode(std::shared_ptr<Node> x, T key) {
            if (x == nil || key == x->data) {
                return x;
            }
            if (key < x->data) {
                return searchNode(x->left, key);
            } else {
                return searchNode(x->right, key);
            }
        }


        void printTree(std::shared_ptr<Node> x) {
            if (x != nil) {
                printTree(x->left);
                std::cout << x->data << " (" << (x->color == Color::RED ? "RED" : "BLACK") << ")\n";
                printTree(x->right);
            }
        }

    public:
        RBTree() {
            nil = std::make_shared<Node>(T(), Color::BLACK);
            root = nil;
        }

        void insert(T val) {
            auto z = std::make_shared<Node>(val);
            insertNode(z);
        }

        bool search(T val) {
            return searchNode(root, val) != nil;
        }

        void print() {
            printTree(root);
        }

};
