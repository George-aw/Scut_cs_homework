#pragma once

namespace ���ʹ��� {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// form5 ժҪ
	/// </summary>
	public ref class form5 : public System::Windows::Forms::Form
	{
	public:
		form5(void)
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
		~form5()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  �ļ�FToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �˳�ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ��ʽOToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ǰ��ɫToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ɫToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �༭EToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ճ��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ɾ��ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ȫѡToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::FontDialog^  fontDialog1;
	private: System::Windows::Forms::ColorDialog^  colorDialog1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(form5::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->�ļ�FToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�˳�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�༭EToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ճ��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ɾ��ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ȫѡToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��ʽOToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ǰ��ɫToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ɫToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->fontDialog1 = (gcnew System::Windows::Forms::FontDialog());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->�ļ�FToolStripMenuItem, 
				this->�༭EToolStripMenuItem, this->��ʽOToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(758, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// �ļ�FToolStripMenuItem
			// 
			this->�ļ�FToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->��ToolStripMenuItem, 
				this->����ToolStripMenuItem, this->�˳�ToolStripMenuItem});
			this->�ļ�FToolStripMenuItem->Name = L"�ļ�FToolStripMenuItem";
			this->�ļ�FToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F));
			this->�ļ�FToolStripMenuItem->Size = System::Drawing::Size(73, 20);
			this->�ļ�FToolStripMenuItem->Text = L"�ļ���&F��";
			// 
			// ��ToolStripMenuItem
			// 
			this->��ToolStripMenuItem->Name = L"��ToolStripMenuItem";
			this->��ToolStripMenuItem->Size = System::Drawing::Size(98, 22);
			this->��ToolStripMenuItem->Text = L"��";
			this->��ToolStripMenuItem->Click += gcnew System::EventHandler(this, &form5::��ToolStripMenuItem_Click);
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(98, 22);
			this->����ToolStripMenuItem->Text = L"����";
			this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &form5::����ToolStripMenuItem_Click);
			// 
			// �˳�ToolStripMenuItem
			// 
			this->�˳�ToolStripMenuItem->Name = L"�˳�ToolStripMenuItem";
			this->�˳�ToolStripMenuItem->Size = System::Drawing::Size(98, 22);
			this->�˳�ToolStripMenuItem->Text = L"�˳�";
			this->�˳�ToolStripMenuItem->Click += gcnew System::EventHandler(this, &form5::�˳�ToolStripMenuItem_Click);
			// 
			// �༭EToolStripMenuItem
			// 
			this->�༭EToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->����ToolStripMenuItem, 
				this->����ToolStripMenuItem, this->ճ��ToolStripMenuItem, this->ɾ��ToolStripMenuItem, this->ȫѡToolStripMenuItem});
			this->�༭EToolStripMenuItem->Name = L"�༭EToolStripMenuItem";
			this->�༭EToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::E));
			this->�༭EToolStripMenuItem->Size = System::Drawing::Size(73, 20);
			this->�༭EToolStripMenuItem->Text = L"�༭��&E��";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::X));
			this->����ToolStripMenuItem->Size = System::Drawing::Size(137, 22);
			this->����ToolStripMenuItem->Text = L"����";
			this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &form5::����ToolStripMenuItem_Click);
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->����ToolStripMenuItem->Size = System::Drawing::Size(137, 22);
			this->����ToolStripMenuItem->Text = L"����";
			this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &form5::����ToolStripMenuItem_Click);
			// 
			// ճ��ToolStripMenuItem
			// 
			this->ճ��ToolStripMenuItem->Name = L"ճ��ToolStripMenuItem";
			this->ճ��ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V));
			this->ճ��ToolStripMenuItem->Size = System::Drawing::Size(137, 22);
			this->ճ��ToolStripMenuItem->Text = L"ճ��";
			this->ճ��ToolStripMenuItem->Click += gcnew System::EventHandler(this, &form5::ճ��ToolStripMenuItem_Click);
			// 
			// ɾ��ToolStripMenuItem
			// 
			this->ɾ��ToolStripMenuItem->Name = L"ɾ��ToolStripMenuItem";
			this->ɾ��ToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::D));
			this->ɾ��ToolStripMenuItem->Size = System::Drawing::Size(137, 22);
			this->ɾ��ToolStripMenuItem->Text = L"ɾ��";
			this->ɾ��ToolStripMenuItem->Click += gcnew System::EventHandler(this, &form5::ɾ��ToolStripMenuItem_Click);
			// 
			// ȫѡToolStripMenuItem
			// 
			this->ȫѡToolStripMenuItem->Name = L"ȫѡToolStripMenuItem";
			this->ȫѡToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::A));
			this->ȫѡToolStripMenuItem->Size = System::Drawing::Size(137, 22);
			this->ȫѡToolStripMenuItem->Text = L"ȫѡ";
			this->ȫѡToolStripMenuItem->Click += gcnew System::EventHandler(this, &form5::ȫѡToolStripMenuItem_Click);
			// 
			// ��ʽOToolStripMenuItem
			// 
			this->��ʽOToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->����ToolStripMenuItem, 
				this->ǰ��ɫToolStripMenuItem, this->����ɫToolStripMenuItem});
			this->��ʽOToolStripMenuItem->Name = L"��ʽOToolStripMenuItem";
			this->��ʽOToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::O));
			this->��ʽOToolStripMenuItem->Size = System::Drawing::Size(75, 20);
			this->��ʽOToolStripMenuItem->Text = L"��ʽ��&O��";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(110, 22);
			this->����ToolStripMenuItem->Text = L"����";
			this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &form5::����ToolStripMenuItem_Click);
			// 
			// ǰ��ɫToolStripMenuItem
			// 
			this->ǰ��ɫToolStripMenuItem->Name = L"ǰ��ɫToolStripMenuItem";
			this->ǰ��ɫToolStripMenuItem->Size = System::Drawing::Size(110, 22);
			this->ǰ��ɫToolStripMenuItem->Text = L"ǰ��ɫ";
			this->ǰ��ɫToolStripMenuItem->Click += gcnew System::EventHandler(this, &form5::ǰ��ɫToolStripMenuItem_Click);
			// 
			// ����ɫToolStripMenuItem
			// 
			this->����ɫToolStripMenuItem->Name = L"����ɫToolStripMenuItem";
			this->����ɫToolStripMenuItem->Size = System::Drawing::Size(110, 22);
			this->����ɫToolStripMenuItem->Text = L"����ɫ";
			this->����ɫToolStripMenuItem->Click += gcnew System::EventHandler(this, &form5::����ɫToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &form5::openFileDialog1_FileOk);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &form5::saveFileDialog1_FileOk);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(9, 39);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(737, 265);
			this->richTextBox1->TabIndex = 2;
			this->richTextBox1->Text = L"";
			// 
			// form5
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(758, 316);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"form5";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"��Ϣ��ȡ";
			this->Load += gcnew System::EventHandler(this, &form5::form5_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ��ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 richTextBox1->Text="";
				 openFileDialog1->InitialDirectory="C:\\temp\\";
				 openFileDialog1->Filter="�ı��ļ�(*.txt)|*.txt|ȫ���ļ�(*.*)|*.*";
				 openFileDialog1->FilterIndex=1;
				 openFileDialog1->RestoreDirectory=true;
				 openFileDialog1->ShowDialog();
			 }
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
		 {
			 String^path=openFileDialog1->FileName;
			 richTextBox1->LoadFile(path,RichTextBoxStreamType::PlainText);
		 }
