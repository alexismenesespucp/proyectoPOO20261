#pragma once

namespace ProyectoPoo20261 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ txtBoxUsuario;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtBoxPass;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->txtBoxUsuario = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtBoxPass = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(141, 247);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(112, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Usuario";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1007, 241);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(233, 66);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Login";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// txtBoxUsuario
			// 
			this->txtBoxUsuario->Location = System::Drawing::Point(431, 241);
			this->txtBoxUsuario->Name = L"txtBoxUsuario";
			this->txtBoxUsuario->Size = System::Drawing::Size(225, 38);
			this->txtBoxUsuario->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(141, 363);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(161, 32);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Contraseña";
			// 
			// txtBoxPass
			// 
			this->txtBoxPass->Location = System::Drawing::Point(431, 363);
			this->txtBoxPass->Name = L"txtBoxPass";
			this->txtBoxPass->Size = System::Drawing::Size(240, 38);
			this->txtBoxPass->TabIndex = 4;
			this->txtBoxPass->UseSystemPasswordChar = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1431, 769);
			this->Controls->Add(this->txtBoxPass);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtBoxUsuario);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ usuario = this->txtBoxUsuario->Text;
		Console::WriteLine("El usuario es: " + usuario);

	}
	};
}
