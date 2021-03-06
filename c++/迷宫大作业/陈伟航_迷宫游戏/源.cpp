//这是一个迷宫游戏
#include<iostream>
#include<ctime>
#include<cstdlib>/*用于生成随机数，形成随机变化的迷宫*/
#include<iomanip>/*用于输出格式控制，使得生成的迷宫外观规则*/
using namespace std;
/*生成迷宫的函数mazegenerator*/
char*mazegenerator(int m,int n)
{
	int i,j,k;/*计数器*/
	char *p=new char[m*n];/*用长度为m*n的数组存放mxn大小的迷宫*/
	srand(int(time(0)));/*用于生成随机数*/
	if(m<10||n<10)//阶数小的时候密一点，增加趣味
		for(i=0;i<m*n;i++)
		{
			if(rand()%3==0)p[i]='.';//随机数为三的倍数时，把迷宫中该点定义为通路
			else p[i]='#';
		}
	else
		for(i=0;i<m*n;i++)
		{
			if(rand()%2==0)p[i]='.';/*随机数为偶数时，把迷宫中该点定义为通路*/
			else p[i]='#';
		}
	/*把左边界和上边界全部封住，只留一个入口，只能从右边界和下边界走出，
	让走出迷宫更有挑战性*/
	for(i=0;i<m;i++)
		p[i]='#';
	for(i=0;i<m*n;i+=m)
		p[i]='#';
	for(i=m-1;i<m*n;i+=m)
		p[i]='#';
	for(i=m*(n-1);i<m*n;i++)
		p[i]='#';
	/*接下来把前3阶构造为T字型*/
	p[0]=p[1]=p[2]=p[2*m]=p[2*m+2]='#';
	p[m+1]=p[m+2]=p[2*m+1]='.';
	/*迷宫入口定义为'x'*/
	p[m]='x';
	/*迷宫是随机的，需要构造一条通路*/
	/*这是一条每三格转一次的通路*/
	for(j=3;j<m;j+=3)
	{
		for(k=0;k<3;k++)
		{
			i=(j-3)+k+1;
			if(i*m+j<m*n)
				p[i*m+j]='.';
		}
	}
	for(i=4;i<m;i+=3)
		for(k=0;k<3;k++)
		{
			j=(i-3)+k+2;
			if(i*m+j<m*n)
				p[i*m+j]='.';
		}
	
	return p;
}
/*生成或修改迷宫后都需要输出新的迷宫*/
void showmaze(char*p,int m,int n)
{
	int i,j;/*i代表行，j代表列，i*n+j是那个点在数组中的序号*/
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			cout<<setw(2)<<p[i*m+j];/*每个字符占两个使得迷宫方正*/
		cout<<endl;
	}
}
/*走迷宫函数mazetraverse*/
void mazetraverse(char*p,int m,int n)
{
	int x,y,z;/*y是当前位置，x是前一步，z是后一步，t用于输入继续走迷宫的指令*/
	/*初始化x,y,即迷宫入口的位置*/
	x=m;
	y=m+1;
	p[y]='x';/*这是迷宫的第一步*/
	cout<<"请按回车键移动:";/*让用户控制走迷宫的进程*/
	cin.get();
	cout<<endl;
	showmaze(p,m,n);/*输出走后的迷宫*/
	cout<<endl;
	cout<<"请按回车键移动: ";
	cin.get();
	/*关键在于用x,y确定z的值*/
	while(!((y>m*(n-1))||(((y+1)%m)==0)))/*到达边界之前执行循环走迷宫*/
	{
		/*判断右的方向，如果右为'.',则向右走*/
		if(y-x==1)z=y+m;
		if(y-x==m)z=y-1;
		if(y-x==-m)z=y+1;
		if(y-x==-1)z=y-m;
		/*右不为'.'时，向y的前方走*/
		if(p[z]=='#')
		{
			/*判断y的前方，如果前为'.',则向前走*/
			if(y-x==1)z=y+1;
			if(y-x==m)z=y+m;
			if(y-x==-m)z=y-m;
			if(y-x==-1)z=y-1;
			/*如果前方为'#'，要向左走*/
			if(p[z]=='#')
			{
				/*判断左的位置*/
				if(y-x==1)z=y-m;
				if(y-x==m)z=y+1;
				if(y-x==-m)z=y-1;
				if(y-x==-1)z=y+m;
				/*如果左为'#'，为死路，需要向后走*/
				if(p[z]=='#')z=x;
			}
		}
		p[z]='x';/*最后都要让z的位置为'x',表示走过的痕迹*/
		showmaze(p,m,n);
		cout<<endl;
		cout<<"请按回车键移动: ";
		cin.get();
		cout<<endl;
		/*替换x,y实现当前位置的移动*/
		x=y;
		y=z;
	}
}
int main()
{
	int m,n;/*n是迷宫的阶数，由于输出窗口大小的限制，
		  n不能大于每行所能显示的字符个数*/
	cout<<"     陈伟航的迷宫游戏\n我的迷宫可是很整洁的哦！^_^\n"<<endl;
	cout<<"这是一个可任意选择大小的迷宫,"<<endl;
	cout<<"每次生成的迷宫都不同。\n"<<endl;
	cout<<"因为屏幕一次最多显示80个字符，\n这里每个字符又占两格，"<<endl
		<<"所以输入超过40阶就不好看啦，\n虽然它还是对的。哈哈\n"<<endl;
	cout<<"请依次输入迷宫的宽度m和高度n(m>2,n>2):"<<endl;
	/*可以进行多组数据的测试*/
	while(cin>>m>>n)
	{
		char*a=mazegenerator(m,n);
		showmaze(a,m,n);
		cout<<endl;
		cout<<"万里长征第一步：\n"<<endl;
		mazetraverse(a,m,n);
		cout<<"恭喜你！你已成功走出迷宫！"<<endl<<endl;
		cout<<"如要尝试新的迷宫，请依次输入迷宫的宽度m和高度n(m>2,n>2):\n否则，按ctrl+z，再按enter结束"<<endl;
	}
}