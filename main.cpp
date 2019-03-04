#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
#include <fstream>
using namespace std;
    double timee = 0;
    bool counting = false;
    clock_t start = clock();
double playPause()
{
    switch (counting)
    {
    case true:
        {
        timee = timee +(-start + clock())*1.0/ CLOCKS_PER_SEC;
        counting = false;
        }
    case false:
        {
        start = clock();
        counting = true;
        }
    }
return timee;
}
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
    bool operator < (const studentas& rhs) const
    {
        return pavard < rhs.pavard;
    }
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
    sort(studentai.begin(), studentai.end());
    /*
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
    }*/
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
void addfromfile(vector <studentas> &studentai, ifstream &file)
{
    if(!file)
    {
        cout << "failas neatidarytas, nuskaitymas nepavyko" << endl;
    }
    if (studentai.size() > 1)
    {
        studentai.erase(studentai.begin()+1, studentai.begin()+studentai.size()-1);
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
        studentai[x].calc();
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
void generatefile(int studentai, string filename)
{
    ofstream file;
    file.open(filename);
    file << "Pavarde\t\tVardas\t\tND1\tND2\tND3\tND4\tND5\tEgzaminas" << endl;
    string temp1, temp2;

    for(int x = 0; x < studentai; ++x)
    {
    ostringstream ostring;
        ostring << x;
        temp1 = ostring.str();
        temp2 = "Pavarde";
        temp2+=temp1;
        file << temp2 << "\t";
        temp2 = "Vardas";
        temp2+= temp1;
        file << temp2 << "\t\t";
        for(int xx = 0; xx < 6; ++xx)
        {
            file << random(1, 10) << "\t";
        }
        file << endl;
    }
    file.close();
}
void printtofile(ofstream &file, studentas studentas)
{
        file << studentas.pavard << "\t\t"<<studentas.vard << "\t\t";
        file.precision(3);
        file.fixed;
        file << studentas.galutinis <<"\t\t";
        file.precision(3);
        file.fixed;
        file << studentas.mediana << endl;
}
void filtertofile(vector <studentas> studentai)
{
    ofstream file1;
    ofstream file2;
    file1.open("vargsiukai.txt");
    file2.open("kietiakai.txt");
    file1 << "Pavarde\t\tVardas\t\tGalutinis (Vid.)\tGalutinis (Med.)" << endl << "-----------------------------------------------------------------------" << endl;
    file2 << "Pavarde\t\tVardas\t\tGalutinis (Vid.)\tGalutinis (Med.)" << endl << "-----------------------------------------------------------------------" << endl;
    int vecsize = studentai.size();
    for(int x = 0; x < vecsize; ++x)
    {
        if(studentai[x].galutinis < 5)
        {
            printtofile(file1, studentai[x]);
        }
        else
        {
            printtofile(file2, studentai[x]);
        }
    }
    file1.close();
    file2.close();
}
int main()
{
int studsk = 100;

srand(time(NULL));
string temp;
int tempint;
    vector <studentas> studentai (1);
    cout << "Iveskite f kad nuskaityti is failo, r, kad ivesti ranka: ";
    cin >> temp;
    if(temp == "f")
    {
        cout <<"Ar norite sugeneruoti faila? Irasykite t arba n" << endl;
        cin >> temp;
        if(temp == "n")
        {
            ifstream stud;
            stud.open("kursiokai.txt");
        addfromfile(studentai, stud);
        }
        else
        {
            for(int x = 0; x < 5; ++x)
            {
            playPause();
            generatefile(studsk, "kursiokai.txt");
            playPause();
            cout << studsk << " studentu generavimo ir irasymo i faila laikas: " << timee << endl;
            timee = 0;
            playPause();
            ifstream stud;
            stud.open("kursiokai.txt");
            addfromfile(studentai, stud);
            stud.close();
            playPause();
            cout << studsk << " studentu nuskaitymo ir vidurkiu apskaiciavimo laikas: " << timee << endl;
            timee = 0;
            playPause();
            sortf(studentai);
            playPause();
            cout << studsk << " studentu pagal pavardes rusiavimas su sortf funkcija: " << timee << endl;
            timee = 0;
            playPause();
            filtertofile(studentai);
            playPause();
            cout << studsk << " studentu rusiavimas ir isvedimas i du failus laikas: " << timee << endl;
            timee = 0;
            system("PAUSE");
            studsk = studsk * 10;
            }
        }
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
    filtertofile(studentai);
    system("PAUSE");
    return 0;
}
