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
		
		SolidBrush^ greenBrush = gcnew SolidBrush(Color::Green);
		g->FillRectangle(greenBrush, 10, 10, 50, 20);
		g->DrawEllipse(Pens::Red, 52, 22, 50, 50);
		
		g->DrawRectangle(Pens::Black, 95, 65, 50, 20);


		// Dibuja una línea desde (20, 20) hasta (200, 20)
		//g->DrawLine(Pens::Black, 20, 20, 200, 20);

		//// Dibuja un rectángulo con posición (30, 40), ancho 100 y alto 50
		//g->DrawRectangle(Pens::Blue, 30, 40, 100, 50);

		//// Dibuja un círculo usando un rectángulo delimitador
		//g->DrawEllipse(Pens::Red, 50, 100, 50, 50);

		//Pen^ customPen = gcnew Pen(Color::Green, 3); // Color Verde, grosor 3
		//g->DrawLine(customPen, 10, 10, 150, 10);

		//array<Point>^ bezierPoints = { Point(50, 150), Point(80, 40), Point(200, 200), Point(250, 50) };
		//g->DrawBezier(Pens::Purple, bezierPoints[0], bezierPoints[1], bezierPoints[2], bezierPoints[3]);

		SolidBrush^ redBrush = gcnew SolidBrush(Color::Red);
		//g->FillRectangle(redBrush, 30, 40, 100, 50);


	}
	};
}
