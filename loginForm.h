#pragma once

#include "signup.h"
// Forward declare SignUpForm to resolve circular dependency
namespace FinalProject_ICP {
    ref class SignUpForm;
}

namespace FinalProject_ICP {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class LoginForm : public System::Windows::Forms::Form
    {
    public:
        property String^ UserRole;
        property String^ UserID;

    private:
        // Form components
        System::Windows::Forms::Panel^ headerPanel;
        System::Windows::Forms::Panel^ mainPanel;
        System::Windows::Forms::Label^ lblTitle;
        System::Windows::Forms::Label^ lblEmail;
        System::Windows::Forms::Label^ lblPassword;
        System::Windows::Forms::TextBox^ txtEmail;
        System::Windows::Forms::TextBox^ txtPassword;
        System::Windows::Forms::Button^ btnLogin;
        System::Windows::Forms::Button^ btnCancel;
        System::Windows::Forms::LinkLabel^ lnkForgotPassword;
        System::Windows::Forms::LinkLabel^ lnkCreateAccount;
        System::ComponentModel::Container^ components;

        MySqlConnection^ sqlConnection;
        String^ connectString = "server=localhost;port=3306;database=university_db;uid=root;password=";

    public:
        LoginForm(void)
        {
            InitializeComponent();
            ConfigureDatabase();
        }

    protected:
        ~LoginForm()
        {
            if (components)
            {
                delete components;
            }
            if (sqlConnection)
            {
                sqlConnection->Close();
                delete sqlConnection;
            }
        }

