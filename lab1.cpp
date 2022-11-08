#include <iostream>
#include "lab1.hpp"

using namespace std;
template <typename t_key, typename t_info>
void splitByPosition(Sequence<t_key, t_info> &seq, int start_pos, int len1, int len2, int count)
{
    Sequence<t_key, t_info> seq1;
    Sequence<t_key, t_info> seq2;
    typename Sequence<t_key, t_info>::Iterator it = seq.begin();
    if (seq.getLength() < start_pos || start_pos < 0 || Len1 < 0 || Len2 < 0 || count < 0)
    {
        return;
    }
    for (int i = 0; i < start_pos; i++)
    {
        it++;
    }
    for (int j = 0; j < count; j++)
    {
        for (int i = 0; i < len1; i++)
        {
            seq1.add(it->key, it->info);
            if (it == seq.end())
            {
                cout << "Sequence 1 " << seq1 << endl;
                cout << "Sequence 2 " << seq2 << endl;
                return;
            }
            it++;
        }
        for (int i = 0; i < len2; i++)
        {
            seq2.add(it->key, it->info);
            if (it == seq.end())
            {
                cout << "Sequence 1 " << seq1 << endl;
                cout << "Sequence 2 " << seq2 << endl;
                return;
            }
            it++;
        }
    }
    cout << "Sequence 1 " << seq1 << endl;
    cout << "Sequence 2 " << seq2 << endl;
}
template <typename t_key, typename t_info>
void splitByKey(Sequence<t_key, t_info> &seq, t_key startKey, int keyOccurrence, int len1, int len2, int count)
{
    Sequence<t_key, t_info> seq1;
    Sequence<t_key, t_info> seq2;
    typename Sequence<t_key, t_info>::Iterator it = seq.begin();
    if (seq.occurrences(startKey) < keyOccurrence || seq.occurrences(startKey) == 0 || keyOccurrence < 0 || Len1 < 0 || Len2 < 0 || count < 0)
    {
        return;
    }
    int counter = 0;
    while (true)
    {
        if (it->key == startKey)
        {
            if (counter == keyOccurrence)
            {
                break;
            }
            counter++;
        }
        it++;
    }
    for (int j = 0; j < count; j++)
    {
        for (int i = 0; i < len1; i++)
        {
            seq1.add(it->key, it->info);
            if (it == seq.end())
            {
                cout << "Sequence 1 " << seq1 << endl;
                cout << "Sequence 2 " << seq2 << endl;
                return;
            }
            it++;
        }
        for (int i = 0; i < len2; i++)
        {
            seq2.add(it->key, it->info);
            if (it == seq.end())
            {
                cout << "Sequence 1 " << seq1 << endl;
                cout << "Sequence 2 " << seq2 << endl;
                return;
            }
            it++;
        }
    }
    cout << "Sequence 1 " << seq1 << endl;
    cout << "Sequence 2 " << seq2 << endl;
}
int main()
{
    // testing the Sequence class, string - key, int - info, but number of the node
    Sequence<string, int> seq;
    Sequence<string, int>::Iterator it;
    cout << "-----------------------------------First test-----------------------------------" << endl;
    seq.add("first", 1);
    seq.add("second", 2);
    seq.add("third-1", 3);
    seq.add("third-1", 4);
    cout << seq;
    cout << "-----------------------------------Second test----------------------------------" << endl;
    seq.remove("third-1");
    cout << seq;
    seq.insert("third-1",3, "second");
    cout << seq;
    cout << "-----------------------------------Third test-----------------------------------" << endl;
    seq.remove("third-1", 1);
    seq.add("forth", 5);
    seq.add("new first", 0, true);
    cout << seq;
    cout << "-----------------------------------Forth test-----------------------------------" << endl;
    seq.remove("new first");
    seq.add("new head, other than new first", 6, true);
    seq.add("to be swapped with head", 0); 
    cout << seq;
    cout << "-----------------------------------Fifth test-----------------------------------" << endl;
    seq.moveNodes("to be swapped with head", "new head, other than new first");
    cout << seq;
    cout << "-----------------------------------Sixth test-----------------------------------" << endl;
    seq.remove("new head, other than new first");
    seq.insert("forth", 4, "third-1");
    it = seq.begin();
    for(int i = 0; i < seq.positionOf("forth",1); i++)
    {
        it++;
    }
    it->info = 7;
    cout << seq;
    cout << "-----------------------------------Seventh test----------------------------------" << endl;
    seq.clear();
    cout << seq;
    cout << "-----------------------------------Eighth test-----------------------------------" << endl;
    seq.add("to remain", 0);
    seq.add("to remain", 1);
    seq.add("to remain", 2);
    seq.add("moved to first", 3);
    seq.add("moved to first", 4);
    seq.add("moved to second", 5);
    seq.add("moved to second", 6);
    seq.add("moved to second", 7);
    seq.add("moved to first", 8);
    seq.add("moved to first", 9);
    seq.add("moved to second", 10);
    seq.add("moved to second", 11);
    seq.add("moved to second", 12);
    seq.add("to remain", 13);
    cout << seq;
    splitByPosition(seq, 3, 2, 3, 2);
    cout << "-----------------------------------Ninth test-----------------------------------" << endl;
    seq.remove("to remain", 3);
    seq.add("moved to first", 13);
    seq.add("moved to first", 14);
    seq.add("moved to second, stop here", 15);
    cout << seq;
    splitByPosition(seq, 3, 2, 3, 3);
    cout << "-----------------------------------Tenth test-----------------------------------" << endl;
    cout << seq;
    seq.insert("start here, to first", 3, "moved to first");
    seq.remove("moved to first");
    splitByKey(seq, string("start here, to first"), 0, 2, 3, 3); 
    return 0;
}