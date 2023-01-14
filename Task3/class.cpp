#include <iostream>
#include "class.hpp"
#include <optional>
using namespace std;

template <typename t_key, typename t_info>
Dictionary<t_key, t_info>::Dictionary()
{
    root = nullptr;
}

template <typename t_key, typename t_info>
Dictionary<t_key, t_info>::Node::Node()
{
    height = 0;
    left = nullptr;
    right = nullptr;
}

template <typename t_key, typename t_info>
Dictionary<t_key, t_info>::~Dictionary()
{
    root = clear(root);
}

template <typename t_key, typename t_info>
int Dictionary<t_key, t_info>::height(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->height;
}

template <typename t_key, typename t_info>
int Dictionary<t_key, t_info>::balance(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

template <typename t_key, typename t_info>
typename Dictionary<t_key, t_info>::Node *Dictionary<t_key, t_info>::leftRotate(Node *node)
{
    Node *right = node->right;
    Node *left = right->left;

    right->left = node;
    node->right = left;

    node->height = max(height(node->left), height(node->right)) + 1;
    right->height = max(height(right->left), height(right->right)) + 1;

    return right;
}

template <typename t_key, typename t_info>
typename Dictionary<t_key, t_info>::Node *Dictionary<t_key, t_info>::rightRotate(Node *node)
{
    Node *left = node->left;
    Node *right = left->right;

    left->right = node;
    node->left = right;

    node->height = max(height(node->left), height(node->right)) + 1;
    left->height = max(height(left->left), height(left->right)) + 1;

    return left;
}

template <typename t_key, typename t_info>
typename Dictionary<t_key, t_info>::Node *Dictionary<t_key, t_info>::insert(Node *node, t_key key, t_info info)
{
    if (node == nullptr)
    {
        return new Node(key, info);
    }

    if (key < node->key)
    {
        node->left = insert(node->left, key, info);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key, info);
    }
    else
    {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balanceFactor = balance(node);

    if (balanceFactor > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }

    if (balanceFactor < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }

    if (balanceFactor > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balanceFactor < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

template <typename t_key, typename t_info>
typename Dictionary<t_key, t_info>::Node *Dictionary<t_key, t_info>::deleteNode(Node *node, t_key key)
{
    if (node == nullptr)
    {
        return node;
    }

    if (key < node->key)
    {
        node->left = deleteNode(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = deleteNode(node->right, key);
    }
    else
    {
        if ((node->left == nullptr) || (node->right == nullptr))
        {
            Node *temp = node->left ? node->left : node->right;

            if (temp == nullptr)
            {
                temp = node;
                node = nullptr;
            }
            else
            {
                *node = *temp;
            }
            delete temp;
        }
        else
        {
            Node *temp = minValueNode(node->right);

            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key);
        }
    }

    if (node == nullptr)
    {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balanceFactor = balance(node);

    if (balanceFactor > 1 && balance(node->left) >= 0)
    {
        return rightRotate(node);
    }

    if (balanceFactor > 1 && balance(node->left) < 0)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balanceFactor< -1 && balance(node->right) <= 0)
    {
        return leftRotate(node);
    }

    if (balanceFactor < -1 && balance(node->right) > 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

template <typename t_key, typename t_info>
typename Dictionary<t_key, t_info>::Node *Dictionary<t_key, t_info>::minValueNode(Node *node)
{
    Node *current = node;

    while (current->left != nullptr)
    {
        current = current->left;
    }

    return current;
}

template <typename t_key, typename t_info>
typename Dictionary<t_key, t_info>::Node *Dictionary<t_key, t_info>::search(Node *node, t_key key)
{
    if (node == nullptr || node->key == key)
    {
        return node;
    }
    if (node->key < key)
    {
        return search(node->right, key);
    }
    return search(node->left, key);
}

template <typename t_key, typename t_info>
void Dictionary<t_key, t_info>::insert(t_key key, t_info info)
{
    root = insert(root, key, info);
}

template <typename t_key, typename t_info>
std::optional<t_info> Dictionary<t_key, t_info>::search(t_key key)
{
    Node *node = search(root, key);
    if (node != nullptr)
    {
        return node->info;
    }
    else
    {
        return {};
    }
}

template <typename t_key, typename t_info>
void Dictionary<t_key, t_info>::display()
{
    print(root);
}

template <typename t_key, typename t_info>
typename Dictionary<t_key, t_info>::Node *Dictionary<t_key, t_info>::print(Node *node)
{
    if (node != nullptr)
    {
        print(node->left);
        cout << node->key << " ";
        print(node->right);
    }
}

template <typename t_key, typename t_info>
typename Dictionary<t_key, t_info>::Node *Dictionary<t_key, t_info>::print(Node *node, int level)
{
    if (node != nullptr)
    {
        print(node->right, level + 1);
        for (int i = 0; i < level; i++)
        {
            cout << "    ";
        }
        cout << node->key << endl;
        print(node->left, level + 1);
    }
}

template <typename t_key, typename t_info>
void Dictionary<t_key, t_info>::displayNode(t_key key)
{
    Node *node = search(root, key);
    if (node != nullptr)
    {
        print(node);
    }
}

template <typename t_key, typename t_info>
bool Dictionary<t_key, t_info>::isEmpty()
{
    return root == nullptr;
}

template <typename t_key, typename t_info>
bool Dictionary<t_key, t_info>::operator!=(const Dictionary<t_key, t_info> &other)
{
    return root != other.root;
}

template <typename t_key, typename t_info>
bool Dictionary<t_key, t_info>::operator==(const Dictionary<t_key, t_info> &other)
{
    return root == other.root;
}

template <typename t_key, typename t_info>
typename Dictionary<t_key, t_info>::Node *Dictionary<t_key, t_info>::clear(Node *node)
{
    if (node != nullptr)
    {
        clear(node->left);
        clear(node->right);
        delete node;
    }
    return nullptr;
}

template <typename t_key, typename t_info>
void Dictionary<t_key, t_info>::clear()
{
    root = clear(root);
}

template <typename t_key, typename t_info>
typename Dictionary<t_key, t_info>::Node *Dictionary<t_key, t_info>::copy(Node *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    Node *newNode = new Node;
    newNode->key = node->key;
    newNode->info = node->info;
    newNode->left = copy(node->left);
    newNode->right = copy(node->right);
    return newNode;
}

template <typename t_key, typename t_info>
Dictionary<t_key, t_info>::Dictionary(const Dictionary<t_key, t_info> &other)
{
    root = copy(other.root);
}

template <typename t_key, typename t_info>
Dictionary<t_key, t_info> &Dictionary<t_key, t_info>::operator=(const Dictionary<t_key, t_info> &other)
{
    if (this != &other)
    {
        clear();
        root = copy(other.root);
    }
    return *this;
}

template <typename t_key, typename t_info>
void Dictionary<t_key, t_info>::remove(t_key key)
{
    root = deleteNode(root, key);
}

template <typename t_key, typename t_info>
void Dictionary<t_key, t_info>::setInfo(t_key key, t_info info)
{
    Node *node = search(root, key);
    if (node != nullptr)
    {
        node->info = info;
    }
}