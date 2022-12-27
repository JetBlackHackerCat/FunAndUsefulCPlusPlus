#pragma once
#include <math.h>

namespace CppCLR_WinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// class PaintArguments = {PaintArguments () = default};

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;

	protected:

	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(406, 48);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1057, 429);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form1";
			this->Text = L"Draw Circles";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}

		
	protected:

		void OnPaint(PaintEventArgs paintEvent) { // uisng OnPaint, but do NOT know how to get that invoked
		// void drawCircles (PaintEventArgs paintEvent) { // can NOT fix the PaintEventArugs no default constructor problem

			 // OnPaint(paintEvent);

			// get graphics object

			Graphics^ graphicsObject = paintEvent.Graphics;
			
			SolidBrush^ brush = gcnew SolidBrush(Color::Blue);
			Pen^ pen = gcnew Pen(Color::Red);
			// pen.set_Width(1);  // set the thickness of the line
			// pen->SetWidth (1);  // set the thickness of the line
			double theta = 0.0;
			double pi = 4.0 * atan(1.0);

			int ry = (int)(100 + 40 * sin(theta)), rx = (int)(100 + 40 * cos(theta));
			int diameter = 80;
			int iterations = 15; // specify number of circles
			for (int i = 0; i < iterations; i++)
			{
				// graphicsObject.DrawEllipse(pen, rx, ry, diameter, diameter);
				graphicsObject->DrawEllipse(pen, rx, ry, diameter, diameter);
				// DrawEllipse(pen, rx, ry, diameter, diameter);
				theta += pi / 180 * (360.0 / iterations);
				rx = (int)(100 + 40 * sin(theta));
				ry = (int)(100 + 40 * cos(theta));
			}


		}
		
#pragma endregion
	
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		//this->Invalidate(); // call OnPaint, does NOT work
		// The code does NOT draw however
		/*
		Graphics^ graphicsObject = CreateGraphics();

		SolidBrush^ brush = gcnew SolidBrush(Color::Blue);
		Pen^ pen = gcnew Pen(Color::Red);
		graphicsObject->DrawEllipse(pen, 50, 50, 200, 200);
		this->Invalidate();
		*/
		drawCircles();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	
		drawCircles();
		/*
		Graphics^ graphicsObject = CreateGraphics();
		SolidBrush^ brush = gcnew SolidBrush(Color::Blue);
		Pen^ pen = gcnew Pen(Color::Red);
		// graphicsObject->DrawEllipse(pen, 50, 50, 200, 200);

		double theta = 0.0;
		double pi = 4.0 * atan(1.0);

		int ry = (int)(100 + 40 * sin(theta)), rx = (int)(100 + 40 * cos(theta));
		int diameter = 80;
		int iterations = 15; // specify number of circles
		for (int i = 0; i < iterations; i++)
		{
			// graphicsObject.DrawEllipse(pen, rx, ry, diameter, diameter);
			graphicsObject->DrawEllipse(pen, rx, ry, diameter, diameter);
			// DrawEllipse(pen, rx, ry, diameter, diameter);
			theta += pi / 180 * (360.0 / iterations);
			rx = (int)(100 + 40 * sin(theta));
			ry = (int)(100 + 40 * cos(theta));
		}
		*/
	}

	 void drawCircles() {

				 Graphics^ graphicsObject = CreateGraphics();
				 SolidBrush^ brush = gcnew SolidBrush(Color::Blue);
				 Pen^ pen = gcnew Pen(Color::Red);
				 // graphicsObject->DrawEllipse(pen, 50, 50, 200, 200);

				 double theta = 0.0;
				 double pi = 4.0 * atan(1.0);

				 int ry = (int)(100 + 40 * sin(theta)), rx = (int)(100 + 40 * cos(theta));
				 int diameter = 80;
				 int iterations = 15; // specify number of circles
				 for (int i = 0; i < iterations; i++)
				 {
					 // graphicsObject.DrawEllipse(pen, rx, ry, diameter, diameter);
					 graphicsObject->DrawEllipse(pen, rx, ry, diameter, diameter);
					 // DrawEllipse(pen, rx, ry, diameter, diameter);
					 theta += pi / 180 * (360.0 / iterations);
					 rx = (int)(100 + 40 * sin(theta));
					 ry = (int)(100 + 40 * cos(theta));
				 }
	 }  // end of method small circle
	 

    };  // end of class Form 1
}
