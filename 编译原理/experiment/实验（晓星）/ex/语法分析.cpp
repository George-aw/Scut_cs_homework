#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<cstring>
#include<string>
#include <list>
#include <cstdlib> 
#include <sstream>  
#include <cstdio>  

using namespace std;

//Token�ṹ����
class Token{
public:
   string key;
   string value;
};

//Token�ؼ����б�
Token tokenlist[36];

//��ʼ��Token�ؼ����б�
void tokenlist_initial()
{
	tokenlist[0].key="TK_TRUE";       tokenlist[0].value="true";
	tokenlist[1].key="TK_FALSE";      tokenlist[1].value="false";
	tokenlist[2].key="TK_OR";         tokenlist[2].value="or";
	tokenlist[3].key="TK_AND";        tokenlist[3].value="and";
	tokenlist[4].key="TK_NOT";        tokenlist[4].value="not";
	tokenlist[5].key="TK_INT";        tokenlist[5].value="int";
	tokenlist[6].key="TK_BOOL";       tokenlist[6].value="bool";
	tokenlist[7].key="TK_STRING";     tokenlist[7].value="string";
	tokenlist[8].key="TK_WHILE";      tokenlist[8].value="while";
	tokenlist[9].key="TK_DO";         tokenlist[9].value="do";
	tokenlist[10].key="TK_IF";        tokenlist[10].value="if";
	tokenlist[11].key="TK_THEN";      tokenlist[11].value="then";
	tokenlist[12].key="TK_ELSE";      tokenlist[12].value="else";
	tokenlist[13].key="TK_END";       tokenlist[13].value="end";
	tokenlist[14].key="TK_REPEAT";    tokenlist[14].value="repeat";
	tokenlist[15].key="TK_UNTIL";     tokenlist[15].value="until";
	tokenlist[16].key="TK_READ";      tokenlist[16].value="read";
	tokenlist[17].key="TK_WRITE";     tokenlist[17].value="write";
	tokenlist[18].key="TK_COMMA";     tokenlist[18].value=",";
	tokenlist[19].key="TK_SEMICOLON"; tokenlist[19].value=";";
	tokenlist[20].key="TK_ADD";       tokenlist[20].value="+";
	tokenlist[21].key="TK_SUB";       tokenlist[21].value="-";
	tokenlist[22].key="TK_MUL";       tokenlist[22].value="*";
	tokenlist[23].key="TK_DIV";       tokenlist[23].value="/";
	tokenlist[24].key="TK_LP";        tokenlist[24].value="(";
	tokenlist[25].key="TK_RP";        tokenlist[25].value=")";
	tokenlist[26].key="TK_GTR";       tokenlist[26].value=">";
	tokenlist[27].key="TK_LSS";       tokenlist[27].value="<";
	tokenlist[28].key="TK_EQU";       tokenlist[28].value="=";
	tokenlist[29].key="TK_LEQ";       tokenlist[29].value="<=";
	tokenlist[30].key="TK_GEQ";       tokenlist[30].value=">=";
	tokenlist[31].key="TK_ASSIGN";    tokenlist[31].value=":=";
	tokenlist[32].key="ID";           tokenlist[32].value="";
	tokenlist[33].key="NUM";          tokenlist[33].value="";
	tokenlist[34].key="STRING";       tokenlist[34].value="";
	tokenlist[35].key="TK_HEX";       tokenlist[35].value="";
	
}



//��������list������
//�ֱ�洢�ʷ��������Token�ʹ�����Ϣ
list<Token> TokenList;
list<string> ErrorList;

          /***********��������*********/
/********�ʷ���������*****/
//�ж��Ƿ��Ƿָ���
int roll(char s);      
//�ж��ַ�������
bool Judge(string s,string substr,list<Token> &TokenList,int &flag);

/********�﷨��������*****/
int LABEL = 0 ;                       //��ǩ��
int TEMPNUM = 0;                      //����ʱ�õı�����
const string TEMP_CONST = "temp";     //�����̶�ǰ׺

//����Label
int newLabel()
{
	return LABEL++;
}


//������ת��ΪString
string newTEMP()
{    
	ostringstream ss;
    ss<<TEMP_CONST<<TEMPNUM;
	TEMPNUM++;
	return ss.str();
}

