#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* link;
};

struct headNode
{
	int count;
	Node* list;
};
// creating a node
Node* createNode(int key)
{
	Node* n=new Node;
	n->data=key;
	n->link=NULL;
	
	return n;
}
// creating a hash,  a hash is a collection of linkedlist
// array of linkedlist hash
// one array one linekdlist that linked list can have many nodes
headNode* createHash(int size)
{
	headNode* hash=new headNode[size];
	int walker=0;
	for (int i=0;i<size;i++)
	{
		hash[walker].count=0;
		hash[walker].list=NULL;
		walker++;
	}
	return hash;
}
// inserting a node in hash
void insHash(headNode* hash,int size,int key)
{
	
	int hashind=key%size;
	Node* newNode=createNode(key);
	
	
	newNode->link=hash[hashind].list;
	
    hash[hashind].list=newNode;
	hash[hashind].count++;
	cout<<key<<" Inserted Successfully"<<endl;
}

void delHash(headNode* hash,int size,int key)
{
	int hashind=key%size;
	Node* dNode=hash[hashind].list;
	Node* temp=NULL;
	while(dNode !=NULL)
	{
		if (dNode->data == key)
		{
			
			hash[hashind].list=dNode->link;
			hash[hashind].count--;
			return;
		}
		temp=dNode;
		dNode=dNode->link;
	}
	cout<<"Element not present in table"<<endl;
}

void search(headNode* hash,int size,int key)
{
	int hashind=key%size;
	Node* sNode=hash[hashind].list;
	while(sNode!=NULL)
	{
		if(sNode->data==key)
		{
			cout<<"Data Found : Data->"<<sNode->data<<endl;
			return;
		}
		sNode=sNode->link;
	}
	cout<<"Element not found"<<endl;
}

void display(headNode* hash,int size)
{
	cout<<"\nHash Table\n";
	for(int i=0;i<size;i++)
	{
		cout<<"Node "<<i+1<<": ";
		Node* temp = hash[i].list;
		if (temp==NULL)
			cout<<"Empty list";
		else
		{
		while(temp!=NULL)
		{
			
			cout<<temp->data<<"-";
			
			temp=temp->link;
			
		}}
		
		cout<<endl;
	}
}


int main()
{
	headNode* hash_table=createHash(10);
	display(hash_table,10);
	insHash(hash_table,10,5); display(hash_table,10);
	insHash(hash_table,10,9); display(hash_table,10);
	insHash(hash_table,10,8); display(hash_table,10);
	insHash(hash_table,10,6); display(hash_table,10);
	delHash(hash_table,10,9); display(hash_table,10);
	search(hash_table,10,6);
	display(hash_table,10);
}
