#include <iostream>
#include <windows.h>
#include"Time.h"

using namespace std;
double PCFreq = 0.0;
__int64 CounterStart = 0;

void Time::startTime()
{
    LARGE_INTEGER li;
    if (!QueryPerformanceFrequency(&li))
        cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart) / 1000000000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double Time::getTime()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart - CounterStart) / PCFreq;
}