//�߼���֤����
bool E_judge(int labeltrue,int labelfalse);
//������ʽ���ձ�������
string rigth_factor();
//�ж��Ƿ������������
bool iscomputeOP(string key);
//ʶ����亯��
bool stmt(int nextLabel);
//������亯��
bool declaration();
//ƥ�����ź���
string parentheses();
//��д��亯��
bool readANDwrite();        


/********����������*****/
/*
�����������ӿ���̨�������
�ʾ��������ò��֡�
*/
//���ʷ�����֮��Ľ�������ļ���
void savetotxt(list<Token> TokenList,list<string> ErrorList)
{
	ofstream outstuf;	
	outstuf.open("d:\\out.txt",ios::out);

	int i=1;
	//д��ʷ�
	for(;TokenList.size()!=0;i++)
	{
		Token tokenlist=TokenList.front();
		TokenList.pop_front();

		outstuf<<"("<<tokenlist.key<<","<<tokenlist.value<<")"<<'\t';
		if(i%4==0)
			outstuf<<'\n';
	}

	outstuf<<'\n'<<'\n';
	//д�������Ϣ
	for(;ErrorList.size()!=0;)
	{
		outstuf<<ErrorList.front();
		ErrorList.pop_front();
	}

	outstuf.close();

}


//����������
int main()
{
	/********�ʷ���������*****/

	//��ʼ��Token�ؼ����б�
	tokenlist_initial();
	//�����ݴ��ı����������
	char s[80];
	ifstream instuf;

	//���ļ��ж�����Ҫ�����Ĵ���
	instuf.open("d:\\experiment2_test1_in.txt",ios::in);  //�Զ��ķ�ʽ�򿪴�����Ϣ�ļ�
//	instuf.open("d:\\experiment2_test2_in.txt",ios::in);  //�Զ��ķ�ʽ�򿪴�����Ϣ�ļ�
	
	int flag=0;    //��¼�к�
	
	while(instuf.getline(s,80))
	{
		flag++;             //�к�+1
		string substr="";
		int i=0;
		int length=strlen(s);
	
		while(i<length)
		{
			if(i==length-1||roll(s[i])!=0)//roll �ж��Ƿ��ǹ�Լ�ַ�
			{ 
				//���һ���ַ����������ж�
				if(i==length-1&&roll(s[i])==0)
					substr+=s[i];
				if( roll(s[i])==2&&substr=="")     //�ж��ս��
					substr+=s[i];
				else if(roll(s[i])==2&&substr!="")
					i--;
				else if(roll(s[i])==1&&substr=="")			
				    {i++;continue;}


				if(Judge(s,substr,TokenList,i)==false)
				{
					string error;
					char sflag[20];
					itoa(flag,sflag, 10); //���һ�������ǽ�����ת�������ֽ���
					error.append("line "+(string)sflag+"��"+substr+"��error��\n");
					cout<<error;
					ErrorList.push_back(error);
					substr="";
				}
                substr="";
				i++;
			}
			
			else
			{
				substr+=s[i++];
			}
		}
	}
	instuf.close();

    //������ִʷ�����ֱ�ӷ��أ����ٽ����﷨����
	if(ErrorList.size()>0)
		return 0;

	//�����ļ���
	//savetotxt(TokenList,ErrorList);

	/********�﷨��������*****/
	while(TokenList.size() !=0)
	{
		stmt(-1);        //�����﷨����
	}
}



              /*********���庯������****/

/********�ʷ���������*****/

//�ж��Ƿ��Ƿָ���
int roll(char s)
{
	if(s==' '||s=='\t'||s=='\n')
		return 1;
	for(int i=18;i<=31;i++)
		if(s==tokenlist[i].value[0])
			return 2;
	return 0;
}

