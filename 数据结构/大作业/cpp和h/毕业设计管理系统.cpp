// ��ҵ��ƹ���ϵͳ.cpp: ����Ŀ�ļ���

#include "stdafx.h"
#include"mainform.h"

using namespace ��ҵ��ƹ���ϵͳ;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// �ڴ����κοؼ�֮ǰ���� Windows XP ���ӻ�Ч��
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// ���������ڲ�������
	Application::Run(gcnew mainform());
	return 0;
}
