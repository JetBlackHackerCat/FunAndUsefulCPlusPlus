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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(22, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Principal";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(118, 22);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(357, 25);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(261, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(86, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Annual Rate";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(618, 28);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(497, 28);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(115, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Number of Years";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(264, 93);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(103, 34);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Calculate";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(25, 170);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(97, 17);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Installment is: ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(22, 216);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(113, 17);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Total Payment is";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(22, 264);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(164, 17);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Total Interest Payment is";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(264, 170);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 17);
			this->label7->TabIndex = 10;
			this->label7->Click += gcnew System::EventHandler(this, &Form1::label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(264, 216);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(0, 17);
			this->label8->TabIndex = 11;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(264, 263);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(0, 17);
			this->label9->TabIndex = 12;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(789, 359);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

// Calculate mortgage payment based on principal, annual rate, and number of years
// The formula came from those of mortage.cpp from chapter 2

	double P, r, I, x; // principal, monthly rate, and installment
	int n; // number of years

	// Get P, principal from Textbox1, right after the label Principal:

	try {
		P = Double::Parse(textBox1->Text);
	}

	catch (FormatException^)
	{
		P = 0.0;
	}

	// Get rate r from Textbox 2. But it has to be divided by 1200 to be monthly rate in percents.
	try {
		r = Double::Parse(textBox2->Text);
	}

	catch (FormatException^)
	{
		r = 0.0;
	}
	r = r / 1200;

    // Get n, the number of years from Textbox3.

	try {
		n = Int32::Parse(textBox3->Text);
	}

	catch (FormatException^)
	{
		n = 0.0;
	}
	//		 The formula that P and its compound interest over n years is
//		 A1 = P * (1 + r)^12n (there are 12 n months)
		//
//		 with monthly installment I, the accumulated repayment plus interest is
//		 A2 = I * [ (1+r)^ (12n - 1) + (1 + r) ^ (12n - 2)+ (1+r) ^ (12n -3) +...
//		       + (1+r)^2 + (1+r) + 1] = I * [ (1+r) ^ 12n - 1] / r
//		 A1 must be equal to A2. Hence, given P, r, and n, we can compute
//		 I
	/*
	cout << "Compute (1+r)^ 12n\n";
	x = pow(1 + r, 12 * n);
	*/

	x = System::Math::Pow(1 + r, 12 * n);

	I = P * x * r / (x - 1);  // Get installment

	label7->Text = "$ " + I;
	label8->Text = (12 * n * I).ToString();
	label9->Text = (12 * n * I - P).ToString();



}
private: System::Void label7_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
