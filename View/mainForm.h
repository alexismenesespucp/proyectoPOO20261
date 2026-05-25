#pragma once

namespace ProyectoPoo20261 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for mainForm
	/// </summary>
	public ref class mainForm : public System::Windows::Forms::Form
	{
	public:
		mainForm(void)
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
		~mainForm()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->SuspendLayout();
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1815, 1021);
			this->Name = L"mainForm";
			this->Text = L"mainForm";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &mainForm::mainForm_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void mainForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		Pen^ sinePen = gcnew Pen(Color::Blue, 2);
		Pen^ sinePen2 = gcnew Pen(Color::Red, 2);

		float amplitude = 50;
		float frequency = 0.1;
		float offsetY = 150;
		for (int x = 0; x < this->ClientSize.Width; x++) {
			double y = offsetY + amplitude * Math::Sin(frequency * x);
			g->DrawEllipse(sinePen, x, y, 1, 1); // Punto para la onda
			double y2 = offsetY + amplitude * Math::Sin(frequency * x + Math::PI / 2);
			g->DrawEllipse(sinePen2, x, y2, 1, 1); // Punto para la onda
		}



	}
	};
}
