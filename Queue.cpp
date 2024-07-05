#include <iostream>
using namespace std;
class Queue
{
	public :
	int front,rear,size;
	int *arr;
	Queue()
	{
		front=-1;
		rear=-1;
		cout<<"Enter the size of queue : ";
		cin>>size;
		arr = new int[size];
	}
	
	bool enqueue()
	{
		if (rear == size-1)	
			return false;
		int ele;
		cout<<"Enter element to be added : ";
		cin>>ele;
		if (front==-1)	front++;
		rear++;
		arr[rear] = ele;
		return true;
	}
	
	bool dequeue()
	{
		if (rear==-1)	return false ;
		cout<<arr[front]<<endl;
		front++;
		return true;
	}
	
	bool queueFront()
	{
		if(front == -1)	return false;
		cout<<arr[front]<<endl;
		front++;
		return true;
	}
	
	bool queueRear()
	{
		if(rear==-1)	return false;
		cout<<arr[rear]<<endl;
		return true;
	}
	
	bool emptyQueue()
	{
		if (front==-1)	 return true;
		return false;  
	}
	
	bool fullQueue()
	{
		if (rear==size-1)	return true;
		return false;
	}
	
	int QueueCount()
	{
		if(rear==-1)	return 0;
		return rear-front+1; 
	}
};
int main()
{
	Queue q1;
	char ch='y';
	cout<<"1.Enqueue\n2.Dequeue\n3.Queue Front element\n4.Queue Rear element\n5.Empty Queue check\n6.Full Queue Check\n7.Queue Count";
	while(ch=='y')
	{
		int choice=0;
		repeat :
		cout<<"\nEnter your choice : ";
		cin>>choice;
		if(choice >7 || choice <1)	
		{
			cout<<"Invalid input for choice"<<endl;
			goto repeat;
		}
		switch(choice)
		{
			case 1 :
				if (q1.enqueue())
					cout<<"Element pushed into Queue "<<endl;
				else
					cout<<"Overflow : Queue limit exceeded"<<endl;
				break;
			case 2 :
				if (q1.dequeue())
					cout<<"Element popped out of Queue "<<endl;
				else
					cout<<"Underflow : Queue empty"<<endl;
				break;
			case 3 :
				if (q1.queueFront())
					cout<<"Queue is empty"<<endl;
				break;
			case 4 :
				if (q1.queueRear())
					cout<<"Queue is empty"<<endl;
				break;
			case 5 :
				if (q1.emptyQueue())
					cout<<"Queue is Empty"<<endl;
				else
					cout<<"queue is not Empty"<<endl;
				break;
			case 6 :
				if (q1.fullQueue())
					cout<<"Queue is full"<<endl;
				else
					cout<<"Queue is not full"<<endl;
				break;
			case 7 :
				if (q1.QueueCount())	
				{
					cout<<"Queue Empty"<<endl;
				}
				cout<<q1.QueueCount()<<endl;
				break;
		}
		cout<<"Press y to continue : ";
		cin>>ch;
	}
}
