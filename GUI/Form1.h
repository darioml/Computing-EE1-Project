#pragma once
#include "EnDeFunctions.h"

namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::Label^  label2;


	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(46, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(291, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Dario\'s Matrix Text Encryptor / Decryptor";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(53, 320);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(133, 32);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Encrypt!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 65);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Decrypted Text:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(25, 166);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(56, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Password:";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(97, 164);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(78, 20);
			this->numericUpDown1->TabIndex = 5;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(192, 164);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(78, 20);
			this->numericUpDown2->TabIndex = 6;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(287, 164);
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(78, 20);
			this->numericUpDown3->TabIndex = 7;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(28, 81);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(337, 77);
			this->richTextBox1->TabIndex = 8;
			this->richTextBox1->Text = L"";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(204, 320);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(133, 32);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Decrypt!";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(28, 215);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(337, 77);
			this->richTextBox2->TabIndex = 11;
			this->richTextBox2->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 199);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(82, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Encrypted Text:";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(377, 382);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(387, 414);
			this->MinimumSize = System::Drawing::Size(387, 414);
			this->Name = L"Form1";
			this->Text = L"Matrix Text En/Decryptor 1.2";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
		{
			button1->Text = "working...";
			button1->Enabled = false;
			button2->Enabled = false;
			//String^ MyInfoDisp = gcnew String(outputMatrix(createEncryptionMatrix(1, 2, 3), 5).c_str());
			//richTextBox3->Text = MyInfoDisp;
			vector<double> inputData;
			String^ encryptText = richTextBox1->Text;
			for(int i = 0; i < (encryptText->Length); i++)
			{
				inputData.push_back((int)encryptText[i]);
			}
			Matrix dataMatrix = Create3xX(inputData);
			Matrix encryMatrix = createEncryptionMatrix(Decimal::ToInt32(numericUpDown1->Value), Decimal::ToInt32(numericUpDown2->Value), Decimal::ToInt32(numericUpDown3->Value));

			Matrix multiply = multiplyMatrix(encryMatrix, dataMatrix);

			String^ MyInfoDisp = gcnew String(outputString(multiply).c_str());
			richTextBox2->Text = MyInfoDisp;

			button1->Enabled = true;
			button1->Text = "Encrypt!";
			button2->Enabled = true;
		}
	public:
void MarshalString ( String ^ s, string& os )
{
	using namespace Runtime::InteropServices;
	const char* chars = 
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}
	private: 
		System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
		{
			string encryptText;
			MarshalString(richTextBox2->Text, encryptText);

			if (encryptText.length() > 1)
			{
				string input;
				double inputNum;
				stringstream test (encryptText);
				vector<double> decrypt;
				while (test >> input) //if there is some text to read...
				{
					stringstream two (input);
					if (two >> inputNum) //and if it is a number...
					{
						decrypt.push_back(inputNum);
					}
				}

				Matrix dataMatrix = Create3xX(decrypt);
				Matrix decryMatrix = CreateMInverse(createEncryptionMatrix(Decimal::ToInt32(numericUpDown1->Value), Decimal::ToInt32(numericUpDown2->Value), Decimal::ToInt32(numericUpDown3->Value)));
			
				Matrix multiply = multiplyMatrix(decryMatrix, dataMatrix);

				string output;
				for (int i = 0; i < multiply.theData.size(); i++)
				{
					output += (char)multiply.theData[i];
				}

				String^ MyInfoDisp = gcnew String(output.c_str());
				richTextBox1->Text = MyInfoDisp;
			}
		}
};
}



