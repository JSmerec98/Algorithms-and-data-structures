#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>

using namespace std;

struct Node
{
    Node *next;

    string name;
    string surname;
    int year;
    string country;

    int count = 0;  
};

class List 
{
    public:

    Node* head;

    List();

    void print();
    void add(string name,string surname, int year, string country);

    vector<Node> return_all_of_country(string country);
    vector<Node> return_country_and_number(); 
    string return_surname_by_year(int year);
};

List::List()
{
    head = 0;
}

void List::add(string name,string surname, int year, string country)
{
    Node *temp = new Node;

    temp->name = name;
    temp->surname = surname;
    temp->year = year;
    temp->country = country;

    if(!head)
    {
        head = temp;
    }
    else
    {
        Node *p = head;
        while(p->next)
        {
            p = p->next;
        }
        p->next = temp;
        temp->next = 0;
    }
}

void List::print()
{
    Node *temp = head;

    while(temp != NULL)
    {
        cout << temp->name << " " << temp->surname;
        cout << " " << temp ->year << " " << temp->country << endl;

        temp = temp->next;
    }
}

vector<Node> List::return_all_of_country(string country)
{
    Node *t;
    t = head;
    Node p;

    vector<Node> Countries;

    while(t != NULL)
    {
        if(t->country == country)
        {
            p.name = t->name;
            p.surname = t->surname;

            Countries.push_back(p);
        }
    
        t = t->next;
    }
    
    return Countries;
}

vector<Node> List::return_country_and_number()
{
    Node *t;
    t = head;

    vector<Node> temp;

    Node p;

    while(t != NULL)
    {
        bool unique = false;

        for(int i = 0; i<temp.capacity(); i++)
        {
            if(temp[i].country == t->country)
            {
                temp[i].count++;
                unique = true;
                break;
            }
        }

        if(unique == false)
        {   
            p.country = t->country;
            p.count = 1;

            temp.push_back(p);
        }
        
        t = t->next;

    }

    return temp;
}

string List::return_surname_by_year(int year)
{
    Node *t;
    t = head;

    string surname;

    while( t != NULL)
    {
        if(t->year == year)
        {
            surname = t->surname;
            break;
        }
        
        t = t->next;
    }

    return surname;
}

int main()
{
    List L;

    fstream plik;

    string name, surname, country;
    int year;

    plik.open("data2.txt",std::ios::in | std::ios::out);
    string dane;
    if( plik.good() == true )
    {
        while (!plik.eof())
        {
            plik >> name;
            plik >> surname;
            plik >> year;
            plik >> country;
            L.add(name,surname,year,country);
        }
    }

    // 1

    vector<Node> temp;
    temp = L.return_all_of_country("Polska");
    
    for(int i = 0; i < temp.capacity(); i++)
    {
        cout << temp[i].name << " " << temp[i].surname << endl;
    }

    cout << endl;

    // 2

    vector<Node> temp2;
    temp2 = L.return_country_and_number();

    
    for(int j = 0; j < temp2.capacity(); j++)
    {
        cout << temp2[j].country << " - " << temp2[j].count << endl;
    }

    // 3 

    cout << endl << L.return_surname_by_year(1936) << endl;

    plik.close();

    return 0;
}
