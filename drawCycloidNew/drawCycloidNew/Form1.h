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
		
		SolidBrush^ drawBrush = gcnew SolidBrush(Color::Green);
	//	Pen^ myPen = gcnew Pen(Color::Red);

		int a = 100, b = 100; // Where the big circle starts
		int r = 50; // the radius of the big circle
		int sr = 2; // the radius of small circle
	private: System::Windows::Forms::Button^  button1;
			 const double PI = 3.14159265358979323846;

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
			this->button1->Location = System::Drawing::Point(175, 63);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"draw";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1387, 369);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		}

		// void drawCycloid() {
			/*
			SolidBrush^ drawBrush = gcnew SolidBrush(Color::Green);
			Pen^ myPen = gcnew Pen(Color::Red);

			int a = 100, b = 100; // Where the big circle starts
			int r = 50; // the radius of the big circle
			int sr = 2; // the radius of small circle
			const double PI = 3.14159265358979323846;
			*/

			

		//    public void drawCurve (PaintEventArgs e) 
			void drawCurve()
			{
				//     System.Drawing.Pen myPen;
				  //   myPen = new System.Drawing.Pen(System.Drawing.Color.Red);

				Graphics^ formGraphics = CreateGraphics();
				Pen^ myPen = gcnew Pen(Color::Red);

				//
			  // 	System.out.println ("Cycloid started now");

				myPen->Color = Color::Blue;
				//	formGraphics.setColor (Color.blue); // the color of the line
											 // where the big circle rolls

				formGraphics->DrawLine(myPen, a - 20, b + r + 1, a + 1000, b + r + 1);
				//		g.drawLine(a-20, b - r - 1, a + 1000, b - r - 1);
				double theta, thetachange;

				theta = 0.0;
				thetachange = PI / 20;

				myPen->Color = Color::Green;


				for (int i = 0; i < 100; i = i + 1) {
					//   Color backgroundColour = getBackground();
					Color backgroundColour = Form1::DefaultBackColor;

					myPen->Color = backgroundColour;
					drawBigCircle(theta, formGraphics, myPen);


					theta = theta + thetachange;

					myPen->Color = Color::Red;

					drawBigCircle(theta, formGraphics, myPen);
					myPen->Color = Color::Green;

					drawSmallCircle(theta, formGraphics);
					///      
				//	Font drawFont = gcnew Font("Arial", 16);

					Thread::Sleep(20);

				}  // end of for loop


		//		myPen->Dispose();
			//	formGraphics->Dispose();
			}  // end of OnPaint

			void drawBigCircle(double theta, Graphics^ formGraphics, Pen^ myPen)
			{
				// Center of big circle is (a + r * theta, b)
				// Center of small solid circle is  x = a + r* theta + r * sin (theta)
				// y = b - r * cos (theta)
				//    		double theta = (i* (Math.PI)/180);
				double bx, by; // center of big circle
				double sx, sy; // center of small circle

				bx = a + r * theta;
				by = b;

				//    			sx = a + r * theta + r * Math.sin(theta);
				//  			sy = b - r * Math.cos (theta);

				formGraphics->DrawEllipse(myPen, (int)bx - r, (int)by - r, 2 * r, 2 * r);

				//          Draw small circle

				//    	    g.setColor(Color.red);
				//    	    g.fillOval ((int) sx - sr, (int) sy - sr, 2 * sr, 2 * sr);

			}  // end of drawBigCircle

			void drawSmallCircle(double theta, Graphics^ formGraphics)
			{
				// Center of big circle is (a + r * theta, b)
				// Center of small solid circle is  x = a + r* theta + r * sin (theta)
				// y = b - r * cos (theta)
				//    		double theta = (i* (Math.PI)/180);
				//   		double bx, by; // center of big circle
				double sx, sy; // center of small circle

				sx = a + r * theta + r * Math::Sin(theta);
				sy = b - r * Math::Cos(theta);

				//          Draw small circle

				//    	    g.setColor(Color.red);
				formGraphics->FillEllipse(drawBrush, (int)sx - sr, (int)sy - sr, 2 * sr, 2 * sr);

			}  // end of drawBigCircle
	//	}  // end of drawCycloid
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		drawCurve();
	}
};  // end of class


} // end of namespace
