#include <map>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void init_exclusion_set(set<string> &exc_set);
void process_file(map<string, int> &word_count, const set<string> &exc_set, ifstream &ifile);
void user_query(map<string, int> &word_count);
void display_word_count(map<string, int> &word_count, ofstream &ofile);

int main()
{
    ifstream ifile("input_file.txt");
    ofstream ofile("output_file.txt");
    if ( ! ifile || ! ofile )
    {
        cerr << "Unable to open file\n";
        return -1;
    }
    
    set<string> exc_set;
    init_exclusion_set(exc_set);

    map<string, int> word_count;
    process_file(word_count, exc_set, ifile);

    user_query(word_count);
    display_word_count(word_count, ofile);

    return 0;
}

void init_exclusion_set(set<string> &exc_set)
{
    static string _exclusion_words[25] = {
        "the","and","but","that","then","are","been", "can","a","could",
        "did","for", "of", "had","have","him","his","her","its","is", 
        "were","which","when","with","would"
    };

    exc_set.insert(_exclusion_words, _exclusion_words+25);
}

void process_file(map<string, int> &word_count, const set<string> &exc_set, ifstream &ifile)
{
    string word;
    while (ifile >> word)
    {
        if (exc_set.count(word))
            continue;
        word_count[word] ++;
    }
}

void user_query(map<string, int> &word_count)
{
    string search_word;
    cout << "Please input a word to research: q to quit ";
    cin >> search_word;
    while(search_word.size() && search_word != "q")
    {
        map<string, int>::const_iterator iter;
        if ((iter = word_count.find(search_word)) != word_count.end())
        {
            cout << "Found! " << iter->first << "occurs " << iter->second << " times. \n";
        }
        else
            cout << search_word << " was not found in text. \n";
        cout << "Another search: (q to quit) ";
        cin >> search_word;
    }
}

void display_word_count(map<string, int> &word_count, ofstream &ofile)
{
    map<string, int>::const_iterator iter = word_count.begin(), end_iter = word_count.end();
    while (iter != end_iter)
    {
        ofile << iter->first << " ( " << iter->second << " ) " << endl;
        ++iter;
    }
    ofile << endl;
}