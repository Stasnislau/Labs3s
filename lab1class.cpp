#include <iostream>
#include "lab1.hpp"
template <typename t_key, typename t_info>
typename Sequence<t_key, t_info>::Node *Sequence<t_key, t_info>::find(t_key key, int occurrence)
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
template <typename t_key, typename t_info>
Sequence<t_key, t_info>::Iterator::Iterator(Node *current)
{
    this->current = current;
}
template <typename t_key, typename t_info>
typename Sequence<t_key, t_info>::Iterator &Sequence<t_key, t_info>::Iterator::operator++(int)
{
    if (current != nullptr)
    {
        current = current->next;
    }
    return *this;
}
template <typename t_key, typename t_info>
typename Sequence<t_key, t_info>::Iterator &Sequence<t_key, t_info>::Iterator::operator++()
{
    if (current != nullptr)
    {
        current = current->next;
    }
    return *this;
}
template <typename t_key, typename t_info>
bool Sequence<t_key, t_info>::Iterator::operator!=(const Sequence<t_key, t_info>::Iterator &other) const
{
    return current != other.current;
}
template <typename t_key, typename t_info>
bool Sequence<t_key, t_info>::Iterator::operator==(const Iterator &other) const
{
    return current == other.current;
}
template <typename t_key, typename t_info>
typename Sequence<t_key, t_info>::Iterator &Sequence<t_key, t_info>::Iterator::operator=(const Sequence<t_key, t_info>::Iterator &other)
{
    current = other.current;
    return *this;
}
template <typename t_key, typename t_info>
typename Sequence<t_key, t_info>::Node &Sequence<t_key, t_info>::Iterator::operator*() const
{
    return *current;
}
template <typename t_key, typename t_info>
typename Sequence<t_key, t_info>::Node *Sequence<t_key, t_info>::Iterator::operator->()
{
    return current;
}
template <typename t_key, typename t_info>
Sequence<t_key, t_info>::Node::Node(t_key key, t_info info, Node *next)
{
    this->key = key;
    this->info = info;
    this->next = next;
}
template <typename t_key, typename t_info>
Sequence<t_key, t_info>::Node::Node()
{
}
template <typename t_key, typename t_info>
Sequence<t_key, t_info>::Sequence()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}
template <typename t_key, typename t_info>
Sequence<t_key, t_info>::Sequence(const Sequence<t_key, t_info> &other)
{
    length = 0;
    head = nullptr;
    tail = nullptr;
    Node *temp = other.head;
    while (temp != nullptr)
    {
        add(temp->key, temp->info);
        temp = temp->next;
    }
}
template <typename t_key, typename t_info>
int Sequence<t_key, t_info>::getLength() const
{
    return length;
}
template <typename t_key, typename t_info>
typename Sequence<t_key, t_info>::Iterator Sequence<t_key, t_info>::begin()
{
    return Iterator(head);
}
template <typename t_key, typename t_info>
typename Sequence<t_key, t_info>::Iterator Sequence<t_key, t_info>::end()
{
    return Iterator(tail);
}
template <typename t_key, typename t_info>
bool Sequence<t_key, t_info>::add(t_key key, t_info info, bool toHead)
{
    if (isEmpty())
    {
        head = new Node{key, info, tail};
        length++;
        tail = head;
        return true;
    }
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
template <typename t_key, typename t_info>
bool Sequence<t_key, t_info>::insert(t_key key, t_info info, const t_key prevKey, int occurrence)
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
template <typename t_key, typename t_info>
bool Sequence<t_key, t_info>::remove(t_key key, int occ)
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
template <typename t_key, typename t_info>
bool Sequence<t_key, t_info>::isEmpty() const
{
    return length == 0;
}
template <typename t_key, typename t_info>
Sequence<t_key, t_info> &Sequence<t_key, t_info>::operator=(const Sequence &other)
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
template <typename t_key, typename t_info>
bool Sequence<t_key, t_info>::moveNodes(t_key key1, t_key key2, int occurrences1, int occurrences2)
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
template <typename t_key, typename t_info>
int Sequence<t_key, t_info>::occurrences(t_key key) const
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
template <typename t_key, typename t_info>
int Sequence<t_key, t_info>::positionOf(t_key key, int occurrence) const
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
template <typename t_key, typename t_info>
bool Sequence<t_key, t_info>::contains(t_key key) const
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
template <typename t_key, typename t_info>
void Sequence<t_key, t_info>::clear()
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