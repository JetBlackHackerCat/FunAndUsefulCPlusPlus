#pragma once

namespace GIUorderform1
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

	//#include <iostream>
	//using namespace std;

	/// <summary> 
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the 
	///          'Resource File Name' property for the managed resource compiler tool 
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
		}

	protected:
		/*
		void Dispose(Boolean disposing)
		{
			if (disposing && components)
			{
				components->Dispose();
			}
			__super::Dispose(disposing);
		}
		*/
	private: System::Windows::Forms::TextBox^   textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  comboBox1;


	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox3;

	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;

	private: System::Windows::Forms::Label^  labelFirstName;
	private: System::Windows::Forms::Label^  labelboardsub;
	private: System::Windows::Forms::Label^  labelbooksub;
	private: System::Windows::Forms::Label^  labelTotal;
	private: System::Windows::Forms::CheckBox^  checkBoxBoard;
	private: System::Windows::Forms::CheckBox^  checkBoxBook;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->labelFirstName = gcnew System::Windows::Forms::Label();
			this->textBox1 = gcnew System::Windows::Forms::TextBox();
			this->label2 = gcnew System::Windows::Forms::Label();
			this->textBox2 = gcnew System::Windows::Forms::TextBox();
			this->button1 = gcnew System::Windows::Forms::Button();
			this->label3 = gcnew System::Windows::Forms::Label();
			this->textBox4 = gcnew System::Windows::Forms::TextBox();
			this->label4 = gcnew System::Windows::Forms::Label();
			this->comboBox1 = gcnew System::Windows::Forms::ComboBox();
			this->checkBoxBoard = gcnew System::Windows::Forms::CheckBox();
			this->label5 = gcnew System::Windows::Forms::Label();
			this->label6 = gcnew System::Windows::Forms::Label();
			this->textBox3 = gcnew System::Windows::Forms::TextBox();
			this->labelboardsub = gcnew System::Windows::Forms::Label();
			this->button2 = gcnew System::Windows::Forms::Button();
			this->labelbooksub = gcnew System::Windows::Forms::Label();
			this->textBox5 = gcnew System::Windows::Forms::TextBox();
			this->label9 = gcnew System::Windows::Forms::Label();
			this->label10 = gcnew System::Windows::Forms::Label();
			this->checkBoxBook = gcnew System::Windows::Forms::CheckBox();
			this->labelTotal = gcnew System::Windows::Forms::Label();
			this->SuspendLayout();
			// 
			// labelFirstName
			// 
			this->labelFirstName->Location = System::Drawing::Point(56, 40);
			this->labelFirstName->Name = "labelFirstName";
			this->labelFirstName->Size = System::Drawing::Size(64, 23);
			this->labelFirstName->TabIndex = 0;
			this->labelFirstName->Text = "First Name";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(144, 40);
			this->textBox1->Name = "textBox1";
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = "";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &GIUorderform1::Form1::textBox1_TextChanged);
			//	this->textBox1->TextChanged += new System::EventHandler(this, textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(288, 40);
			this->label2->Name = "label2";
			this->label2->TabIndex = 2;
			this->label2->Text = "Last Name";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(456, 40);
			this->textBox2->Name = "textBox2";
			this->textBox2->TabIndex = 3;
			this->textBox2->Text = "";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(168, 248);
			this->button1->Name = "button1";
			this->button1->TabIndex = 4;
			this->button1->Text = "Calculate";
			this->button1->Click += gcnew System::EventHandler(this, &GIUorderform1::Form1::button1_Click);
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(288, 80);
			this->label3->Name = "label3";
			this->label3->TabIndex = 7;
			this->label3->Text = "State";
			this->label3->Click += gcnew System::EventHandler(this, &GIUorderform1::Form1::label3_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(144, 80);
			this->textBox4->Name = "textBox4";
			this->textBox4->TabIndex = 6;
			this->textBox4->Text = "";
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(64, 80);
			this->label4->Name = "label4";
			this->label4->Size = System::Drawing::Size(64, 23);
			this->label4->TabIndex = 5;
			this->label4->Text = "City";
			// 
			// comboBox1
			// 
			// System::Object __mcTemp__1[] = new System::Object [44] = 
			
	//	 System::Object^ __mcTemp__1[] = new System::Object^ [44];

		/*
			__mcTemp__1[0] = "Alabama";
			__mcTemp__1[1] = "Alaska";
		    __mcTemp__1[2] = "Arizona";
		 

			
			__mcTemp__1[3] = "Arkansas";
			__mcTemp__1[4] = "California";
			__mcTemp__1[5] = "Colorado";
			__mcTemp__1[6] = "Delaware";
			__mcTemp__1[7] = "Florida";
			__mcTemp__1[8] = "Georgia";
			__mcTemp__1[9] = "Idaho";
			__mcTemp__1[10] = "Iowa";
			__mcTemp__1[11] = "Kansas";
			__mcTemp__1[12] = "Kentucky";
			__mcTemp__1[13] = "Louisiana";
			__mcTemp__1[14] = "Maine";
			__mcTemp__1[15] = "Massachusetts";
			__mcTemp__1[16] = "Michigan";
			__mcTemp__1[17] = "Minnesota";
			__mcTemp__1[18] = "Mississippi";
			__mcTemp__1[19] = "Missouri";
			__mcTemp__1[20] = "Montana";
			__mcTemp__1[21] = "Nebraska";
			__mcTemp__1[22] = "Nevada";
			__mcTemp__1[23] = "New Hampshire";
			__mcTemp__1[24] = "New Jersey";
			__mcTemp__1[25] = "New Mexico";
			__mcTemp__1[26] = "New York";
			__mcTemp__1[27] = "North Carolina";
			__mcTemp__1[28] = "North Dakota";
			__mcTemp__1[29] = "Ohio";
			__mcTemp__1[30] = "Oregon";
			__mcTemp__1[31] = "Pensylvania";
			__mcTemp__1[32] = "Rhode Island";
			__mcTemp__1[33] = "South Carolina";
			__mcTemp__1[34] = "South Dakota";
			__mcTemp__1[35] = "Tenesse";
			__mcTemp__1[36] = "Texas";
			__mcTemp__1[37] = "Utah";
			__mcTemp__1[38] = "Vermont";
			__mcTemp__1[39] = "Washington";
			__mcTemp__1[40] = "West Virginia";
			__mcTemp__1[41] = "Wisconsin";
			__mcTemp__1[42] = "Wyoming";
			__mcTemp__1[43] = "";
		*/	
			
		//	this->comboBox1->Items->AddRange(__mcTemp__1);
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Alabama", L"Alaska", L"California", L"Texas" });
			this->comboBox1->Location = System::Drawing::Point(456, 80);
			this->comboBox1->Name = "comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 8;
			this->comboBox1->Text = "Enter State";
			// 
			// checkBoxBoard
			// 
			this->checkBoxBoard->Location = System::Drawing::Point(72, 128);
			this->checkBoxBoard->Name = "checkBoxBoard";
			this->checkBoxBoard->TabIndex = 9;
			this->checkBoxBoard->Text = "Board";
			this->checkBoxBoard->CheckedChanged += gcnew System::EventHandler(this, &GIUorderform1::Form1::checkBox1_CheckedChanged);
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(160, 136);
			this->label5->Name = "label5";
			this->label5->TabIndex = 11;
			this->label5->Text = "Unit Price:  $120";
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(264, 136);
			this->label6->Name = "label6";
			this->label6->TabIndex = 12;
			this->label6->Text = "Quantity";
			// 
			// textBox3
			// 
			this->textBox3->Enabled = false;
			this->textBox3->Location = System::Drawing::Point(360, 136);
			this->textBox3->Name = "textBox3";
			this->textBox3->Size = System::Drawing::Size(104, 20);
			this->textBox3->TabIndex = 13;
			this->textBox3->Text = "";
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &GIUorderform1::Form1::textBox3_TextChanged);
			// 
			// labelboardsub
			// 
			this->labelboardsub->Location = System::Drawing::Point(488, 136);
			this->labelboardsub->Name = "labelboardsub";
			this->labelboardsub->TabIndex = 14;
			this->labelboardsub->Text = "Subtotal:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(392, 248);
			this->button2->Name = "button2";
			this->button2->TabIndex = 15;
			this->button2->Text = "Submit";
			this->button2->Click += gcnew System::EventHandler(this, &GIUorderform1::Form1::button2_Click);
			// 
			// labelbooksub
			// 
			this->labelbooksub->Location = System::Drawing::Point(488, 184);
			this->labelbooksub->Name = "labelbooksub";
			this->labelbooksub->TabIndex = 20;
			this->labelbooksub->Text = "Subtotal:";
			// 
			// textBox5
			// 
			this->textBox5->Enabled = false;
			this->textBox5->Location = System::Drawing::Point(360, 184);
			this->textBox5->Name = "textBox5";
			this->textBox5->Size = System::Drawing::Size(104, 20);
			this->textBox5->TabIndex = 19;
			this->textBox5->Text = "";
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &GIUorderform1::Form1::textBox5_TextChanged);
			// 
			// label9
			// 
			this->label9->Location = System::Drawing::Point(264, 184);
			this->label9->Name = "label9";
			this->label9->TabIndex = 18;
			this->label9->Text = "Quantity";
			// 
			// label10
			// 
			this->label10->Location = System::Drawing::Point(160, 184);
			this->label10->Name = "label10";
			this->label10->TabIndex = 17;
			this->label10->Text = "Unit Price:  $80";
			// 
			// checkBoxBook
			// 
			this->checkBoxBook->Location = System::Drawing::Point(72, 176);
			this->checkBoxBook->Name = "checkBoxBook";
			this->checkBoxBook->TabIndex = 16;
			this->checkBoxBook->Text = "Book";
			this->checkBoxBook->CheckedChanged += gcnew System::EventHandler(this, &GIUorderform1::Form1::checkBoxBook_CheckedChanged);
			// 
			// labelTotal
			// 
			this->labelTotal->Location = System::Drawing::Point(208, 216);
			this->labelTotal->Name = "labelTotal";
			this->labelTotal->TabIndex = 21;
			this->labelTotal->Text = "Total: ";
			// 
			// Form1
			// 
			this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
			this->ClientSize = System::Drawing::Size(624, 342);
			this->Controls->Add(this->labelTotal);
			this->Controls->Add(this->labelbooksub);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->checkBoxBook);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->labelboardsub);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->checkBoxBoard);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->labelFirstName);
			this->Name = "Form1";
			this->Text = "Form1";
			this->Load += gcnew System::EventHandler(this, &GIUorderform1::Form1::Form1_Load);
			this->ResumeLayout(false);

		}


	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
	{
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^ e)
	{
		/*
		count ++;
		String *output = new String ("Welcome ");
		output = String::Concat (output, textBox1->get_Text());
		output = String::Concat (output, textBox2->get_Text());
		MessageBox::Show (output, S"Hi");
		if (count % 2 == 0)
		labelFirstName->set_Visible(false);
		else
		labelFirstName->set_Visible(true);

		*/
		double x = 0.0, y;
		String^ z;

		z = textBox3->Text;
		try {
			x = Double::Parse(textBox3->Text);
		}
		catch (FormatException^ z) {
			x = 0.0;
		}
		x *= 120.0;
		try {
			y = Double::Parse(textBox5->Text);
		}
		catch (FormatException^ z) {
			y = 0.0;
		}
		y *= 80.0;
		x = x + y;
		labelTotal->Text = String::Concat(" Total is $: ", x.ToString());

	}

	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
	}

			 static int count;

	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		//textBox3->set_Enabled(true);
		textBox3->Enabled = true; // ?? not clear how to change
	}

	private: System::Void checkBoxBook_CheckedChanged(System::Object^ sender, System::EventArgs^  e)
	{
		textBox5->Enabled = true;
	}

	private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		double x;
		try {
			x = Double::Parse(textBox3->Text);
		}

		catch (FormatException^)
		{
			x = 0.0;
		}

		labelboardsub->Text = String::Concat("Subtotal: $ ", (120 * x).ToString());
	}

	private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		double x;
		try {
			x = Double::Parse(textBox5->Text);
		}

		catch (FormatException^)
		{
			x = 0.0;
		}

		labelboardsub->Text = String::Concat("Subtotal: $ ", (80 * x).ToString());
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^  e)
	{
		String^ output = gcnew String(" ");
		double subboard, subbook, total;
		output = String::Concat("Thanks for ordering with us \nName:", textBox1->Text,
			" ", textBox2->Text,
			"\nCity: ", textBox4->Text,
			"\nState: ", comboBox1->SelectedItem);

		try {
			subboard = Double::Parse(textBox3->Text);
		}
		catch (FormatException^) {
			subboard = 0.0;
		}
		try {
			subbook = Double::Parse(textBox5->Text);
		}
		catch (FormatException^) {
			subbook = 0.0;
		}

		total = subboard * 120.0 + subbook * 80.0;

		output = String::Concat(output, "\nOrder Details:\nItem\tQuantity\t",
			"Price\tSubtotal",
			"\nBoard\t", subboard.ToString(), "\t$120.0\t",
			(subboard*120.0).ToString(),
			"\nBook\t", subbook.ToString(), "\t$80.0\t",
			(subbook*80.0).ToString(),
			"\nTotal\t", total.ToString()
		);

		MessageBox::Show(output);
	}

	private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e)
	{
	}

	};
}
