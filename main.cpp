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
using namespace std;
    double timee = 0;
    bool counting = false;
    clock_t start = clock();
    double totaltime = 0;
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
void sortf(deque <studentas> &studentai)
{
    sort(studentai.begin(), studentai.end());

}
void sortf(list <studentas> &studentai)
{
    studentai.sort();

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
void print(deque <studentas> studentai)
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
void print(const list <studentas> studenta)
{
    list <studentas>::const_iterator studentai = studenta.begin();
    string temp;
    cout << "Pavarde\t\tVardas\t\tGalutinis (Vid.)\tGalutinis (Med.)" << endl << "-----------------------------------------------------------------------" << endl;
    while(studentai != studenta.end())
    {
        cout << studentai->pavard << "\t\t"<<studentai->vard << "\t\t";
        cout.precision(3);
        cout.fixed;
        cout << studentai->galutinis <<"\t\t";
        cout.precision(3);
        cout.fixed;
        cout << studentai->mediana << endl;
        ++studentai;
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
void addfromfile(deque <studentas> &studentai, ifstream &file)
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
void addfromfile(list <studentas> &studentai, ifstream &file)
{
    if(!file)
    {
        cout << "failas neatidarytas, nuskaitymas nepavyko" << endl;
    }
    if (studentai.size() > 1)
    {
        list <studentas>::const_iterator beg = studentai.begin();
        beg++;
        studentai.erase(beg, studentai.end());
    }

    string temp;
    double tempd;
    file >> temp;
    int x = 0;
    studentas studtemp;
    for (int xx = 0; xx< 5; ++xx)
    {
    studtemp.nd.push_back(0);
    }
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

        studtemp.pavard = temp;
        file >> temp;
        studtemp.vard = temp;
        file >> tempd;
        studtemp.nd[0] = tempd;
        file >> tempd;
        studtemp.nd[1] = tempd;
        file >> tempd;
        studtemp.nd[2] = tempd;
        file >> tempd;
        studtemp.nd[3] = tempd;
        file >> tempd;
        studtemp.nd[4] = tempd;
        file >> tempd;
        studtemp.egz = tempd;
        studtemp.calc();
        ++x;
        temp = "";
        file >> temp;
        //cout <<"neveikia, pradedama push back funkcija"<< studentai.size()<<endl;
        studentai.push_back(studtemp);
        //cout << "veikia pb pabaigta"<<endl;
    }
}
void add (list <studentas> &studentai)
{
    studentas studtemp;
    string ttemp;
    bool notdone = true;
    int x = 0;
    while (notdone)
    {
cout << "Parasykite varda: ";
cin >>studtemp.vard;
cout << endl << "Parasykite pavarde: ";
cin >> studtemp.pavard;
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
            studtemp.nd.push_back(random(1, 10));
        }
        temp  = "done";
    }
    else
    {
        studtemp.nd.push_back(stod(temp));
    }
}
cout << "iveskite egzamino pazymi: ";
cin >> studtemp.egz;
cout <<endl<< "Mokinys ivestas, jei norite baigti rasykite done, \njei ne, parasykite bet ka: "<< endl;
cin >> ttemp;

if(ttemp == "done")
{
    notdone = false;
}
else
{
    cout << "irasomas naujas studentas: "<< endl;
studentai.push_back(studtemp);
    ++x;
}
    }
}
void add (deque <studentas> &studentai)
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


void filtertofile(list <studentas> &studentai)
{
    ofstream file1;
    ofstream file2;
    list <studentas>::const_iterator studit = studentai.begin();
    file1.open("vargsiukai.txt");
    file2.open("kietiakai.txt");
    file1 << "Pavarde\t\tVardas\t\tGalutinis (Vid.)\tGalutinis (Med.)" << endl << "-----------------------------------------------------------------------" << endl;
    file2 << "Pavarde\t\tVardas\t\tGalutinis (Vid.)\tGalutinis (Med.)" << endl << "-----------------------------------------------------------------------" << endl;
    while(studit != --studentai.end())
    {
        if(studit->galutinis < 5)
        {
            printtofile(file1, *studit);
        }
        else
        {
            printtofile(file2, *studit);
        }
        studit++;
    }
    file1.close();
    file2.close();

}
void filtertofile(deque <studentas> studentai)
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
int studsk = 10;

