#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N = 25;
int d[N];

void Quick_sort(int low, int high)
{
    int i;
    int j;
    int piwot;

    i = (high + low) / 2;
    piwot = d[i];
    d[i] = d[high];

    for(j = i = low; i < high; i++)
    {
        if(d[i] < piwot)
        {
            // swap
            int temp = d[i];
            d[i] = d[j];
            d[j] = temp;
            j++;
        }
    }

    d[high] = d[j]; 
    d[j] = piwot;

    if(j - 1 > low)  
        Quick_sort(low, j - 1);
    
    if(j + 1 < high) 
        Quick_sort(j + 1, high);
}

int main()
{
    srand(time(NULL));

    for(int i = 0; i<N; i++)
        d[i] = rand() % 100;


    cout << "UNSORTED: " << endl;
    for(int i = 0; i<N; i++)
        cout << d[i] << " ";

    cout << endl;

    Quick_sort(0,N-1);

    cout << "SORTED:" << endl;
    for(int i = 0; i<N; i++)
    cout << d[i] << " ";

    cout << endl;

    return 0;
}
