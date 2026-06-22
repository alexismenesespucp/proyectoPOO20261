#pragma once

namespace ProyectoPoo20261 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Controller;
	using namespace Threading;

	/// <summary>
	/// Summary for listarUsuarios
	/// </summary>
	public ref class listarUsuarios : public System::Windows::Forms::Form
	{
	public:
		Thread^ myThread;
		listarUsuarios(System::Windows::Forms::Form^ p)
		{
			InitializeComponent();
			FormularioLogin = p;

			LoadData();
			
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~listarUsuarios()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::Form^ FormularioLogin;
	private: System::Windows::Forms::DataGridView^ dataGridView1;


	private: System::Windows::Forms::Button^ actualizar;
	private: System::Windows::Forms::Button^ eliminar;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Usuario;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ contrasena;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;





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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Usuario = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->contrasena = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->actualizar = (gcnew System::Windows::Forms::Button());
			this->eliminar = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->id, this->Usuario,
					this->contrasena
			});
			this->dataGridView1->Location = System::Drawing::Point(61, 41);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(1);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 102;
			this->dataGridView1->RowTemplate->Height = 40;
			this->dataGridView1->Size = System::Drawing::Size(633, 270);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &listarUsuarios::dataGridView1_CellClick);
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &listarUsuarios::dataGridView1_CellContentClick);
			this->dataGridView1->CellValidating += gcnew System::Windows::Forms::DataGridViewCellValidatingEventHandler(this, &listarUsuarios::dataGridView1_CellValidating);
			this->dataGridView1->RowEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &listarUsuarios::dataGridView1_RowEnter);
			this->dataGridView1->RowValidated += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &listarUsuarios::dataGridView1_RowValidated);
			this->dataGridView1->Enter += gcnew System::EventHandler(this, &listarUsuarios::dataGridView1_Enter);
			// 
			// id
			// 
			this->id->FillWeight = 50;
			this->id->HeaderText = L"id";
			this->id->Name = L"id";
			this->id->ReadOnly = true;
			this->id->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->id->Width = 50;
			// 
			// Usuario
			// 
			this->Usuario->HeaderText = L"Usuario";
			this->Usuario->MinimumWidth = 12;
			this->Usuario->Name = L"Usuario";
			this->Usuario->ReadOnly = true;
			this->Usuario->Width = 250;
			// 
			// contrasena
			// 
			this->contrasena->HeaderText = L"Contrasena";
			this->contrasena->MinimumWidth = 12;
			this->contrasena->Name = L"contrasena";
			this->contrasena->ReadOnly = true;
			this->contrasena->Width = 250;
			// 
			// actualizar
			// 
			this->actualizar->Enabled = false;
			this->actualizar->Location = System::Drawing::Point(763, 63);
			this->actualizar->Margin = System::Windows::Forms::Padding(1);
			this->actualizar->Name = L"actualizar";
			this->actualizar->Size = System::Drawing::Size(100, 29);
			this->actualizar->TabIndex = 1;
			this->actualizar->Text = L"Actualizar";
			this->actualizar->UseVisualStyleBackColor = true;
			this->actualizar->Click += gcnew System::EventHandler(this, &listarUsuarios::actualizar_Click);
			// 
			// eliminar
			// 
			this->eliminar->Enabled = false;
			this->eliminar->Location = System::Drawing::Point(763, 115);
			this->eliminar->Margin = System::Windows::Forms::Padding(1);
			this->eliminar->Name = L"eliminar";
			this->eliminar->Size = System::Drawing::Size(100, 26);
			this->eliminar->TabIndex = 2;
			this->eliminar->Text = L"Eliminar";
			this->eliminar->UseVisualStyleBackColor = true;
			this->eliminar->Click += gcnew System::EventHandler(this, &listarUsuarios::eliminar_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(758, 176);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Contraseña:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(759, 201);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(79, 20);
			this->textBox1->TabIndex = 4;
			this->textBox1->UseSystemPasswordChar = true;
			// 
			// listarUsuarios
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(917, 445);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->eliminar);
			this->Controls->Add(this->actualizar);
			this->Controls->Add(this->dataGridView1);
			this->Margin = System::Windows::Forms::Padding(1);
			this->Name = L"listarUsuarios";
			this->Text = L"listarUsuarios";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &listarUsuarios::listarUsuarios_FormClosed);
			this->Load += gcnew System::EventHandler(this, &listarUsuarios::listarUsuarios_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void LoadData() {
			dataGridView1->Rows->Clear();
			for (int i = 0; i < Controller::Operations::usuarios->Count; i++) {
				dataGridView1->Rows->Add(Controller::Operations::usuarios[i]->id,Controller::Operations::usuarios[i]->Nombre, Controller::Operations::usuarios[i]->veriticationToken);
			}
		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

	}
private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	String^ cellText = "";
	if (this->dataGridView1->CurrentRow != nullptr) {
		cellText = dataGridView1->CurrentRow->Cells[0]->Value->ToString();
		cellText = cellText->Trim()->ToLower();
	}
	Console::WriteLine("Button " + cellText->Equals("admin"));

	if (!cellText->Equals("admin") && !cellText->Equals("")) {
			this->actualizar->Enabled = true;
			this->eliminar->Enabled = true;
	}
	else {
		this->actualizar->Enabled = false;
		this->eliminar->Enabled = false;
	}

}
private: System::Void dataGridView1_Enter(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void dataGridView1_RowEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

}
private: System::Void dataGridView1_RowValidated(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

}
private: System::Void dataGridView1_CellValidating(System::Object^ sender, System::Windows::Forms::DataGridViewCellValidatingEventArgs^ e) {

}

 void ConsultaDatos() {
	 Controller::Operations::UpdateUser();
	 LoadData();
}

private: System::Void listarUsuarios_Load(System::Object^ sender, System::EventArgs^ e) {
	myThread = gcnew Thread(gcnew ThreadStart(this, &listarUsuarios::ConsultaBaseDatos));
	myThread->Start();
}

	   delegate void MyDelegate();

	   void ConsultaBaseDatos() {
		   while (true) {
			   try {
				   myThread->Sleep(2000);
				   Invoke(gcnew MyDelegate(this, &listarUsuarios::ConsultaDatos));
				}
			   catch (Exception^ ex) {
				   return;
			   }
		   }
		   
	   }
private: System::Void eliminar_Click(System::Object^ sender, System::EventArgs^ e) {
	int id = Int32::Parse(dataGridView1->CurrentRow->Cells[0]->Value->ToString());
	Controller::Operations::deleteUserSQL(id);
	Console::WriteLine("Eliminando el usuario: " + id);
}
private: System::Void listarUsuarios_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	FormularioLogin->Show();
}
private: System::Void actualizar_Click(System::Object^ sender, System::EventArgs^ e) {
	int id = Int32::Parse(dataGridView1->CurrentRow->Cells[0]->Value->ToString());
	String^ username = dataGridView1->CurrentRow->Cells[1]->Value->ToString();
	String^ password = textBox1->Text->Trim();
	Controller::Operations::updateUserSQL(id, username, password);
}
};
}
