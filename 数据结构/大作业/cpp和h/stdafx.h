// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
#pragma once

// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include"leidef.h"
#include"function.h"
#include<fstream>
#include"Articleinfo.h"
#include"Form2.h"
#include"collection.h"
#include "StuForm.h"

#include"mark.h"
#include "TecForm.h"
#include"manageForm.h"
#include"regForm.h"
#include"login.h"


int stunum;//ѧ������
int tecnum;//��ʦ����
int arcnum;//��������
int repnum;//�ٱ�����
int manum;//����Ա����
int usertype;//�û�����
char username[50];//�û���
Student globalstu;//ѧ��
Teacher globaltec;//��ʦ
Manager globalman;//����Ա
Article globalart;//����
LList<Student>stulist;
LList<Teacher>teclist;
LList<Manager>manlist;
LList<Record>replist;
LList<Article>artlist;
LList<Article>artfromsj[6];//���ǰ�רҵ����������Դ�����е�ÿ��Ҳ��רҵ���ҵĽ��
LList<Student>stuidindex[10];//ѧ��ID����Դ����������ǵ�����¼
LList<Article>artidindex[10];//����ID����Դ����������ǵ�����¼
LList<Article>artmarkindex[5];//���·�������Դ
LList<Article>artfrommark;//���·������ҽ��
LList<Article>artfromname;//��ʦ�������ҽ��
LList<Article>finalartresult;
LList<Student>checkstulist;
