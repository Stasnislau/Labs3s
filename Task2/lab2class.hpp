#include <iostream>
#ifndef LAB2CLASS_HPP
#define LAB2CLASS_HPP
template <typename t_key, typename t_info>
class Ring
{
    struct Node
    {
        t_key key;
        t_info info;
        Node *next;
        Node *prev;
        Node(t_key key, t_info info, Node *next, Node *prev)
        {
            this->key = key;
            this->info = info;
            this->next = next;
            this->prev = prev;
        }
    };
    Node *head;
    Node *tail;
    int size;
    // returns a pointer to the element with the key key and of specified occurrence
    Node *find(t_key key, int occurrence = 0);

public:
    // Constructor
    Ring();
    // Destructor
    ~Ring();
    // inserts an element after the element with the key prevKey
    void insert(t_key key, t_info info, t_key prevKey, int occurrence = 0);
    // inserts an element at the beginning of the ring
    void pushFront(t_key key, t_info info);
    // inserts an element at the end of the ring
    void pushBack(t_key key, t_info info);
    // removes the element with the key key and of specified occurrence
    void remove(t_key key, int occurrence = 0);
    // removes the element at the specified position
    void removeByPosition(int position);
    // inserts an element at the specified position
    void insertByPosition(t_key key, t_info info, int position);
    // returns the length of the ring
    int getLength() const;
    // returns true if the ring is empty
    bool isEmpty() const;
    // removes all elements from the ring
    void clear();
    // checks if the ring contains an element with the key key
    bool contains(t_key key) const;
    Ring &operator=(const Ring<t_key, t_info> &other);
    // returns the position of the element with the key key and of specified occurrence
    int positionOf(t_key key, int occurrence = 0) const;
    // returns the number of occurrences of the element with the key key
    int occurrencesOf(t_key key) const;
    class Iterator
    {
    private:
        Node *current;

    public:
        Iterator(Node *current = nullptr);
        Iterator &operator++(int);
        Iterator &operator++();
        Iterator &operator--(int);
        Iterator &operator--();
        bool operator!=(const Iterator &other) const;
        bool operator==(const Iterator &other) const;
        Iterator &operator=(const Iterator &other);
        t_key getKey() const;
        t_info getInfo() const;
        void setKey(t_key key);
        void setInfo(t_info info);
        friend class Ring;
    };
    // returns an iterator to the first element
    Iterator begin();
    // removes element at the position pointed by the iterator, and returns an iterator to the next element
    void remove(Iterator &it);
    friend std::ostream &operator<<(std::ostream &out, const Ring<t_key, t_info> &ring)
    {
        std::cout << "Poshlo po pizde" << std::endl;
        Node *temp = ring.head;
        std::cout << "Ring of length: " << ring.size << std::endl;
        for (int i = 0; i < ring.size; i++)
        {
            out << temp->key << " " << temp->info << std::endl;
            temp = temp->next;
        }
        return out;
    }
};
#endif