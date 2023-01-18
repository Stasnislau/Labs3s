#include "class.hpp"
#include "class.cpp"
#include <fstream>
#include <iostream>
#include <string>
#include "lab2class.hpp"
#include "lab2class.cpp"

using namespace std;

void createDictionaryFromFile(Dictionary<string, int> &dict, string fileName)
{
    ifstream file(fileName);
    if(!file.is_open())
    {
        cout << "File not found" << endl;
        return;
    }
    string line;
    while(getline(file, line))
    {
        int pos = 0;
        while(pos < line.length())
        {
            string word = "";
            while(
            pos < line.length() && (line[pos] != ' ' && line[pos] != ':'  && line[pos] != ',' 
            && line[pos] != '.' && line[pos] != '!' && line[pos] != '?' && line[pos] !='(' 
            && line[pos] != ')' && line[pos] != '"' && line[pos] != ';' && line[pos] != '['
            && line[pos] != ']' && line[pos] != '{' && line[pos] != '}'))
            {
                word += line[pos];
                pos++;
            }
            pos++;
            if(word != "")
            {
                if(!dict.search(word))
                {
                    dict.insert(word, 1);
                }
                else
                {
                    dict.setInfo(word, dict.search(word).value() + 1);
                }
            }
        }
    }
}

void ringDictionary(Dictionary<string, int> &dict, Ring<string, int> &ring)
{
    int length = 0;
    auto array = dict.getAllElements(length);
    for(int i = 0; i < length; i++)
    {
        ring.pushBack(array[i].first, array[i].second);
    }
}

int main()
{
    Dictionary<int, int> dict;
    
    cout << "--------------------------First test--------------------------" << endl;
    dict.insert(1, 1);
    dict.insert(2, 2);
    dict.insert(3, 3);
    dict.insert(4, 4);
    dict.insert(5, 5);
    dict.display();

    cout << "--------------------------Second test--------------------------" << endl;

    dict.remove(3);
    dict.displayNode(3);
    dict.display();

    cout << "--------------------------Third test--------------------------" << endl;

    dict.clear();
    cout << "Display the tree (should be empty):" << endl;
    dict.display();
    cout << "Check if the tree is empty: " << (dict.isEmpty() ? "Yes" : "No")  << endl;

    cout << "--------------------------Fourth test--------------------------" << endl;

    Dictionary<string, int> dict2;
    dict2.insert("one", 1);
    dict2.insert("two", 2);
    dict2.insert("three", 3);
    dict2.insert("four", 4);
    dict2.displayNode("two");
    dict2.search("two") == 2 ? cout << "Yes" << endl : cout << "No" << endl;
    dict2.search("five") ? cout << "Yes" << endl : cout << "No" << endl;
    dict2.remove("two");
    dict2.displayNode("two");

    cout << "--------------------------Fifth test--------------------------" << endl;

    Dictionary<string, int> dict3;
    dict3.insert("six", 6);
    dict3.insert("seven", 7);
    dict2.setInfo("four", 5);
    dict2.setInfo("five", 6);

    cout << "Check if the tree is empty: " << (dict3.isEmpty() ? "Yes" : "No")  << endl;
    dict3.display();

    cout << "are dict2 and dict3 equal? " << (dict2 == dict3 ? "Yes" : "No") << endl;
    cout << "are dict2 and dict2 not equal? " << (dict2 != dict2 ? "Yes" : "No") << endl;

    cout << "--------------------------Sixth test--------------------------" << endl;

    cout << "Displaying dict2: " << endl;
    dict2.display();

    cout << "Displaying dict3: " << endl;
    dict3.display();

    dict3 = dict2;

    cout << "Displaying dict3 after assignment: " << endl;

    dict3.display();

    Dictionary<string, int> dict4(dict2);

    cout << "Displaying dict4 after copy constructor of dict2: " << endl;

    dict4.display();

    cout << "--------------------------Seventh test--------------------------" << endl;

    Dictionary<string, int> dict5;
    createDictionaryFromFile(dict5, "random.txt");

    cout << "Displaying dict5: " << endl;
    dict5.display();

    cout << "--------------------------Eighth test--------------------------" << endl;

    Dictionary<string, int> dict6;
    createDictionaryFromFile(dict6, "random.txt");

    cout << "--------------------------Ninth test--------------------------" << endl;
    Ring <string, int> ring;
    ringDictionary(dict6, ring);

    cout << ring << endl;

    cout << "End of tests--------------------------------------------------" << endl;

}