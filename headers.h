#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
#include <fstream>
#include <exception>
using namespace std;
struct studentas
{
    string vard, pavard;
    double vidNd, egz, galutinis;
    vector <double> nd;
    int calc();
    double mediana;
};
double random(int min, int max);
void sortf(vector <studentas> &studentai);
void print(vector <studentas> studentai);
int addfromfile(vector <studentas> &studentai);
void add (vector <studentas> &studentai);



