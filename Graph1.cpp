#include<iostream>
using namespace std;
#define max 100
struct adjlist
{
	int ver;
	adjlist *next;
};
struct vertex
{
	string name;
	bool processed;
	adjlist *first;
};
class Queue
{
	int a[max];
	int front,rear;
	public:
		Queue()
		{
			front=rear=-1;
		}
		bool enqueue(int dataIn)
		{
			if(rear==(max-1))
			{
				return false;
			}
			rear++;
			a[rear]=dataIn;
			if(front==-1)
			{
				front=0;
			}
			return true;
		}
		
		bool dequeue(int &dataOut)
		{
			if(front==-1)
			{
				return false;
			}
			dataOut=a[front];
			if(front==rear)
			{
				front=rear=-1;
			}
			else
			{
				front++;
			}
			return true;
		}
		bool empty()
		{
			if(front==-1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};
class Graph
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
			int m,ind;
			cout<<"Enter name of the vertex:";
			cin>>G[i].name;
			cout<<"Enter no of adjacent to "<<G[i].name<<endl;
			cin>>m;
			G[i].first=NULL;
			for(int j=0;j<m;j++)
			{
				cout<<"Enter the index of adjacent vertex -"<<j<<":";
				cin>>ind;
				adjlist *T=new adjlist;
				T->ver=ind;
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
			cout<<" "<<G[i].processed<<" ";
			adjlist *t=G[i].first;
			while(t!=NULL)
			{
				cout<<"-->"<<t->ver;
				t=t->next;
			}
			cout<<endl;
		}
	}
	void BFS(int s)
	{
		for(int i=0;i<n;i++)
		{
			G[i].processed=false;
	    }
			Queue q;
			q.enqueue(s);
			G[s].processed=true;
			while(!q.empty())
			{
				int u;
				q.dequeue(u);
				cout<<G[u].name <<", ";
                adjlist *t=G[u].first;
                while(t!=NULL)
                {
                	if(!G[t->ver].processed)
                	{
                		q.enqueue(t->ver);
                		G[t->ver].processed=true;
					}
					t=t->next;
				}
				G[u].processed=true;
			}
		}
};

int main()
{
	int s;
	Graph g;
	g.createGraph();
	cout<<"Enter start vertex index: ";
    cin>>s;
	g.BFS(s);
	g.display();
	
	return 0;
}
