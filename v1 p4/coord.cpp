#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h> //qsort
#include <float.h>
#include <math.h>
using namespace std;

ifstream in("data.in");
ofstream out("data.out");

struct point
{
    int x, y;
};

//Next two functions are used to qSort points by x, respectively y coordinate.
int compareX(const void* a, const void* b)
{
    point* p1 = (point*) a;
    point* p2 = (point*) b;
    return (p1 -> x - p2 -> x);
    //return ( (((point*) a) -> getx()) - (((point*) b) -> getx()) );
}

int compareY(const void* a, const void* b)
{
    point* p1 = (point*) a;
    point* p2 = (point*) b;
    return (p1 -> y - p2 -> y);
    //return ( (((point*) a) -> gety()) - (((point*) b) -> gety()) );
}

float calcDist(point Px[], point Py[], int n)
{
    if (n <= 3)
    {
        float min = FLT_MAX;
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
            {
                float d = sqrt((Px[i].x - Px[j].x) * (Px[i].x - Px[j].x) + (Px[i].y - Px[j].y) * (Px[i].y - Px[j].y));
                if (d < min)
                    min = d;
            }
        return min;
    }
    else
    {
        point middle = Px[n/2];
        
        point PxRight[n - n/2 - 1];
        int ri = 0;
        for (int i = 0; i < n; i++)
            if (Px[i].x > middle.x)
                PxRight[ri++] = Px[i];

        point PyLeft[n/2], PyRight[n - n/2 - 1];
        int li = 0; 
        ri = 0;  
        for (int i = 0; i < n; i++)
        {
            if (Py[i].x <= middle.x)
                PyLeft[li++] = Py[i];
            else
                PyRight[ri++] = Py[i];
        }
        float leftDist = calcDist(Px, PyLeft, n/2);
        float rightDist = calcDist(PxRight, PyRight, n - n/2);
        float minDistSides;
        if (leftDist < rightDist)
            minDistSides = leftDist;
        else
            minDistSides = rightDist;

        point strip[n];
        int stripSize = 0;
        for (int i = 0; i < n; i++)
            if (abs(Py[i].x - middle.x) < minDistSides)
                strip[stripSize++] = Py[i];
        
        float minDist = minDistSides;
        for (int i = 0; i < stripSize; ++i)
            for (int j = i+1; j < stripSize && (strip[j].y - strip[i].y) < minDist; ++j)
            {
                float dist = sqrt((strip[i].x - strip[j].x) * (strip[i].x - strip[j].x) + (strip[i].y - strip[j].y) * (strip[i].y - strip[j].y));
                if (dist < minDist)
                    minDist = dist;
 
            }
    return minDist;
    }
}

float minDistance()
{
    int n;
    in >> n; //Number of points
    point P[n];
    for (int i = 0; i < n; i++)
    {
        in >> P[i].x >> P[i].y;
    }

    point Px[n], Py[n];
    for (int i = 0; i < n; i++)
    {
        Px[i].x = P[i].x;
        Px[i].y = P[i].y;
        Py[i].x = P[i].x;
        Py[i].y = P[i].y;
    }

    qsort(Px, n, sizeof(struct point), compareX);
    qsort(Py, n, sizeof(struct point), compareY);

    return calcDist(Px, Py, n);
}
int main()
{
    float minD = minDistance();
    out << "Minimum distance: " << minD;
    return 0;
}