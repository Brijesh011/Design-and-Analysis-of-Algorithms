#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class CountSort
{
    private:
        int arr[100000];
    public:
     void ReadInput( int n)
        {
            ifstream fin("CSinput.txt");
            for(int i=0; i<n; i++)
                fin>>arr[i];
            fin.close(); 
        }
        void WriteOutput(int n)
        {
            ofstream fout;
            fout.open("Csortoutput.txt");
            for(int i=0; i<n; i++)
                fout<<arr[i]<<"\t";
            fout.close();
        }
    void Sort(int n,int &counting)
{
    int output[n],i;
    int count[10]={0};
    for(int i=0; i<n; i++)
        ++count[arr[i]];
    for(int i=1;i<10;i++)
    {
        count[i]+=count[i-1];
    }
    for(int i=n-1;i>=0;i--)
       {
            counting++;
         output[count[arr[i]]-1]=arr[i];
         --count[arr[i]];
       }
    for(i=0;i<n;i++)
        arr[i]=output[i];
}
};
int main()
{
    CountSort x;
    int len[7]={10,50,100,500,1000,5000,100000};
    for(int i=0;i<1;i++)
    {
        int counting=0;
        x.ReadInput(len[i]);
        x.Sort(len[i],counting);
        x.WriteOutput(len[i]);
        cout<<"NO of comparisons in for "<<len[i]<<" input is "<<counting<<endl;
    }
}
