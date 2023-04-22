#include <iostream>
#include <string.h>

using namespace std;

class RK{
	char *T, *P;
	int n,m;
	int d = 10,q=4999;
	
	public:
		RK(string pattern,string text){
			
			m = pattern.length();
			P = new char[m+1];
			for(int i=1;i<=m;i++)
			P[i] = pattern[i-1];
			
			n = text.length();
			T = new char[n+1];
			for(int i=1;i<=n;i++)
			T[i] = text[i-1];
			
		}
		void preprocess(int &p){
			int count =0;
			p =0;
			for(int i=1;i<=m;i++)
			{
				count = count + 1;
				p = (d*p + P[i]) % q;
			}
			cout<<"Preprocessing count ="<<" "<<count<<endl;
		}
		
		void RKMatcher(int p){
			int h = 1;
			
			for(int i =1;i<m;i++ )
			{
				h *= d;
				h = h%q;
			}
			int count = 0;
			int t0 = 0;
			int flag;
			
			for(int i=1;i<=m;i++){
				count ++;
				t0 = (d*t0 + T[i]) % q;
			}
			while(t0 < 0)
				t0 += q;
			
			for(int s=0;s<=n-m;s++){
				count = count + 1;
				flag = 0;
				if(p == t0 )
				{
					for(int j=1;j<=m;j++){
						count++;
						if(P[j] != T[s+j]){
							 flag = 1;
							break;
						}
						
					}
					
					if(flag == 0){
						cout<<"Pattern occurs with valid shift"<<" "<<s;
					}
				}
				
		
			if(s < n-m){
				
				
				t0 = (d*(t0-T[s+1]*h)+T[s+m+1]) % q;
			}
			while(t0 < 0)
				t0 += q;
		}
			cout<<"Number of active operations are"<<count<<endl;
		} 
};

int main(){
	string s1,s2;
	int p;
	cout<<"Enter the pattern "<<endl;
	cin>>s1;
	
	cout<<"Enter the text"<<endl;
	cin>>s2;
	
	RK r(s1,s2);
	r.preprocess(p);
	r.RKMatcher(p);
}
