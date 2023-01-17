#ifndef DICTIONARY
#define DICTIONARY

#include <iostream>
#include <optional>

template <typename t_key, typename t_info>
class Dictionary
{
private:
    struct Node
    {
        t_key key;
        t_info info;
        int height;
        Node *left;
        Node *right;

        Node(t_key key, t_info info) : key(key), info(info), height(1), left(nullptr), right(nullptr) {}
        Node();
    };

    Node *root;

    int height(Node *);
    int getBalance(Node *);
    Node *clear(Node *);
    Node *leftRotate(Node *);
    Node *rightRotate(Node *);
    Node *insert(Node *, t_key, t_info);
    Node *search(Node *, t_key);
    Node *deleteNode(Node *, t_key);
    Node *minValueNode(Node *);
    Node *print(Node *, int);
    Node *size(Node *, int &);
    Node *copy(Node *);
    void inOrderTraversal(Node *, std::pair<t_key, t_info> *, int &);

public:
    Dictionary();
    Dictionary(const Dictionary &);
    ~Dictionary();

    void insert(t_key, t_info);
    void remove(t_key);
    int size();
    void clear();
    std::optional<t_info> search(t_key);
    void display();
    void displayNode(t_key);
    bool isEmpty();
    void setInfo(t_key, t_info);
    Dictionary &operator=(const Dictionary &);
    bool operator==(const Dictionary &);
    bool operator!=(const Dictionary &);
    std::pair<t_key, t_info> *getAllElements(int &);
};

#endif