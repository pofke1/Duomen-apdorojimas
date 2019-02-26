
#include <headers.h>

int main()
{
srand(time(NULL));
string temp;
    vector <studentas> studentai (1);
    cout << "Iveskite f kad nuskaityti is failo, r, kad ivesti ranka: ";
    cin >> temp;
    int tempp;
    if(temp == "f")
    {
        tempp = addfromfile(studentai);
        if(tempp == -1)
        {
            system("PAUSE");
            return 0;
        }
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
    print (studentai);
    }
    catch(exception& e)
    {
        cout << "Programa negali toliau dirbi" << endl;
    }
    system("PAUSE");
    return 0;
}
