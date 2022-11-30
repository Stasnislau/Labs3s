#include <iostream>
#ifndef LAB1_HPP
#define LAB1_HPP
template <typename t_key, typename t_info>
class Sequence
{
private:
    struct Node
    {
        t_key key;
        t_info info;
        Node *next;
        Node(t_key key, t_info info, Node *next);
        Node();
    };
    Node *head, *tail;
    int length;
    Node *find(t_key key, int occurrence = 0);

public:
    class Iterator
    {
    private:
        Node *current;

    public:
        Iterator(Node *current = nullptr);
        Iterator &operator++(int);
        Iterator &operator++();
        bool operator!=(const Iterator &other) const;

        bool operator==(const Iterator &other) const;
        Iterator &operator=(const Iterator &other);
        // returns the key of the node the iterator points to
        t_key getKey() const;
        // returns the info of the node the iterator points to
        t_info getInfo() const;
        // sets the key of the node the iterator points to
        void setKey(t_key key);
        // sets the info of the node the iterator points to
        void setInfo(t_info info);
        
    };
    // returns iterator to the first element
    Iterator begin();
    // returns iterator to the last element
    Iterator end();
    // empty constructor
    Sequence();
    // copy constructor
    Sequence(const Sequence<t_key, t_info> &other);
    // destructor
    ~Sequence();
    // returns the number of elements in the sequence
    int getLength() const;
    // add a new element at the end or head of the sequence depending on the value of toHead, default is at the end
    bool add(t_key key, t_info info, bool toHead = false);
    // insert after the specified occurrence of the key
    bool insert(t_key key, t_info info, const t_key prevKey, int occurrence = 0);
    // removes the specified occurrence of the key
    bool remove(t_key key, int occ = 0);
    // returns true if the sequence is empty
    bool isEmpty() const;
    // overload of = operator
    Sequence &operator=(const Sequence &other);
    // swaps the elements at the specified occurrences of the keys
    bool moveNodes(t_key key1, t_key key2, int occurrences1 = 0, int occurrences2 = 0);
    // returns the number of occurrences of a specified key
    int occurrences(t_key key) const;
    // returns the position of the specified occurrence of the key in the list
    int positionOf(t_key key, int occurrence = 0) const;
    // removes an element at the specified position
    bool removeByPosition(int position);
    // checks if an element with the specified key exists in the sequence
    bool contains(t_key key) const;
    // removes all elements from the sequence
    void clear();

    // overload of << operator
    friend std::ostream &operator<<(std::ostream &out, Sequence<t_key, t_info> &other)
    {

        typename Sequence<t_key, t_info>::Node *temp = other.head;
        if (other.isEmpty())
        {
            out << "Empty sequence" << std::endl;
            return out;
        }
        out << "Sequence with length " << other.getLength() << ":\n";
        while (temp != nullptr)
        {
            out << temp->key << " " << temp->info << std::endl;
            temp = temp->next;
        }
        return out;
    }
};
#endif