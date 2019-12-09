#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Person
{
    string surname;
    float score;
};

vector <Person> tab;

int main()
{
    vector <Person> tab;

    fstream plik;

    string surname;
    float score;

    plik.open("file.txt",std::ios::in | std::ios::out);
    if( plik.good() == true )
    {
         Person temp;

        while (!plik.eof())
        {
            plik >> temp.surname;
            plik >> temp.score;
            tab.push_back(temp);
        }
    }

    tab.pop_back();
    int n = tab.size();

    for(int i=0;i<n;i++)
    {
		for(int j=1;j<n-i;j++) 
		{
            if (tab[j].score >tab[j+1].score)
                swap(tab[j], tab[j+1]);
        }
    }
    cout << endl;

    for(int i = 0; i<tab.size(); i++)
    {
        cout << i+1 << ". " << tab[i].surname << " - " << tab[i].score << endl;
    }

    int x;
    cout << "Which element: ";
    cin >> x;

    cout << tab[x].surname << " - " << tab[x].score << endl;

    plik.close();

    return 0;
}
