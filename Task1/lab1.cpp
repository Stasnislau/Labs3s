#include <iostream>
#include "lab1.hpp"
#include "lab1class.cpp"

using namespace std;
template <typename t_key, typename t_info>
void splitByPosition(Sequence<t_key, t_info> &seq, int start_pos, int len1, int len2, int count, Sequence<t_key, t_info> &seq1, Sequence<t_key, t_info> &seq2)
{
    typename Sequence<t_key, t_info>::Iterator it = seq.begin();
    if (seq.getLength() < start_pos || start_pos < 0 || len1 < 0 || len2 < 0 || count < 0)
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
            seq1.add(it.getKey(), it.getInfo());
            if (it == seq.end())
            {
                return;
            }
            it++;
        }
        for (int i = 0; i < len2; i++)
        {
            seq2.add(it.getKey(), it.getInfo());
            if (it == seq.end())
            {
                return;
            }
            it++;
        }
    }
}
template <typename t_key, typename t_info>
void splitByKey(Sequence<t_key, t_info> &seq, t_key startKey, int keyOccurrence, int len1, int len2, int count, Sequence<t_key, t_info> &seq1, Sequence<t_key, t_info> &seq2)
{
    typename Sequence<t_key, t_info>::Iterator it = seq.begin();
    if (seq.occurrences(startKey) < keyOccurrence || seq.occurrences(startKey) == 0 || keyOccurrence < 0 || len1 < 0 || len2 < 0 || count < 0)
    {
        return;
    }
    int counter = 0;
    while (true)
    {
        if (it.getKey() == startKey)
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
            seq1.add(it.getKey(), it.getInfo());
            if (it == seq.end())
            {
                return;
            }
            it++;
        }
        for (int i = 0; i < len2; i++)
        {
            seq2.add(it.getKey(), it.getInfo());
            if (it == seq.end())
            {
                return;
            }
            it++;
        }
    }
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
    Sequence<string, int> seqTemp(seq);
    cout << seqTemp;
    cout << seq;
    cout << "-----------------------------------Second test----------------------------------" << endl;
    seq.remove("third-1");
    cout << seq;
    seq.insert("third-1", 3, "second");
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
    for (int i = 0; i < seq.positionOf("forth", 1); i++)
    {
        it++;
    }
    it.setInfo(7);
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
    Sequence<string, int> seq1;
    Sequence<string, int> seq2;
    splitByPosition(seq, 3, 2, 3, 2, seq1, seq2);
    cout << seq1;
    cout << seq2;
    cout << "-----------------------------------Ninth test-----------------------------------" << endl;
    seq.remove("to remain", 3);
    seq.add("moved to first", 13);
    seq.add("moved to first", 14);
    seq.add("moved to second, stop here", 15);
    seq1.clear();
    seq2.clear();
    cout << seq;
    splitByPosition(seq, 3, 2, 3, 3, seq1, seq2);
    cout << seq1;
    cout << seq2;
    seq1.clear();
    seq2.clear();
    cout << "-----------------------------------Tenth test-----------------------------------" << endl;
    cout << seq;
    seq.insert("start here, to first", 3, "moved to first");
    seq.remove("moved to first");
    splitByKey(seq, string("start here, to first"), 0, 2, 3, 3, seq1, seq2);
    cout << seq1;
    cout << seq2;
    cout << "-----------------------------------Wrong parameters test-------------------------" << endl;
    seq.clear();
    seq1.clear();
    seq2.clear();
    seq.add("first", 1);
    seq.add("second", 2);
    cout << seq;
    seq.remove("third",-2);
    cout << seq;
    seq.remove("third", 1);
    cout << seq;
    seq.remove("second", -1);
    cout << seq;
    seq.insert("third", 3, "not-existing");
    splitByKey(seq, string("non-existing"), 0, 2, 3, 3, seq1, seq2);
    splitByPosition(seq, -1, 2, 3, 3, seq1, seq2);
    cout << seq;

    
    cout << "------------------------------------Test end-------------------------------------" << endl;
    return 0;
    // to do cont iterator and using iterator for creating new sequence
}