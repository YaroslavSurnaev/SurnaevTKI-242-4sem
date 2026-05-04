#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    cout << "Enter numbers for list L1 (print any letter to stop): " << endl;
    list<double> l1{ istream_iterator<double>(cin), istream_iterator<double>() };

    cin.clear();
    cin.ignore(1000, '\n');

    cout << "Enter numbers for list L2 (must be even number, print any letter to stop): " << endl;
    list<double> l2{ istream_iterator<double>(cin), istream_iterator<double>() };

    if (l2.empty() || l2.size() % 2 != 0) {
        cout << "Error: The number of elements in L2 must be even." << endl;
        return 1;
    }

    auto it_mid = next(l2.begin(), l2.size() / 2);

    l1.splice(l1.begin(), l2, l2.begin(), it_mid);

    cout << "New list L1: ";
    copy(l1.begin(), l1.end(), ostream_iterator<double>(cout, " "));
    cout << endl;

    cout << "Remaining list L2: ";
    copy(l2.begin(), l2.end(), ostream_iterator<double>(cout, " "));
    cout << endl;

    return 0;
}