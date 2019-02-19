#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
#include <fstream>
using namespace std;

double random(int min, int max)
{
    return rand()%(max+1-min)+min;
}

struct studentas
{
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
void sortf(vector <studentas> &studentai)
{
    int sizev = studentai.size();
    vector <string> vardai (sizev);
    vector <studentas> studentai2(sizev);
    for(int x = 0; x < sizev; ++x)
    {
        vardai[x] = studentai[x].pavard;
        studentai2[x] = studentai[x];
    }
    sort(vardai.begin(), vardai.end());
    bool notdone = true;

    for(int x = 0; x < sizev; ++x)
    {
        for(int y = 0; notdone == true; ++y)
        {
            if(vardai[x]== studentai2[y].pavard)
            {
                studentai[x] = studentai2[y];
                notdone = false;
            }
        }
        notdone = true;
    }
}
void print(vector <studentas> studentai)
{
    string temp;
    int vecsize;
    cout << "Pavarde\t\tVardas\t\tGalutinis (Vid.)\tGalutinis (Med.)" << endl << "-----------------------------------------------------------------------" << endl;
    vecsize = studentai.size();
    for(int x = 0; x < vecsize; ++x)
    {
        cout << studentai[x].pavard << "\t\t"<<studentai[x].vard << "\t\t";
        cout.precision(3);
        cout.fixed;
        cout << studentai[x].galutinis <<"\t\t";
        cout.precision(3);
        cout.fixed;
        cout << studentai[x].mediana << endl;
    }



}
void addfromfile(vector <studentas> &studentai)
{
    ifstream file;
    file.open("kursiokai.txt");
    if(!file)
    {
        cout << "failas neatidarytas, nuskaitymas nepavyko" << endl;
    }
    string temp;
    double tempd;
    file >> temp;
    int x = 0;
        while(temp != "Egzaminas")
        {
            file >> temp;
        }
    while(temp != "")
    {
        if(temp == "Egzaminas")
        {
        file >> temp;
        }

        studentai[x].pavard = temp;
        file >> temp;
        studentai[x].vard = temp;
        file >> tempd;
        studentai[x].nd.push_back(tempd);
        file >> tempd;
        studentai[x].nd.push_back(tempd);
        file >> tempd;
        studentai[x].nd.push_back(tempd);
        file >> tempd;
        studentai[x].nd.push_back(tempd);
        file >> tempd;
        studentai[x].nd.push_back(tempd);
        file >> tempd;
        studentai[x].egz = tempd;
        ++x;
        temp = "";
        file >> temp;
        studentai.push_back(studentai[0]);

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
string temp;
    vector <studentas> studentai (1);
    cout << "Iveskite f kad nuskaityti is failo, r, kad ivesti ranka: ";
    cin >> temp;
    if(temp == "f")
    {
        addfromfile(studentai);
    }
    else
    {
        add(studentai);
    }
    for(int x = 0; x < studentai.size(); ++x)
    {
        studentai[x].calc();
    }
    sortf(studentai);
    print (studentai);
    system("PAUSE");
    return 0;
}
