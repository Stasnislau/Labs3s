#include "lab2class.hpp"
#include "lab2class.cpp"
#include <iostream>
using namespace std;
template <typename t_key, typename t_info>
void splitByPosition(Ring<t_key, t_info> &ring, int startPosition, bool direct, int repetitions, Ring<t_key, t_info> &ring1, bool direct1, int length1, Ring<t_key, t_info> &ring2, bool direct2, int length2)
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
void splitByKey(
    Ring<t_key, t_info> &ring, t_key startKey, int startOccurrence, bool direct, int repetitions,
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
    cout << "-----------------------------------First test-----------------------------------" << endl;
    Ring<int, string> ring1;
    ring1.pushBack(1, "one");
    ring1.pushBack(2, "two");
    ring1.pushBack(3, "three");
    ring1.pushBack(4, "four");
    ring1.pushFront(0, "zero");
    ring1.pushBack(4, "4 to be deleted");
    cout << "Ring 1: " << '\n' << ring1 << endl;
    cout << "-----------------------------------Second test-----------------------------------" << endl;
    ring1.remove(4, 1);
    cout << "Ring 1 after removing 4: " << '\n' << ring1 << endl;
    cout << "-----------------------------------Third test-----------------------------------" << endl;
    ring1.pushFront(0, "NEW HEAD TO BE DELETED");
    ring1.pushBack(4, "NEW TAIL TO BE DELETED");
    cout << "Ring 1 after adding new head and tail: " << '\n' << ring1 << endl;
    cout << "-----------------------------------Fourth test-----------------------------------" << endl;
    ring1.remove(0, 0);
    ring1.remove(4, 1);
    cout << "Ring 1 after removing new head and tail: " << '\n' << ring1 << endl;
    cout << "-----------------------------------Fifth test-----------------------------------" << endl;
    ring1.insert(100, "one hundred before three", 3);
    cout << "Ring 1 after inserting 100 before three: " << '\n' << ring1 << endl;
    ring1.insert(-1, "new head", 0);
    cout << "Ring 1 after inserting new head: " << '\n' << ring1 << endl;
    ring1.removeByPosition(0);
    cout << "Ring 1 after removing new head: " << '\n' << ring1 << endl;
    ring1.insertByPosition(-1, "new head", 0);
    cout << "Ring 1 after inserting new head: " << '\n' << ring1 << endl;
    ring1.removeByPosition(0);
    ring1.remove(100, 0);
    cout << "Ring 1 after removing 100 and new Head: " << '\n' << ring1 << endl;
    cout << "-----------------------------------Sixth test-----------------------------------" << endl;
    Ring<int, int> ring2;
    ring2.pushBack(1, 1);
    ring2.pushBack(2, 2);
    ring2.pushBack(3, 3);
    ring2.pushBack(4, 4);
    ring2.pushBack(5, 5);
    cout << ring2 << endl;
    ring2.clear();
    cout << ring2 << endl;
    cout << "-----------------------------------Seventh test-----------------------------------" << endl;
    Ring<int, double> ring3;
    ring3.insertByPosition(1, 1.1, 0);
    ring3.pushBack(2, 2.2);
    ring3.pushBack(3, 3.3);
    ring3.pushBack(4, 4.4);
    ring3.pushBack(5, 5.5);
    cout << ring3 << endl;
    Ring<int, double>::Iterator it;
    it = ring3.begin();
    it++;
    it++;
    ring3.remove(it);
    cout << ring3 << endl;
    cout << "-----------------------------------Eighth test-----------------------------------" << endl;
    Ring<int, string> ring4;

    ring4.pushBack(1, "one");
    ring4.pushBack(2, "two");
    ring4.pushBack(3, "three");
    ring4.pushBack(4, "four");
    ring4.pushBack(5, "five");
    cout << "Ring 4: " << '\n' << ring4 << endl;
    Ring<int, string> ring5;
    Ring<int, string> ring6;
    splitByPosition(ring4, 1, true, 4, ring5, true, 2 , ring6, false, 1);
    cout << "Ring 5: " << '\n' << ring5 << endl;
    cout << "Ring 6: " << '\n' << ring6 << endl;
    cout << "-----------------------------------Ninth test-----------------------------------" << endl;
    ring5.clear();
    ring6.clear();
    splitByKey(ring4,2, 0, false,  4, ring5, true, 2, ring6, false, 1);
    cout << "Ring 5: " << '\n' << ring5 << endl;
    cout << "Ring 6: " << '\n' << ring6 << endl;
    ring5.clear();
    ring5.pushBack(1, "one");
    Ring<Ring<int, string>, int> ring7;
    cout << "Doshlo do pushback" << endl;
    ring7.pushBack(ring5, 1);
    ring7.pushBack(ring5, 2);
    ring7.pushBack(ring5, 3);
    cout << "Doshlo do cout" << endl;
    cout << ring7 << endl;
    cout << "-----------------------------------End of Tests 1---------------------------------" << endl;
    return 0;
}