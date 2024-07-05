#include<iostream>
using namespace std;
#include<limits>
struct adjlist
{
	int ver;
	int weight;
	adjlist *next;
};
struct vertex
{
	string name;
	bool intree;
	int key;
	int par;
	adjlist *first;
};

class Spantree
{
		vertex G[10];
	    int n;
		
		public:
	void createGraph()
	{
		cout<<"No. of vertices:";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int m,ind,w;
			cout<<"Enter name of the vertex:";
			cin>>G[i].name;
			cout<<"Enter no of adjacent to "<<G[i].name<<endl;
			cin>>m;
			G[i].first=NULL;
			for(int j=0;j<m;j++)
			{
				cout<<"Enter the index of adjacent vertex -"<<j<<":";
				cin>>ind;
				cout<<"enter weight"<<endl;
				cin>>w;
				adjlist *T=new adjlist;
				T->ver=ind;
				T->weight=w;
				T->next=G[i].first;
				G[i].first=T;
			}
		}
	}
	void display()
	{
		cout<<"Graph"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<G[i].name;
			cout<<" "<<G[i].intree<<" ";
			adjlist *t=G[i].first;
			while(t!=NULL)
			{
			    cout<<"--> {"<<t->ver<<" "<<t->weight<<" }";
				t=t->next;
			}
			cout<<endl;
		}
	}
	void MWST_prims()
	{
		int i,j,v,total=0;
		for(i=0;i<n;i++)
		{
			G[i].intree=false;
			G[i].key=INT_MAX;
			G[i].par=-1;	
		}
		G[0].key=0; // start index which i take
		for(i=0;i<n;i++)
		{
			int min_key=INT_MAX;
			for(j=0;j<n;j++)
			{
				if(!G[j].intree && min_key>G[j].key)
				{
					v=j;
					min_key=G[j].key;
				}
			}
			G[v].intree=true;
			total+=G[v].key;
			if(G[v].par!=-1)
			{
				cout<<G[G[v].par].name<<"-->"<<G[v].name<<endl;
			}
			adjlist *t=G[v].first;
			while(t!=NULL)
			{
				if(!G[t->ver].intree && G[t->ver].key>t->weight) // second cond satisifes if the value is infinity and no connection made 
				{
					G[t->ver].key=t->weight;
					G[t->ver].par=v;
				}
				t=t->next;
			}
		}
		cout<<"Total weight "<<total<<endl;
	}
};
int main()
{
	int s;
	Spantree g;
	g.createGraph();
	//cout<<"Enter start vertex index: ";
    //cin>>s;
    cout<<"edges of spanning tree"<<endl;
	g.MWST_prims();
	g.display();
	
}
