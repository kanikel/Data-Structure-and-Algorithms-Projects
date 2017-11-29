#include<iostream>
#include<cstdlib>
#include<time.h>
#include<string>
#include <stdio.h>
using namespace std;

//Bubble排序算法， 对相邻的两个数依次进行比较和调整，让较大的数往下沉，较小的往上冒
//Bubble排序需约0.005~0.006s(n=1000) 
template<class T>void Bubble (T a[] , int n)
{
	int i,j;
	T temp;//创建中间变量 
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>i;j--)
		{
			if(a[j-1]>a[j])//从后往前将相邻的两个数作比较后将较小的数字前移 
			{              //第一个循环即将数组中的最小值移到最前端之后每次皆可减少比较次数 
				temp=a[j-1];
				a[j-1]=a[j];
				a[j]=temp;
			}
		}
	}
}

//Ranking排序算法，用索引数组排序 
//Ranking排序需约0.008s(n=1000)
//创建索引数组 
template<class T>void Rank(T a[],int n,int r[])
{
	for(int i=0;i<n;i++)
		r[i]=0;//初始化r[] 
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[j]<=a[i])r[i]++;//通过数的比较，对编号的r[]进行自加 
			else r[j]++;
		}
	}
}

//Ranking 
template<class T>void Ranking (T a[] , int n,int r[])
{
	T*u=new T[n+1];//创建一个新的动态数组 
	for(int i=0;i<n;i++)//以r[]的数值为u[]的编号，赋予对应的a[]值 
	u[r[i]]=a[i];
	for(int i=0;i<n;i++)
	a[i]=u[i];//再将u[]的赋予对应a[] 
	delete [] u;
}

//Select排序算法，找出最小的数与第一个数交换，再在剩下的数中找出最小的数与剩下数的第一个交换以此类推 
//Select排序需约0.004s(n=1000) 
template<class T>void Select(T a[],int n)
{
	int i,j,min;
	T temp;
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)//找出此次i循环中最小的数 
		{
			if(a[j]<a[min])
			min=j;
		}
		if(i!=min)//若此次i循环中，i与min不等则交换a[i]与a[min]的值 
		{
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	    }
	}
	
}

//Insertion排序算法，将数进行比较后根据大小插入数组中 
//Insertion排序需约0.002s(n=1000)
template<class T>void Insertion(T a[],int n)
{
	int i,j;
	T temp;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		for(j=i-1;j>=0&&temp<a[j];j--)//循环并比较数值后将两个数值交换实现插入 
		{
			a[j+1]=a[j];
		}
		a[j+1]=temp;
	}
}

int main()
{
	int n;
    cout<<"请输入数组长度n(大于等于1000)";
	cin >>n;
	cout<<"请从Bubble,Ranking,Select,Insertion中选择排序算法(输入排序算法的名称如Bubble)";
	string str1;
	cin>>str1;
	int *p=new int[n];//创建动态数组 
	srand(time(NULL));
	for (int i=0;i<n;i++)
	p[i]=int(rand());//为动态数组赋随机值 
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
	for (int i=0;i<n;i++)//输出排序后的数组 
	cout<<p[i]<<endl;
	cout<<"排序所需时间约为"<<0.001*(double(end)-double(begin))<<"s"<<endl;
	delete []p;//清除
	return 0;
}


