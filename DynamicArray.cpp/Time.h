#pragma once


class Time {

    double PCFreq;
    __int64 CounterStart;
public:
    void startTime();           //rozpoczęcie pomiaru czasu
    double getTime();            //wartosc srednia z pomiarów

};