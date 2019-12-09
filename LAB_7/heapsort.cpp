#include <iostream>

using namespace std;

void max_heapify(int a[], int i, int n)
{
    int l,r,largest,loc;
    l = 2*i;
    r = (2*i+1);
    if( (l<=n) && a[l]>a[i] )
        largest=l;
    else
        largest=i;

    if( (r<=n) && (a[r]>a[largest]))
        largest=r;

    if( largest!=i )
    {
        loc=a[i];
        a[i]=a[largest];
        a[largest]=loc;
        max_heapify(a, largest,n);
    }
}
void build_max_heap(int a[], int n)
{
    for(int k = n/2; k >= 1; k--)
    {
        max_heapify(a, k, n);
    }
}
void heapsort(int a[], int n)
{

    build_max_heap(a,n);
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        max_heapify(a, 1, i - 1);
    }
}

int main()
{
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the elements in the array"<<endl;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    
    }
    heapsort(a, n);
    cout<<"SORTED: "<<endl;
    for (int i = 1; i <= n; i++)
    {
        cout<<a[i]<<endl;
    }
}
