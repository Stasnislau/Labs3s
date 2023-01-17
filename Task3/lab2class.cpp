#include "lab2class.hpp"
template <typename t_key, typename t_info>
Ring<t_key, t_info>::Ring()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}
template <typename t_key, typename t_info>
Ring<t_key, t_info>::~Ring()
{
    clear();
}
template <typename t_key, typename t_info>
void Ring<t_key, t_info>::insert(t_key key, t_info info, t_key prevKey, int occurrence)
{
    Node *temp = find(prevKey, occurrence);
    if (temp == nullptr)
    {
        return;
    }
    if (temp == head)
    {
        pushFront(key, info);
    }
    else
    {
        Node *newNode = new Node(key, info, temp, temp->prev);
        temp->prev->next = newNode;
        temp->prev = newNode;
        size++;
    }
}
template <typename t_key, typename t_info>
void Ring<t_key, t_info>::pushFront(t_key key, t_info info)
{
    if (isEmpty())
    {
        head = new Node(key, info, nullptr, nullptr);
        tail = head;
        head->next = head;
        head->prev = head;
    }
    else
    {
        Node *newNode = new Node(key, info, head, tail);
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }
    size++;
}
template <typename t_key, typename t_info>
void Ring<t_key, t_info>::pushBack(t_key key, t_info info)
{
    if (isEmpty())
    {
        head = new Node(key, info, nullptr, nullptr);
        tail = head;
        head->next = head;
        head->prev = head;
    }
    else
    {
        Node *newNode = new Node(key, info, head, tail);
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
        std::cout << head->next << std::endl;
    }
    size++;
}
template <typename t_key, typename t_info>
void Ring<t_key, t_info>::removeByPosition(int position)
{
    if (position < 0 || position >= size)
    {
        return;
    }
    Node *temp = head;
    for (int i = 0; i < position; i++)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        head = head->next;
        delete temp;
        size--;
        return;
    }
    if (temp == tail)
    {
        tail = tail->prev;
        delete temp;
        size--;
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    size--;
}
template <typename t_key, typename t_info>
void Ring<t_key, t_info>::remove(t_key key, int occurrence)
{
    if (occurrence < 0 || occurrence > occurrencesOf(key))
    {
        return;
    }
    Node *temp = find(key, occurrence);
    if (temp == nullptr)
    {
        return;
    }
    if (temp == head)
    {
        head = head->next;
    }
    if (temp == tail)
    {
        tail = tail->prev;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    size--;
}
template <typename t_key, typename t_info>
void Ring<t_key, t_info>::insertByPosition(t_key key, t_info info, int position)
{
    if (position < 0 || position > size)
    {
        if (size == 0 && position == 0)
        {
            pushFront(key, info);
        }
        return;
    }
    if (position == 0)
    {
        pushFront(key, info);
    }
    else if (position == size)
    {
        pushBack(key, info);
    }
    else
    {
        Node *temp = head;
        for (int i = 0; i < position; i++)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(key, info, temp, temp->prev);
        temp->prev->next = newNode;
        temp->prev = newNode;
        size++;
    }
}
template <typename t_key, typename t_info>
int Ring<t_key, t_info>::getLength() const
{
    return size;
}
template <typename t_key, typename t_info>
bool Ring<t_key, t_info>::isEmpty() const
{
    return size == 0;
}
template <typename t_key, typename t_info>
void Ring<t_key, t_info>::clear()
{
    Node *temp = head;
    while (temp != tail)
    {
        Node *toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    delete tail;
    head = nullptr;
    tail = nullptr;
    size = 0;
}
template <typename t_key, typename t_info>
bool Ring<t_key, t_info>::contains(t_key key) const
{
    Node *temp = head;
    while (temp != tail)
    {
        if (temp->key == key)
        {
            return true;
        }
        temp = temp->next;
    }
    if (temp->key == key)
    {
        return true;
    }
    return false;
}
template <typename t_key, typename t_info>
void Ring<t_key, t_info>::remove(Iterator &it)
{

    if (it.current == nullptr)
    {
        return;
    }
    Node *temp = it.current;
    if (temp == head && temp == tail)
    {
        delete temp;
        head = nullptr;
        tail = nullptr;
        size = 0;
        return;
    }
    if (temp == head)
    {
        head = head->next;
    }
    else if (temp == tail)
    {
        tail = tail->prev;
    }
    it++;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    size--;
}
template <typename t_key, typename t_info>
typename Ring<t_key, t_info>::Node *Ring<t_key, t_info>::find(t_key key, int occurrence)
{
    if (occurrence < 0 || occurrence > occurrencesOf(key))
    {
        return nullptr;
    }
    Node *temp = head;
    int counter = 0;
    while (temp != tail)
    {
        if (temp->key == key)
        {
            if (counter == occurrence)
            {
                return temp;
            }
            counter++;
        }
        temp = temp->next;
    }
    if (temp->key == key)
    {
        if (counter == occurrence)
        {
            return temp;
        }
    }
    return nullptr;
}
template <typename t_key, typename t_info>
int Ring<t_key, t_info>::occurrencesOf(t_key key) const
{
    int counter = 0;
    Node *temp = head;
    while (temp != tail)
    {
        if (temp->key == key)
        {
            counter++;
        }
        temp = temp->next;
    }
    if (temp->key == key)
    {
        counter++;
    }
    return counter;
}
template <typename t_key, typename t_info>
int Ring<t_key, t_info>::positionOf(t_key key, int occurrence) const
{
    if (occurrence < 0 || occurrence > occurrencesOf(key))
    {
        return -1;
    }
    Node *temp = head;
    int counter = 0;
    int position = 0;
    while (temp != tail)
    {
        if (temp->key == key)
        {
            if (counter == occurrence)
            {
                return position;
            }
            counter++;
        }
        temp = temp->next;
        position++;
    }
    if (temp->key == key)
    {
        if (counter == occurrence)
        {
            return position;
        }
    }
    return -1;
}
template <typename t_key, typename t_info>
Ring<t_key, t_info> &Ring<t_key, t_info>::operator=(const Ring &other)
{
    if (this != &other)
    {
        clear();
        Node *temp = other.head;
        while (temp != other.tail)
        {
            pushBack(temp->key, temp->info);
            temp = temp->next;
        }
        pushBack(temp->key, temp->info);
    }
    return *this;
}
template <typename t_key, typename t_info>
Ring<t_key, t_info>::Iterator::Iterator(Node *current)
{
    this->current = current;
}
template <typename t_key, typename t_info>
typename Ring<t_key, t_info>::Iterator &Ring<t_key, t_info>::Iterator::operator++()
{
    if (current != nullptr)
    {
        current = current->next;
    }
    return *this;
}
template <typename t_key, typename t_info>
typename Ring<t_key, t_info>::Iterator &Ring<t_key, t_info>::Iterator::operator++(int)
{
    if (current != nullptr)
    {
        current = current->next;
    }
    return *this;
}
template <typename t_key, typename t_info>
typename Ring<t_key, t_info>::Iterator &Ring<t_key, t_info>::Iterator::operator--()
{
    if (current != nullptr)
    {
        current = current->prev;
    }
    return *this;
}
template <typename t_key, typename t_info>
typename Ring<t_key, t_info>::Iterator &Ring<t_key, t_info>::Iterator::operator--(int)
{
    if (current != nullptr)
    {
        current = current->prev;
    }
    return *this;
}
template <typename t_key, typename t_info>
bool Ring<t_key, t_info>::Iterator::operator==(const Iterator &other) const
{
    return current == other.current;
}
template <typename t_key, typename t_info>
bool Ring<t_key, t_info>::Iterator::operator!=(const Iterator &other) const
{
    return current != other.current;
}
template <typename t_key, typename t_info>
typename Ring<t_key, t_info>::Iterator &Ring<t_key, t_info>::Iterator::operator=(const Iterator &other)
{
    current = other.current;
    return *this;
}
template <typename t_key, typename t_info>
t_key Ring<t_key, t_info>::Iterator::getKey() const
{
    return current->key;
}
template <typename t_key, typename t_info>
t_info Ring<t_key, t_info>::Iterator::getInfo() const
{
    return current->info;
}
template <typename t_key, typename t_info>

void Ring<t_key, t_info>::Iterator::setInfo(t_info info)
{
    current->info = info;
}
template <typename t_key, typename t_info>
void Ring<t_key, t_info>::Iterator::setKey(t_key key)
{
    current->key = key;
}
template <typename t_key, typename t_info>
typename Ring<t_key, t_info>::Iterator Ring<t_key, t_info>::begin()
{
    return Iterator(head);
}
