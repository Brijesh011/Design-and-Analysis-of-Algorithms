//Maximum Subarray
#include<iostream>
#include<fstream>
#include<limits.h>
using namespace std;
struct subarray
{
	int left;
	int right;
	int maxsum;
};
class MSA
{
	private:
	int a[100010];
	public:
	void readinput(int n){
		ifstream fin("maxsubinput.txt");
		for(int i=0;i<n;i++)
		    fin>>a[i];
		fin.close();
	}
	subarray bruteforce(int n,int &count){
		struct subarray temp;
		temp.maxsum=INT_MIN;
		for(int i=0;i<n;i++)
		{
			int sum=0;
			for(int j=i;j<n;j++)
			{
				sum=sum+a[j];
				count++;
				if (sum>temp.maxsum)
				{
					temp.maxsum=sum;
					temp.left=i;
					temp.right=j;
				}
			}
		}
		return temp;
	}
	subarray maxcrosssub(int l,int m,int h,int &count){
		int sum=0;
		subarray temp;
		int leftmax=INT_MIN;
		for(int i=m;i>=l;i--)
		{
			sum=sum+a[i];
			count++;
			if (sum>leftmax)
			{
				leftmax=sum;
				temp.left=i;
			}
		}
		sum=0;
		int rightmax=INT_MIN;
		for(int i=m+1;i<=h;i++)
		{
			sum=sum+a[i];
			count++;
			if (sum>rightmax)
			{
				rightmax=sum;
				temp.right=i;
			}
		}
		temp.maxsum=leftmax+rightmax;
		return temp;
	}
	subarray dc(int low,int high,int &count){
		subarray ans,left_sub,right_sub,cross_sub;
		if (high==low)
		{
			ans.left=ans.right=high;
			ans.maxsum=a[high];
			return ans;
		}
		else
		{
			int mid=(low+high)/2;
			left_sub=dc(low,mid,count);
			right_sub=dc(mid+1,high,count);
			cross_sub=maxcrosssub(low,mid,high,count);
			if(left_sub.maxsum>=right_sub.maxsum && left_sub.maxsum>=cross_sub.maxsum)
				return left_sub;
			else if(right_sub.maxsum>=left_sub.maxsum && right_sub.maxsum>=cross_sub.maxsum)
				return right_sub;
			else
				return cross_sub;	
		}
	}	
};
int main()
{
	MSA m1;
	subarray res;
	int len[]={10,50,100,500,1000,5000,10000};
	int ch,count;
	cout<<"\n1.max subarray using brute force\n2.max subarray using divide and conquer\n3.exit"<<endl;
	do{
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Brute Force Method:"<<endl;
				for(int i=0;i<7;i++)
				{
				count=0;
				int n=len[i];
				m1.readinput(n);
				res=m1.bruteforce(n,count);
				cout<<"Maximum subarray for "<<n<<" elements is "<<res.left<<","<<res.right<<","<<res.maxsum<<endl;
				cout<<"Number of comparisons for "<<n<<" elements is "<<count<<endl;
				}	
				break;
			case 2:
				cout<<"Divide And Conquer Method:"<<endl;
				for(int i=0;i<7;i++)
				{
				count=0;
				int n=len[i];
				m1.readinput(n);
				res=m1.dc(0,n-1,count);
				cout<<"Maximum subarray for "<<n<<" elements is "<<res.left<<","<<res.right<<","<<res.maxsum<<endl;
				cout<<"Number of comparisons for "<<n<<" elements is "<<count<<endl;
				}	
				break;
		}
	}while(ch<3);
}