    private:
        void ConfigureDatabase(void)
        {
            try {
                sqlConnection = gcnew MySqlConnection(connectString);
            }
            catch (Exception^ ex) {
                MessageBox::Show("Database configuration error: " + ex->Message,
                    "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        void InitializeComponent(void)
        {
            this->components = gcnew System::ComponentModel::Container();

            // Form Configuration
            this->Text = L"Login - University Management System";
            this->StartPosition = FormStartPosition::CenterScreen;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Size = System::Drawing::Size(600, 700);
            this->BackColor = System::Drawing::Color::White;

            // Header Panel
            this->headerPanel = gcnew System::Windows::Forms::Panel();
            this->headerPanel->BackColor = System::Drawing::Color::FromArgb(0, 71, 160);
            this->headerPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->headerPanel->Height = 80;

            // Title Label
            this->lblTitle = gcnew System::Windows::Forms::Label();
            this->lblTitle->Text = L"LOGIN";
            this->lblTitle->Font = gcnew System::Drawing::Font("Segoe UI", 20, FontStyle::Bold);
            this->lblTitle->ForeColor = System::Drawing::Color::White;
            this->lblTitle->AutoSize = false;
            this->lblTitle->Size = System::Drawing::Size(600, 80);
            this->lblTitle->TextAlign = ContentAlignment::MiddleCenter;
            this->headerPanel->Controls->Add(this->lblTitle);

            // Main Panel
            this->mainPanel = gcnew System::Windows::Forms::Panel();
            this->mainPanel->Location = System::Drawing::Point(50, 100);
            this->mainPanel->Size = System::Drawing::Size(500, 550);
            this->mainPanel->BackColor = System::Drawing::Color::White;

            // Email Label
            this->lblEmail = gcnew System::Windows::Forms::Label();
            this->lblEmail->Text = L"Email";
            this->lblEmail->Location = System::Drawing::Point(0, 20);
            this->lblEmail->Size = System::Drawing::Size(500, 20);
            this->lblEmail->Font = gcnew System::Drawing::Font("Segoe UI", 10);
            this->lblEmail->ForeColor = System::Drawing::Color::FromArgb(64, 64, 64);

            // Email TextBox
            this->txtEmail = gcnew System::Windows::Forms::TextBox();
            this->txtEmail->Location = System::Drawing::Point(0, 45);
            this->txtEmail->Size = System::Drawing::Size(500, 30);
            this->txtEmail->Font = gcnew System::Drawing::Font("Segoe UI", 12);
            this->txtEmail->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txtEmail->ForeColor = System::Drawing::Color::Gray;
            this->txtEmail->Text = L"Email";
            this->txtEmail->GotFocus += gcnew System::EventHandler(this, &LoginForm::RemovePlaceholder);
            this->txtEmail->LostFocus += gcnew System::EventHandler(this, &LoginForm::AddPlaceholder);

            // Password Label
            this->lblPassword = gcnew System::Windows::Forms::Label();
            this->lblPassword->Text = L"Password";
            this->lblPassword->Location = System::Drawing::Point(0, 90);
            this->lblPassword->Size = System::Drawing::Size(500, 20);
            this->lblPassword->Font = gcnew System::Drawing::Font("Segoe UI", 10);
            this->lblPassword->ForeColor = System::Drawing::Color::FromArgb(64, 64, 64);

            // Password TextBox
            this->txtPassword = gcnew System::Windows::Forms::TextBox();
            this->txtPassword->Location = System::Drawing::Point(0, 115);
            this->txtPassword->Size = System::Drawing::Size(500, 30);
            this->txtPassword->Font = gcnew System::Drawing::Font("Segoe UI", 12);
            this->txtPassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txtPassword->ForeColor = System::Drawing::Color::Gray;
            this->txtPassword->Text = L"Password";
            this->txtPassword->GotFocus += gcnew System::EventHandler(this, &LoginForm::RemovePlaceholder);
            this->txtPassword->LostFocus += gcnew System::EventHandler(this, &LoginForm::AddPlaceholder);

            // Login Button
            this->btnLogin = gcnew System::Windows::Forms::Button();
            this->btnLogin->Text = L"LOGIN";
            this->btnLogin->Location = System::Drawing::Point(0, 180);
            this->btnLogin->Size = System::Drawing::Size(500, 40);
            this->btnLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnLogin->BackColor = System::Drawing::Color::FromArgb(0, 71, 160);
            this->btnLogin->ForeColor = System::Drawing::Color::White;
            this->btnLogin->Font = gcnew System::Drawing::Font("Segoe UI", 12, FontStyle::Bold);
            this->btnLogin->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnLogin->Click += gcnew System::EventHandler(this, &LoginForm::btnLogin_Click);

            // Cancel Button
            this->btnCancel = gcnew System::Windows::Forms::Button();
            this->btnCancel->Text = L"EXIT";
            this->btnCancel->Location = System::Drawing::Point(0, 230);
            this->btnCancel->Size = System::Drawing::Size(500, 40);
            this->btnCancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnCancel->BackColor = System::Drawing::Color::White;
            this->btnCancel->ForeColor = System::Drawing::Color::FromArgb(0, 71, 160);
            this->btnCancel->Font = gcnew System::Drawing::Font("Segoe UI", 12);
            this->btnCancel->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnCancel->Click += gcnew System::EventHandler(this, &LoginForm::btnCancel_Click);

            // Forgot Password Link
            this->lnkForgotPassword = gcnew System::Windows::Forms::LinkLabel();
            this->lnkForgotPassword->Text = L"Forgot Password?";
            this->lnkForgotPassword->Location = System::Drawing::Point(0, 280);
            this->lnkForgotPassword->Size = System::Drawing::Size(500, 30);
            this->lnkForgotPassword->TextAlign = ContentAlignment::MiddleCenter;
            this->lnkForgotPassword->LinkColor = System::Drawing::Color::FromArgb(0, 71, 160);
            this->lnkForgotPassword->Font = gcnew System::Drawing::Font("Segoe UI", 10);
            this->lnkForgotPassword->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(
                this, &LoginForm::lnkForgotPassword_LinkClicked);

            // Create Account Link
            this->lnkCreateAccount = gcnew System::Windows::Forms::LinkLabel();
            this->lnkCreateAccount->Text = L"Don't have an account? Sign up";
            this->lnkCreateAccount->Location = System::Drawing::Point(0, 310);
            this->lnkCreateAccount->Size = System::Drawing::Size(500, 30);
            this->lnkCreateAccount->TextAlign = ContentAlignment::MiddleCenter;
            this->lnkCreateAccount->LinkColor = System::Drawing::Color::FromArgb(0, 71, 160);
            this->lnkCreateAccount->Font = gcnew System::Drawing::Font("Segoe UI", 10);
            this->lnkCreateAccount->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(
                this, &LoginForm::lnkCreateAccount_LinkClicked);

            // Add controls to main panel
            this->mainPanel->Controls->Add(this->lblEmail);
            this->mainPanel->Controls->Add(this->txtEmail);
            this->mainPanel->Controls->Add(this->lblPassword);
            this->mainPanel->Controls->Add(this->txtPassword);
            this->mainPanel->Controls->Add(this->btnLogin);
            this->mainPanel->Controls->Add(this->btnCancel);
            this->mainPanel->Controls->Add(this->lnkForgotPassword);
            this->mainPanel->Controls->Add(this->lnkCreateAccount);

            // Add panels to form
            this->Controls->Add(this->headerPanel);
            this->Controls->Add(this->mainPanel);

            // Set accept button
            this->AcceptButton = this->btnLogin;
        }

        void RemovePlaceholder(Object^ sender, EventArgs^ e)
        {
            TextBox^ textBox = safe_cast<TextBox^>(sender);
            if (textBox->ForeColor == System::Drawing::Color::Gray)
            {
                textBox->Text = "";
                textBox->ForeColor = System::Drawing::Color::Black;
                if (textBox == txtPassword)
                {
                    textBox->PasswordChar = '*';
                }
            }
        }

        void AddPlaceholder(Object^ sender, EventArgs^ e)
        {
            TextBox^ textBox = safe_cast<TextBox^>(sender);
            if (String::IsNullOrWhiteSpace(textBox->Text))
            {
                if (textBox == txtEmail)
                {
                    textBox->Text = "Email";
                }
                else if (textBox == txtPassword)
                {
                    textBox->Text = "Password";
                    textBox->PasswordChar = '\0';
                }
                textBox->ForeColor = System::Drawing::Color::Gray;
            }
        }

        void btnLogin_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (txtEmail->Text == "Email" || txtPassword->Text == "Password" ||
                String::IsNullOrWhiteSpace(txtEmail->Text) || String::IsNullOrWhiteSpace(txtPassword->Text)) {
                MessageBox::Show("Please enter both email and password.",
                    "Login Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            try {
                if (sqlConnection->State == ConnectionState::Closed) {
                    sqlConnection->Open();
                }

                String^ query = "SELECT user_id, role, password FROM users WHERE email = @email";

                MySqlCommand^ cmd = gcnew MySqlCommand(query, sqlConnection);
                cmd->Parameters->AddWithValue("@email", txtEmail->Text);

                MySqlDataReader^ reader = cmd->ExecuteReader();

                if (reader->Read()) {
                    String^ storedPassword = reader["password"]->ToString();

                    if (storedPassword == txtPassword->Text) { // In production, use proper password verification
                        this->UserID = reader["user_id"]->ToString();
                        this->UserRole = reader["role"]->ToString();

                        this->DialogResult = System::Windows::Forms::DialogResult::OK;
                        MessageBox::Show("Welcome back!", "Login Successful",
                            MessageBoxButtons::OK, MessageBoxIcon::Information);

                        this->Hide();
                        // Main form navigation would go here
                    }
                    else {
                        MessageBox::Show("Invalid password.",
                            "Login Failed", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    }
                }
                else {
                    MessageBox::Show("Email not found.",
                        "Login Failed", MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
            }
            catch (Exception^ ex) {
                MessageBox::Show("Login error: " + ex->Message,
                    "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
            finally {
                if (sqlConnection->State == ConnectionState::Open) {
                    sqlConnection->Close();
                }
            }
        }

        void btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
        {
            Application::Exit();
        }

        void lnkForgotPassword_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
        {
            MessageBox::Show("Please contact your system administrator to reset your password.",
                "Password Reset", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        void lnkCreateAccount_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
        {
            SignUpForm^ signupForm = gcnew SignUpForm();
            this->Hide();
            signupForm->Show();
        }
    };
}