//�ж��ַ�������
bool Judge(string s,string substr,list<Token> &TokenList,int &flag)
{
	int i=0;
	for(;i<=25;i++)
		if(substr.compare(tokenlist[i].value)==0)   //�жϳ�������
		{
			TokenList.push_back(tokenlist[i]);   //����List
			return true;
		}

	string sflag;
	if(s[flag+1]=='=')
		{
			sflag=substr+s[flag+1];
			for(i=29;i<=31;i++)
				if(sflag.compare(tokenlist[i].value)==0)   //�ж�˫���������
				{
					TokenList.push_back(tokenlist[i]);   //����List
					flag++ ;
					return true;
				}
	}
	else
		{
			sflag=substr;
			for(i=26;i<=28;i++)
				if(sflag.compare(tokenlist[i].value)==0)   //�ж�˫���������
				{
					TokenList.push_back(tokenlist[i]);   //����List
					return true;
				}
	}


	//�ж��Ƿ�������
	for(i=0;i<substr.length();)
	{
		if(substr[i]>='0'&&substr[i]<='9')
			i++;
		else
			break;
	}
	if(i==substr.length())
	{
		tokenlist[33].value=substr;
		TokenList.push_back(tokenlist[33]);   //����List
		return true;
	}

	//�ж��Ƿ���ʮ��������
	if(substr[0]=='0'&&(substr[1]=='x'||substr[1]=='X'))
	{
		//�ж��Ƿ���ʮ����������
		for(i=2;i<substr.length();)
		{
			if((substr[i]>='0'&&substr[i]<='9')||
			   (substr[i]>='a'&&substr[i]<='f')||
			   (substr[i]>='A'&&substr[i]<='F'))
				i++;
			else
				break;
	     }
		if(i==substr.length())
		{
			tokenlist[35].value=substr;
			TokenList.push_back(tokenlist[35]);   //����List
			return true;
		}
	}

	//�ж��Ƿ��Ǳ�ʶ��
	for(i=0;i<substr.length();)
	{
		if((substr[i]>='0'&&substr[i]<='9')||
		   (substr[i]>='a'&&substr[i]<='z')||
		   (substr[i]>='A'&&substr[i]<='Z'))
			i++;
		else
			break;
	}
	if(i==substr.length())
	{
		tokenlist[32].value=substr;
		TokenList.push_back(tokenlist[32]);   //����List
		return true;
	}


	//�ж��Ƿ����ַ���
	if(substr[0]=='\'')
	{
		for(i=substr.length()-1;substr[i]!='\''&&i<s.length()-flag;i++)
			substr+=s[flag++];
		if(substr[substr.length()-1]=='\'')
		{
			tokenlist[34].value=substr;
			TokenList.push_back(tokenlist[34]);   //����List
			flag++;
			return true;
		}
	}

	//�ж��Ƿ���ע��
	if(substr[0]=='{')
	{
		for(i=substr.length()-1;substr[i]!='}'&&i<s.length();i++)
			substr+=s[flag++];
		if(substr[substr.length()-1]=='}')
		{
			return true;
		}
	}

	//����
	return false;

}


              /********�﷨��������*****/
//�ж��Ƿ��������
bool iscomputeOP(string key)
{
	bool flag = false;
	for(int i = 20 ;i <= 23 ;i++)
	{
		if(key.compare(tokenlist[i].key ) == 0) 
		{
			flag = true;
			break;
		}
	}
	return flag;
}

//����ƥ�亯��
//��鵽��һ��������ʱ���ã����������pop�� �������ı���
string parentheses()
{
	if(TokenList.front().value == "(" ) //ɾ��������
		TokenList.pop_front();

     string lasttemp = rigth_factor();  //��¼�����б��ʽ
	 
	 if(TokenList.front().value == ")" )//ɾ��������
        TokenList.pop_front();
	 else
	  {
		  cout<<"�ҵģ��أ����ң�"<<endl;
          exit(0);
	  }
	 
	 return lasttemp; 
}

//������ʽ���ձ���
string rigth_factor()
{  
	Token i = TokenList.front();
	string lastTEMP;

	if(i.key == "ID"|i.key == "NUM" )
	{
	  lastTEMP=i.value ;
      TokenList.pop_front();
	}
	else if(i.value=="(")         //������
	{
		lastTEMP = parentheses();
	}
    
	string text;                  //��¼����������

	//���������
	while(TokenList.size()>0 &&iscomputeOP(TokenList.front().key))
	{
		i = TokenList.front();
		TokenList.pop_front();
		Token j = TokenList.front();
        string newtemp = newTEMP();
		string exp;                //������
		if(j.value=="(")
		{ 
			exp = parentheses();
		}
		else if(j.key == "ID"|j.key == "NUM")
		{
			exp = j.value;
		    TokenList.pop_front();
		}
		else 
		{
			cout<<"���ʽ����"<<lastTEMP<<"������ַǷ�����"<<endl;
			exit(0);
		}

	   cout<<newtemp <<" := "<< lastTEMP <<i.value <<exp<<endl;

       lastTEMP = newtemp;
	}
    return lastTEMP;
}


