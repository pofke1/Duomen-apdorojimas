#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <sstream>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
#include <windows.h>
#include <fstream>
#include <ostream>
using namespace std;
    extern double timee;
     extern bool counting;
     extern clock_t start;
double random(int min, int max);
double playPause();
struct studentas
{
    string vard, pavard;
    double vidNd, egz, galutinis;
    vector <double> nd;
    int calc();
    double mediana;
    bool operator < (const studentas& rhs) const
    {
        return pavard < rhs.pavard;
    }
};
struct laikai
{
    laikai();
    int studsk;
    string konteineriotipas;
    vector <double> laikas;
    printlaikai(ostream &stream);
};
void sortf(vector <studentas> &studentai);
void sortf(deque <studentas> &studentai);
void sortf(list <studentas> &studentai);
void print(vector <studentas> studentai, string filename);
void print(deque <studentas> studentai, string filename);
void print(list <studentas> studentai, string filename);
void print(vector <studentas> studentai, ostream &stream);
void print(deque <studentas> studentai, ostream &stream);
void print(const list <studentas> studenta, ostream &stream);
void addfromfile(vector <studentas> &studentai, string filename);
void addfromfile(deque <studentas> &studentai, string filename);
void addfromfile(list <studentas> &studentai, string filename);
void add (list <studentas> &studentai);
void add (deque <studentas> &studentai);
void add (vector <studentas> &studentai);
void generatefile(int studentai, string filename);
void printtofile(ofstream &file, studentas studentas);
void filtertofile(const vector <studentas> studentai);
void filtertofile(const list <studentas> studentai);
void filtertofile(const deque <studentas> studentai);
void filtertomassive(vector <studentas> &studentai, vector <studentas> &vargsiukai, vector <studentas> &kietekai, int way);
void filtertomassive(deque <studentas> &studentai, deque <studentas> &vargsiukai, deque <studentas> &kietekai, int way);
void filtertomassive(list <studentas> &studentai, list <studentas> &vargsiukai, list <studentas> &kietekai, int way);
float input(string textToOutput, int minvalue, int maxvalue);
float input(string textToOutput, int minvalue);


