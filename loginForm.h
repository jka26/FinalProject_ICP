#pragma once

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
        // Public properties to store authenticated user's info
        property String^ UserRole;
        property String^ UserID;

    private:
        // Form components
        System::Windows::Forms::Panel^ mainPanel;
        System::Windows::Forms::Panel^ headerPanel;
        System::Windows::Forms::Panel^ formPanel;
        System::Windows::Forms::Label^ lblTitle;
        System::Windows::Forms::Label^ lblEmail;
        System::Windows::Forms::TextBox^ txtEmail;
        System::Windows::Forms::Button^ btnLogin;
        System::Windows::Forms::Button^ btnExit;
        System::Windows::Forms::LinkLabel^ lnkForgotPassword;
        System::Windows::Forms::LinkLabel^ lnkCreateAccount;
        System::ComponentModel::Container^ components;

        // Database connection
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
            this->Text = L"University Management System";
            this->StartPosition = FormStartPosition::CenterScreen;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Size = System::Drawing::Size(800, 500);
            this->BackColor = System::Drawing::Color::White;

            // Main Panel (container)
            this->mainPanel = gcnew System::Windows::Forms::Panel();
            this->mainPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->mainPanel->Padding = System::Windows::Forms::Padding::Empty;

            // Header Panel
            this->headerPanel = gcnew System::Windows::Forms::Panel();
            this->headerPanel->BackColor = System::Drawing::Color::FromArgb(0, 71, 160);
            this->headerPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->headerPanel->Height = 60;

            // Title Label
            this->lblTitle = gcnew System::Windows::Forms::Label();
            this->lblTitle->Text = L"UNIVERSITY MANAGEMENT SYSTEM";
            this->lblTitle->Font = gcnew System::Drawing::Font("Segoe UI", 16, FontStyle::Bold);
            this->lblTitle->ForeColor = System::Drawing::Color::White;
            this->lblTitle->AutoSize = false;
            this->lblTitle->Size = System::Drawing::Size(800, 60);
            this->lblTitle->TextAlign = ContentAlignment::MiddleCenter;
            this->headerPanel->Controls->Add(this->lblTitle);

            // Form Panel (login container)
            this->formPanel = gcnew System::Windows::Forms::Panel();
            this->formPanel->Location = System::Drawing::Point(250, 100);
            this->formPanel->Size = System::Drawing::Size(300, 300);
            this->formPanel->BackColor = System::Drawing::Color::White;

            // Email Label
            this->lblEmail = gcnew System::Windows::Forms::Label();
            this->lblEmail->Text = L"Email";
            this->lblEmail->Location = System::Drawing::Point(0, 20);
            this->lblEmail->Size = System::Drawing::Size(300, 20);
            this->lblEmail->Font = gcnew System::Drawing::Font("Segoe UI", 10);
            this->lblEmail->ForeColor = System::Drawing::Color::FromArgb(64, 64, 64);

            // Email TextBox
            this->txtEmail = gcnew System::Windows::Forms::TextBox();
            this->txtEmail->Location = System::Drawing::Point(0, 45);
            this->txtEmail->Size = System::Drawing::Size(300, 30);
            this->txtEmail->Font = gcnew System::Drawing::Font("Segoe UI", 12);
            this->txtEmail->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

            // Login Button
            this->btnLogin = gcnew System::Windows::Forms::Button();
            this->btnLogin->Text = L"LOGIN";
            this->btnLogin->Location = System::Drawing::Point(0, 100);
            this->btnLogin->Size = System::Drawing::Size(300, 40);
            this->btnLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnLogin->BackColor = System::Drawing::Color::FromArgb(0, 71, 160);
            this->btnLogin->ForeColor = System::Drawing::Color::White;
            this->btnLogin->Font = gcnew System::Drawing::Font("Segoe UI", 12, FontStyle::Bold);
            this->btnLogin->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnLogin->Click += gcnew System::EventHandler(this, &LoginForm::btnLogin_Click);

            // Forgot Password Link
            this->lnkForgotPassword = gcnew System::Windows::Forms::LinkLabel();
            this->lnkForgotPassword->Text = L"Forgot Password?";
            this->lnkForgotPassword->Location = System::Drawing::Point(0, 150);
            this->lnkForgotPassword->Size = System::Drawing::Size(300, 20);
            this->lnkForgotPassword->TextAlign = ContentAlignment::MiddleCenter;
            this->lnkForgotPassword->LinkColor = System::Drawing::Color::FromArgb(0, 71, 160);
            this->lnkForgotPassword->Font = gcnew System::Drawing::Font("Segoe UI", 9);
            this->lnkForgotPassword->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(
                this, &LoginForm::lnkForgotPassword_LinkClicked);

            // Create Account Link
            this->lnkCreateAccount = gcnew System::Windows::Forms::LinkLabel();
            this->lnkCreateAccount->Text = L"Don't have an account? Sign up";
            this->lnkCreateAccount->Location = System::Drawing::Point(0, 180);
            this->lnkCreateAccount->Size = System::Drawing::Size(300, 20);
            this->lnkCreateAccount->TextAlign = ContentAlignment::MiddleCenter;
            this->lnkCreateAccount->LinkColor = System::Drawing::Color::FromArgb(0, 71, 160);
            this->lnkCreateAccount->Font = gcnew System::Drawing::Font("Segoe UI", 9);
            this->lnkCreateAccount->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(
                this, &LoginForm::lnkCreateAccount_LinkClicked);

            // Exit Button
            this->btnExit = gcnew System::Windows::Forms::Button();
            this->btnExit->Text = L"Exit";
            this->btnExit->Location = System::Drawing::Point(0, 220);
            this->btnExit->Size = System::Drawing::Size(300, 40);
            this->btnExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnExit->BackColor = System::Drawing::Color::White;
            this->btnExit->ForeColor = System::Drawing::Color::FromArgb(0, 71, 160);
            this->btnExit->Font = gcnew System::Drawing::Font("Segoe UI", 12);
            this->btnExit->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btnExit->Click += gcnew System::EventHandler(this, &LoginForm::btnExit_Click);

            // Add controls to panels
            this->formPanel->Controls->Add(this->lblEmail);
            this->formPanel->Controls->Add(this->txtEmail);
            this->formPanel->Controls->Add(this->btnLogin);
            this->formPanel->Controls->Add(this->lnkForgotPassword);
            this->formPanel->Controls->Add(this->lnkCreateAccount);
            this->formPanel->Controls->Add(this->btnExit);

            // Add panels to form
            this->Controls->Add(this->headerPanel);
            this->Controls->Add(this->formPanel);

            // Set accept button
            this->AcceptButton = this->btnLogin;
        }

        void btnLogin_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (String::IsNullOrEmpty(txtEmail->Text)) {
                MessageBox::Show("Please enter your email address.",
                    "Login Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            try {
                if (sqlConnection->State == ConnectionState::Closed) {
                    sqlConnection->Open();
                }

                String^ query = "SELECT user_id, role FROM users WHERE email = @email";

                MySqlCommand^ cmd = gcnew MySqlCommand(query, sqlConnection);
                cmd->Parameters->AddWithValue("@email", txtEmail->Text);

                MySqlDataReader^ reader = cmd->ExecuteReader();

                if (reader->Read()) {
                    this->UserID = reader["user_id"]->ToString();
                    this->UserRole = reader["role"]->ToString();

                    this->DialogResult = System::Windows::Forms::DialogResult::OK;
                    MessageBox::Show("Welcome back!", "Login Successful",
                        MessageBoxButtons::OK, MessageBoxIcon::Information);

                    this->Hide();
                    // Main form navigation would go here
                }
                else {
                    MessageBox::Show("Invalid email address.",
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

        void btnExit_Click(System::Object^ sender, System::EventArgs^ e)
        {
            Application::Exit();
        }

        void lnkForgotPassword_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
        {
            MessageBox::Show("Please contact your system administrator for assistance.",
                "Account Help", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        void lnkCreateAccount_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
        {
            this->Hide();
            SignUpForm^ signupForm = gcnew SignUpForm();
            signupForm->ShowDialog();
            this->Show();
        }
    };
}