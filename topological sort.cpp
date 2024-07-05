#include<iostream>
#include<string.h>
using namespace std;

enum vcolor{white,gray,black};

struct node{
	int ver;
	node *next;
};
struct vnode{
	string vname;
	int d; // start time
	int f; // end time 
	int pi;     
	vcolor color;
	node *adjptr;   
};
class Graph{
	int n;
	vnode vertex[10];
	node *list;
	int time;
	public:
		void createGraph(){
			cout<<"Enter number of vertice : ";
			cin>>n;
			
			for(int i=1;i<=n;i++){
				cout<<"Enter vertex "<<i<<"name : ";
				cin>>vertex[i].vname;
				vertex[i].adjptr = NULL;
				cout<<"Enter number of adjacent vertices : ";
				int m;
				cin>>m;
				node *cur = NULL;  // cur is like last 
				for(int j=1;j<=m;j++){
					node *t = new node;
					cout<<"Enter the index of adjacent vertex : ";
					cin>>t->ver;
					if(cur == NULL){
						vertex[i].adjptr = t;
					}
					else{
						cur->next = t;
					}
					t->next = NULL;
					cur = t;
				}
			}
		}
		void DFS(){
			for(int i=1;i<=n;i++){
				vertex[i].color = white;
				vertex[i].pi = -1;
			}
			time = 0;
			list = NULL;
			for(int v=1;v<=n;v++){
				if(vertex[v].color == white){
					DFS_VISIT(v);
				}
			}
		}
		void DFS_VISIT(int u){
			time = time+1;
			vertex[u].d = time;
			vertex[u].color = gray;
			node *temp = vertex[u].adjptr;
			while(temp != NULL){
				int v = temp->ver;
				if(vertex[v].color == white){
					vertex[v].pi = u;
					DFS_VISIT(v);
				}
				temp = temp->next;
			}
			
			time = time+1;
			vertex[u].f = time;
			vertex[u].color = black;
			
			node *t = new node;
			t->ver = u;
			t->next = list;
			list = t;
			
		}
		void TopSort(){
			DFS();
			node *temp = list;
			while(temp != NULL){
				cout<<vertex[temp->ver].vname<<"\t"<<endl;
				temp = temp->next;
			}
			return;
		}
};
int main(){
	Graph g;
	g.createGraph();
	g.TopSort();
}
