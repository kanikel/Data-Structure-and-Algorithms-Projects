#include<iostream>
#include<cstdlib>
#include<time.h>
#include<string>
#include <stdio.h>
using namespace std;

//Bubble sorting algorithms, repeated swapping the adjacent elements if they are in wrong order
//Bubble sorting algorithm taks 0.005~0.006s (n=1000)
template<class T>void Bubble (T a[] , int n)
{
	int i,j;
	T temp;// create intermidiate variable
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>i;j--)
		{
			if(a[j-1]>a[j]) //Move the smaller numbers forward after comparing the two adjacent numbers
			{               //Move the minimum value of the array to the forefront in the first round and the comparisons reduce each time
				temp=a[j-1];
				a[j-1]=a[j];
				a[j]=temp;
			}
		}
	}
}

//Rank sort: another method of sorting an array
//Rank sort takes about 0.008s(n=1000)
//Create an indexed array 
template<class T>void Rank(T a[],int n,int r[])
{
	for(int i=0;i<n;i++)
		r[i]=0;// Initialize r[] 
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[j]<=a[i])r[i]++;
			else r[j]++;
		}
	}
}

//Ranking 
template<class T>void Ranking (T a[] , int n,int r[])
{
	T*u=new T[n+1];//Create a new dynamic array
	for(int i=0;i<n;i++)
	u[r[i]]=a[i];
	for(int i=0;i<n;i++)
	a[i]=u[i]; 
	delete [] u;
}

//Selection sort: find the smallest number to exchange with the first number, and then find the remaining smallest number to exchange with the remaiining first number , and so on
//Selection sort takes about 0.004s(n=1000) 
template<class T>void Select(T a[],int n)
{
	int i,j,min;
	T temp;
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)//find the smallest number in i rounds 
		{
			if(a[j]<a[min])
			min=j;
		}
		if(i!=min)//exchange the values of a[i] with a[min] if i not equal to min
		{
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	    }
	}
	
}

//Insertion sort
//Insertion sort takes about 0.002s(n=1000)
template<class T>void Insertion(T a[],int n)
{
	int i,j;
	T temp;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		for(j=i-1;j>=0&&temp<a[j];j--) 
		{
			a[j+1]=a[j];
		}
		a[j+1]=temp;
	}
}

int main() //main functions for four sorting algorithms
{
	int n;
    cout<<"Please input the length of array: n(>=1000)";
	cin >>n;
	cout<<"Please select the sorting algorithms from Bubble,Ranking,Selection,Insertion";
	string str1;
	cin>>str1;
	int *p=new int[n];//Create a dynamic array 
	srand(time(NULL));
	for (int i=0;i<n;i++)
	p[i]=int(rand());//Assign random values to dynamic arrays
	double begin,end;
	if(str1=="Bubble") 
	{begin=clock();
	 Bubble(p,n);
	 end=clock();
	}

	if(str1=="Ranking")
	{
	int *r=new int[n];
	begin=clock();
	Rank(p,n,r);
	Ranking(p,n,r);
	end=clock();
    }
	if(str1=="Select")
	{
	begin=clock();
	Select(p,n);
	end=clock();
    }
	if(str1=="Insertion")
	{
	begin=clock();
	Insertion(p,n);
	end=clock();
    }
	for (int i=0;i<n;i++)//Outpu the sorted array 
	cout<<p[i]<<endl;
	cout<<"The sorting takes around"<<0.001*(double(end)-double(begin))<<"s"<<endl;
	delete []p;
	return 0;
}


