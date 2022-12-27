#pragma once

namespace CppCLR_WinformsProjekt
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	// public ref class Form1 : public System::Windows::Forms::Form
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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;

	private: static int count = 0;

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
			this->button1 = gcnew System::Windows::Forms::Button();
			this->button2 = gcnew System::Windows::Forms::Button();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(104, 88);
			this->button1->Name = L"button1";
			this->button1->TabIndex = 0;
			this->button1->Text = L"MoveMe";
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			
			// this->button1->Click += new System::EventHandler(this, button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(288, 88);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(200, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"ChangeMe";
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// this->button2->Click += new System::EventHandler(this, button2_Click);
			// 
			// Form1
			// 
			this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
			this->ClientSize = System::Drawing::Size(600, 374);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			// this->Load += new System::EventHandler(this, Form1_Load);
			this->ResumeLayout(false);

		}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^  e)
	{
		count++;

		//	 button1->set_Left (button1->get_Left() + 20);
		
	//	button1->set_Top(button1->get_Top() + 20);
		button1->Top = button1->Top + 20;
		
		switch (count % 5) {
		case 0:
		//	button1->set_BackColor(Color::Red);
			button1->BackColor = Color::Red;
			break;
		case 1:
		//	button1->set_BackColor(Color::Green);
			button1->BackColor = Color::Green;
			break;
		case 2:
		//	button1->set_BackColor(Color::Blue);
			button1->BackColor = Color::Blue;
			break;
		case 3:
		//	button1->set_BackColor(Color::Orange);
			button1->BackColor = Color::Orange;
			break;
		case 4:
		//	button1->set_BackColor(Color::Purple);
			button1->BackColor = Color::Purple;
			break;
		default:

		//	button1->set_BackColor(Color::DarkGray);
			button1->BackColor = Color::DarkGray;
			break;

		}


	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		count++;
		switch (count % 3)
		{
		case 0:
			button2->Text = L"Como esta usted?";
			//button2->set_Text("Como esta usted?");
			break;
		case 1:
		//	button2->set_Text("Comment allez vous?");
			button2->Text = L"Comment allez vous ? ";
			break;
		case 2:
		//	button2->set_Text("Wie gehts?");
			button2->Text = L"Wie gehts? ";
			break;
		default:
		//	button2->set_Text("Change me!");
			button2->Text = L"Change me! ";
			break;
		}
	}

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
	{
	}

	};
}
