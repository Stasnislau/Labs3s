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

    // returns height of the node
    int height(Node *); 
    // returns balance factor of the node
    int getBalance(Node *);
    // recursive function to clear the tree
    Node *clear(Node *);
    // recursive function to perform left rotation
    Node *leftRotate(Node *);
    // recursive function to perform right rotation
    Node *rightRotate(Node *);
    // recursive function to insert a node
    Node *insert(Node *, t_key, t_info);
    // recursive function to search a node
    Node *search(Node *, t_key);
    // recursive function to delete a node
    Node *deleteNode(Node *, t_key);
    // recursive function to find the minimum value node
    Node *minValueNode(Node *);
    // recursive function to print a certain node
    Node *print(Node *, int);
    // recursive function to get the size of the tree
    Node *size(Node *, int &);
    // recursive function to copy a node
    Node *copy(Node *);
    // recursive function to get all elements of the tree
    void inOrderTraversal(Node *, std::pair<t_key, t_info> *, int &);

public:
    // constructor
    Dictionary();
    // copy constructor
    Dictionary(const Dictionary &);
    // destructor
    ~Dictionary();
    // inserts a node with the given key and info using recursive function insert
    void insert(t_key, t_info);
    // removes a node with the given key using recursive function deleteNode
    void remove(t_key);
    // returns the size of the tree using recursive function size
    int size();
    // clears the tree using recursive function clear
    void clear();
    // searches for a node with the given key using recursive function search, returns the info of the node if found or an empty optional if not found
    std::optional<t_info> search(t_key);
    // prints the tree using recursive function print
    void display();
    // prints the node with the given key
    void displayNode(t_key);
    // returns true if the tree is empty, false otherwise
    bool isEmpty();
    // sets the info of the node with the given key to the given info
    void setInfo(t_key, t_info);
    // returns array of all elements of the tree using recursive function inOrderTraversal in the form of a std::pair<t_key, t_info> and the size is provided by reference in the parameters
    std::pair<t_key, t_info> *getAllElements(int &);

    Dictionary &operator=(const Dictionary &);
    bool operator==(const Dictionary &);
    bool operator!=(const Dictionary &);
};

#endif