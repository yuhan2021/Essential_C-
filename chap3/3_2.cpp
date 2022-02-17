#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <map>
using namespace std;

class LessThan {
public:
    bool operator() (const string & s1, const string & s2){
        return s1.size() < s2.size();
    }
};

void display_vector(const vector<string> & text, ostream & os, int len=8);

int main() {
    ifstream ifile("input_file.txt");
    ofstream ofile("sort_file.txt");

    if ( ! ifile || ! ofile ) {
        cerr << "Unable to open file! \n";
        return -1;
    }

    vector<string> text;
    string word;

    while (ifile >> word) {
        text.push_back(word);
    }

    sort(text.begin(), text.end(), LessThan());
    display_vector(text, ofile);

    return 0;
}

void display_vector(const vector<string> & text, ostream & os, int len) {
    vector<string>::const_iterator iter = text.begin(), end_iter = text.end();
    int elem_cnt = 1;
    while (iter != end_iter) {
        os << *iter++ << ((elem_cnt++ % len) ? ' ' : '\n');
    }
    os << endl;
}