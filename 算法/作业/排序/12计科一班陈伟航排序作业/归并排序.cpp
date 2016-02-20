#include<iostream>
#include<cmath>
#include<ctime>
#include<fstream>
using namespace std;
//�鲢����
void mergesort(int*p,int*temp,int left, int right)
{
  	int mid=(left+right)/2;
  	if (left==right) return;
	//����ߵ����н��й鲢����
  	mergesort(p, temp, left, mid);
	//���ұߵ����н��й鲢����
  	mergesort(p, temp, mid+1, right);
	//�ϲ�����������������
	for (int i=left;i<=right;i++) //����ԭ����
    		temp[i]=p[i];
  	int i1=left,i2=mid+1;
  	for (int curr=left; curr<=right; curr++)
	{
    		if (i1 == mid+1)//��ߵ������Ѿ����ŵ�������
				p[curr] = temp[i2++];
    		else if(i2>right)//�ұߵ������Ѿ����ŵ�������
				p[curr] = temp[i1++];
    		else if (temp[i1] < temp[i2])
				p[curr] = temp[i1++];
    		else p[curr] = temp[i2++];
	}
}

int main()
{
	fstream f;//�����Զ�д�ļ������ü�¼���ݡ���
	f.open("d:\\�鲢����.txt",ios::out);
	f<<"���ݸ���	\t����ʱ��\n";
	srand(int(time(0)));
	for(int n=0;n<9;n++)
	{
		int base=(int)pow(10.0,n);
		for(int m=1;m<10;m++)
		{
			int length=m*base;
			if(length>100000000)return 0;//����һ�ڻ��ڴ治��
			f<<length<<"\t\t";
			cout<<"���ݸ�����"<<length<<"\t";
			int*p=new int[length];
			for(int i=0;i<length;i++){p[i]=rand();}
			//p[i]��ֵ��0��32767
				//���Բ鿴���������������
				//cout<<p[i]<<" ";
			
			//cout<<endl;
			int*tmp=new int[length];
			clock_t t1=clock();
			mergesort(p,tmp,0,length-1);
			clock_t t2=clock();
			f<<(double)(t2-t1)/CLOCKS_PER_SEC<<"��"<<endl;
			cout<<(double)(t2-t1)/CLOCKS_PER_SEC<<"��"<<endl;
			cout<<endl;
			delete p;
			delete tmp;
			f<<endl;
		}		
	}
	f.close();
}