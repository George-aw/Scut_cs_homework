#pragma once


namespace ��ҵ��ƹ���ϵͳ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// mainform ժҪ
	/// </summary>
	public ref class mainform : public System::Windows::Forms::Form
	{
	public:
		mainform(void)
		{
			InitializeComponent();
			//
			//TODO: �ڴ˴���ӹ��캯������
			//
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~mainform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::NotifyIcon^  notifyIcon1;
	protected: 
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ��ʾ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �˳�����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �˳�����ToolStripMenuItem1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// ����������������
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(mainform::typeid));
			this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->��ʾ����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�˳�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�˳�����ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// notifyIcon1
			// 
			this->notifyIcon1->ContextMenuStrip = this->contextMenuStrip1;
			this->notifyIcon1->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"notifyIcon1.Icon")));
			this->notifyIcon1->Text = L"notifyIcon1";
			this->notifyIcon1->Visible = true;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->��ʾ����ToolStripMenuItem, 
				this->�˳�����ToolStripMenuItem, this->�˳�����ToolStripMenuItem1});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(125, 70);
			// 
			// ��ʾ����ToolStripMenuItem
			// 
			this->��ʾ����ToolStripMenuItem->Name = L"��ʾ����ToolStripMenuItem";
			this->��ʾ����ToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->��ʾ����ToolStripMenuItem->Text = L"���µ�¼";
			this->��ʾ����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainform::��ʾ����ToolStripMenuItem_Click);
			// 
			// �˳�����ToolStripMenuItem
			// 
			this->�˳�����ToolStripMenuItem->Name = L"�˳�����ToolStripMenuItem";
			this->�˳�����ToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->�˳�����ToolStripMenuItem->Text = L"��������";
			this->�˳�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &mainform::�˳�����ToolStripMenuItem_Click);
			// 
			// �˳�����ToolStripMenuItem1
			// 
			this->�˳�����ToolStripMenuItem1->Name = L"�˳�����ToolStripMenuItem1";
			this->�˳�����ToolStripMenuItem1->Size = System::Drawing::Size(124, 22);
			this->�˳�����ToolStripMenuItem1->Text = L"�˳�����";
			this->�˳�����ToolStripMenuItem1->Click += gcnew System::EventHandler(this, &mainform::�˳�����ToolStripMenuItem1_Click);
			// 
			// mainform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 136);
			this->ContextMenuStrip = this->contextMenuStrip1;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"mainform";
			this->Text = L"mainform";
			this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
			this->Load += gcnew System::EventHandler(this, &mainform::mainform_Load);
			this->contextMenuStrip1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void mainform_Load(System::Object^  sender, System::EventArgs^  e) {
				 extern int stunum;
				 extern int tecnum;
				 extern int arcnum;
				 extern int repnum;
				 extern int manum;
				 extern LList<Student>stulist;
				 extern LList<Teacher>teclist;
				 extern LList<Manager>manlist;
				 extern LList<Record>replist;
				 extern LList<Article>artlist;
				 //�����ļ��Ƿ����
				 fstream f;
				 f.open("d:\\maxnum.txt",ios::in|ios::out);
				 if(!f)
				 {
					 f=fstream("d:\\maxnum.txt",ios::out);
					 //���������ٱ�����ѧ��������ʦ��������Ա��
					 f<<"0"<<"\n"<<"0"<<"\n"<<"0"<<"\n"<<"0"<<"\n"<<"0";
					 stunum=0;
					 tecnum=0;
					 arcnum=0;
					 repnum=0;
					 manum=0;
				 }
				 else
				 {
					 f>>arcnum>>repnum>>stunum>>tecnum>>manum;
				 }
				 f.close();
				 //ѧ����Ϣ�ļ��Ƿ����
				 fstream f2;
				 f2.open("d:\\stulist.dat",ios::in|ios::binary);
				 if(!f2)
				 {
					 f2=fstream("d:\\stulist.dat",ios::out|ios::binary);
					 Student s1;
					 s1.setendmark(1);
					 s1.setexsitmark(1);
					 f2.write((char*)&s1,sizeof(Student));
				 }
				 f2.close();
				 f2.open("d:\\stulist.dat",ios::in|ios::binary);
				 Student s2=Student();
				 f2.seekg(0,ios::beg);
				 do 
				 {
					 f2.read((char*)&s2,sizeof(Student));
					 stulist.append(s2);
				 } while (s2.getendmark()==0);
				 stulist.moveToEnd();
				 stulist.prev();
				 stulist.remove();
				 /*for(stulist.moveToStart();stulist.currPos()<stulist.length();stulist.next())
				 {
					 MessageBox::Show(gcnew String(stulist.getValue().getname())+gcnew String(stulist.getValue().getpwd()));
				 }*/
				 f2.close();

				 //������֤

				 //��ʦ��Ϣ�ļ��Ƿ����
				 fstream f3;
				 f3.open("d:\\teclist.dat",ios::in|ios::binary);
				 if(!f3)
				 {
					 f3=fstream("d:\\teclist.dat",ios::out|ios::binary);
					 Teacher t1;
					 t1.setendmark(1);
					 t1.setexsitmark(1);
					 f3.write((char*)&t1,sizeof(Teacher));
				 }
				 f3.close();
				 f3.open("d:\\teclist.dat",ios::in|ios::binary);
				 Teacher t2=Teacher();
				 f3.seekg(0,ios::beg);
				 do 
				 {
					 f3.read((char*)&t2,sizeof(Teacher));
					 teclist.append(t2);
				 } while (t2.getendmark()==0);
				 teclist.moveToEnd();
				 teclist.prev();
				 teclist.remove();
				 f3.close();
				 //����Ա��Ϣ�ļ��Ƿ����
				 fstream f4;
				 f4.open("d:\\manlist.dat",ios::in|ios::binary);
				 if(!f4)
				 {
					 f4=fstream("d:\\manlist.dat",ios::out|ios::binary);
					 Manager m1;
					 m1.setendmark(1);
					 m1.setexsitmark(1);
					 f4.write((char*)&m1,sizeof(Manager));
				 }
				 f4.close();
				 f4.open("d:\\manlist.dat",ios::in|ios::binary);
				 Manager m2=Manager();
				 f4.seekg(0,ios::beg);
				 do 
				 {
					 f4.read((char*)&m2,sizeof(Manager));
					 manlist.append(m2);
				 } while (m2.getendmark()==0);
				 manlist.moveToEnd();
				 manlist.prev();
				 manlist.remove();
				 f4.close();
				 //������Ϣ�ļ��Ƿ����
				 fstream f5;
				 f5.open("d:\\artlist.dat",ios::in|ios::binary);
				 if(!f5)
				 {
					 f5=fstream("d:\\artlist.dat",ios::out|ios::binary);
					 Article a1;
					 a1.setendmark(1);
					 a1.setexsitmark(1);
					 f5.write((char*)&a1,sizeof(Student));
				 }
				 f5.close();
				 f5.open("d:\\artlist.dat",ios::in|ios::binary);
				 Article a2=Article();
				 f5.seekg(0,ios::beg);
				 do 
				 {
					 f5.read((char*)&a2,sizeof(Article));
					 artlist.append(a2);
				 } while (a2.getendmark()==0);
				 artlist.moveToEnd();
				 artlist.prev();
				 artlist.remove();
				 f5.close();
				 //�ٱ���Ϣ�ļ��Ƿ����
				 fstream f6;
				 f6.open("d:\\replist.dat",ios::in|ios::binary);
				 if(!f6)
				 {
					 f6=fstream("d:\\replist.dat",ios::out|ios::binary);
					 Record r1;
					 r1.setendmark(1);
					 r1.setexsitmark(1);
					 f6.write((char*)&r1,sizeof(Record));
				 }
				 f6.close();
				 f6.open("d:\\replist.dat",ios::in|ios::binary);
				 Record r2=Record();
				 f6.seekg(0,ios::beg);
				 do 
				 {
					 f6.read((char*)&r2,sizeof(Record));
					 replist.append(r2);
				 } while (r2.getendmark()==0);
				 replist.moveToEnd();
				 replist.prev();
				 replist.remove();
				 f6.close();
			 
				 login^f1=gcnew login();
				 f1->Show();
				 this->Hide();
			 }
	private: System::Void ��ʾ����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 login^f1=gcnew login();
				 f1->Show();
				 if(f1->WindowState==FormWindowState::Minimized)
					 f1->WindowState=FormWindowState::Normal;
			 }
	private: System::Void �˳�����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 Form2^f1=gcnew Form2();
				 f1->Show();
				 if(f1->WindowState==FormWindowState::Minimized)
					 f1->WindowState=FormWindowState::Normal;
			 }
	private: System::Void �˳�����ToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
				 extern LList<Student>stulist;
				 extern LList<Teacher>teclist;
				 extern LList<Manager>manlist;
				 extern LList<Record>replist;
				 extern LList<Article>artlist;
				 extern int stunum;
				 extern int tecnum;
				 extern int arcnum;
				 extern int repnum;
				 extern int manum;
				 extern Student globalstu;
				 fstream f;
				 f.open("d:\\maxnum.txt",ios::in|ios::out);
				 f.clear();
				 f<<arcnum<<"\n"<<repnum<<"\n"<<stunum<<"\n"<<tecnum<<"\n"<<manum;
				 f.close();

				 //ѧ����Ϣ�ļ��洢
				 fstream f2;
				 f2.open("d:\\stulist.dat",ios::out|ios::binary);
				  f2.clear();
				 for(stulist.moveToStart();stulist.currPos()<stulist.length();stulist.next())
				 {
					 //MessageBox::Show(gcnew String(stulist.getValue().getname())+gcnew String(stulist.getValue().getpwd()));
					 f2.write((char*)&stulist.getValue(),sizeof(Student));
				 }
				 Student s1;
				 s1.setendmark(1);
				 s1.setexsitmark(1);
				 f2.write((char*)&s1,sizeof(Student));
				 f2.close();

				

				 //��ʦ��Ϣ�ļ��Ƿ����
				 fstream f3;
				 f3.open("d:\\teclist.dat",ios::out|ios::binary);
				  f3.clear();
				 for(teclist.moveToStart();teclist.currPos()<teclist.length();teclist.next())
				 {
					 f3.write((char*)&teclist.getValue(),sizeof(Teacher));
				 }
				 Teacher t1;
				 t1.setendmark(1);
				 t1.setexsitmark(1);
				 f3.write((char*)&t1,sizeof(Teacher));
				 f3.close();
				 //����Ա��Ϣ�ļ��Ƿ����
				 fstream f4;
				 f4.open("d:\\manlist.dat",ios::out|ios::binary);
				 f4.clear();
				 for(manlist.moveToStart();manlist.currPos()<manlist.length();manlist.next())
				 {
					 f4.write((char*)&manlist.getValue(),sizeof(Manager));
				 }
				 Manager m1;
				 m1.setendmark(1);
				 m1.setexsitmark(1);
				 f4.write((char*)&m1,sizeof(Manager));
				 f4.close();
				 //������Ϣ�ļ��Ƿ����
				 fstream f5;
				 f5.open("d:\\artlist.dat",ios::out|ios::binary);
				 f5.clear();
				 for(artlist.moveToStart();artlist.currPos()<artlist.length();artlist.next())
				 {
					 f5.write((char*)&artlist.getValue(),sizeof(Article));
				 }
				 Article a1;
				 a1.setendmark(1);
				 a1.setexsitmark(1);
				 f5.write((char*)&a1,sizeof(Student));
				 f5.close();
				 //�ٱ���Ϣ�ļ��Ƿ����
				 fstream f6;
				 f6.open("d:\\replist.dat",ios::out|ios::binary);
				 f6.clear();
				 for(replist.moveToStart();replist.currPos()<replist.length();replist.next())
				 {
					 f6.write((char*)&replist.getValue(),sizeof(Record));
				 }
				 Record r1;
				 r1.setendmark(1);
				 r1.setexsitmark(1);
				 f6.write((char*)&r1,sizeof(Record));
				 f6.close();

				 Close();
			 }
};
}
