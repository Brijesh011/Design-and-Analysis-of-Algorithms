#include<iostream>
#include<fstream>
using namespace std;
class RS
{
    private:
        int a[100000];
    public:
        void ReadInput(int n)
        {
            ifstream fin("input.txt");
            for(int i=0; i<n; i++)
                fin>>a[i];
        }
        void WriteOutput(int n)
        {
            ofstream fout;
            fout.open("RSoutput.txt");
            for(int i=0; i<n; i++)
                fout<<a[i]<<"\t";
            fout.close();
        }
    int getMax(int n)
{
    int mx=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]>mx)
            mx=a[i];
    }
    return mx;
}
void CountSort(int n,int exp,int &counting)
{
    int output[n];
    int i,count[10]={0};
    for(i=0;i<n;i++)
        count[(a[i]/exp)%10]++;
    for(i=1;i<10;i++)
        count[i]+=count[i-1];
    for(i=n-1;i>=0;i--)
    {
        counting++;
        output[count[(a[i]/exp)%10]-1]=a[i];
        count[(a[i]/exp)%10]--;
    }
    for(i=0;i<n;i++)
        a[i]=output[i];
    
}
void RadixSort(int n,int &counting)
{
    int m=getMax(n);
    for(int exp=1;m/exp>0;exp*=10)
        CountSort(n,exp,counting);

}
};
int main()
{
     RS x;
    int len[7]={10,50,100,500,1000,5000,10000};
    for(int i=0;i<7;i++)
    {
        int counting=0;
        x.ReadInput(len[i]);
        x.RadixSort(len[i],counting);
        x.WriteOutput(len[i]);
        cout<<"NO of comparisons in for "<<len[i]<<" input is "<<counting<<endl;
    }
}
