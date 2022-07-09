#include <stdio.h>
#include <iostream>

using namespace std;

#define maxSize 100

struct Gmatrix
{
    int pointArr[maxSize];
    int data[maxSize][maxSize];
    int countPoint;
};

void initalMatrix(Gmatrix &G)
{
    G.countPoint = 0;
}

void createMatrix(Gmatrix &G, int *pointArr, int plength, int (*edgeArr)[2], int elength)
{
    int fromPoint, toPoint;
    for (int i = 0; i < plength; i++)
    {
        G.pointArr[i] = pointArr[i];
    }
    G.countPoint = plength;
    for (int i = 0; i < elength; i++)
    {
        for (fromPoint = 0; fromPoint < G.countPoint; fromPoint++)
        {
            if (edgeArr[i][0] == G.pointArr[fromPoint])
                break;
        }
        for (toPoint = 0; toPoint < G.countPoint; toPoint++)
        {
            if (edgeArr[i][1] == G.pointArr[toPoint])
                break;
        }
        G.data[fromPoint][toPoint] = 1;
    }
}