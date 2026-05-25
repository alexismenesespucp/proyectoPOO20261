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
			this->DoubleBuffered = true; // Evita el parpadeo en la animación
			xPosition = 0;
			timer1->Interval = 1000;
			timer1->Enabled = true;
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
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		int xPosition;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();

			this->timer1->Tick += gcnew System::EventHandler(this, &mainForm::timer1_Tick);

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
		Pen^ wavePen = gcnew Pen(Color::Blue, 2); // Pen para la onda
		SolidBrush^ rectBrush = gcnew SolidBrush(Color::Red); // Brocha para el rectángulo

		// Parámetros de la onda
		double amplitude = 50;
		double frequency = 0.05; // Cambiar este valor cambia la longitud de onda
		double offsetY = 200; // Posición vertical de la onda

		// Dibuja la onda cosenoidal
		for (int x = 0; x < this->ClientSize.Width; ++x) {
			double y = offsetY + amplitude * Math::Cos(frequency * x);
			g->DrawRectangle(Pens::Blue, x, y, 1, 1); // Punto para la onda
		}

		// Dibuja el rectángulo en movimiento siguiendo la onda cosenoidal
		double yRect = offsetY + amplitude * Math::Cos(frequency * xPosition);
		g->FillRectangle(rectBrush, xPosition, yRect - 10, 20, 20);


	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		xPosition += 5; // Incrementa la posición X para mover el rectángulo
		if (xPosition > this->ClientSize.Width)
			xPosition = 0; // Repetir movimiento
		this->Invalidate(); // Refresca la pantalla
	}
	};
}
