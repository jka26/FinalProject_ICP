#pragma once
//#include <mysql.h>
#include <string>

namespace FinalProject_ICP {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class SignUpForm : public System::Windows::Forms::Form
    {
    public:
        SignUpForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~SignUpForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::TextBox^ txtFirstName;
        System::Windows::Forms::TextBox^ txtLastName;
        System::Windows::Forms::TextBox^ txtEmail;
        System::Windows::Forms::Button^ btnSubmit;
    private: System::Windows::Forms::ComboBox^ Role;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::TextBox^ textBox1;


           System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->txtFirstName = (gcnew System::Windows::Forms::TextBox());
            this->txtLastName = (gcnew System::Windows::Forms::TextBox());
            this->txtEmail = (gcnew System::Windows::Forms::TextBox());
            this->btnSubmit = (gcnew System::Windows::Forms::Button());
            this->Role = (gcnew System::Windows::Forms::ComboBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->SuspendLayout();
            // 
            // txtFirstName
            // 
            this->txtFirstName->ForeColor = System::Drawing::Color::Gray;
            this->txtFirstName->Location = System::Drawing::Point(75, 77);
            this->txtFirstName->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->txtFirstName->Name = L"txtFirstName";
            this->txtFirstName->Size = System::Drawing::Size(298, 26);
            this->txtFirstName->TabIndex = 0;
            this->txtFirstName->Text = L"First Name";
            this->txtFirstName->GotFocus += gcnew System::EventHandler(this, &SignUpForm::RemovePlaceholderFirstName);
            this->txtFirstName->LostFocus += gcnew System::EventHandler(this, &SignUpForm::AddPlaceholderFirstName);
            // 
            // txtLastName
            // 
            this->txtLastName->ForeColor = System::Drawing::Color::Gray;
            this->txtLastName->Location = System::Drawing::Point(75, 131);
            this->txtLastName->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->txtLastName->Name = L"txtLastName";
            this->txtLastName->Size = System::Drawing::Size(298, 26);
            this->txtLastName->TabIndex = 1;
            this->txtLastName->Text = L"Last Name";
            this->txtLastName->GotFocus += gcnew System::EventHandler(this, &SignUpForm::RemovePlaceholderLastName);
            this->txtLastName->LostFocus += gcnew System::EventHandler(this, &SignUpForm::AddPlaceholderLastName);
            // 
            // txtEmail
            // 
            this->txtEmail->ForeColor = System::Drawing::Color::Gray;
            this->txtEmail->Location = System::Drawing::Point(75, 182);
            this->txtEmail->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->txtEmail->Name = L"txtEmail";
            this->txtEmail->Size = System::Drawing::Size(298, 26);
            this->txtEmail->TabIndex = 2;
            this->txtEmail->Text = L"Email";
            this->txtEmail->GotFocus += gcnew System::EventHandler(this, &SignUpForm::RemovePlaceholderEmail);
            this->txtEmail->LostFocus += gcnew System::EventHandler(this, &SignUpForm::AddPlaceholderEmail);
            // 
            // btnSubmit
            // 
            this->btnSubmit->Location = System::Drawing::Point(123, 374);
            this->btnSubmit->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->btnSubmit->Name = L"btnSubmit";
            this->btnSubmit->Size = System::Drawing::Size(181, 46);
            this->btnSubmit->TabIndex = 3;
            this->btnSubmit->Text = L"Submit";
            this->btnSubmit->UseVisualStyleBackColor = true;
            this->btnSubmit->Click += gcnew System::EventHandler(this, &SignUpForm::btnSubmit_Click);
            // 
            // Role
            // 
            this->Role->FormattingEnabled = true;
            this->Role->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Student", L"Faculty", L"Admin" });
            this->Role->Location = System::Drawing::Point(123, 299);
            this->Role->Name = L"Role";
            this->Role->Size = System::Drawing::Size(250, 28);
            this->Role->TabIndex = 4;
            this->Role->Tag = L"";
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(71, 302);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(46, 20);
            this->label1->TabIndex = 5;
            this->label1->Text = L"Role:";
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(75, 244);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(298, 26);
            this->textBox1->TabIndex = 6;
            // 
            // SignUpForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(450, 462);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->Role);
            this->Controls->Add(this->txtFirstName);
            this->Controls->Add(this->txtLastName);
            this->Controls->Add(this->txtEmail);
            this->Controls->Add(this->btnSubmit);
            this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
            this->Name = L"SignUpForm";
            this->Text = L"Signup";
            this->Load += gcnew System::EventHandler(this, &SignUpForm::SignUpForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }

        // Placeholder handling
        void RemovePlaceholderFirstName(Object^ sender, EventArgs^ e)
        {
            if (txtFirstName->Text == "First Name")
            {
                txtFirstName->Text = "";
                txtFirstName->ForeColor = System::Drawing::Color::Black;
            }
        }

        void AddPlaceholderFirstName(Object^ sender, EventArgs^ e)
        {
            if (String::IsNullOrWhiteSpace(txtFirstName->Text))
            {
                txtFirstName->Text = "First Name";
                txtFirstName->ForeColor = System::Drawing::Color::Gray;
            }
        }

        void RemovePlaceholderLastName(Object^ sender, EventArgs^ e)
        {
            if (txtLastName->Text == "Last Name")
            {
                txtLastName->Text = "";
                txtLastName->ForeColor = System::Drawing::Color::Black;
            }
        }

        void AddPlaceholderLastName(Object^ sender, EventArgs^ e)
        {
            if (String::IsNullOrWhiteSpace(txtLastName->Text))
            {
                txtLastName->Text = "Last Name";
                txtLastName->ForeColor = System::Drawing::Color::Gray;
            }
        }

        void RemovePlaceholderEmail(Object^ sender, EventArgs^ e)
        {
            if (txtEmail->Text == "Email")
            {
                txtEmail->Text = "";
                txtEmail->ForeColor = System::Drawing::Color::Black;
            }
        }

        void AddPlaceholderEmail(Object^ sender, EventArgs^ e)
        {
            if (String::IsNullOrWhiteSpace(txtEmail->Text))
            {
                txtEmail->Text = "Email";
                txtEmail->ForeColor = System::Drawing::Color::Gray;
            }
        }

        // Submit button functionality
        void btnSubmit_Click(Object^ sender, EventArgs^ e)
        {
            String^ firstName = this->txtFirstName->Text;
            String^ lastName = this->txtLastName->Text;
            String^ email = this->txtEmail->Text;

            if (String::IsNullOrWhiteSpace(firstName) || firstName == "First Name" ||
                String::IsNullOrWhiteSpace(lastName) || lastName == "Last Name" ||
                String::IsNullOrWhiteSpace(email) || email == "Email")
            {
                MessageBox::Show("Please fill out all fields.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            try
            {
                String^ connString = "Server=localhost;Uid=jemi;Pwd=SjQeLm1#;Database=university_db;";
                MySqlConnection^ conn = gcnew MySqlConnection(connString);
                conn->Open();

                String^ query = "INSERT INTO users (first_name, last_name, email) VALUES (@FirstName, @LastName, @Email)";
                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                cmd->Parameters->AddWithValue("@FirstName", firstName);
                cmd->Parameters->AddWithValue("@LastName", lastName);
                cmd->Parameters->AddWithValue("@Email", email);
                cmd->ExecuteNonQuery();

                conn->Close();
                MessageBox::Show("Registration Successful!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("An error occurred: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
    private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void SignUpForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
