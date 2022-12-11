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
    Node *find(t_key key, int occurrence = 0);

public:
    Ring();
    ~Ring();
    void insert(t_key key, t_info info, t_key prevKey, int occurrence = 0);
    void pushFront(t_key key, t_info info);
    void pushBack(t_key key, t_info info);
    void remove(t_key key, int occurrence = 0);
    void insertByPosition(t_key key, t_info info, int position);
    int getLength() const;
    bool isEmpty() const;
    void clear();
    bool contains(t_key key) const;
    Ring &operator=(const Ring<t_key, t_info> &other);
    int positionOf(t_key key, int occurrence = 0) const;
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
    };
    Iterator begin();
    friend std::ostream &operator<<(std::ostream &out, const Ring<t_key, t_info> &ring)
    {
        Node *temp = ring.head;
        for (int i = 0; i < ring.size; i++)
        {
            out << temp->key << " " << temp->info << std::endl;
            temp = temp->next;
        }
        return out;
    }
};
#endif