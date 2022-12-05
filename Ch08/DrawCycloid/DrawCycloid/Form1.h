#pragma once

namespace CppCLR_WinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
			this->SuspendLayout();
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(379, 321);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	};

	void drawCycloid() {



	//	System.Drawing.SolidBrush drawBrush = new System.Drawing.SolidBrush(System.Drawing.Color.Green);
		Graphics formGraphics = CreateGraphics();
		SolidBrush drawBrush = new SolidBrush(Color::Green);
		System.Drawing.Pen myPen = new System.Drawing.Pen(System.Drawing.Color.Red);

		private int a = 100, b = 100; // Where the big circle starts
		private int r = 50; // the radius of the big circle
		private int sr = 2; // the radius of small circle
		public const double PI = 3.14159265358979323846;
		Graphics formGraphics = CreateGraphics();

		//
	  // 	System.out.println ("Cycloid started now");

		myPen.Color = System.Drawing.Color.Blue;
		//	formGraphics.setColor (Color.blue); // the color of the line
									 // where the big circle rolls

		formGraphics.DrawLine(myPen, a - 20, b + r + 1, a + 1000, b + r + 1);
		//		g.drawLine(a-20, b - r - 1, a + 1000, b - r - 1);
		double theta, thetachange;

		theta = 0.0;
		thetachange = PI / 20;

		myPen.Color = System.Drawing.Color.Green;


		for (int i = 0; i < 100; i = i + 1) {
			//   Color backgroundColour = getBackground();
			Color backgroundColour = Form1.DefaultBackColor;

			myPen.Color = backgroundColour;
			drawBigCircle(theta, formGraphics);


			theta = theta + thetachange;

			myPen.Color = System.Drawing.Color.Red;

			drawBigCircle(theta, formGraphics);
			myPen.Color = System.Drawing.Color.Green;

			drawSmallCircle(theta, formGraphics);
			///      
			Font drawFont = new Font("Arial", 16);

			Thread.Sleep(20);

		}  // end of for loop


		myPen.Dispose();
		formGraphics.Dispose();
	}

	public void drawBigCircle(double theta, Graphics formGraphics)
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

		formGraphics.DrawEllipse(myPen, (int)bx - r, (int)by - r, 2 * r, 2 * r);

		//          Draw small circle

		//    	    g.setColor(Color.red);
		//    	    g.fillOval ((int) sx - sr, (int) sy - sr, 2 * sr, 2 * sr);

	}  // end of drawBigCircle

	public void drawSmallCircle(double theta, Graphics formGraphics)
	{
		// Center of big circle is (a + r * theta, b)
		// Center of small solid circle is  x = a + r* theta + r * sin (theta)
		// y = b - r * cos (theta)
		//    		double theta = (i* (Math.PI)/180);
		//   		double bx, by; // center of big circle
		double sx, sy; // center of small circle

		sx = a + r * theta + r * System.Math.Sin(theta);
		sy = b - r * System.Math.Cos(theta);

		//          Draw small circle

		//    	    g.setColor(Color.red);
		formGraphics.FillEllipse(drawBrush, (int)sx - sr, (int)sy - sr, 2 * sr, 2 * sr);

	}  // end of drawBigCircle
}