private: System::Void ����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 saveFileDialog1->InitialDirectory="C:\\temp\\";
			 saveFileDialog1->Filter="�ı��ļ�(*.txt)|*.txt|ȫ���ļ�(*.*)|*.*";
			 saveFileDialog1->FilterIndex=1;
			 saveFileDialog1->RestoreDirectory=true;
			 saveFileDialog1->ShowDialog();
		 }
private: System::Void saveFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
		 {
			 String^path=saveFileDialog1->FileName;
			 richTextBox1->SaveFile(path,RichTextBoxStreamType::PlainText);
			 MessageBox::Show("�ļ��ѱ���","����ɹ�",MessageBoxButtons::OK,MessageBoxIcon::Information);
		 }
private: System::Void �˳�ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Close();
		 }
private: System::Void ����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 fontDialog1->ShowColor=true;
			 fontDialog1->ShowApply=true;
			 fontDialog1->ShowHelp=true;
			 Windows::Forms::DialogResult result;
			 result=fontDialog1->ShowDialog();
			 if(result==Windows::Forms::DialogResult::OK)
			 {
				 richTextBox1->Font=fontDialog1->Font;
				 richTextBox1->ForeColor=fontDialog1->Color;
			 }
		 }
private: System::Void ǰ��ɫToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 colorDialog1->ShowDialog();
			 richTextBox1->ForeColor=colorDialog1->Color;
		 }
private: System::Void ����ɫToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 colorDialog1->ShowDialog();
			 richTextBox1->BackColor=colorDialog1->Color;
		 }
private: System::Void ����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 richTextBox1->Cut();
		 }
private: System::Void ����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 richTextBox1->Copy();
		 }
private: System::Void ճ��ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 richTextBox1->Paste();
		 }
private: System::Void ɾ��ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 richTextBox1->SelectedText="";
		 }
private: System::Void ȫѡToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 richTextBox1->SelectAll();
		 }
private: System::Void form5_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
