#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ifstream in_file("./text.txt");
    if ( ! in_file )
    {
        cerr << "oops! unable to open input file\n";
        return -1;
    }
    ofstream out_file("./text_sort.txt");
    if ( ! out_file )
    {
        cerr << "oops! unable to open output file\n";
        return -2;
    }

    string word;
    vector<string> text;
    while (in_file >> word)
    {
        text.push_back(word);
    }

    cout << "unsorted text: \n";
    for (int ix = 0; ix < text.size(); ++ix)
    {
        cout << text[ix] << " ";
    }

    sort(text.begin(), text.end());

    out_file << "sorted text: \n";
    for (int ix = 0; ix < text.size(); ++ix)
    {
        out_file << text[ix] << " ";
    }
    out_file << endl;

    return 0;
}