#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

struct point {
    double x, y;
    string s;

    point(double x = 0, double y = 0, string s = "") : x(x), y(y), s(s) {}

    operator string() const {
        return to_string(x) + " " + to_string(y) + " " + s;
    }

    bool operator<(const point& other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return s < other.s;
    }
};

istream& operator>>(istream& is, point& p) {
    is >> p.x >> p.y >> p.s;
    return is;
}

ostream& operator<<(ostream& os, const point& p) {
    os << string(p);
    return os;
}

int main() {
    string name = "input.txt";
    ifstream infile(name);

    if (!infile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    vector<point> V;
    copy(istream_iterator<point>(infile), istream_iterator<point>(), back_inserter(V));

    point origin(0, 0, "");

    stable_partition(V.begin(), V.end(), bind(less<point>(), placeholders::_1, origin));

    cout << "Preobrazovanniy nabor dannykh:" << endl;
    for (const auto& p : V) {
        cout << p << endl;
    }

    return 0;
}