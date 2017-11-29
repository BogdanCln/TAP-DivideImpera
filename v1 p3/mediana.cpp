#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream in("data.in");
ofstream out("data.out");

int midOdd(int mid, vector <int> &vec1, vector <int> &vec2)
{
    int i = 0, j = 0, res;
    for (int k = 0; k < mid; k++)
    {
        if (vec1[i] < vec2[j])
        {
            res = 1;
            i++;
        }
        else
        {
            res = 2;
            j++;
        }
    }
    if (res == 1)
        return vec1[i];
    else
        return vec2[j];

}
int midEven(int mid, vector <int> &vec1, vector <int> &vec2)
{
    int i = 0, j = 0, res, x1, x2;
    for (int k = 0; k < mid-1; k++)
    {
        if (vec1[i] < vec2[j])
        {
            res = 1;
            i++;
        }
        else
        {
            res = 2;
            j++;
        }
    }
    if (res == 1)
        x1 = vec1[i];
    else
        x1 = vec2[j];
    
    if (vec1[i] < vec2[j])
        x2 = vec1[i+1];
    else
        x2 = vec2[j+1];

    res = (x1+x2) / 2;
    return res;
}
int main()
{
    int n, m;

    in >> n;
    vector <int> vec1;
    vec1.resize(n);
    for (int i = 0; i < n; i++)
        in >> vec1[i];

    in >> m;
    vector <int> vec2;
    vec2.resize(m);
    for (int i = 0; i < m; i++)
        in >> vec2[i];

    int sum = n + m;
    if ((sum % 2) == 0)
        out << midEven(sum/2, vec1, vec2);
    else
        out << midOdd(sum/2, vec1, vec2);
    return 0;
}