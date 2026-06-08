#pragma once

namespace ProyectoPoo20261 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Controller;

	/// <summary>
	/// Summary for listarUsuarios
	/// </summary>
	public ref class listarUsuarios : public System::Windows::Forms::Form
	{
	public:
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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Usuario;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ contrasena;
	private: System::Windows::Forms::Button^ actualizar;
	private: System::Windows::Forms::Button^ eliminar;


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
			this->Usuario = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->contrasena = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->actualizar = (gcnew System::Windows::Forms::Button());
			this->eliminar = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Usuario,
					this->contrasena
			});
			this->dataGridView1->Location = System::Drawing::Point(163, 98);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 102;
			this->dataGridView1->RowTemplate->Height = 40;
			this->dataGridView1->Size = System::Drawing::Size(1689, 643);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &listarUsuarios::dataGridView1_CellClick);
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &listarUsuarios::dataGridView1_CellContentClick);
			this->dataGridView1->CellValidating += gcnew System::Windows::Forms::DataGridViewCellValidatingEventHandler(this, &listarUsuarios::dataGridView1_CellValidating);
			this->dataGridView1->RowEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &listarUsuarios::dataGridView1_RowEnter);
			this->dataGridView1->RowValidated += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &listarUsuarios::dataGridView1_RowValidated);
			this->dataGridView1->Enter += gcnew System::EventHandler(this, &listarUsuarios::dataGridView1_Enter);
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
			this->actualizar->Location = System::Drawing::Point(2034, 150);
			this->actualizar->Name = L"actualizar";
			this->actualizar->Size = System::Drawing::Size(267, 68);
			this->actualizar->TabIndex = 1;
			this->actualizar->Text = L"Actualizar";
			this->actualizar->UseVisualStyleBackColor = true;
			// 
			// eliminar
			// 
			this->eliminar->Enabled = false;
			this->eliminar->Location = System::Drawing::Point(2034, 275);
			this->eliminar->Name = L"eliminar";
			this->eliminar->Size = System::Drawing::Size(267, 63);
			this->eliminar->TabIndex = 2;
			this->eliminar->Text = L"Eliminar";
			this->eliminar->UseVisualStyleBackColor = true;
			// 
			// listarUsuarios
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2446, 1255);
			this->Controls->Add(this->eliminar);
			this->Controls->Add(this->actualizar);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"listarUsuarios";
			this->Text = L"listarUsuarios";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}

		void LoadData() {
			dataGridView1->Rows->Clear();
			for (int i = 0; i < Controller::Operations::usuarios->Count; i++) {
				dataGridView1->Rows->Add(Controller::Operations::usuarios[i]->Nombre, Controller::Operations::usuarios[i]->veriticationToken);
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
};
}
