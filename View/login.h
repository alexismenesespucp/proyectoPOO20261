#pragma once
#include "mainForm.h"
namespace ProyectoPoo20261 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Security::Cryptography;
	using namespace System::Text;
	using namespace Model;
	/// <summary>
	/// Summary for login
	/// </summary>
	public ref class login : public System::Windows::Forms::Form
	{
	public:
		login(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~login()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ txtBoxUsuario;

	private: System::Windows::Forms::TextBox^ txtBoxPass;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(login::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->txtBoxUsuario = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxPass = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1007, 241);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(233, 66);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Login";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &login::button1_Click);
			// 
			// txtBoxUsuario
			// 
			this->txtBoxUsuario->Location = System::Drawing::Point(431, 241);
			this->txtBoxUsuario->Name = L"txtBoxUsuario";
			this->txtBoxUsuario->Size = System::Drawing::Size(225, 38);
			this->txtBoxUsuario->TabIndex = 2;
			this->txtBoxUsuario->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &login::MyForm_KeyPress);
			// 
			// txtBoxPass
			// 
			this->txtBoxPass->Location = System::Drawing::Point(431, 363);
			this->txtBoxPass->Name = L"txtBoxPass";
			this->txtBoxPass->Size = System::Drawing::Size(240, 38);
			this->txtBoxPass->TabIndex = 4;
			this->txtBoxPass->UseSystemPasswordChar = true;
			this->txtBoxPass->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &login::MyForm_KeyPress);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(141, 363);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(161, 32);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Contraseña";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(141, 247);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(112, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Usuario";
			// 
			// login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1431, 769);
			this->Controls->Add(this->txtBoxPass);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtBoxUsuario);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"login";
			this->Text = L"Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ usuario = this->txtBoxUsuario->Text;
		String^ password = this->txtBoxPass->Text;

		Usuario^ user = gcnew Usuario(usuario, password);
		user->setTokenVerification("c93ccd78b2076528346216b3b2f701e6");

		//Console::WriteLine(GetMD5Hash("admin" + "1234"));	
		if (user->autentificar())
		{
			this->Hide();
			Console::WriteLine("El usuario y contraseña están correctos");
			mainForm^ mainFormInstance = gcnew mainForm();
			mainFormInstance->ShowDialog();
		}
		else
		{
			Console::WriteLine("El usuario o la contraseña están incorrectos ");
		}

	}
	private: System::Void MyForm_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == (char)System::Windows::Forms::Keys::Enter) {
			button1_Click(sender, e);
			e->Handled = true;
		}
	}
};
}
