#include "funkc.h"
     double timee = 0;
     bool counting = false;
     clock_t start = clock();
float input(string textToOutput, int minvalue, int maxvalue)
{
    float temp;
    cout << textToOutput;
    while(!(cin >> temp)||temp < minvalue || temp > maxvalue)
    {
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        cout << textToOutput;
    }
    return temp;
}
float input(string textToOutput, int minvalue)
{
    float temp;
    cout << textToOutput;
    while(!(cin >> temp)||temp < minvalue)
    {
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        cout << textToOutput;
    }
    return temp;
}

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
laikai::printlaikai(ostream &stream)
{
    laikas[4] = laikas[0] + laikas[1] + laikas[2];
    laikas[5] = laikas[0] + laikas[1] + laikas[3];

    stream << konteineriotipas<< " "<< studsk<<" studentu nuskaitymas is failo ir vidurkio skaiciavimas: " << laikas[0] << endl;
    stream << konteineriotipas<< " "<< studsk<<" studentu vardu rusiavimas su sort: " << laikas[1] << endl;
    stream << konteineriotipas<< " "<< studsk<<" rusiavimas i du vektorius tik kopijuojant: " << laikas[2] << endl;
    stream << konteineriotipas<< " "<< studsk<<" rusiavimas i du vektorius perkeliant: " << laikas[3] << endl;
    stream << konteineriotipas<< " "<< studsk<<" visas programos laikas kopijuojant: " << laikas[4] << endl;
    stream << konteineriotipas<< " "<< studsk<<" visas programos laikas perkeliant: " << laikas[5] << endl;


}
laikai::laikai()
{
    for(int x = 0; x < 6; ++x)
    {
        laikas.push_back(0);
    }
}
void sortf(vector <studentas> &studentai)
{
    sort(studentai.begin(), studentai.end());
}
void sortf(deque <studentas> &studentai)
{
    sort(studentai.begin(), studentai.end());

}
void sortf(list <studentas> &studentai)
{
    studentai.sort();

}
void print(vector <studentas> studentai, ostream &stream)
{
    string temp;
    int vecsize;
    stream << "Pavarde\t\tVardas\t\tGalutinis (Vid.)\tGalutinis (Med.)" << endl << "-----------------------------------------------------------------------" << endl;
    vecsize = studentai.size();
    for(int x = 0; x < vecsize; ++x)
    {
        stream << studentai[x].pavard << "\t\t"<<studentai[x].vard << "\t\t";
        stream.precision(3);
        stream.fixed;
        stream << studentai[x].galutinis <<"\t\t";
        stream.precision(3);
        stream.fixed;
        stream << studentai[x].mediana << endl;
    }
}
void print(vector <studentas> studentai, string filename)
{
    string temp;
    int vecsize;
    ofstream file;
    file.open(filename);
    file << "Pavarde\t\tVardas\t\tGalutinis (Vid.)\tGalutinis (Med.)" << endl << "-----------------------------------------------------------------------" << endl;
    vecsize = studentai.size();
    for(int x = 0; x < vecsize; ++x)
    {
        file << studentai[x].pavard << "\t\t"<<studentai[x].vard << "\t\t";
        file.precision(3);
        file.fixed;
        file << studentai[x].galutinis <<"\t\t";
        file.precision(3);
        file.fixed;
        file << studentai[x].mediana << endl;
    }



}
void print(deque <studentas> studentai, ostream &stream)
{
    string temp;
    int vecsize;
    stream << "Pavarde\t\tVardas\t\tGalutinis (Vid.)\tGalutinis (Med.)" << endl << "-----------------------------------------------------------------------" << endl;
    vecsize = studentai.size();
    for(int x = 0; x < vecsize; ++x)
    {
        stream << studentai[x].pavard << "\t\t"<<studentai[x].vard << "\t\t";
        stream.precision(3);
        stream.fixed;
        stream << studentai[x].galutinis <<"\t\t";
        stream.precision(3);
        stream.fixed;
        stream << studentai[x].mediana << endl;
    }



}
void print(deque <studentas> studentai, string filename)
{
    string temp;
    int vecsize;
    ofstream file;
    file.open(filename);
    file << "Pavarde\t\tVardas\t\tGalutinis (Vid.)\tGalutinis (Med.)" << endl << "-----------------------------------------------------------------------" << endl;
    vecsize = studentai.size();
    for(int x = 0; x < vecsize; ++x)
    {
        file << studentai[x].pavard << "\t\t"<<studentai[x].vard << "\t\t";
        file.precision(3);
        file.fixed;
        file << studentai[x].galutinis <<"\t\t";
        file.precision(3);
        file.fixed;
        file << studentai[x].mediana << endl;
    }



}
void print(const list <studentas> studenta, ostream &stream)
{
    list <studentas>::const_iterator studentai = studenta.begin();
    string temp;
    stream << "Pavarde\t\tVardas\t\tGalutinis (Vid.)\tGalutinis (Med.)" << endl << "-----------------------------------------------------------------------" << endl;
    while(studentai != studenta.end())
    {
        stream << studentai->pavard << "\t\t"<<studentai->vard << "\t\t";
        stream.precision(3);
        stream.fixed;
        stream << studentai->galutinis <<"\t\t";
        stream.precision(3);
        stream.fixed;
        stream << studentai->mediana << endl;
        ++studentai;
    }
}
void print(const list <studentas> studenta, string filename)
{
    ofstream file;
    file.open(filename);
    list <studentas>::const_iterator studentai = studenta.begin();
    string temp;
    file << "Pavarde\t\tVardas\t\tGalutinis (Vid.)\tGalutinis (Med.)" << endl << "-----------------------------------------------------------------------" << endl;
    while(studentai != studenta.end())
    {
        file << studentai->pavard << "\t\t"<<studentai->vard << "\t\t";
        file.precision(3);
        file.fixed;
        file << studentai->galutinis <<"\t\t";
        file.precision(3);
        file.fixed;
        file << studentai->mediana << endl;
        ++studentai;
    }
}
void addfromfile(vector <studentas> &studentai, string filename)
{
    ifstream file;
    file.open(filename);
    if(!file)
    {
        cout << "failas neatidarytas, nuskaitymas nepavyko" << endl;
    }
    if (studentai.size() > 0)
    {
        studentai.clear();
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
void addfromfile(deque <studentas> &studentai, string filename)
{
    ifstream file;
    file.open(filename);
    if(!file)
    {
        cout << "failas neatidarytas, nuskaitymas nepavyko" << endl;
    }
    if (studentai.size() > 0)
    {
        studentai.clear();
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
void addfromfile(list <studentas> &studentai, string filename)
{
    ifstream file;
    file.open(filename);
    if(!file)
    {
        cout << "failas neatidarytas, nuskaitymas nepavyko" << endl;
    }
    if (studentai.size() > 0)
    {
        studentai.clear();
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
void filtertofile(const vector <studentas> studentai)
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
void filtertofile(const list <studentas> studentai)
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
void filtertofile(const deque <studentas> studentai)
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
void filtertomassive(vector <studentas> &studentai, vector <studentas> &vargsiukai, vector <studentas> &kietekai, int way)
{
    /*
    1 to copy
    2 to delete
    */
    int size = studentai.size();
    switch (way)
    {
    case 1:
        {
            for (int x = 0; x < size; ++x)
            {
                if(studentai[x].galutinis < 5)
                {
                    vargsiukai.push_back(studentai[x]);
                }
                else
                {
                    kietekai.push_back(studentai[x]);
                }
            }
        }
    case 2:
        {
            vector<studentas>::const_iterator first = studentai.begin();
            for (int x = 0; x < size; ++x)
            {
                if(studentai[x].galutinis < 5)
                {
                    vargsiukai.push_back(studentai[x]);
                    studentai.erase(first + x);
                    --size;
                }

            }
        }
    }
}

void filtertomassive(deque <studentas> &studentai, deque <studentas> &vargsiukai, deque <studentas> &kietekai, int way)
{
    /*
    1 to copy
    2 to delete
    */
    int size = studentai.size();
    switch (way)
    {
    case 1:
        {
            for (int x = 0; x < size; ++x)
            {
                if(studentai[x].galutinis < 5)
                {
                    vargsiukai.push_back(studentai[x]);
                }
                else
                {
                    kietekai.push_back(studentai[x]);
                }
            }
        }
    case 2:
        {
            deque<studentas>::const_iterator first = studentai.begin();
            for (int x = 0; x < size; ++x)
            {
                if(studentai[x].galutinis < 5)
                {
                    vargsiukai.push_back(studentai[x]);
                    studentai.erase(first + x);
                    --size;
                }

            }
        }
    }
}
void filtertomassive(list <studentas> &studentai, list <studentas> &vargsiukai, list <studentas> &kietekai, int way)
{
    /*
    1 to copy
    2 to delete
    */
    list <studentas>::const_iterator it = studentai.end();
    --it;
    list <studentas>::const_iterator first = studentai.begin();
    list <studentas>::const_iterator previous = it;
    switch (way)
    {
    case 1:
        {
            while (it != first)
            {
               if(it->galutinis < 5)
               {
                   vargsiukai.push_back(*first);
               }
               else
               {
                   kietekai.push_back(*first);
               }
               ++first;
            }
        }
    case 2:
        {
            while (it != first)
            {
               if(it->galutinis < 5)
               {
                   vargsiukai.push_back(*it);
                   if(it == first)
                   {
                       return;
                   }
                   previous= it;
                   --it;
                   studentai.erase(previous);

               }
               else
               {
                    --it;
               }
            }
        }
    }
}

