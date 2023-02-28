#include <iostream>
#include <new>
#include <vector>
#include <list>
#include <cstdlib>
#include <string.h>
#include <typeinfo>
using namespace std;

template<class T>
class Gestiune;

class CArticol{
protected:
    int cota;
    int exemplare;
    string titlu;

public:
    CArticol();
    CArticol(int,int,string);
    CArticol(const CArticol&);
    CArticol& operator=(CArticol);
    virtual ~CArticol();

    virtual void Citire();
    virtual void Afisare();

    friend istream& operator>>(istream&,CArticol&);
    friend ostream& operator<<(ostream&,const CArticol&);

    int getCota() const;
    int getExemplare() const;
    virtual string getTip() const;
    string getTitlu() const;
    void setExemplare(int);
};

CArticol::CArticol(){}
CArticol::CArticol(int c,int e,string t):cota(c),exemplare(e),titlu(t){}
CArticol::CArticol(const CArticol& a)
{
    cota=a.cota;
    exemplare=a.exemplare;
    titlu=a.titlu;
}
CArticol& CArticol::operator=(CArticol a)
{
    if(this!=&a)
    {
        cota=a.cota;
        exemplare=a.exemplare;
        titlu=a.titlu;
    }
    return *this;
}
CArticol::~CArticol(){}

void CArticol::Citire()
{
    cout<<"Introduceti cota: "; cin>>cota;
    cout<<"Introduceti numarul de exemplare: "; cin>>exemplare;
    cout<<"Introduceti titlul: "; cin>>titlu;
}
void CArticol::Afisare()
{
    cout<<"Cota: "<<cota<<endl;
    cout<<"Numarul de exemplare: "<<exemplare<<endl;
    cout<<"Titlul: "<<titlu<<endl;
}
istream& operator>>(istream& in,CArticol& a)
{
    cout<<"Introduceti cota: "; in>>a.cota;
    cout<<"Introduceti numarul de exemplare: "; in>>a.exemplare;
    cout<<"Introduceti titlul: "; in>>a.titlu;
    return in;
}
ostream& operator<<(ostream& out,const CArticol& a)
{
    cout<<"Cota: "; out<<a.cota<<endl;
    cout<<"Numarul de exemplare: "; out<<a.exemplare<<endl;
    cout<<"Titlul: "; out<<a.titlu<<endl;
    return out;
}

int CArticol::getCota() const {return cota;}
int CArticol::getExemplare() const {return exemplare;}
string CArticol::getTitlu() const {return titlu;}
string CArticol::getTip() const {}
void CArticol::setExemplare(int e){exemplare=e;}


class CCD: public CArticol{
    bool completare;

public:
    CCD();
    CCD(int,int,string,bool);
    CCD(const CCD&);
    CCD& operator=(CCD);
    ~CCD();

    void Citire();
    void Afisare();

    friend istream& operator>>(istream&,CCD&);
    friend ostream& operator<<(ostream&,const CCD&);

    string getTip() const;
};

CCD::CCD(){}
CCD::CCD(int c,int e,string t,bool cc):
    CArticol(c,e,t),completare(cc){}
CCD::CCD(const CCD& c):CArticol(c)
{
    completare=c.completare;
}
CCD& CCD::operator=(const CCD c)
{
    if(this!=&c)
    {
        this->CArticol::operator=(c);
        completare=c.completare;
    }
    return *this;
}
CCD::~CCD(){}

void CCD::Citire()
{
    CArticol::Citire();

    cout<<"Introduceti TRUE sau FALSE - CD-ul vine in completarea unei carti: ";
    cin>>completare;
}
void CCD::Afisare()
{
    CArticol::Afisare();

    cout<<"CD-ul vine in completarea unei carti: ";
    if(completare)cout<<"DA";
    else cout<<"NU";
}
istream& operator>>(istream& in,CCD& c)
{
    in>>dynamic_cast<CArticol&>(c);

    cout<<"Introduceti TRUE sau FALSE - CD-ul vine in completarea unei carti: ";
    in>>c.completare;
    return in;
}
ostream& operator<<(ostream& out,const CCD& c)
{
    out<<dynamic_cast<const CArticol&>(c);

    cout<<"CD-ul vine in completarea unei carti: ";
    if(c.completare)out<<"DA";
    else out<<"NU";
    return out;
}

