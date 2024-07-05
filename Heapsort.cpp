#include<iostream>
#include<fstream>
#include<limits.h>
#include<cmath>
using namespace std;
class HS
{
    private:
        int a[10000];
        int heapsize;
    public:
        void ReadInput( int n)
        {   
            heapsize=n;   
            ifstream fin("input.txt");
            for(int i=0; i<n; i++)
                fin>>a[i];
        }
        void WriteOutput(int n)
        {
            ofstream fout;
            fout.open("QSoutput.txt");
            for(int i=0; i<n; i++)
                fout<<a[i]<<"\t";
            fout.close();
        }
void MaxHeapify(int i,int &count)
{
    int l,r;
    l=2*i+1;
    r=2*i+2;
    int largest=i;
    if(a[l]>a[i] && l<heapsize)
    {
        largest=l;
    }
    if(a[r]>a[largest] && r<heapsize)
    {
        largest=r;
    }
    if(largest!=i)
    {
                count++;
        std::swap(a[i],a[largest]);
        MaxHeapify(largest,count);
    }
}
void BuildMax(int n,int &count)
{
    for(int i=ceil(n/2)-1;i>=0;i--)
        MaxHeapify(i,count);
}
void HeapSort(int n,int &count)
{
    for(int i=n-1;i>=0;i--)
    {
        std::swap(a[0],a[i]);
        heapsize--;
        MaxHeapify(0,count);
    }
}
};
int main()
{
    HS s;
    int len[7]={10,50,100,500,1000,5000,10000};
    for( int i=0;i<7;i++)
    {
        int count=0;
        s.ReadInput(len[i]);
        s.BuildMax(len[i],count);
        s.HeapSort(len[i],count);
        s.WriteOutput(len[i]);
        cout<<" No of comparisions for "<<len[i]<<" inputs  is : "<<count<<endl;
    }
    return 0;
}
