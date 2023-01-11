#ifndef DICTIONARY
#define DICTIONARY

#include <iostream>

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

        Node(t_key key, t_info info) : key(key), info(info), height(0), left(nullptr), right(nullptr) {}
    };

    Node *root;

    int height(Node *);
    int balance(Node *);
    Node *clear(Node *);
    Node *leftRotate(Node *);
    Node *rightRotate(Node *);
    Node *insert(Node *, t_key, t_info);
    Node *search(Node *, t_key);
    Node *deleteNode(Node *, t_key);
    Node *minValueNode(Node *);
    Node *print(Node *);
    Node *print(Node *, int);
    Node *copy(Node *);

public:
    Dictionary();
    Dictionary(const Dictionary &);
    ~Dictionary();

    void insert(t_key, t_info);
    void remove(t_key);
    void clear();
    t_info search(t_key);
    void display();
    void displayNode(t_key);
    bool isEmpty();
    Dictionary &operator=(const Dictionary &);
    bool operator==(const Dictionary &);
    bool operator!=(const Dictionary &);
};

#endif