//��������������;��
bool declaration()
{
	while (TokenList.front().value != ";" )
	{
		TokenList.pop_front();
	}
    
	TokenList.pop_front();    //�ѷֺ�Ҳɾ��

	return true;
}


//��д��ֵ���
bool readANDwrite()
{    
	string text = TokenList.front().value;
	TokenList.pop_front();       //ȥ��read | write
    Token c;

	while(TokenList.size() > 0 &&(c=TokenList.front()).value!= ";")
	{
		if(c.value == ",")
		{
			TokenList.pop_front();//������� ","
			continue;
		}
		else if(c.key == "ID" )
		{
			TokenList.pop_front();
			cout<<text<<" "<<c.value<<endl;
		}
		else 
		{
			break;//�������˵��ˣ����ű��
		}
	}

	return true;
}

//�߼���֤����
bool E_judge(int labeltrue,int labelfalse)
{   
	string text="";      //�洢��������Ϣ
    int label1;
	int label2;

	Token i = TokenList.front();    //����Token

	if (i.key == "ID"|i.key=="NUM") // ��һ���ַ���id
	{
		TokenList.pop_front();
		text += i.value;
	}
	else if(i.value== "(" )     //��һ���ַ��ǡ�����
	{
		text += parentheses();
	}
     else if(i.key == "TK_NOT") //��һ���ַ��� not 
	 { 
		text += i.value;
		i = TokenList.front();
       	TokenList.pop_front();
	}
	//PART ONE OVER  �Ѿ����߼�������ߵĸ��

	/******��ʼ��֤�߼������******/
	Token j = TokenList.front();
    TokenList.pop_front();

	bool flag = false;
    for(int k = 26;k <= 30 ; k ++)   //�жϷ���
	{
		if(j.key ==tokenlist[k].key ) 
		{
			flag = true ;
			break;
		}
	}

	//�������ȷ��ֱ���˳�
	if (!flag )
		exit(1);

	text += j.value;

   /******��֤�߼����������******/


	j = TokenList.front();

        
	/*****������ұߵ�*****/
	if (j.key == "ID"|j.key=="NUM") // ��һ���ַ���id������
	{
		TokenList.pop_front();
		text += j.value;
	}
	else if(j.value== "(" )        //��һ���ַ��� ��
	{
		text += parentheses();
	}
	else
	{
          return false;
	} 


	if(TokenList.size() == 0 )
	{
		label1 = labeltrue;
		label2 = labelfalse;
        cout<<"if "<<text <<" GOTO  Label "<<label1<<endl<<"GOTO Label "<<label2<<endl;
	    return true;
	}

    /***************if֮��********************/
	if ((j=TokenList.front()).value == "and")
	{
		TokenList.pop_front();
		label1 = newLabel();
		label2 = labelfalse;
		cout<<"if "<<text <<" GOTO  Label "<<label1<<endl<<"GOTO Label "<<label2<<endl;
		cout<<"Label "<<label1<<endl;

	    return E_judge(labeltrue , labelfalse);   //�ݹ�
	}
	else if((j=TokenList.front()).value == "or")
	{
		TokenList.pop_front();
        label1 = labeltrue;
		label2 = newLabel();
	 			
		cout<<"if "<<text <<" GOTO  Label "<<label1<<endl<<"GOTO Label "<<label2<<endl;
		cout<<"Label "<<label2<<endl;
		return E_judge(labeltrue , labelfalse);
	}
	else 
	{
		label1 = labeltrue;
		label2 =labelfalse;
       	cout<<"if "<<text <<" GOTO  Label "<<label1<<endl<<"GOTO Label "<<label2<<endl;
		return true;
	}
	
	return false;

}



