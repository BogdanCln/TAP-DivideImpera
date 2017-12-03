#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream in("data.in");
ofstream out("data.out");

int printMedian(vector <int> vec1, vector <int> vec2)
{
    int med1, med2;
    if (vec1.size() % 2 == 0)
        med1 = (vec1.size() / 2) - 1;
    else
        med1 = (vec1.size() / 2);

    if (vec2.size() % 2 == 0)
        med2 = (vec2.size() / 2) - 1;
    else
        med2 = (vec2.size() / 2);
     
    out << "\nVectori curenti:\n";
    for (int i = 0; i < vec1.size(); i++)
        out << vec1[i] << " ";
    out << " (" << vec1.size() << ") - \t" << vec1[med1] << endl;
    for (int i = 0; i < vec2.size(); i++)
        out << vec2[i] << " ";
    out << " (" << vec2.size() << ") - \t" << vec2[med2];
   
    if ((vec1.size() > 2) && (vec2.size() > 2))
    {
        if (vec1[med1] == vec2[med2])
            return vec1[med1];
        else if (vec1[med1] < vec2[med2])
        {
            vector <int> newvec1, newvec2;
            for (int i = med1; i < vec1.size(); i++)
                newvec1.push_back(vec1[i]);
            for (int i = 0; i <= med2; i++)
                newvec2.push_back(vec2[i]);
            return printMedian(newvec1, newvec2);
        }
        else if (vec1[med1] > vec2[med2])
        {
            vector <int> newvec1, newvec2;
            for (int i = 0; i <= med1; i++)
                newvec1.push_back(vec1[i]);
            for (int i = med2; i < vec2.size(); i++)
                newvec2.push_back(vec2[i]);
            return printMedian(newvec1, newvec2);    
        }
    }
    else
    {
        if (vec1[med1] == vec2[med2])
            return vec1[med1];
        else 
        {
            int mid = (vec1.front() + vec2.back()) / 2;
            return mid;
        }
    }
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

    out << "\nMediana: " << printMedian(vec1, vec2);
    
    return 0;
}