string CCD::getTip() const {return "CD";}


class CCarte: public CArticol{
    string data_emitere;

public:
    CCarte();
    CCarte(int,int,string,string);
    CCarte(const CCarte&);
    CCarte& operator=(CCarte);
    ~CCarte();

    void Citire();
    void Afisare();

    friend istream& operator>>(istream&,CCarte&);
    friend ostream& operator<<(ostream&,const CCarte&);

    string getTip() const;
};

CCarte::CCarte(){}
CCarte::CCarte(int c,int e,string t,string d):
    CArticol(c,e,t),data_emitere(d){}
CCarte::CCarte(const CCarte& c):CArticol(c)
{
    data_emitere=c.data_emitere;
}
CCarte& CCarte::operator=(CCarte c)
{
    if(this!=&c)
    {
        this->CArticol::operator=(c);
        data_emitere=c.data_emitere;
    }
    return *this;
}
CCarte::~CCarte(){}

void CCarte::Citire()
{
    CArticol::Citire();

    cout<<"Introduceti data emiterii: ";
    cin>>data_emitere;
}
void CCarte::Afisare()
{
    CArticol::Afisare();

    cout<<"Data emiterii: "<<data_emitere<<endl;
}
istream& operator>>(istream& in,CCarte& c)
{
    in>>dynamic_cast<CArticol&>(c);

    cout<<"Introduceti data emiterii: "; in>>c.data_emitere;
    return in;
}
ostream& operator<<(ostream& out,const CCarte& c)
{
    out<<dynamic_cast<const CArticol&>(c);

    cout<<"Data emiterii: "; out<<c.data_emitere<<endl;
    return out;
}

string CCarte::getTip() const {return "Carte";}


class CRevista: public CCarte{

public:
    CRevista();
    CRevista(int,int,string,string);
    CRevista(const CRevista&);
    CRevista& operator=(const CRevista);
    ~CRevista();

    void Citire();
    void Afisare();

    friend istream& operator>>(istream&,CRevista&);
    friend ostream& operator<<(ostream&,const CRevista&);

    string getTip() const;
};

CRevista::CRevista(){}
CRevista::CRevista(int c,int e,string t,string d):
    CCarte(c,e,t,d){}
CRevista::CRevista(const CRevista& r):CCarte(r){}
CRevista& CRevista::operator=(const CRevista r)
{
    if(this!=&r)
        this->CCarte::operator=(r);
    return *this;
}
CRevista::~CRevista(){}

void CRevista::Citire()
{
    CCarte::Citire();
}
void CRevista::Afisare()
{
    CCarte::Afisare();
}
istream& operator>>(istream& in,CRevista& r)
{
    in>>dynamic_cast<CCarte&>(r);
    return in;
}
ostream& operator<<(ostream& out,const CRevista& r)
{
    out<<dynamic_cast<const CCarte&>(r);
    return out;
}

string CRevista::getTip() const {return "Revista";}


class CBiblioteca: public CArticol{
    vector<CArticol*> articole;

public:
    CBiblioteca();

    void addArticol(CArticol*);
    void printArticole();
    void imprumutaArticol(int);
    void restituieArticol(int);
};

CBiblioteca::CBiblioteca(){}

