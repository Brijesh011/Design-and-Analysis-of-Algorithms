// Minimum Weight Spanning Tree - Prims method
// Graph input with Adjacency matrix

#include<conio.h>
#include<iostream>
using namespace std;
#define SIZE 10

class MWST
{
	int G[10][10]; int Nodecount;
	char Data[10]; int Dist[10];
	int InTree[10];
	public:
		MWST(int cnt)
		{	
			Nodecount=cnt;
			for(int i=0;i<10;i++)
			{
				Dist[i]=99999;
				InTree[i]=0;
			}
			for(int i=0;i<10;i++)
				for(int j=0;j<10;j++)
					G[i][j]=0;
		}
		void graphInput()
		{
			int adjcnt,i,j,edgewt; char data,src,dest;
			for(i=0;i<Nodecount;i++)
			{
				cout<<"Enter node - "<<i<<" data: ";
				cin>>Data[i];
			}
			cout<<"\nEnter edge weights:\n";
			for(i=0;i<Nodecount;i++)
				for(j=0;j<Nodecount;j++)
				{
					cout<<"Weight of "<<Data[i]<<" - "<<Data[j]<<" : ";
					cin>>G[i][j];
				}
		}
		void graphOutput()
		{
			int indx,i,j;
			for(i=0;i<Nodecount;i++)
			{
				cout<<"\nVertex - "<<Data[i]<<"--->";
				for(j=0;j<Nodecount;j++)
				{
					if (G[i][j] != 0)
						cout<<Data[j]<<" "<<G[i][j]<<"  ";					
				}
			}
		}
		void mwst(char start)
		{
			int i,j,x,y,minval,edgecnt=0, strtvrtx,weight=0;
			bool treeComplete;
			for(i=0;i<Nodecount;i++)
			{
				if (Data[i]==start)
				{
					strtvrtx=i;
					break;
				}
			}
			InTree[strtvrtx]=1;
			treeComplete=false;
			cout<<"\n MWST edges are : \n";
			while (!treeComplete)
			{
				treeComplete=true;
				minval=99999;
				x=y=0;   // set edge to null
				for(i=0;i<Nodecount;i++)  // loop thru all vertices
				{
					if (InTree[i])  // if vertex in tree
					{
						for(j=0;j<Nodecount;j++)  // loop thru all edges
						{
							if (!InTree[j] && G[i][j]) // check if vertex j is not included in tree and 
							{							// is also adjacent to vertex i
								treeComplete=false;						
								if (minval > G[i][j])
								{
									minval = G[i][j]; // update edge weight
									x=i; y=j;			// update edge 
								}
							}
						}
					}
				}
				cout<<Data[x]<<" - "<<Data[y]<<" wt "<<G[x][y]<<endl; // include edge in tree
				InTree[y]=1; //set destination vertex to in-tree
				weight+=G[x][y]; //update tree weight
			}
			cout<<"\n Total weight = "<<weight;
		} 
};

int main()
{
	int count; char start;
	cout<<"Total vertices count : "; cin>>count;
	MWST obj(count); 
	obj.graphInput();
	obj.graphOutput();
	cout<<"\nEnter start vertex : "; cin>>start;
	obj.mwst(start);
}
