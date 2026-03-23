#include<iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    cout << "Enter symbols (print any letter for end input):" << endl;

    vector<char> symbols{istream_iterator<char>(cin),
                          istream_iterator<char>()};

    ofstream outFile("output.txt");

    copy(symbols.begin(), symbols.end(),
        ostream_iterator<char>(outFile, " "));

    cout << "Symbols written to file output.txt with spaces after each symbol." << endl;

    return 0;
}