bool stmt(int nextLabel)
{
    Token current = TokenList.front();

/*	if-stmt -> if  logical-or-exp then stmt-sequence [else stmt-sequence] end*/
	if( current.key=="TK_IF" )
	{
		TokenList.pop_front();
		int labeltrue;
		int labelfalse;
        int labelend;

		labeltrue  = newLabel();
        labelfalse = newLabel();
        labelend   = newLabel();

		E_judge(labeltrue,labelfalse);

		if(TokenList.size() > 0&&
		   TokenList.front().key == "TK_THEN")
		   TokenList.pop_front();
          cout<<"Label "<<labeltrue<<endl;

		  while(TokenList.size() > 0&&
			    TokenList.front().key!="TK_END"&&
			    TokenList.front().key!="TK_ELSE")//STMT - SEQUENCE
		  {
		      stmt(-1);
		  }
		 

		if(TokenList.size() > 0&&TokenList.front().key == "TK_ELSE")//��else 
		{   
			cout<<"GOTO Label "<<labelend<<endl;//����then, ȥ��β
            cout<<"Label "<< labelfalse<<endl;

			TokenList.pop_front();			
			
		    while(TokenList.front().key!="TK_END")//STMT - SEQUENCE
		    {
			   stmt(-1);
		    }

			TokenList.pop_front();
            cout<<"Label "<<labelend<<endl;
		}
		else //û��else
		{
             cout<<"Label "<<labelfalse<<endl;
			 if(TokenList.size() > 0) 
			    TokenList.pop_front();
			 else
			 {
				 cout<<"end �����"<<endl;
			 }
		}		
	}

	else if(current.key=="ID")//ASSIGN STSM
	{   
		string text = current.value;
		TokenList.pop_front();
		Token i = TokenList.front();

		if( i.key =="TK_ASSIGN"){ 
			text += i.value;
			TokenList.pop_front();
		}
		else {
			cout<<"��ֵ������"<<endl;
			exit(0);
		}//error

		text+=rigth_factor();
		cout<<text<<endl;
		if(TokenList.size() > 0 && TokenList.front().value == ";")//�����ֺ�
			TokenList.pop_front();
	}

/*	while-stmt -> while logical-or-exp do stmt-sequence end*/
	else if (current.key=="TK_WHILE")
	{
         TokenList.pop_front();
		 int labelbegin;
		 int labeldo;
		 int labelend;

		 labelbegin = newLabel();
		 labeldo    = newLabel();
		 labelend   = newLabel();

        
         cout<<"Label "<<labelbegin<<endl;//��ʼ���
		 E_judge(labeldo,labelend);//�߼�����
         cout<<"Label "<<labeldo<<endl;//ѭ���忪ʼ���

		 if(TokenList.front().key == "TK_DO")//ȥ��do
		 {
			 TokenList.pop_front();
		 }
		 else                        //û��do ��ô�У�
		 {
			  cout<<"��ôû��do �ģ�"<<endl;
			  exit(1);
			
		 }

		   while(TokenList.front().key!="TK_END")//STMT - SEQUENCE
		  {
		      stmt(-1);
		  }

		   if(TokenList.front().key == "TK_END")//ȥ��END
			   TokenList.pop_front();

		   cout<<"GOTO Label "<<labelbegin<<endl; //�ص���ʼ���ٴν����ж�
		
	     cout<<"Label "<<labelend<<endl;        //��β��ʶ
	}

	/*	repeat-stmt	-> repeat stmt-sequence until logical-or-exp*/
	else if (current.key=="TK_REPEAT")
	{
         TokenList.pop_front();
		 int labelbegin;
		 int labelend;

		 labelbegin = newLabel();
		 labelend   = newLabel();

         cout<<"Label "<<labelbegin<<endl;
		 
		 while(TokenList.front().key!="TK_UNTIL")//STMT - SEQUENCE
		  {
		      stmt(-1);
		  }

		   if(TokenList.front().key=="TK_UNTIL"){//ȥ�� until
			   TokenList.pop_front();
		   }
		   else {
			   cout<<"��ôû��until �ģ���"<<endl;
			   return false;
		   }

		 E_judge(labelend,labelbegin);

	     cout<<"Label "<<labelend<<endl;

	}
	else if (current.key=="TK_INT"|current.key=="TK_STRING"|current.key=="TK_BOOL")
	{
		declaration(); // ����ֵ���
	}
	else if (current.key =="TK_READ"|current.key == "TK_WRITE")
	{
          readANDwrite();

	}
	else //������
	{
		cout<<"�����޷�ʶ��ı�ʶ"<<current.value<<endl;
		cout<<"���ӽṹ�����˳�"<<endl;
		exit(0);
	}

	if( nextLabel!= -1 )
		cout<<"GOTO Label "<< nextLabel<<endl;

	if(TokenList.size() >0 &&TokenList.front().value == ";")//�����ֺ�
			TokenList.pop_front();

	return true;
}


