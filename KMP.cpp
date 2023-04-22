#include <iostream>
#include <string.h>

using namespace std;

class KMP{
	char *P,*T;
	int lps[100],n,m;
	
	public:
		
	void naive(){
		int count =0;
		for(int s=0;s<=n-m;s++){
			int flag = 0;
			for(int j=1;j<=m;j++){
				count ++;
				if(P[j] != T[s+j]){
					flag = 1;
					break;
				}
			}
			if(flag == 0){
				cout<<"Pattern occurs with valid shift"<<" "<<s<<endl;
			}
		}
		cout<<"The number of active operations"<<" "<<count<<endl;
	}
		
	KMP(string pattern,string text)
	{
		m = pattern.length();
		P = new char[m+1];
		for(int i=1;i<=m;i++)
		P[i] = pattern[i-1];
		
		n = text.length();
		T = new char[n+1];
		for(int i=1;i<=n;i++)
		T[i] = text[i-1];
	}
	
	void ComputePrefix(){
		lps[1] = 0;
		int k=0,count =0;
		for(int q=2;q<=m;q++){
			count = count +1;
			while(k>0 && P[k+1] != P[q]){
				k = lps[k];
				count = count +1;
			}
			if(P[k+1] == P[q])
				k = k+1;
			lps[q] = k;
		}
		cout<<"Preprocessing Pattern count ="<<count<<endl;
	}
	
	void KMPMatcher(){
		int count = 0;
		int q = 0;
		
		for(int i=1;i<=n;i++){
		   
			count = count+1;
			while(q>0 && P[q+1] != T[i]){
				q = lps[q];
				count = count +1;
			}
			if(P[q+1] == T[i]){
				q = q+1;
				if(q == m ){
					cout<<"Pattern occurs with valid shift"<<i-m<<endl;
					q = lps[q];
				}
			}
		}
		cout<<"The number of active operations"<<" "<<count<<endl;
		
	}
	
};

int main(){
	string s1,s2;
	
	cout<<"Enter the pattern "<<endl;
	cin>>s1;
	
	cout<<"Enter the text"<<endl;
	cin>>s2;
	
	
	KMP r(s1,s2);
	r.naive();
	r.ComputePrefix();
	r.KMPMatcher();
}
