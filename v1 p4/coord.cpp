/*

    Complexitate O(n logn)
    1.  Ordonez punctele dupa coordonata X
    2. Setez bound la jumatatea distantei dintre primul si ultimul punct pe X
    2.1 Refac bound recursiv pana cand raman cu maxim 3 puncte in interior
    3. Calculez in stilul brute force dl, respectiv dr, cand am maxim 3 pcte  
    
    4.

*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

ifstream in("data.in");
ofstream out("data.out");

struct point
{
public:
    int x;
    int y;
};

bool xCompare(point* p1, point* p2) {return (p1 -> x) < (p2 -> x);}

int main()
{
    int n;
    in >> n; // no of points
    point* p[n], xSorted[n];

    out << "Puncte:\n";
    for (int i = 0; i < n; i++)
    {
        p[i] = new point;
        in >> p[i] -> x >> p[i] -> y;
        out << "(" << p[i] -> x << ", " << p[i] -> y << ")\n";
        xSorted[i] = p[i];
    }

    sort(xSorted[0], xSorted[n], xCompare);

    for (int i = 0; i < n; i++)
        out << "(" << p[i] -> x << ", " << p[i] -> y << ")\n";
    return 0;
}