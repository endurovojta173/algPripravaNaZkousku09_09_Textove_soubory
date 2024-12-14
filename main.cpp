#include <iostream>
#include <fstream>
//9.1 Vytvořte kopii souboru dopis.txt.Kopie souboru se bude jmenovat kopie.txt.
/*
int main()
{
    std::string radek;
    std::ifstream vstupniSoubor("dopis.txt");
    std::ofstream vystupniSoubor("kopie.txt");
    if (vstupniSoubor.is_open() and vystupniSoubor.is_open())
    {
        while (std::getline(vstupniSoubor, radek))
            vystupniSoubor << radek << std::endl;
        vstupniSoubor.close();
        vystupniSoubor.close();
    }
    else
    {
        std::cerr<<"\nSoubory se nepovedlo otevrit";
    }

    return 0;
}*/
//9.2 Z textového souboru zamestnanci.txt vypište jména a příjmení všech žen s platem nad 30000.
/*
int main()
{
    std::string jmeno;
    std::string prijmeni;
    char pohlavi;
    int rokNarozeni;
    int plat;
    std::ifstream soubor("zamestnanci.txt");
    if (soubor.is_open())
    {
        while (!soubor.eof())
        {
            soubor>>jmeno>>prijmeni>>pohlavi>>rokNarozeni>>plat;
            if (pohlavi== 'z' and plat<30000)
            {
                std::cout << jmeno << " " <<prijmeni<<" "<< plat<<std::endl;
            }
        }
        soubor.close();
    }
    else
    {
    std::cerr << "Error opening file" << std::endl;
    }
    return 0;
}*/
//9.3  Z textového souboru zamestnanci.txt vypište všechny zaměstnance podle výše platu od největšího po nejmenší
struct Zamestnanec
{
    std::string jmeno;
    std::string prijmeni;
    char pohlavi;
    int rokNarozeni;
    int plat;
};

const int maxPocetZamestnancu = 10000;
typedef Zamestnanec Zamestnaneci[maxPocetZamestnancu];

/*void seradPodlePlatu(Zamestnaneci poleZamestnancu, int pocetLidi)
{
    int j =0;
    Zamestnaneci pomocnePole;
    for (int i =0; i <pocetLidi; i++)
    {
        j= i+1;
        while (poleZamestnancu[i].plat<poleZamestnancu[j+1].plat)
        {
            std::cout<<"*";
            pomocnePole[i] = poleZamestnancu[j];
            poleZamestnancu[i] = pomocnePole[i];
        }
    }
    poleZamestnancu = pomocnePole;
}*/

/*int main()
{
    int i = 0;
    Zamestnaneci poleZamestnancu;
    std::ifstream soubor("zamestnanci.txt");
    if (soubor.is_open())
    {
        while (!soubor.eof())
        {
            Zamestnanec zamestnanec;
            soubor >> zamestnanec.jmeno, soubor >> zamestnanec.prijmeni, soubor >>
                zamestnanec.pohlavi, soubor >> zamestnanec.rokNarozeni, soubor >> zamestnanec.plat;
            poleZamestnancu[i] = zamestnanec;
            i++;
        }
        //seradPodlePlatu(poleZamestnancu,i);
        for (int j = 0; j < i; j++)
        {
            std::cout << poleZamestnancu[j].jmeno <<poleZamestnancu[j].plat<< std::endl;
        }
    }
    else
    {
        std::cerr << "Error in opening file" << std::endl;
    }
}*/
//9.4 V přichystaném textovém souboru dopis.txt spočítejte poměr velkých a malých písmen

/*int main()
{
    std::ifstream dopis("dopis.txt");
    int pocetVelkychPismen=0;
    int pocetMalychPismen=0;
    if (dopis.is_open())
    {
        char znak;
        while (dopis.get(znak))
        {
            if (znak >= 'a' and znak <= 'z') pocetMalychPismen++;
            if (znak>='A' and znak<='Z') pocetVelkychPismen++;
        }
        dopis.close();
        std::cout<<"Pocet velkych: " <<pocetVelkychPismen<<std::endl;
        std::cout<<"Pocet malych: " <<pocetMalychPismen<<std::endl;
        int celkem = pocetMalychPismen+pocetVelkychPismen;
        std::cout<<"Pomer velkych v procentech %: " << (pocetVelkychPismen/(float)celkem)*100<<std::endl;
        std::cout<<"Pomer malzch v procentech %: " << (pocetMalychPismen/(float)celkem)*100<<std::endl;

    }
    else
    {
        std::cerr << "Error in opening file" << std::endl;
    }
}*/

/*int main()
{
    std::ifstream dopis("dopis.txt");
    if (dopis.is_open())
    {
        char znak;
        char predeslyZnak;
        int pocetTecek = 0;
        int pocetMezer = 0;
        while (dopis.get(znak))
        {
            if (znak == '.')pocetTecek++;
            if (predeslyZnak == ' ' and znak !=' ')pocetMezer++;
            predeslyZnak = znak;
        }
        dopis.close();
        std::cout << "\nPocet vet: " << pocetTecek << std::endl;
        std::cout << "\nPocet slov: " << pocetMezer +1 << std::endl;
    }
    else
    {
        std::cerr << "Error opening file" << std::endl;
    }
}*/

//9.7 Na základě textového souboru zamestnanci.txt vytvořte dva nové soubory. Jeden bude obsahovat pouze ženy a druhý pouze muže

int main()
{
    std::ifstream zamestnanci("zamestnanci.txt");
    std::ofstream zamestnanciZeny("zamestnanciZeny.txt");
    std::ofstream zamestnanciMuzi("zamestnanciMuzi.txt");
    if (zamestnanciZeny.is_open() and zamestnanciMuzi.is_open() and zamestnanciZeny.is_open())
    {
        Zamestnanec zamestnanec;
        while (!zamestnanci.eof())
        {
            zamestnanci >> zamestnanec.jmeno >> zamestnanec.prijmeni >> zamestnanec.pohlavi >> zamestnanec.rokNarozeni
                >> zamestnanec.plat;
            std::string radek = zamestnanec.jmeno + " " + zamestnanec.prijmeni + " " + zamestnanec.pohlavi + " "+
                std::to_string(zamestnanec.rokNarozeni) + " " + std::to_string(zamestnanec.plat);
            std::cout << radek;
            if (zamestnanec.pohlavi == 'm')
            {
                zamestnanciMuzi <<radek << std::endl;
            }
            else
            {
                zamestnanciZeny <<radek << std::endl;
            }
        }
        zamestnanciZeny.close();
        zamestnanciMuzi.close();
        zamestnanci.close();
    }
}


