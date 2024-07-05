#include<iostream>
#include<fstream>
using namespace std;
struct node
{
    double data;
    node* next;
};
class SList
{
    private:
        node* a;
        int size;
    public:
        SList()
        {
            a=NULL;
            size=0;
        }
        bool ElementAt(int p,double &x)
        {
            node* t=a;
            int c=1;
            while(t!=NULL)
            {
                if(c==p)
                {
                    x=t->data;
                    return true;
                }
                t=t->next;
                c++;
            }
            return false;
        }
        void InsertFront(double x)
        {
            node* n;
            n=new node;
            n->data=x;
            n->next=a;
            a=n;
            size++;
        }
        void Sort(int &count)
        {
            node *i,*j;
            double t;
            i=a;
            for(i=a;i!=NULL;i=i->next)
            {
                for(j=i->next;j!=NULL;j=j->next)
                {
                    count++;
                    if(j->data<i->data)
                    {
                        t=i->data;
                        i->data=j->data;
                        j->data=t;
                    }
                }
            }
        }
};
class BS
{
    private:
        double a[100000];
    public:
        void ReadInput(int n)
        {
            ifstream fin("BucketSortInput.txt");
            for(int i=0; i<n; i++)
                fin>>a[i];
        }
        void WriteOutput(int n)
        {
            ofstream fout;
            fout.open("BSoutput.txt");
            for(int i=0; i<n; i++)
                fout<<a[i]<<"\t";
            fout.close();
        }
    void BucketSort(int n,int &count)
    {
    SList *Buckets;
    Buckets=new SList[n];
    int bno;
     for(int i=0;i<n;i++)
    {
        count++;
        bno=a[i]*n;
        Buckets[bno].InsertFront(a[i]);
    }
    for(int i=0;i<n;i++)
    {
        Buckets[i].Sort(count);
    }
    double t;
    int j=0;
    for(int i=0;i<n;i++)
    {
        for(int p=1;p<=sizeof(Buckets[i]);p++)
        {
            if(Buckets[i].ElementAt(p,t))
            {
                a[j++]=t;
            }
        }
    }
}
};
int main()
{
    BS x;
    int len[7]={10,50,100,500,1000,5000,10000};
    for(int i=0;i<7;i++)
    {
        int count=0;
        x.ReadInput(len[i]);
        x.BucketSort(len[i],count);
        x.WriteOutput(len[i]);
        cout<<"NO of comparisons in for "<<len[i]<<" input is "<<count<<endl;
    }
}