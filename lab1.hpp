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
        Node &operator*() const;
        Node *operator->();
    };
    Iterator begin();
    Iterator end();

    Sequence();
    Sequence(const Sequence<t_key, t_info> &other);
    int getLength() const;
    // add a new element at the end or head of the sequence depending on the value of toHead, default is to the end
    bool add(t_key key, t_info info, bool toHead = false);
    // insert after the specified occurrence of the key
    bool insert(t_key key, t_info info, const t_key prevKey, int occurrence = 0);
    // removes the specified occurrence of the key
    bool remove(t_key key, int occ = 0);
    bool isEmpty() const;
    Sequence &operator=(const Sequence &other);
    // swaps the elements at the specified occurrences of the keys
    bool moveNodes(t_key key1, t_key key2, int occurrences1 = 0, int occurrences2 = 0);
    int occurrences(t_key key) const;
    int positionOf(t_key key, int occurrence = 0) const;
    bool contains(t_key key) const;
    // removes all elements from the sequence
    void clear();
    friend std::ostream &operator<<(std::ostream &out, Sequence<t_key, t_info> &other)
    {
         try
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
    }
    catch (const char *message)
    {
        std::cerr << "Error: " << message << '\n';
    }
    return out;
    }
};
#endif