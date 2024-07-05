#include <iostream>
using namespace std;
class Stack
{
	public :
	int top;
	int *arr;
	int size;
	Stack()
	{
		top=-1;
		cout<<"Enter size of Stack : " ;
		cin>>size;
		arr = new int[size];
	}
	bool isFull()
	{
		if (top==size-1)	return true;
		return false;
	}
	bool isEmpty()
	{
		if(top==-1)	return true;
		return false;
	}
	bool push()
	{
		if (top<size-1)
		{
			int ele;
			cout<<"Enter element to be added : ";
			cin>>ele;
			top++;
			arr[top] = ele;
			return true;
		}
		return false;
	}
	bool pop()
	{
		if (top==-1)	return false;
		cout<<arr[top]<<endl;
		top--;
		return true;
	}
	bool stackTop()
	{
		if (top==-1)	return false;
		cout<<arr[top]<<endl; // YOU CAN GUVE COUT 
		// EVEN IF U HV A RETURN STATEMENT
		return true;
	}
	void disp()
	{
		cout<<endl<<"Stack elements : ";
		for(int i=0;i<=top;i++)	cout<<arr[i]<<" ";
		cout<<endl;
	}
};

int main()
{
	Stack s1;
	char ch='y';
	cout<<"1.Push\n2.Pop\n3.Empty check\n4.Full check\n5.Display top element\n6.Display stack";
	while(ch =='y')
	{
		int choice=0;
		repeat :
		cout<<"\nEnter your choice : ";
		cin>>choice;
		if(choice >6 || choice <1)	
		{
			cout<<"Invalid input for choice"<<endl;
			goto repeat;
		}
		switch(choice)
		{
			case 1 :
				if (s1.push())
					cout<<"Element pushed into stack "<<endl;
				else
					cout<<"Overflow : Stack limit exceeded"<<endl;
				break;
			case 2 :
				if (s1.pop())
					cout<<"Element popped out of stack "<<endl;
				else
					cout<<"Underflow : Stack empty"<<endl;
				break;
			case 3 :
				if (s1.isEmpty())
					cout<<"Stack is empty"<<endl;
				else
					cout<<"Stack is not empty"<<endl;
				break;
			case 4 :
				if (s1.isFull())
					cout<<"Stack is full"<<endl;
				else
					cout<<"Stack is not full"<<endl;
				break;
			case 5 :
				if (!s1.stackTop())
					cout<<"Stack Empty"<<endl;
				break;
			case 6 :
				s1.disp();
				break;
		}
		cout<<"Press y to continue : ";
		cin>>ch;
	}
}
