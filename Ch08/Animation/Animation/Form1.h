#pragma once

namespace CppCLR_WinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
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
			this->button1->Location = System::Drawing::Point(150, 119);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"animation";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(379, 321);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}

		//void OnPaint(PaintEventArgs paintEvent)
		void 	callAnimation() 
		{
			//__super::OnPaint(paintEvent); // call base OnPaint method

			// get graphics object
		//	Graphics ^graphicsObject = paintEvent->Graphics;
			Graphics^ graphicsObject = CreateGraphics();

			SolidBrush ^brush = gcnew SolidBrush(Color::Blue);
			Pen ^pen = gcnew Pen(Color::AliceBlue);
			Color *currentColor;
			//	 Pen *pen = new Pen( Color::Yellow);

			int xMax = 400, yMax = 300;
			int xStart = 10, yStart = 10;
			int xChange = 50, yChange = 50;
			int diameter = 50;
			int x, y;
			int change = 0;
			// create filled rectangle

			x = xStart; y = yStart;

			brush->Color = Color::Blue;

			for (int i = 0; i < 80; i++)
			{
				brush->Color = this->BackColor;
				graphicsObject->FillEllipse(brush, x, y, 50, 50);

				if (y + yChange + diameter > yMax || y + yChange < 0)
				{
					yChange = -yChange;

					//	 brush->Color = Color::Red;
					change = 2;
				}

				if (x + xChange + diameter > xMax || x + xChange < 0)
				{
					xChange = -xChange;

					//	 brush->Color = Color::Green;
					change = 1;
				}


				x += xChange;
				y += yChange;
				switch (change)
				{
				case 0:
					brush->Color = Color::Blue;
					break;
				case 1:
					brush->Color = Color::Red;
					break;
				case 2:
					brush->Color = Color::Green;
					break;
				default:
					brush->Color = Color::Black;
					break;
				}

				graphicsObject->FillEllipse(brush, x, y, 50, 50);
				Thread::Sleep(500);

				/*
				//	 brush->Color = this->BackColor;
				//	 graphicsObject->FillEllipse(brush, x, y, 50, 50);

				//	 x += xChange;
				//	 y += yChange;
				*/

			}

			// add a string : 5/7/06

			Drawing::Font ^arial = gcnew Drawing::Font(L"Arial", 12, FontStyle::Bold);

		} // end method OnPaint    

#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		callAnimation();
	}
};
}
