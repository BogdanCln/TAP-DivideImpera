#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream in("data.in");
ofstream out("data.out");

void indexBinarySearch(vector <int> &seq, int &n)
{
    int index = n/2, ok = 0;
    while (!ok)
    {
        if (seq[index] == index)
        {
            return index;
            ok++;
        }
        else if (seq[index] < index)
            index = (index + n) / 2;
    }
}

int main()
{
    int n;
    in >> n;
    vector <int> seq(n);
    for (int i = 0; i < n; i++)
        in >> seq[i];
    out << indexBinarySearch(seq, n);
    return 0;
}
