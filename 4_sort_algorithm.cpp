#include<iostream>
#include<cstdlib>
#include<time.h>
#include<string>
#include <stdio.h>
using namespace std;

//Bubble�����㷨�� �����ڵ����������ν��бȽϺ͵������ýϴ�������³�����С������ð
//Bubble������Լ0.005~0.006s(n=1000) 
template<class T>void Bubble (T a[] , int n)
{
	int i,j;
	T temp;//�����м���� 
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>i;j--)
		{
			if(a[j-1]>a[j])//�Ӻ���ǰ�����ڵ����������ȽϺ󽫽�С������ǰ�� 
			{              //��һ��ѭ�����������е���Сֵ�Ƶ���ǰ��֮��ÿ�νԿɼ��ٱȽϴ��� 
				temp=a[j-1];
				a[j-1]=a[j];
				a[j]=temp;
			}
		}
	}
}

//Ranking�����㷨���������������� 
//Ranking������Լ0.008s(n=1000)
//������������ 
template<class T>void Rank(T a[],int n,int r[])
{
	for(int i=0;i<n;i++)
		r[i]=0;//��ʼ��r[] 
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[j]<=a[i])r[i]++;//ͨ�����ıȽϣ��Ա�ŵ�r[]�����Լ� 
			else r[j]++;
		}
	}
}

//Ranking 
template<class T>void Ranking (T a[] , int n,int r[])
{
	T*u=new T[n+1];//����һ���µĶ�̬���� 
	for(int i=0;i<n;i++)//��r[]����ֵΪu[]�ı�ţ������Ӧ��a[]ֵ 
	u[r[i]]=a[i];
	for(int i=0;i<n;i++)
	a[i]=u[i];//�ٽ�u[]�ĸ����Ӧa[] 
	delete [] u;
}

//Select�����㷨���ҳ���С�������һ��������������ʣ�µ������ҳ���С������ʣ�����ĵ�һ�������Դ����� 
//Select������Լ0.004s(n=1000) 
template<class T>void Select(T a[],int n)
{
	int i,j,min;
	T temp;
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)//�ҳ��˴�iѭ������С���� 
		{
			if(a[j]<a[min])
			min=j;
		}
		if(i!=min)//���˴�iѭ���У�i��min�����򽻻�a[i]��a[min]��ֵ 
		{
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	    }
	}
	
}

//Insertion�����㷨���������бȽϺ���ݴ�С���������� 
//Insertion������Լ0.002s(n=1000)
template<class T>void Insertion(T a[],int n)
{
	int i,j;
	T temp;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		for(j=i-1;j>=0&&temp<a[j];j--)//ѭ�����Ƚ���ֵ��������ֵ����ʵ�ֲ��� 
		{
			a[j+1]=a[j];
		}
		a[j+1]=temp;
	}
}

int main()
{
	int n;
    cout<<"���������鳤��n(���ڵ���1000)";
	cin >>n;
	cout<<"���Bubble,Ranking,Select,Insertion��ѡ�������㷨(���������㷨��������Bubble)";
	string str1;
	cin>>str1;
	int *p=new int[n];//������̬���� 
	srand(time(NULL));
	for (int i=0;i<n;i++)
	p[i]=int(rand());//Ϊ��̬���鸳���ֵ 
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
	for (int i=0;i<n;i++)//������������� 
	cout<<p[i]<<endl;
	cout<<"��������ʱ��ԼΪ"<<0.001*(double(end)-double(begin))<<"s"<<endl;
	delete []p;//���
	return 0;
}


