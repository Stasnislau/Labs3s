#include <iostream>
#include "lab1.hpp"

using namespace std;
template <typename t_key, typename t_info>
void splitByPosition(Sequence<t_key, t_info> &seq, int start_pos, int len1, int len2, int count)
{
    Sequence<t_key, t_info> seq1;
    Sequence<t_key, t_info> seq2;
    typename Sequence<t_key, t_info>::Iterator it = seq.begin();
    for (int i = 0; i < start_pos; i++)
    {
        it++;
    }
    for (int j = 0; j < count; j++)
    {
        for (int i = 0; i < len1; i++)
        {
            seq1.insert(it->key, it->info);
            if (it == seq.end())
            {
                cout << "Sequence 1: " << seq1 << endl;
                cout << "Sequence 2: " << seq2 << endl;
                return;
            }
            it++;
        }
        for (int i = 0; i < len2; i++)
        {
            seq2.insert(it->key, it->info);
            if (it == seq.end())
            {
                cout << "Sequence 1: " << seq1 << endl;
                cout << "Sequence 2: " << seq2 << endl;
                return;
            }
            it++;
        }
    }
    cout << "Sequence 1: " << seq1 << endl;
    cout << "Sequence 2: " << seq2 << endl;
}
template <typename t_key, typename t_info>
void splitByKey(Sequence<t_key, t_info> &seq, t_key startKey, int keyOccurrence, int len1, int len2, int count)
{
    Sequence<t_key, t_info> seq1;
    Sequence<t_key, t_info> seq2;
    typename Sequence<t_key, t_info>::Iterator it = seq.begin();
    int i = 0;
    while (i < keyOccurrence)
    {
        if (it->key == startKey)
        {
            i++;
        }
        it++;
    }
    for (int j = 0; j < count; j++)
    {
        for (int i = 0; i < len1; i++)
        {
            seq1.insert(it->key, it->info);
            if (it == seq.end())
            {
                cout << "Sequence 1: " << seq1 << endl;
                cout << "Sequence 2: " << seq2 << endl;
                return;
            }
            it++;
        }
        for (int i = 0; i < len2; i++)
        {
            seq2.insert(it->key, it->info);
            if (it == seq.end())
            {
                cout << "Sequence 1: " << seq1 << endl;
                cout << "Sequence 2: " << seq2 << endl;
                return;
            }
            it++;
        }
    }
    cout << "Sequence 1: " << seq1 << endl;
    cout << "Sequence 2: " << seq2 << endl;
}
int main()
{
    Sequence<int, string> seq;
    Sequence<int, string>::Iterator it;
    seq.insert(1, "one");
    seq.insert(1, "one");
    seq.insert(2, "two");
    seq.insert(3, "three");
    cout << seq;
    splitByPosition(seq, 1, 2, 1, 1);
    std::cout << "-----------------------" << std::endl;
    splitByKey(seq, 1, 1, 2, 1, 1);
    return 0;
}