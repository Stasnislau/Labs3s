#include "class.hpp"
#include "class.cpp"
#include <cassert>

using namespace std;
int main()
{
    cout << "-----------------------------First test-----------------------------" << endl;
    Dictionary<string, int> dict;
    dict.insert("a", 1);
    dict.insert("b", 2);
    dict.insert("c", 3);
    dict.display();

    cout << endl << endl << endl;
    cout << "-----------------------------Second test-----------------------------" << endl;

    Dictionary<string, int> dict2;
    dict2.insert("a", 1);
    dict2.insert("b", 2);
    dict2.insert("c", 3);
    dict2.remove ("b");
    dict2.display();

    cout << "-----------------------------Third test-----------------------------" << endl;

}