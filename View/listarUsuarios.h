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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Usuario,
					this->contrasena
			});
			this->dataGridView1->Location = System::Drawing::Point(163, 98);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 102;
			this->dataGridView1->RowTemplate->Height = 40;
			this->dataGridView1->Size = System::Drawing::Size(1689, 643);
			this->dataGridView1->TabIndex = 0;
			// 
			// Usuario
			// 
			this->Usuario->HeaderText = L"Usuario";
			this->Usuario->MinimumWidth = 12;
			this->Usuario->Name = L"Usuario";
			this->Usuario->Width = 250;
			// 
			// contrasena
			// 
			this->contrasena->HeaderText = L"Contrasena";
			this->contrasena->MinimumWidth = 12;
			this->contrasena->Name = L"contrasena";
			this->contrasena->Width = 250;
			// 
			// listarUsuarios
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2446, 1255);
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
	};
}
