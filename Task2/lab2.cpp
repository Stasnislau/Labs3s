#include "lab2class.hpp"
#include "lab2class.cpp"
#include <iostream>
using namespace std;
template <typename t_key, typename t_info>
void split_by_position(Ring<t_key, t_info> &ring, int startPosition, bool direct, int repetitions, Ring<t_key, t_info> &ring1, bool direct1, int length1, Ring<t_key, t_info> &ring2, bool direct2, int length2)
{
    if (startPosition < 0 || startPosition >= ring.getLength() || repetitions < 0 || length1 < 0 || length2 < 0 || ring.getLength() == 0)
    {
        return;
    }
    typename Ring<t_key, t_info>::Iterator it = ring.begin();
    Ring<t_key, t_info> tempRing1;
    Ring<t_key, t_info> tempRing2;
    if (direct)
    {
        for (int i = 0; i < startPosition; i++)
        {
            it++;
        }
        for (int i = 0; i < repetitions; i++)
        {
            for (int j = 0; j < length1; j++)
            {
                if (direct1)
                {
                    tempRing1.pushBack(it.getKey(), it.getInfo());
                }
                else
                {
                    tempRing1.pushFront(it.getKey(), it.getInfo());
                }
                it++;
            }
            for (int j = 0; j < length2; j++)
            {
                if (direct2)
                {
                    tempRing2.pushBack(it.getKey(), it.getInfo());
                }
                else
                {
                    tempRing2.pushFront(it.getKey(), it.getInfo());
                }
                it++;
            }
        }
    }
    else
    {
        for (int i = 0; i < startPosition; i++)
        {
            it--;
        }
        for (int i = 0; i < repetitions; i++)
        {
            for (int j = 0; j < length1; j++)
            {
                if (direct1)
                {
                    tempRing1.pushBack(it.getKey(), it.getInfo());
                }
                else
                {
                    tempRing1.pushFront(it.getKey(), it.getInfo());
                }
                it--;
            }
            for (int j = 0; j < length2; j++)
            {
                if (direct2)
                {
                    tempRing2.pushBack(it.getKey(), it.getInfo());
                }
                else
                {
                    tempRing2.pushFront(it.getKey(), it.getInfo());
                }
                it--;
            }
        }
    }
    it = tempRing1.begin();
    for (int i = 0; i < tempRing1.getLength(); i++)
    {
        ring1.pushBack(it.getKey(), it.getInfo());
        it++;
    }
    it = tempRing2.begin();
    for (int i = 0; i < tempRing2.getLength(); i++)
    {
        ring2.pushBack(it.getKey(), it.getInfo());
        it++;
    }
}
template <typename t_key, typename t_info>
void split_by_key(
    const Ring<t_key, t_info> &ring, t_key &startKey, int startOccurrence, bool direct, int repetitions,
    Ring<t_key, t_info> &ring1, bool direct1, int len1,
    Ring<t_key, t_info> &ring2, bool direct2, int len2)
{
    if (startOccurrence < 0 || repetitions < 0 || len1 < 0 || len2 < 0 || ring.getLength() == 0)
    {
        return;
    }
    typename Ring<t_key, t_info>::Iterator it = ring.begin();
    Ring<t_key, t_info> tempRing1;
    Ring<t_key, t_info> tempRing2;
    int count = 0;
    if (direct)
    {
        bool found = false;
        for (int i = 0; i < ring.getLength(); i++)
        {
            if (it.getKey() == startKey)
            {
                if (count == startOccurrence)
                {
                    found = true;
                    break;
                }
                count++;
            }
            it++;
        }
        if (!found)
        {
            return;
        }
        for (int i = 0; i < repetitions; i++)
        {
            for (int j = 0; j < len1; j++)
            {
                if (direct1)
                {
                    tempRing1.pushBack(it.getKey(), it.getInfo());
                }
                else
                {
                    tempRing1.pushFront(it.getKey(), it.getInfo());
                }
                it++;
            }
            for (int j = 0; j < len2; j++)
            {
                if (direct2)
                {
                    tempRing2.pushBack(it.getKey(), it.getInfo());
                }
                else
                {
                    tempRing2.pushFront(it.getKey(), it.getInfo());
                }
                it++;
            }
        }
    }
    else
    {
        bool found = false;
        for (int i = 0; i < ring.getLength(); i++)
        {
            if (it.getKey() == startKey)
            {
                if (count == startOccurrence)
                {
                    found = true;
                    break;
                }
                count++;
            }
            it--;
        }
        if (!found)
        {
            return;
        }
        for (int i = 0; i < repetitions; i++)
        {
            for (int j = 0; j < len1; j++)
            {
                if (direct1)
                {
                    tempRing1.pushBack(it.getKey(), it.getInfo());
                }
                else
                {
                    tempRing1.pushFront(it.getKey(), it.getInfo());
                }
                it--;
            }
            for (int j = 0; j < len2; j++)
            {
                if (direct2)
                {
                    tempRing2.pushBack(it.getKey(), it.getInfo());
                }
                else
                {
                    tempRing2.pushFront(it.getKey(), it.getInfo());
                }
                it--;
            }
        }
    }
    it = tempRing1.begin();
    for (int i = 0; i < tempRing1.getLength(); i++)
    {
        ring1.pushBack(it.getKey(), it.getInfo());
        it++;
    }
    it = tempRing2.begin();
    for (int i = 0; i < tempRing2.getLength(); i++)
    {
        ring2.pushBack(it.getKey(), it.getInfo());
        it++;
    }
}
int main()
{
    Ring<int, int> ring;
    ring.pushBack(1, 1);
    ring.pushBack(2, 2);
    ring.pushBack(3, 3);
    ring.pushBack(4, 4);
    ring.pushBack(5, 5);
    Ring<int, int> ring1;
    Ring<int, int> ring2;
    split_by_position(ring, 1, true, 4, ring1, true, 2, ring2, false, 1);
    cout << "ring: " << ring << endl;
    cout << "ring1: " << ring1 << endl;
    cout << "ring2: " << ring2 << endl;
    return 0;
}