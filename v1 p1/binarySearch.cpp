#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream in("data.in");
ofstream out("data.out");
    
int indexBinarySearch(vector <int> &seq, int &n)
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
        else if (seq[index] > index)
            index = index / 2;
        if ((index < 0) || (index >= n))
        {
             return -1;
             ok++;
        }
    }
}

int main()
{
    int n;
    in >> n;
    vector <int> seq(n);
    for (int i = 0; i < n; i++)
        in >> seq[i];
    int ret;
    ret = indexBinarySearch(seq, n);
    
    if (ret != -1)
        out << "Index: " << ret;
    else
        out << "Not found.";

    return 0;
}
