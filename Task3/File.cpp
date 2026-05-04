#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <cmath>

using namespace std;

int main() {
    cout << "Введите числа (введите любую букву для окончания ввода):" << endl;
    vector<double> V{ istream_iterator<double>(cin), istream_iterator<double>() };

    if (V.empty()) {
        return 0;
    }

    map<int, double> M;

    for (double val : V) {
        int digit = abs((int)val) % 10;

        if (M.find(digit) == M.end()) {
            M[digit] = 0;
        }
        else {
            M[digit] += val;
        }
    }

    cout << "Результаты (Цифра -> Сумма):" << endl;
    for (auto const& pair : M) {
        cout << pair.first << " -> " << pair.second << endl;
    }

    return 0;
}