void CBiblioteca::addArticol(CArticol* a)
{
    articole.push_back(a);
}
void CBiblioteca::printArticole()
{
    for(int i=0;i<articole.size();i++)
    {
        cout<<"Articolul: "<<articole[i]->getTitlu()<<endl;
        cout<<"Tip: "<<articole[i]->getTip()<<endl;
        cout<<"Exemplare: "<<articole[i]->getExemplare()<<endl<<endl;
    }
}
void CBiblioteca::imprumutaArticol(int cota)
{
    vector<CArticol*>::iterator p;

    for(p=articole.begin();p!=articole.end();p++)
        if((**p).getCota()==cota)
        {
            int numar_exemplare=(**p).getExemplare();
            numar_exemplare--;
            (**p).setExemplare(numar_exemplare);
        }
}
void CBiblioteca::restituieArticol(int cota)
{
    vector<CArticol*>::iterator p;

    for(p=articole.begin();p!=articole.end();p++)
        if((**p).getCota()==cota)
        {
            int numar_exemplare=(**p).getExemplare();
            numar_exemplare++;
            (**p).setExemplare(numar_exemplare);
        }
}


template <class T>
class Gestiune{
    list<T*> articole;
    static int nrarticole;

public:
    Gestiune<T>& operator+=(int);

    void Citire();
    void Afisare();
};

template <class T>
int Gestiune<T>::nrarticole=0;

template <class T>
Gestiune<T>& Gestiune<T>::operator+=(int x)
{
    nrarticole+=x;
}

template <class T>
void Gestiune<T>::Citire()
{
    T* a=new T();
    a->Citire();
    articole.push_back(a);
    this->operator+=(1);
}

template <class T>
void Gestiune<T>::Afisare()
{
    for(auto p=articole.begin();p!=articole.end();p++)
      (*p)->Afisare();
}


class Meniu{
    static Meniu* instanta;

    Meniu(){};
    Meniu(const Meniu&);
    Meniu& operator=(const Meniu);

    Gestiune<CCarte> carti;
    Gestiune<CRevista> reviste;
    Gestiune<CCD> cd;

public:
    static Meniu* getInstanta()
    {
        if(instanta==NULL)instanta=new Meniu();
        return instanta;
    }
    static void deleteInstanta()
    {
        if(instanta!=NULL)delete instanta;
        instanta=NULL;
    }

    void AdaugaArticol();
    void AfisareArticole();
};

Meniu* Meniu::instanta=NULL;

void Meniu::AdaugaArticol()
{
    int optiune;
    bool input=false;
    while(!input)
    {
        cout<<"Introduceti optiunea de citire: 1 pentru o carte, 2 pentru o revista, 3 pentru un CD!";
        cout<<endl<<"Optiunea aleasa: "; cin>>optiune;
        switch(optiune)
        {
            case 1:{carti.Citire(); input=true; break;}
            case 2:{reviste.Citire(); input=true; break;}
            case 3:{cd.Citire(); input=true; break;}
            default:{cout<<"Optiunea introdusa nu este valida! Mai incercati o data!"<<endl;}
        }
    }
}
void Meniu::AfisareArticole()
{
    cout<<"Carti: "<<endl;
    carti.Afisare();
    cout<<"Reviste: "<<endl;
    reviste.Afisare();
    cout<<"CD: "<<endl;
    cd.Afisare();
}


int main()
{
    Meniu* M=M->getInstanta();

    int optiune=1;
    while(optiune)
    {
        bool input=false;
        while(!input)
        {
            cout<<"Introduceti optiunea de citire: 0 pentru incheierea citirii, 1 pentru adaugarea unui articol, 2 pentru afisarea articolelor introduse!";
            cout<<endl<<"Optiunea aleasa: "; cin>>optiune;
            switch(optiune)
            {
                case 0:{input=true; break;}
                case 1:{M->AdaugaArticol(); input=true; break;}
                case 2:{M->AfisareArticole(); input=true; break;}
                default:{cout<<"Optiunea introdusa nu este valida! Mai incercati o data!"<<endl;}
            }
        }
    }

    M->deleteInstanta();
    return 0;
}
