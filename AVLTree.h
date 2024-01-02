// Get idea from: https://gist.github.com/gowoonsori/3ea3a2d0fb8b9f3f7c6ac4d8876d8a85

#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

namespace SHM {
    template<typename T>
    class AVLTreeNode {
    public:
        T key;
        AVLTreeNode* left = nullptr;
        AVLTreeNode* right = nullptr;
        int height = 1;
    };

    template<typename T, typename Compare = std::less<T>>
    class AVLTree {
        AVLTreeNode<T>* root;

        std::function<bool(const T &, const T &)> compare;

        AVLTreeNode<T>* is_key(T key);
        void balance(AVLTreeNode<T>* &r, T key);
        void transplant(AVLTreeNode<T>* x);
        int get_balance_factor(AVLTreeNode<T>* r);

        AVLTreeNode<T>* rotate_left(AVLTreeNode<T>* x);
        AVLTreeNode<T>* rotate_right(AVLTreeNode<T>* y);
    public:
//        AVLTree() = default;

        AVLTree(const std::vector<T> &_v, const Compare& _compare = Compare());

        int get_height(AVLTreeNode<T>* r);
        AVLTreeNode<T>* insert(AVLTreeNode<T>* r, T key);
        AVLTreeNode<T>* erase(AVLTreeNode<T>* r, T key);
        AVLTree<T>* build(const std::vector<T> &v);
    };

    template<typename T, typename Compare>
    SHM::AVLTree<T, Compare>::AVLTree(const std::vector<T> &_v, const Compare& _compare) {
        compare = _compare;
        root = build(_v);
    }

    template<typename T, typename Compare>
    AVLTree<T>* AVLTree<T, Compare>::build(const std::vector<T> &v) {
        auto r = new AVLTree<T>;

        for (auto i : v) {
            if (!is_key(i))
                r->root->insert(i);
        }

        return r;
    }

    template<typename T, typename Compare>
    AVLTreeNode<T>* SHM::AVLTree<T, Compare>::is_key(T key) {
        AVLTreeNode<T>* tmp = root;

        while (tmp != nullptr && tmp->key != key)
            tmp = (compare(key, tmp->key)) ? tmp->left : tmp->right;

        return tmp;
    }

    template<typename T, typename Compare>
    void SHM::AVLTree<T, Compare>::balance(AVLTreeNode<T>* &r, T key) {
        int balance_factor = get_balance_factor(r);

        // 1. LL
        if (balance_factor > 1 && compare(key, r->left->key)) {
            r = rotate_right(r);
        }
        // 2. LR
        else if (balance_factor > 1 && !compare(key, r->left->key)) {
            r->left = rotate_left(r->left);
            r = rotate_right(r);
        }
        // 3. RR
        else if (balance_factor < -1 && !compare(key, r->right->key)) {
            r = rotate_left(r);
        }
        // 4. RL
        else if (balance_factor < -1 && compare(key, r->right->key)) {
            r->right = rotate_right(r->right);
            r = rotate_left(r);
        }
    }

    // if a node is deleted, children the node had have a new parent.
    template<typename T, typename Compare>
    void SHM::AVLTree<T, Compare>::transplant(AVLTreeNode<T>* x) {
        AVLTreeNode<T>* y = x;

        if (x->left == nullptr && x->right != nullptr) {
            x = x->right;
        } else if (x->right != nullptr && x->right == nullptr) {
            x = x->left;
        } else {
            AVLTreeNode<T>* z = x->right;
            AVLTreeNode<T>* parent_z = x;

            while (z->left != nullptr) {
                parent_z = z;
                z = z->left;
            }

            x->key = z->key;

            if (parent_z == x)
                x->right = z->right;
            else
                parent_z->left = z->right;
            y = z;
        }

        delete y;
    }

    template<typename T, typename Compare>
    AVLTreeNode<T>* SHM::AVLTree<T, Compare>::rotate_left(AVLTreeNode<T>* x) {
        AVLTreeNode<T>* y = x->right;
        x->right = y->left;
        y->left = x;

        x->height = std::max(get_height(x->left), get_height(x->right)) + 1;
        y->height = std::max(get_height(y->left), get_height(y->right)) + 1;

        return y;
    }

    template<typename T, typename Compare>
    AVLTreeNode<T>* SHM::AVLTree<T, Compare>::rotate_right(AVLTreeNode<T>* y) {
        AVLTreeNode<T>* x = y->left;
        y->left = x->right;
        x->right = y;

        y->height = std::max(get_height(y->left), get_height(y->right)) + 1;
        x->height = std::max(get_height(x->left), get_height(x->right)) + 1;

        return x;
    }

    template<typename T, typename Compare>
    int SHM::AVLTree<T, Compare>::get_balance_factor(AVLTreeNode<T>* r) {
        return get_height(r->left) - get_height(r->right);
    }

    template<typename T, typename Compare>
    int SHM::AVLTree<T, Compare>::get_height(AVLTreeNode<T>* r) {
        return (r != nullptr) ? r->height : 0;
    }

    template<typename T, typename Compare>
    AVLTreeNode<T>* SHM::AVLTree<T, Compare>::insert(AVLTreeNode<T>* r, T key) {
        if (r == nullptr) {
            AVLTreeNode<T>* z = new AVLTreeNode<T>;
            z->key = key;
            r = z;
            return r;
        } else if (compare(r->key, key)) {
            r->right = insert(r->right, key);
        } else {
            r->left = insert(r->left, key);
        }

        r->height = std::max(get_height(r->left), get_height(r->right)) + 1;
        balance(r, key);

        return r;
    }

    template<typename T, typename Compare>
    AVLTreeNode<T>* SHM::AVLTree<T, Compare>::erase(AVLTreeNode<T>* r, T key) {
        if (!compare(r->key, key) && r->left != nullptr) {
            r->left = erase(r->left, key);
        } else if (compare(r->key, key) && r->right != nullptr) {
            r->right = erase(r->right, key);
        } else if (r->key == key) {
            transplant(r);
        }

        // if it is not erase `root`...
        if (r != nullptr) {
            r->height = std::max(get_height(r->left), get_height(r->right)) + 1;
            balance(r, key);
        }

        return r;
    }
}   // namespace SHM

#endif // AVLTREE_H
