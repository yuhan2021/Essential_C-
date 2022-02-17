#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;

class even_elem {
public:
    bool operator() (int elem) {
        return elem%2 ? false : true;
    }
};

int main() {
    ofstream even_file("even_file.txt"), odd_file("odd_file.txt");
    if ( ! even_file || ! odd_file ) {
        cerr << "Unable to open the output files. \n";
        return -1;
    }

    vector<int> input_num;
    istream_iterator<int> in_stream(cin), eos;
    copy ( in_stream, eos, back_inserter(input_num) );

    vector<int>::iterator devision = partition(input_num.begin(), input_num.end(), even_elem());

    ostream_iterator<int> even_iter(even_file, "\n"), odd_iter(odd_file, " ");
    copy(input_num.begin(), devision, even_iter);
    copy(devision, input_num.end(), odd_iter);

}