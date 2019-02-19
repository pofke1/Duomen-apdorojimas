#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
using namespace std;

double random(int min, int max)
{
    return rand()%(max+1-min)+min;
}

class studentas
{
public:
    string vard, pavard;
    double vidNd, egz, galutinis;
    vector <double> nd;
    int calc();
    double mediana;
};
studentas::calc ()
{
    //cout << "start"<<endl;
    double suma = 0;
    int vecsize = nd.size();
    for(int x = 0; x < vecsize; ++x)
    {
        suma = suma + nd[x];
    }
    vidNd = suma/vecsize;
    galutinis = vidNd*0.4+0.6*egz;
    sort(nd.begin(), nd.end());
    int temp = 0;
    temp = nd.size()/2;
    if(temp == nd.size())
    {
        mediana = (nd[temp-1]+nd[temp])/2;
        mediana = 0.4*mediana + 0.6*egz;
    }
    else
    {
        mediana = nd[temp+1];
        mediana = 0.4*mediana + 0.6*egz;
    }

}
void print(vector <studentas> studentai)
{
    string temp;
    int vecsize;
    cout << "jei norite, kad spausdintu medianas rasykite m, jei vidurkius v: ";
    cin >> temp;
    if(temp == "v")
    {
    cout << "Pavarde\t\tVardas\t\tGalutinis (Vid.)" << endl << "--------------------------------------------------" << endl;
    vecsize = studentai.size();
    for(int x = 0; x < vecsize; ++x)
    {
        cout << studentai[x].pavard << "\t\t"<<studentai[x].vard << "\t\t";
        cout.precision(3);
        cout.fixed;
        cout << studentai[x].galutinis << endl;
    }
    }
    else
    {
            cout << "Pavarde\t\tVardas\t\tGalutinis (Med.)" << endl << "--------------------------------------------------" << endl;
    vecsize = studentai.size();
    for(int x = 0; x < vecsize; ++x)
    {
        cout << studentai[x].pavard << "\t\t"<<studentai[x].vard << "\t\t"<<studentai[x].mediana << endl;
    }
    }

}
void add (vector <studentas> &studentai)
{
    string ttemp;
    bool notdone = true;
    int x = 0;
    while (notdone)
    {
cout << "Parasykite varda: ";
cin >>studentai[x].vard;
cout << endl << "Parasykite pavarde: ";
cin >> studentai[x].pavard;
cout << endl <<endl<< "Rasykite namu darbu pazymius, jei norite kad sugeneruotu atsitiktinai rasykite rand,\n kai surasysite visus rasykite done:";
string temp;
while(temp != "done")
{
    cin >> temp;
    if(temp == "done")
    {
        cout <<"Namu darbu pazymiai surasyti" << endl;
    }
    else if (temp == "rand")
    {
        int y = random(1, 10);
        for(int xx = 0; xx < y; ++xx)
        {
            studentai[x].nd.push_back(random(1, 10));
        }
        temp  = "done";
    }
    else
    {
        studentai[x].nd.push_back(stod(temp));
    }
}
cout << "iveskite egzamino pazymi: ";
cin >> studentai[x].egz;
cout <<endl<< "Mokinys ivestas, jei norite baigti rasykite done, \njei ne, parasykite bet ka: "<< endl;
cin >> ttemp;

if(ttemp == "done")
{
    notdone = false;
}
else
{
    cout << "irasomas naujas studentas: "<< endl;
studentai.push_back(studentai[0]);
    ++x;
}
    }
}
int main()
{
srand(time(NULL));

    vector <studentas> studentai (1);
    add(studentai);
    for(int x = 0; x < studentai.size(); ++x)
    {
        studentai[x].calc();
    }
    print (studentai);
    system("PAUSE");
    return 0;
}
