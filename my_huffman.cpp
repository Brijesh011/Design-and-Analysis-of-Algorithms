#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
struct charnode{
	char c;
	int freq;
	int codelen;
	string code;
	charnode *parent;
	charnode *left;
	charnode *right;
};
class PQ{
	charnode **Q;
	int heapsize;
	public:
		void create_PQ(charnode *C[],int n){
			
			heapsize = n;
			Q = new charnode*[n];
			for(int i=1;i<=heapsize;i++){
				Q[i] = C[i];
			}
			for(int i=heapsize/2;i>=1;i--){
				Min_Heapify(i);
			}
		}
		void Min_Heapify(int i){
			int l=2*i;
			int r=2*i+1;
			int smallest;
			if(l<=heapsize && Q[l]->freq<Q[i]->freq)
				smallest = l;
			else
				smallest = i;
			if(r<=heapsize && Q[r]->freq<Q[smallest]->freq)
				smallest = r;
			if(smallest!=i){
				charnode *t = Q[i];
				Q[i] = Q[smallest];
				Q[smallest] = t;
				Min_Heapify(smallest);
				
			}
		}
		void insert(charnode *z){
			heapsize = heapsize+1;
			int i=heapsize;
			Q[i] = z;
			while(i>1 && Q[i/2]->freq>Q[i]->freq){
				charnode *temp = Q[i];
				Q[i] = Q[i/2];
				Q[i/2] = temp;
				i = i/2;
			}
		}
		charnode *Extract_Min(){
			charnode *temp = new charnode;
			temp = Q[1];
			Q[1] = Q[heapsize];
			heapsize = heapsize-1;
			Min_Heapify(1);
			return temp;
		}
};
class Huffman{
	int n;
	charnode **C;
	public:
		Huffman(char ch[], int freq[], int len)
		{
			n = len;
			C = new charnode*[len];
			for (int i=1; i<=n; i++){
				C[i]=new charnode;
				C[i]->c=ch[i];
				C[i]->freq=freq[i];
				C[i]->codelen=0;
				C[i]->code="";
				C[i]->left=C[i]->right=C[i]->parent=NULL;
		    }
    	}
		charnode* BuildTree(){
			PQ Q;
			
			Q.create_PQ(C,n);
			for(int i=1;i<=n-1;i++){
				charnode *x,*y,*z;
				z = new charnode;
				z->codelen = 0;
				z->code = "";
				z->c = '$';
				z->parent = NULL;
				x = Q.Extract_Min();
					
				y = Q.Extract_Min();
				z->left = x;
				z->right = y;
				x->parent = y->parent = z;
				z->freq = x->freq+y->freq;
				Q.insert(z);
			
			}
			return Q.Extract_Min();
		}	
		void display(){
			
			for(int i=1;i<=n;i++){
				findcode(C[i]);
				cout<<C[i]->c<<"\t"<<C[i]->freq<<"\t"<<C[i]->codelen<<"\t Code: "<<C[i]->code<<endl;
			}
		}
		void findcode(charnode *t){
			if(t->codelen>0)
				return;
			if(t->parent == NULL){
				t->code = "";
				t->codelen = 0;
			}
			else{
				findcode(t->parent);
				t->codelen = t->parent->codelen+1;
				if (t->parent->left==t)
		   			t->code=t->parent->code+"0";
				else 
		    		t->code=t->parent->code+"1";
			}
		}
		int filesize(){
			int fs_var = 0;
			for(int i=1;i<=n;i++){
				fs_var = fs_var + C[i]->freq*C[i]->codelen;
			}
			return fs_var;
		}
		void inorder(charnode *t){
			if(t == NULL)
				return;
			inorder(t->left);
			if(t->c!='$')
				cout<<t->c;
			inorder(t->right);
		}
		void preorder(charnode *t){
			if(t == NULL)
				return;
			if(t->c!='$')
				cout<<t->c;
			preorder(t->left);
			preorder(t->right);
		}
};
int main(){
	int n;
	char a[20];
	int f[20];
	cout << "Enter No. of characters: ";
	cin >> n;
	cout << "Enter the char & freq: "<< endl;
	for(int i=1;i<=n;i++)
	   cin >> a[i] >> f[i];
	Huffman H(a,f,n);
	cout<<endl;
	charnode *root = H.BuildTree();
	H.display();
	cout<<endl<<"Inorder traversal : ";
	H.inorder(root);
	cout<<endl<<"Preorder traversal : ";
	H.preorder(root);
	charnode *t;
    int FL_FS;
    int VL_FS;
    int tot_freq=0;
    for (int i=1; i<=n; i++)
    	tot_freq += f[i];
	FL_FS = tot_freq * (int)(log2(n)+1); 
	VL_FS = H.filesize();

	cout << "File size in Variable Length: " << VL_FS << endl;
	cout << "File size in Fixed Length: " <<  FL_FS << endl;
	cout << "Compression Ratio: " << 100-(double)VL_FS/FL_FS*100 << endl;
	return 0;
}
