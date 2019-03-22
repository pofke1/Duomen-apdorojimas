![version][version-badge]

## Programos tikslas


Programa atlieka darbą su studentų ir jų pažymių informacija, atspausdina darbo eigos rezultatus priklausomai nuo programos versijos ir reikalavimų versijai.

## Programos išvedimas 

Skirtingų versijų programų išvedimai skiriasi: 

V0.1:
```shell
Parasykite varda: Povilas

Parasykite pavarde: Januska


Rasykite namu darbu pazymius, jei norite kad sugeneruotu atsitiktinai rasykite rand,
 kai surasysite visus rasykite done:rasykite pazymius/rand/done: 10
rasykite pazymius/rand/done: 5
rasykite pazymius/rand/done: 7
rasykite pazymius/rand/done: done
Namu darbu pazymiai surasyti
iveskite egzamino pazymi: 9

Mokinys ivestas, jei norite baigti rasykite done,
jei ne, parasykite bet ka:
done
jei norite, kad spausdintu medianas rasykite m, jei vidurkius v: m
Pavarde         Vardas          Galutinis (Med.)
--------------------------------------------------
Januska         Povilas         8.2
Press any key to continue . . .
```
v0.2:
```shell
Iveskite f kad nuskaityti is failo, r, kad ivesti ranka: f
Ar norite sugeneruoti faila? Irasykite t arba nt
Pavarde         Vardas          Galutinis (Vid.)        Galutinis (Med.)
-----------------------------------------------------------------------
Pavarde0                Vardas0         3.12            3.6
Pavarde1                Vardas1         3.88            4.4
Pavarde2                Vardas2         5.88            6.6
Pavarde3                Vardas3         2.8             3.4
Pavarde4                Vardas4         5.28            5.8
Pavarde5                Vardas5         6.36            6.6
Pavarde6                Vardas6         4.88            5.4
Pavarde7                Vardas7         5.64            6.4
Pavarde8                Vardas8         4.76            5.4
Pavarde9                Vardas9         3.96            4.2
9.48Press any key to continue . . .
```
v0.3:
```shell
Iveskite f kad nuskaityti is failo, r, kad ivesti ranka: f
Ar norite sugeneruoti faila? Jei taip iveskite studentu skaiciu, jei ne iveskite 0: 10
Pavarde         Vardas          Galutinis (Vid.)        Galutinis (Med.)
-----------------------------------------------------------------------
Pavarde0                Vardas0         6.76            7.4
Pavarde1                Vardas1         7.92            8.2
Pavarde2                Vardas2         3.12            3.8
Pavarde3                Vardas3         6.92            7.2
Pavarde4                Vardas4         6.68            7
Pavarde5                Vardas5         5.2             5.8
Pavarde6                Vardas6         4.8             5.2
Pavarde7                Vardas7         3               3.4
Pavarde8                Vardas8         5.88            6.8
Pavarde9                Vardas9         6.92            7.4
Press any key to continue . . .
```
v0.4:
```shell
10 studentu generavimo ir irasymo i faila laikas: 0.005
10 studentu nuskaitymo ir vidurkiu apskaiciavimo laikas: 0.005
10 studentu pagal pavardes rusiavimas su sortf funkcija: 0.001
10 studentu rusiavimas ir isvedimas i du failus laikas: 0.008
100 studentu generavimo ir irasymo i faila laikas: 0.008
100 studentu nuskaitymo ir vidurkiu apskaiciavimo laikas: 0.005
100 studentu pagal pavardes rusiavimas su sortf funkcija: 0.002
100 studentu rusiavimas ir isvedimas i du failus laikas: 0.008
1000 studentu generavimo ir irasymo i faila laikas: 0.029
1000 studentu nuskaitymo ir vidurkiu apskaiciavimo laikas: 0.028
1000 studentu pagal pavardes rusiavimas su sortf funkcija: 0.001
1000 studentu rusiavimas ir isvedimas i du failus laikas: 0.021
10000 studentu generavimo ir irasymo i faila laikas: 0.213
10000 studentu nuskaitymo ir vidurkiu apskaiciavimo laikas: 0.245
10000 studentu pagal pavardes rusiavimas su sortf funkcija: 0.005
10000 studentu rusiavimas ir isvedimas i du failus laikas: 0.123
100000 studentu generavimo ir irasymo i faila laikas: 1.924
100000 studentu nuskaitymo ir vidurkiu apskaiciavimo laikas: 2.487
100000 studentu pagal pavardes rusiavimas su sortf funkcija: 0.046
100000 studentu rusiavimas ir isvedimas i du failus laikas: 1.078
Press any key to continue . . .
```
v0.5 (reikia pasirinkti nuo keliu studentu pradeti ir kiek kartu ta skaiciu veliau daugint is 10):
```shell
nuo kiek studentu pradet skaiciuoti? 100000
kiek kartu daugint ta skaiciu? 0
----VEKTORIUS----
100000 studentu generavimo ir irasymo i faila laikas: 1.881
100000 studentu nuskaitymo ir vidurkiu apskaiciavimo laikas: 2.497
100000 studentu pagal pavardes rusiavimas su sortf funkcija: 0.048
100000 studentu rusiavimas ir isvedimas i du failus laikas: 1.087
isviso uztruko: 5.513
----DEQUE----
100000 studentu generavimo ir irasymo i faila laikas: 1.954
100000 studentu nuskaitymo ir vidurkiu apskaiciavimo laikas: 2.623
100000 studentu pagal pavardes rusiavimas su sortf funkcija: 0.06
100000 studentu rusiavimas ir isvedimas i du failus laikas: 1.135
isviso uztruko: 5.772
----LISTAS----
100000 studentu generavimo ir irasymo i faila laikas: 1.997
100000 studentu nuskaitymo ir vidurkiu apskaiciavimo laikas: 2.598
100000 studentu pagal pavardes rusiavimas su sortf funkcija: 0.017
100000 studentu rusiavimas ir isvedimas i du failus laikas: 1.155
isviso uztruko: 5.767
Press any key to continue . . .
```
v1.0:
```shell
Iveskite studentu skaiciu: 100000
vector 100000 studentu nuskaitymas is failo ir vidurkio skaiciavimas: 2.49
vector 100000 studentu vardu rusiavimas su sort: 0.074
vector 100000 rusiavimas i du vektorius tik kopijuojant: 24.804
vector 100000 rusiavimas i du vektorius perkeliant: 6.048
vector 100000 visas programos laikas kopijuojant: 27.368
vector 100000 visas programos laikas perkeliant: 8.612
deque 100000 studentu nuskaitymas is failo ir vidurkio skaiciavimas: 3.26
deque 100000 studentu vardu rusiavimas su sort: 0.099
deque 100000 rusiavimas i du vektorius tik kopijuojant: 12.072
deque 100000 rusiavimas i du vektorius perkeliant: 5.736
deque 100000 visas programos laikas kopijuojant: 15.431
deque 100000 visas programos laikas perkeliant: 9.095
list 100000 studentu nuskaitymas is failo ir vidurkio skaiciavimas: 3.326
list 100000 studentu vardu rusiavimas su sort: 0.013
list 100000 rusiavimas i du vektorius tik kopijuojant: 0.033
list 100000 rusiavimas i du vektorius perkeliant: 0.014
list 100000 visas programos laikas kopijuojant: 3.372
list 100000 visas programos laikas perkeliant: 3.353
Press any key to continue . . .
```
Šiame release pridėta v1.0 versija bei kartu patobulintos visos buvusios versijos, panaikinti bugai. Funkc.cpp ir funkc.h tinka tiek v0.3 versijai, tiek v1.0 (tik šioms versijoms reikalingi).