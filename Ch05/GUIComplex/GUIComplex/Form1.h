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
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;

  

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(108, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"xReal";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(262, 48);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(562, 50);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(434, 50);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 15);
			this->label2->TabIndex = 2;
			this->label2->Text = L"xImaginary";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(562, 93);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(434, 95);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 15);
			this->label3->TabIndex = 6;
			this->label3->Text = L"yImaginary";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(262, 95);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(107, 95);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(38, 15);
			this->label4->TabIndex = 4;
			this->label4->Text = L"yReal";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(110, 144);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Sum";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(266, 144);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Product";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(107, 203);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(101, 15);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Sum in Cartesian";
			this->label5->Click += gcnew System::EventHandler(this, &Form1::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(107, 252);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(120, 15);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Product in Cartesian:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(262, 295);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 15);
			this->label7->TabIndex = 12;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(262, 332);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(0, 15);
			this->label8->TabIndex = 13;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(264, 294);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(0, 15);
			this->label9->TabIndex = 14;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(262, 296);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(0, 15);
			this->label10->TabIndex = 15;
			this->label10->Click += gcnew System::EventHandler(this, &Form1::label10_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(262, 332);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(0, 15);
			this->label11->TabIndex = 16;
			this->label11->Click += gcnew System::EventHandler(this, &Form1::label11_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(108, 296);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(58, 15);
			this->label12->TabIndex = 17;
			this->label12->Text = L"x in Polar";
			this->label12->Click += gcnew System::EventHandler(this, &Form1::label12_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(266, 203);
			this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(48, 15);
			this->label13->TabIndex = 18;
			this->label13->Text = L"label13";
			this->label13->Click += gcnew System::EventHandler(this, &Form1::label13_Click);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(268, 252);
			this->label14->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(48, 15);
			this->label14->TabIndex = 19;
			this->label14->Text = L"label14";
			this->label14->Click += gcnew System::EventHandler(this, &Form1::label14_Click);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(110, 332);
			this->label15->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(57, 15);
			this->label15->TabIndex = 20;
			this->label15->Text = L"y in Polar";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(110, 369);
			this->label16->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(93, 15);
			this->label16->TabIndex = 21;
			this->label16->Text = L"Product in polar";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(265, 369);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(48, 15);
			this->label17->TabIndex = 22;
			this->label17->Text = L"label17";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(888, 431);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {  // Sum button clicked

		double rx, ix, ry, iy; // real and imaginary part of x
		try {
			rx = Double::Parse(textBox1->Text);
		}

		catch (FormatException^)
		{
			rx = 0.0;
		}

		try {
			ix = Double::Parse(textBox2->Text);
		}

		catch (FormatException^)
		{
			ix = 0.0;
		}

	
		try {
			ry = Double::Parse(textBox4->Text);
		}

		catch (FormatException^)
		{
			ry = 0.0;
		}

		try {
			iy = Double::Parse(textBox3->Text);
		}

		catch (FormatException^)
		{
			iy = 0.0;
		}

		// print sum in label10

		double rSum, iSum;

		rSum = rx + ry;
		iSum = ix + iy;

		label13->Text = "(" + rSum + " + " + iSum + "i)";
	}
private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label11_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	// Code to compute the product of two complex numbers
	// (a+bi)*(c+di) = (ac - bd) + (ad + bc) i
	// Also calculates the polar forms of x and y and their products in polar

	double rx, ix, ry, iy; // real and imaginary part of x
	double radiusx, anglex, radiusy, angley, radiusprod, angleprod;
	try {
		rx = Double::Parse(textBox1->Text);
	}

	catch (FormatException^)
	{
		rx = 0.0;
	}

	try {
		ix = Double::Parse(textBox2->Text);
	}

	catch (FormatException^)
	{
		ix = 0.0;
	}


	try {
		ry = Double::Parse(textBox4->Text);
	}

	catch (FormatException^)
	{
		ry = 0.0;
	}

	try {
		iy = Double::Parse(textBox3->Text);
	}

	catch (FormatException^)
	{
		iy = 0.0;
	}

	// print sum in label10

	double rProd, iProd;
	double pi = 4.0* System::Math::Atan2(1, 1); // arctan (1) is pi /4 or 45 degrees
	rProd = rx * ry - ix * iy;
	iProd = rx * iy + ry * ix;

	label14->Text = "(" + rProd + " + " + iProd + "i)";

	radiusx = System::Math::Sqrt(rx * rx + ix * ix);
	radiusy = System::Math::Sqrt(ry * ry + iy * iy);

	anglex = System::Math::Atan2(ix, rx);
	angley = System::Math::Atan2(iy, ry);

	label10->Text = radiusx + "* e^i " + anglex * 180 / pi + " degrees";
	label11->Text = radiusy + "* e^i " + angley * 180 / pi + " degrees";

	label17->Text = (radiusx *radiusy) + "* e^i " + (angley + anglex) * 180 / pi + " degrees";

}
private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label13_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label14_Click(System::Object^ sender, System::EventArgs^ e) {
}

}; // end of class
}  // end of namespace