srand(time(NULL));
string temp;
int tempint;
vector<studentas> studentai (1);
deque <studentas> studentaideq (1);
vector <studentas> studentaivec (1);
list <studentas> studentaili (1);

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
            for(int xx = 0;xx<3;++xx)
            {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), xx+1);

            if(xx == 0)
            {
                cout << "----VEKTORIUS----"<<endl;
                for(int x = 0; x < 5; ++x)
                {
                playPause();
                generatefile(studsk, "kursiokai.txt");
                playPause();
                cout << studsk << " studentu generavimo ir irasymo i faila laikas: " << timee << endl;
                totaltime = totaltime + timee;
                timee = 0;
                playPause();
                ifstream stud;
                stud.open("kursiokai.txt");
                addfromfile(studentaivec, stud);
                stud.close();
                playPause();
                cout << studsk << " studentu nuskaitymo ir vidurkiu apskaiciavimo laikas: " << timee << endl;
                totaltime = totaltime + timee;
                timee = 0;
                playPause();
                sortf(studentaivec);
                playPause();
                cout << studsk << " studentu pagal pavardes rusiavimas su sortf funkcija: " << timee << endl;
                totaltime = totaltime + timee;
                timee = 0;
                playPause();
                filtertofile(studentaivec);
                playPause();
                cout << studsk << " studentu rusiavimas ir isvedimas i du failus laikas: " << timee << endl;
                totaltime = totaltime + timee;
                timee = 0;
                cout << "isviso uztruko: "<< totaltime << endl;
                totaltime = 0;
                studsk = studsk * 10;
                }
            }
            else if(xx == 1)
            {
                studsk = 10;
                cout << "----DEQUE----"<<endl;

                for(int x = 0; x < 5; ++x)
                {
                playPause();
                generatefile(studsk, "kursiokai.txt");
                playPause();
                cout << studsk << " studentu generavimo ir irasymo i faila laikas: " << timee << endl;
                totaltime = totaltime + timee;
                timee = 0;
                playPause();
                ifstream stud;
                stud.open("kursiokai.txt");
                addfromfile(studentaideq, stud);
                stud.close();
                playPause();
                cout << studsk << " studentu nuskaitymo ir vidurkiu apskaiciavimo laikas: " << timee << endl;
                totaltime = totaltime + timee;
                timee = 0;
                playPause();
                sortf(studentaideq);
                playPause();
                cout << studsk << " studentu pagal pavardes rusiavimas su sortf funkcija: " << timee << endl;
                totaltime = totaltime + timee;
                timee = 0;
                playPause();
                filtertofile(studentaideq);
                playPause();
                cout << studsk << " studentu rusiavimas ir isvedimas i du failus laikas: " << timee << endl;
                totaltime = totaltime + timee;
                timee = 0;
                cout << "isviso uztruko: "<< totaltime << endl;
                totaltime = 0;
                studsk = studsk * 10;
                }
                studentaideq.clear();
            }
            else
            {

                studsk = 10;
                cout << "----LISTAS----"<<endl;

                for(int x = 0; x < 5; ++x)
                {
                playPause();
                generatefile(studsk, "kursiokai.txt");
                playPause();
                cout << studsk << " studentu generavimo ir irasymo i faila laikas: " << timee << endl;
                totaltime = totaltime + timee;
                timee = 0;
                playPause();
                ifstream stud;
                stud.open("kursiokai.txt");
                addfromfile(studentaili, stud);
                stud.close();
                playPause();
                cout << studsk << " studentu nuskaitymo ir vidurkiu apskaiciavimo laikas: " << timee << endl;
                totaltime = totaltime + timee;
                timee = 0;
                playPause();
                sortf(studentaili);
                playPause();
                cout << studsk << " studentu pagal pavardes rusiavimas su sortf funkcija: " << timee << endl;
                totaltime = totaltime + timee;
                timee = 0;
                playPause();
                filtertofile(studentaili);
                playPause();
                cout << studsk << " studentu rusiavimas ir isvedimas i du failus laikas: " << timee << endl;
                totaltime = totaltime + timee;
                timee = 0;
                cout << "isviso uztruko: "<< totaltime << endl;
                totaltime = 0;
                studsk = studsk * 10;
                }
                studentaili.clear();
            }

        }
        }
    }
    else
    {
        add(studentai);
    }
    /*for(int x = 0; x < studentai.size(); ++x)
    {
        studentai[x].calc();
    }*/
    sortf(studentaivec);
    print (studentaivec);
    filtertofile(studentaivec);
    system("PAUSE");
    return 0;
}
