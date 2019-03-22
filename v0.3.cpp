
#include <funkc.h>

int main()
{
srand(time(NULL));
string temp;
    vector <studentas> studentai (1);

    temp = input("Iveskite f kad nuskaityti is failo, r, kad ivesti ranka: ", "f", "r");
    int tempp;
    if(temp == "f")
    {
        tempp = input("Ar norite sugeneruoti faila? Jei taip iveskite studentu skaiciu, jei ne iveskite 0: ", 0);
        if(tempp != 0)
        {
            generatefile(tempp, "kursiokai.txt");
        }
        addfromfile(studentai, "kursiokai.txt");

    }
    else
    {
        add(studentai);
    }
    for(int x = 0; x < studentai.size(); ++x)
    {

        try
        {
        studentai[x].calc();
        }
        catch(exception& e)
        {
            x = studentai.size();
        }
    }

    try
    {
    sortf(studentai);
    print (studentai, cout);
    }
    catch(exception& e)
    {
        cout << "Programa negali toliau dirbi" << endl;
    }
    system("PAUSE");
    return 0;
}
