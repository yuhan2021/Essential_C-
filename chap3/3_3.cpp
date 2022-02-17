#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;

typedef vector<string> vstring;

void populate_map(ifstream & name_file, map<string, vstring> & families) {
    string line;
    while (getline(name_file, line)) {
        string family_name;
        vector<string> children_names;
        string::size_type curr_pos = 0, prev_pos = 0, line_size = line.size();
        while ( (curr_pos = line.find_first_of(' ', curr_pos)) != string::npos ){
            if ( ! prev_pos ) 
                family_name = line.substr(prev_pos, curr_pos - prev_pos);
            else
                children_names.push_back(line.substr(prev_pos, curr_pos - prev_pos));
            prev_pos = ++curr_pos;
        }
        //handle last child name
        if (prev_pos < line_size) {
            children_names.push_back(line.substr(prev_pos, curr_pos - prev_pos));
        }

        if ( ! families.count(family_name) )
            families[family_name] = children_names;
        else
            cerr << "Oops! We already have a " << family_name << " family in our map! \n";

    }
}

void query(const map<string, vstring> & families, const string & family_name) {
    map<string, vstring>::const_iterator iter = families.find(family_name);
    if ( iter == families.end() ) {
        cout << "Sorry. The " << family_name << " is not currently entered. \n";
        return;
    }
    cout << "The " << family_name;
    if ( ! iter->second.size() ) {
        cout << " has no children. \n";
    }
    else {
        cout << " has " << iter->second.size() << " children: ";
        vector<string>::const_iterator vec_iter = iter->second.begin(), vec_iter_end = iter->second.end();
        while ( vec_iter != vec_iter_end) {
            cout << *vec_iter++ << ' ';
        }
        cout << endl;
    }
}

void display(map<string, vstring> & families) {
    map<string, vstring>::const_iterator iter = families.begin(), iter_end = families.end();
    while (iter != iter_end) {
        cout << "The " << iter->first << " family ";
        if (iter->second.empty()) {
            cout << "has no children. \n";
        }
        else {
            cout << "has " << iter->second.size() << " children: ";
            vector<string>::const_iterator vec_iter = iter->second.begin(), vec_iter_end = iter->second.end();
            while ( vec_iter != vec_iter_end) {
                cout << *vec_iter++ << ' ';
            }
            cout << endl;
        }
        ++iter;
    }
}

int main() {
    map<string, vstring> families;
    ifstream name_file("families.txt");
    if (!name_file) {
        cerr << "Unable to find families.txt file. \n";
        return -1;
    }
    populate_map(name_file, families);

    cout << "Please input a family name to query: (q to quit) ";
    string family_name;
    cin >> family_name;
    while ( family_name != "q"){
        query(families, family_name);
        cout << "Continue to enter a family name: (q to quit) ";
        cin >> family_name;
    }
        
    display(families);

    return 0;
}