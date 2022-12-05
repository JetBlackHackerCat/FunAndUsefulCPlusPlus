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
// #pragma once



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
		private: System::Windows::Forms::Button^  button1;
		public:

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
				this->button1 = (gcnew System::Windows::Forms::Button());
				this->SuspendLayout();
				// 
				// button1
				// 
				this->button1->Location = System::Drawing::Point(232, 33);
				this->button1->Name = L"button1";
				this->button1->Size = System::Drawing::Size(75, 23);
				this->button1->TabIndex = 0;
				this->button1->Text = L"button1";
				this->button1->UseVisualStyleBackColor = true;
				this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
				// 
				// Form1
				// 
				this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
				this->ClientSize = System::Drawing::Size(543, 288);
				this->Controls->Add(this->button1);
				this->Name = L"Form1";
				this->Text = L"Draw 15 puzzle";
				this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
				this->ResumeLayout(false);

			}



		protected:

			void OnPaint(PaintEventArgs paintEvent) {

			//	__super::OnPaint(paintEvent);

				// get graphics object

				Graphics^ graphicsObject = paintEvent.Graphics;
				SolidBrush^ brush = gcnew SolidBrush(Color::Blue);
				Pen^ pen = gcnew Pen(Color::Black);
				// pen->set_Width(1);  // set the thickness of the line



				int cellSide = 40; // specify the side of a cell (there are 16 cells)
				int lx = 50, ly = 40; // specify upper left cornet at (50, 50)
				// Draw 5 horizontal lines with nested for loops

				for (int j = 0; j < 5; j++) // Draw 5 horizontal lines
					for (int i = 0; i < 4; i++)  // Draw 4 segments of each horizontal line; here j stays the same
					{
						graphicsObject->DrawLine(pen, lx + i * cellSide, ly + j * cellSide, lx + (i + 1) * cellSide, ly + j * cellSide);
					}

				// Draw 5 vertical lines with nested for loops

				for (int i = 0; i < 5; i++) // Draw 5 vertical lines
					for (int j = 0; j < 4; j++)  // Draw 4 segments of each vertical line; here i stays the same
					{
						graphicsObject->DrawLine(pen, lx + i * cellSide, ly + j * cellSide, lx + i * cellSide, ly + (j + 1) * cellSide);
					}

				// Sketch the 15 integers

					// Set brush with the font style and font typeface, point size


				FontStyle style = FontStyle::Regular;
				Drawing::Font^ arial = gcnew Drawing::Font("Arial", 12, style);


				String^ s;


				for (int k = 0; k < 15; k++)
				{

					s = (k + 1).ToString();
					graphicsObject->DrawString(s, arial, brush, lx + (k % 4) * cellSide + cellSide / 2, ly + (k / 4) * cellSide + cellSide / 2);
				}



			}
		private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
		{
		}

		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			//	__super::OnPaint(paintEvent);

				// get graphics object

			Graphics^ graphicsObject = CreateGraphics();
			SolidBrush^ brush = gcnew SolidBrush(Color::Blue);
			Pen^ pen = gcnew Pen(Color::Black);
			// pen->set_Width(1);  // set the thickness of the line



			int cellSide = 40; // specify the side of a cell (there are 16 cells)
			int lx = 50, ly = 40; // specify upper left cornet at (50, 50)
			// Draw 5 horizontal lines with nested for loops

			for (int j = 0; j < 5; j++) // Draw 5 horizontal lines
				for (int i = 0; i < 4; i++)  // Draw 4 segments of each horizontal line; here j stays the same
				{
					graphicsObject->DrawLine(pen, lx + i * cellSide, ly + j * cellSide, lx + (i + 1) * cellSide, ly + j * cellSide);
				}

			// Draw 5 vertical lines with nested for loops

			for (int i = 0; i < 5; i++) // Draw 5 vertical lines
				for (int j = 0; j < 4; j++)  // Draw 4 segments of each vertical line; here i stays the same
				{
					graphicsObject->DrawLine(pen, lx + i * cellSide, ly + j * cellSide, lx + i * cellSide, ly + (j + 1) * cellSide);
				}

			// Sketch the 15 integers

				// Set brush with the font style and font typeface, point size


			FontStyle style = FontStyle::Regular;
			Drawing::Font^ arial = gcnew Drawing::Font("Arial", 12, style);


			String^ s;


			for (int k = 0; k < 15; k++)
			{

				s = (k + 1).ToString();
				graphicsObject->DrawString(s, arial, brush, lx + (k % 4) * cellSide + cellSide / 2, ly + (k / 4) * cellSide + cellSide / 2);
			}



		}
};
	


}
