#pragma once
#include"form5.h"
#include"form15.h"
#include"form16.h"
#include"form14.h"
#include"form25.h"
namespace ���ʹ��� {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// form13 ժҪ
	/// </summary>
	public ref class form13 : public System::Windows::Forms::Form
	{
	public:
		form13(void)
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
		~form13()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;

	private:
		/// <summary>
		/// ����������������
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(form13::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(31, 45);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(66, 40);
			this->button1->TabIndex = 0;
			this->button1->Text = L"��Ǽ�";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &form13::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(113, 45);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(66, 40);
			this->button2->TabIndex = 1;
			this->button2->Text = L"��޸�";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &form13::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(31, 102);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(66, 42);
			this->button3->TabIndex = 2;
			this->button3->Text = L"��ѯ";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &form13::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(195, 45);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(66, 40);
			this->button4->TabIndex = 3;
			this->button4->Text = L"�浵";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &form13::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(83, 215);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(126, 40);
			this->button5->TabIndex = 4;
			this->button5->Text = L"���ز�ѡ����������";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &form13::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(195, 101);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(66, 41);
			this->button6->TabIndex = 5;
			this->button6->Text = L"��ʼ��";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &form13::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(83, 159);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(126, 40);
			this->button7->TabIndex = 6;
			this->button7->Text = L"��ȡ������¼";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &form13::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(113, 102);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(66, 42);
			this->button8->TabIndex = 7;
			this->button8->Text = L"����";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &form13::button8_Click);
			// 
			// form13
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(292, 283);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"form13";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"��������";
			this->Load += gcnew System::EventHandler(this, &form13::form13_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void form13_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
			 }
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 extern int actyear,actmonth,actday;
				 date b;
				 extern char*datedat;
				 manageactivity a;
				 String^message="���������ϴ��ڣ���ɾ��ԭ�����ݣ�Ҫ���г�ʼ����?";
				 String^caption="��ʼ��";
				 MessageBoxButtons buttons=MessageBoxButtons::YesNo;
				 System::Windows::Forms::DialogResult result;
				result=MessageBox::Show(message,caption, buttons);
				if(result==System::Windows::Forms::DialogResult::Yes)
				{
					a.initial(datedat);
					String^s1=gcnew String(datedat);
					MessageBox::Show("����Ļ�����ļ��Ѿ���ʼ��",s1,MessageBoxButtons::OK);
				}
				else 
				{
					MessageBox::Show("ȡ������","��ʼ�����",MessageBoxButtons::OK);
				}
			 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Close();
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 extern int actyear,actmonth,actday;
			 manageactivity a;
			 date b;
			 extern char*datedat;
			 extern char*datetxt;
			 a.createtxt(datedat,datetxt,actyear,actmonth,actday);
			 String^s1=gcnew String(datetxt);
			 MessageBox::Show("�ı��ļ��ѽ���\n��������·���д�\n"+s1,"�浵�ɹ�",MessageBoxButtons::OK);
		 }
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 MessageBox::Show("���ȴ浵","��ʾ",MessageBoxButtons::OK);
			 form5^f5=gcnew form5();
			 f5->StartPosition=FormStartPosition::WindowsDefaultLocation;
			 f5->Show();
			 button5->Select();
		 }
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 extern int p;
			 p=0;
			 form15^f15=gcnew form15();
			 f15->StartPosition=FormStartPosition::WindowsDefaultLocation;
			 f15->Show();
			 button5->Select();
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 extern int p;
			 p=0;
			 extern int changesign;
			 changesign=0;
			  form16^f16=gcnew form16();
			 f16->StartPosition=FormStartPosition::WindowsDefaultLocation;
			 f16->Show();
			 button5->Select();
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 form25^f25=gcnew form25();
			 f25->StartPosition=FormStartPosition::WindowsDefaultLocation;
			 f25->Show();
			 button5->Select();
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 extern int changesign;
			 changesign=1;
			 MessageBox::Show("���Ȳ�ѯ���ҵ����޸ĵĻ\nȻ���޸�","��ʾ",MessageBoxButtons::OK,MessageBoxIcon::Information);
			 form16^f16=gcnew form16();
			 f16->StartPosition=FormStartPosition::WindowsDefaultLocation;
			 f16->Show();
			 button5->Select();
		 }
};
}
