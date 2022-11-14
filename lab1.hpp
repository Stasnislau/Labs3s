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
        Node(t_key key, t_info info, Node *next)
        {
            this->key = key;
            this->info = info;
            this->next = next;
        }
        Node()
        {
        }
    };
    Node *head, *tail;
    int length;
    Node *find(t_key key, int occurrence = 0)
    {
        Node *temp = head;
        int count = 0;
        while (temp != nullptr)
        {
            if (temp->key == key)
            {
                if (count == occurrence)
                {
                    return temp;
                }
                count++;
            }
            temp = temp->next;
        }
        return nullptr;
    }

public:
    class Iterator
    {
    private:
        Node *current;

    public:
        Iterator(Node *current = nullptr)
        {
            this->current = current;
        }
        Iterator &operator++(int)
        {
            if (current != nullptr)
            {
                current = current->next;
            }
            return *this;
        }
        Iterator &operator++()
        {
            if (current != nullptr)
            {
                current = current->next;
            }
            return *this;
        }
        bool operator!=(const Iterator &other) const
        {
            return current != other.current;
        }
        bool operator==(const Iterator &other) const
        {
            return current == other.current;
        }
        Iterator &operator=(const Iterator &other)
        {
            current = other.current;
            return *this;
        }
        Node &operator*() const
        {
            return *current;
        }
        Node *operator->()
        {
            return current;
        }

    };
    Sequence()
    {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
    Sequence(const Sequence<t_key, t_info> &other)
    {
        length = 0;
        head = nullptr;
        tail = nullptr;
        Node *temp = other.head;
        std::cout << "Copy constructor called" << std::endl;
        while (temp != nullptr)
        {
            add(temp->key, temp->info);
            temp = temp->next;
        }
        std::cout << "Copy constructor finished" << std::endl;
    }
    int getLength() const
    {
        return length;
    }
    Iterator begin()
    {
        return Iterator(head);
    }
    Iterator end()
    {
        return Iterator(tail);
    } 
    // add a new element at the end or head of the sequence depending on the value of toHead, default is to the end
    bool add(t_key key, t_info info, bool toHead = false)
    {
        std::cout << length << std::endl;
        if (isEmpty())
        {
            head = new Node{key, info, tail};
            length++;
            tail = head;
            return true;
        }
        std:: cout << "after first" << std::endl;
        if (toHead)
        {
            Node *temp = new Node{key, info, head};
            head = temp;
            length++;
            return true;
        }
        tail->next = new Node{key, info, nullptr};
        tail = tail->next;
        length++;
        return true;
    }
    // insert after the specified occurrence of the key
    bool insert(t_key key, t_info info, const t_key prevKey, int occurrence = 0)
    {
        Node *temp = find(prevKey, occurrence);
        if (temp == nullptr)
        {
            return false;
        }
        Node *newNode = new Node{key, info, temp->next};
        temp->next = newNode;
        length++;
        if (temp == tail)
        {
            tail = newNode;
        }
        return true;
    }
    // removes the specified occurrence of the key
    bool remove(t_key key, int occ = 0)
    {
        if (isEmpty())
        {
            return false;
        }
        Node *temp = find(key, occ);
        if (temp == nullptr)
        {
            return false;
        }
        if (temp == head)
        {
            head = head->next;
            delete temp;
            length--;
            return true;
        }
        Node *prev = head;
        while (prev->next != temp)
        {
            prev = prev->next;
        }
        prev->next = temp->next;
        delete temp;
        length--;
        if (prev->next == nullptr)
        {
            tail = prev;
        }
        return true;
    }
    bool isEmpty() const
    {
        return length == 0;
    }
    Sequence &operator=(const Sequence &other)
    {
        if (this != &other)
        {
            clear();
            Node *temp = other.head;
            while (temp != nullptr)
            {
                add(temp->key, temp->info);
                temp = temp->next;
            }
        }
        return *this;
    }
    // swaps the elements at the specified occurrences of the keys
    bool moveNodes(t_key key1, t_key key2, int occurrences1 = 0, int occurrences2 = 0)
    {
        Node *temp1 = find(key1, occurrences1);
        Node *temp2 = find(key2, occurrences2);
        if (temp1 == nullptr || temp2 == nullptr)
        {
            return false;
        }
        t_key tempKey = temp1->key;
        t_info tempInfo = temp1->info;
        temp1->key = temp2->key;
        temp1->info = temp2->info;
        temp2->key = tempKey;
        temp2->info = tempInfo;
        return true;
    }
    int occurrences(t_key key) const
    {
        int count = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->key == key)
            {
                count++;
            }
            temp = temp->next;
        }
        return count;
    }
    int positionOf(t_key key, int occurrence = 0) const
    {
        int count = 0;
        int position = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->key == key)
            {
                if (count == occurrence)
                {
                    return position;
                }
                count++;
            }
            position++;
            temp = temp->next;
        }
        return -1;
    }
    bool contains(t_key key) const
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->key == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    // removes all elements from the sequence
    void clear()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
    friend std::ostream &operator<<(std::ostream &out, Sequence &other)
    {
        try
        {
            Node *temp = other.head;
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