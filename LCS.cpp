#include<iostream>
#include<fstream>
#include<string.h>
#include<limits.h>
using namespace std;
int count=0;
class LCS
{
	private:
		int c[30][30];
		char b[30][30];
		char X[30],Y[30];
	public:
		void readInput(int m,int n){
			ifstream fin("lcs_input.txt");
			string s1,s2;
			fin>>s1>>s2;
			for(int i=0;i<m;i++)
				X[i+1]=s1[i];
			for(int j=0;j<n;j++)
				Y[j+1]=s2[j];
		}
		void initialization(int m,int n){
			for(int i=0;i<=m;i++)
			{
				for(int j=0;j<=n;j++)
					c[i][j]=INT_MIN;
			}
		}
		int dp_bu(int m,int n){
			for(int j=0;j<=n;j++)
				c[0][j]=0;
			for(int i=1;i<=m;i++)
				c[i][0]=0;
			for(int i=1;i<=m;i++)
			{
				for(int j=1;j<=n;j++)
				{
					count+=1;
					if(X[i]==Y[j])
					{
					c[i][j]=c[i-1][j-1]+1;
					b[i][j]='C';	
					}
					else if(c[i-1][j]>=c[i][j-1])
					{
						c[i][j]=c[i-1][j];
						b[i][j]='U';
					}
					else
					{
						c[i][j]=c[i][j-1];
						b[i][j]='L';
					}	
				}	
			}
			return c[m][n];	
		}
		void print_lcs(int i,int j){
			if (i==0 || j==0)
				return;
			if (b[i][j]=='C')
			{
				print_lcs(i-1,j-1);
				cout<<X[i]<<" ";
			}
			else if(b[i][j]=='U')
				print_lcs(i-1,j);
			else
				print_lcs(i,j-1);	
		}
		int lcs_dc(int i,int j){
			  count++;
			  if (i==0 || j==0)
				return 0;
			  if(X[i]==Y[j])
				return (lcs_dc(i-1,j-1)+1);
			  else{
			  	int t1=lcs_dc(i-1,j);
			  	int t2=lcs_dc(i,j-1);
			  	if(t1>=t2)
			  		return t1;
			  	else
			  		return t2;
			  }
		}
		int lcs_dp_td(int i,int j){
			if (c[i][j]>0)
				return c[i][j];
			if (i==0 || j==0)
			{
				c[i][j]=0;
				return c[i][j];
			}
			count+=1;
			if(X[i]==Y[j])
			{
				c[i][j]=lcs_dp_td(i-1,j-1)+1;
				b[i][j]='C';
			}
			else
			{
				int t1=lcs_dp_td(i-1,j);
				int t2=lcs_dp_td(i,j-1);
				if(t1>=t2)
				{
				c[i][j]=t1;
				b[i][j]='U';	
				}
				else
				{
				c[i][j]=t2;
				b[i][j]='L';	
				}	
			}
			return c[i][j];	
		}
		
};
int main()
{
	LCS sample;
	int l1,l2,l3,m,n;
	cout<<"Enter the length of X sequence: "<<endl;cin>>m;
	cout<<"Enter the length of Y sequence: "<<endl;cin>>n;
	sample.readInput(m,n);
	
	sample.initialization(m,n);
	cout<<"\nDynamic Programming - Top down approach :-";
	l1=sample.lcs_dp_td(m,n);
	cout<<"\nMaximal length = "<<l1<<endl;
	cout<<"Number of basic operations : "<<count;
	count=0;
	
	cout<<"\nDynamic Programming - Bottom up approach :-";
	l2=sample.dp_bu(m,n);
	cout<<"\nMaximal length = "<<l2<<endl;
	cout<<"Number of basic operations : "<<count;
	count=0;
	
	cout<<"\nDivide and conquer :-";
	l3=sample.lcs_dc(m,n);
	cout<<"\nMaximal length = "<<l3<<endl;
	cout<<"Number of basic operations : "<<count;
	
	cout<<"\nLongest Common Subsequence : ";
	sample.print_lcs(m,n);
	cout<<endl;
}

