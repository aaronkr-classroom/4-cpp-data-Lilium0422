//chp3ex3.cpp
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

int main()
{
    cout << "Enter all words followed by EOF : " << endl;

    vector<string> words;
    vector<int> counts;
    typedef vector<string>::size_type vec_sz;
    string word;
    vec_sz size;


    while (cin >> word) {
        int index = -1;
        size = words.size();
        for (int i = 0; i < size; i++)
            if (words[i] == word)
                index = i;
        
        if (index >= 0)
            ++counts[index];
        else {
            words.push_back(word);
            counts.push_back(1);
        }
    }

    size = words.size();
    if (size == 0) {
        cout << endl << "You must enter words. "
            "Please try again." << endl;
        return 1;
    }

    for (int i = 0; i < size; ++i)
        cout << "단어: " << words[i] << ", 등장 횟수: " << counts[i] << endl;

    return 0;
}