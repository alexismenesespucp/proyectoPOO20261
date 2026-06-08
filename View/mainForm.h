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
			xPositionRectangle = 25;
			xPositionCircle = 0;
			timer1->Interval = 100;
			timer1->Enabled = true;
			goingFast = false;
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
		int xPositionRectangle;
		bool goingFast;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
		   int xPositionCircle;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &mainForm::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Tick += gcnew System::EventHandler(this, &mainForm::timer2_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(187, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1285, 1750);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &mainForm::pictureBox1_Paint);
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1815, 1021);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"mainForm";
			this->Text = L"°°";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &mainForm::mainForm_Paint);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void mainForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if(!goingFast && xPositionRectangle - xPositionCircle <5 && xPositionRectangle - xPositionCircle > -5) {
			goingFast = true;
			xPositionRectangle += 20;
		}
		else if (goingFast && xPositionRectangle - xPositionCircle < 150 && xPositionRectangle - xPositionCircle > -150) {
			xPositionRectangle += 20;
		}
		else if(goingFast && xPositionRectangle - xPositionCircle > 150 && xPositionRectangle - xPositionCircle < -150 ){
			goingFast = false;
			xPositionRectangle += 5;
		}
		else {
			xPositionRectangle += 5;
		}
		if (xPositionRectangle > this->pictureBox1->Width)
			xPositionRectangle = 0; // Repetir movimiento
		
		this->pictureBox1->Invalidate();
		//this->Invalidate(); // Refresca la pantalla
	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		xPositionCircle += 8; // Incrementa la posición X para mover el círculo
		if (xPositionCircle > this->pictureBox1->Width)
			xPositionCircle = 0; // Repetir movimiento
		this->Invalidate(); // Refresca la pantalla
	}
private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	Graphics^ g = e->Graphics;
	Pen^ wavePen = gcnew Pen(Color::Blue, 2); // Pen para la onda
	SolidBrush^ rectBrush = gcnew SolidBrush(Color::Red); // Brocha para el rectángulo
	SolidBrush^ circleBrush = gcnew SolidBrush(Color::Green); // Brocha para el rectángulo

	// Parámetros de la onda
	double amplitude = 20;
	double frequency = 0.05; // Cambiar este valor cambia la longitud de onda
	double offsetY = 200; // Posición vertical de la onda

	// Dibuja la onda cosenoidal
	
	for (int x = 0; x < this->pictureBox1->Width; ++x) {
		double y = offsetY + amplitude * Math::Cos(frequency * x);
		g->DrawRectangle(Pens::Blue, x, y, 1, 1); // Punto para la onda
	}

	// Dibuja el rectángulo en movimiento siguiendo la onda cosenoidal
	double yRect = offsetY + amplitude * Math::Cos(frequency * xPositionRectangle);
	double yCircle = offsetY + amplitude * Math::Cos(frequency * xPositionCircle);

	g->FillRectangle(rectBrush, xPositionRectangle, yRect - 10, 20, 20);

	g->FillEllipse(circleBrush, xPositionCircle, yCircle - 10, 20, 20);



}
};
}
