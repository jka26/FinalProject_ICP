#pragma once
#include <string>
#include <regex>
#include "loginForm.h"

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
    private:
        System::Windows::Forms::Panel^ headerPanel;
        System::Windows::Forms::Panel^ mainPanel;
        System::Windows::Forms::Label^ lblTitle;
        System::Windows::Forms::TextBox^ txtFirstName;
        System::Windows::Forms::TextBox^ txtLastName;
        System::Windows::Forms::TextBox^ txtEmail;
        System::Windows::Forms::TextBox^ txtPassword;
        System::Windows::Forms::TextBox^ txtConfirmPassword;
        System::Windows::Forms::Button^ btnSignUp;
        System::Windows::Forms::Button^ btnCancel;
        System::Windows::Forms::ComboBox^ cmbRole;
        System::Windows::Forms::Label^ lblRole;
        System::Windows::Forms::Label^ lblPasswordRequirements;
        System::Windows::Forms::LinkLabel^ lnkLogin;
        System::ComponentModel::Container^ components;

        MySqlConnection^ sqlConnection;
        String^ connectString = "server=localhost;port=3306;database=university_db;uid=root;password=";

    public:
        SignUpForm(void)
        {
            InitializeComponent();
            ConfigureDatabase();
        }

    protected:
        ~SignUpForm()
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
            this->Text = L"Sign Up - University Management System";
            this->StartPosition = FormStartPosition::CenterScreen;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Size = System::Drawing::Size(600, 800);
            this->BackColor = System::Drawing::Color::White;

            // Header Panel
            this->headerPanel = gcnew Panel();
            this->headerPanel->BackColor = System::Drawing::Color::FromArgb(0, 71, 160);
            this->headerPanel->Dock = DockStyle::Top;
            this->headerPanel->Height = 80;

            // Title Label
            this->lblTitle = gcnew Label();
            this->lblTitle->Text = L"CREATE NEW ACCOUNT";
            this->lblTitle->Font = gcnew System::Drawing::Font("Segoe UI", 20, FontStyle::Bold);
            this->lblTitle->ForeColor = System::Drawing::Color::White;
            this->lblTitle->AutoSize = false;
            this->lblTitle->TextAlign = ContentAlignment::MiddleCenter;
            this->lblTitle->Dock = DockStyle::Fill;
            this->headerPanel->Controls->Add(this->lblTitle);

            // Main Panel
            this->mainPanel = gcnew Panel();
            this->mainPanel->Location = Point(50, 100);
            this->mainPanel->Size = Drawing::Size(500, 650);
            this->mainPanel->BackColor = System::Drawing::Color::White;

            // First Name
            this->txtFirstName = gcnew TextBox();
            this->txtFirstName->Location = Point(0, 20);
            this->txtFirstName->Size = Drawing::Size(500, 30);
            this->txtFirstName->Font = gcnew System::Drawing::Font("Segoe UI", 12);
            this->txtFirstName->ForeColor = System::Drawing::Color::Gray;
            this->txtFirstName->Text = L"First Name";
            this->txtFirstName->BorderStyle = BorderStyle::FixedSingle;
            this->txtFirstName->GotFocus += gcnew EventHandler(this, &SignUpForm::RemovePlaceholder);
            this->txtFirstName->LostFocus += gcnew EventHandler(this, &SignUpForm::AddPlaceholder);

            // Last Name
            this->txtLastName = gcnew TextBox();
            this->txtLastName->Location = Point(0, 70);
            this->txtLastName->Size = Drawing::Size(500, 30);
            this->txtLastName->Font = gcnew System::Drawing::Font("Segoe UI", 12);
            this->txtLastName->ForeColor = System::Drawing::Color::Gray;
            this->txtLastName->Text = L"Last Name";
            this->txtLastName->BorderStyle = BorderStyle::FixedSingle;
            this->txtLastName->GotFocus += gcnew EventHandler(this, &SignUpForm::RemovePlaceholder);
            this->txtLastName->LostFocus += gcnew EventHandler(this, &SignUpForm::AddPlaceholder);

            // Email
            this->txtEmail = gcnew TextBox();
            this->txtEmail->Location = Point(0, 120);
            this->txtEmail->Size = Drawing::Size(500, 30);
            this->txtEmail->Font = gcnew System::Drawing::Font("Segoe UI", 12);
            this->txtEmail->ForeColor = System::Drawing::Color::Gray;
            this->txtEmail->Text = L"Email";
            this->txtEmail->BorderStyle = BorderStyle::FixedSingle;
            this->txtEmail->GotFocus += gcnew EventHandler(this, &SignUpForm::RemovePlaceholder);
            this->txtEmail->LostFocus += gcnew EventHandler(this, &SignUpForm::AddPlaceholder);

            // Password
            this->txtPassword = gcnew TextBox();
            this->txtPassword->Location = Point(0, 170);
            this->txtPassword->Size = Drawing::Size(500, 30);
            this->txtPassword->Font = gcnew System::Drawing::Font("Segoe UI", 12);
            this->txtPassword->ForeColor = System::Drawing::Color::Gray;
            this->txtPassword->Text = L"Password";
            this->txtPassword->BorderStyle = BorderStyle::FixedSingle;
            this->txtPassword->GotFocus += gcnew EventHandler(this, &SignUpForm::RemovePlaceholder);
            this->txtPassword->LostFocus += gcnew EventHandler(this, &SignUpForm::AddPlaceholder);
            this->txtPassword->TextChanged += gcnew EventHandler(this, &SignUpForm::ValidatePassword);

            // Confirm Password
            this->txtConfirmPassword = gcnew TextBox();
            this->txtConfirmPassword->Location = Point(0, 220);
            this->txtConfirmPassword->Size = Drawing::Size(500, 30);
            this->txtConfirmPassword->Font = gcnew System::Drawing::Font("Segoe UI", 12);
            this->txtConfirmPassword->ForeColor = System::Drawing::Color::Gray;
            this->txtConfirmPassword->Text = L"Confirm Password";
            this->txtConfirmPassword->BorderStyle = BorderStyle::FixedSingle;
            this->txtConfirmPassword->GotFocus += gcnew EventHandler(this, &SignUpForm::RemovePlaceholder);
            this->txtConfirmPassword->LostFocus += gcnew EventHandler(this, &SignUpForm::AddPlaceholder);

            // Password Requirements Label
            this->lblPasswordRequirements = gcnew Label();
            this->lblPasswordRequirements->Location = Point(0, 260);
            this->lblPasswordRequirements->Size = Drawing::Size(500, 40);
            this->lblPasswordRequirements->Font = gcnew System::Drawing::Font("Segoe UI", 9);
            this->lblPasswordRequirements->ForeColor = System::Drawing::Color::Gray;
            this->lblPasswordRequirements->Text = L"Password must contain at least 8 characters, one uppercase letter,\none lowercase letter, one number, and one special character.";

            // Role Label
            this->lblRole = gcnew Label();
            this->lblRole->Text = L"Select Role:";
            this->lblRole->Location = Point(0, 310);
            this->lblRole->Size = Drawing::Size(100, 30);
            this->lblRole->Font = gcnew System::Drawing::Font("Segoe UI", 12);

            // Role ComboBox
            this->cmbRole = gcnew ComboBox();
            this->cmbRole->Location = Point(100, 310);
            this->cmbRole->Size = Drawing::Size(400, 30);
            this->cmbRole->Font = gcnew System::Drawing::Font("Segoe UI", 12);
            this->cmbRole->DropDownStyle = ComboBoxStyle::DropDownList;
            this->cmbRole->Items->AddRange(gcnew cli::array<Object^> { "Student", "Faculty" });

            // Sign Up Button
            this->btnSignUp = gcnew Button();
            this->btnSignUp->Text = L"SIGN UP";
            this->btnSignUp->Location = Point(0, 370);
            this->btnSignUp->Size = Drawing::Size(500, 40);
            this->btnSignUp->FlatStyle = FlatStyle::Flat;
            this->btnSignUp->BackColor = System::Drawing::Color::FromArgb(0, 71, 160);
            this->btnSignUp->ForeColor = System::Drawing::Color::White;
            this->btnSignUp->Font = gcnew System::Drawing::Font("Segoe UI", 12, FontStyle::Bold);
            this->btnSignUp->Cursor = Cursors::Hand;
            this->btnSignUp->Click += gcnew EventHandler(this, &SignUpForm::btnSignUp_Click);

            // Cancel Button
            this->btnCancel = gcnew Button();
            this->btnCancel->Text = L"CANCEL";
            this->btnCancel->Location = Point(0, 420);
            this->btnCancel->Size = Drawing::Size(500, 40);
            this->btnCancel->FlatStyle = FlatStyle::Flat;
            this->btnCancel->BackColor = System::Drawing::Color::White;
            this->btnCancel->ForeColor = System::Drawing::Color::FromArgb(0, 71, 160);
            this->btnCancel->Font = gcnew System::Drawing::Font("Segoe UI", 12);
            this->btnCancel->Cursor = Cursors::Hand;
            this->btnCancel->Click += gcnew EventHandler(this, &SignUpForm::btnCancel_Click);

            // Login Link
            this->lnkLogin = gcnew LinkLabel();
            this->lnkLogin->Text = L"Already have an account? Login here";
            this->lnkLogin->Location = Point(0, 470);
            this->lnkLogin->Size = Drawing::Size(500, 30);
            this->lnkLogin->TextAlign = ContentAlignment::MiddleCenter;
            this->lnkLogin->LinkColor = System::Drawing::Color::FromArgb(0, 71, 160);
            this->lnkLogin->Font = gcnew System::Drawing::Font("Segoe UI", 10);
            this->lnkLogin->LinkClicked += gcnew LinkLabelLinkClickedEventHandler(
                this, &SignUpForm::lnkLogin_LinkClicked);

            // Add controls to panels
            this->mainPanel->Controls->Add(this->txtFirstName);
            this->mainPanel->Controls->Add(this->txtLastName);
            this->mainPanel->Controls->Add(this->txtEmail);
            this->mainPanel->Controls->Add(this->txtPassword);
            this->mainPanel->Controls->Add(this->txtConfirmPassword);
            this->mainPanel->Controls->Add(this->lblPasswordRequirements);
            this->mainPanel->Controls->Add(this->lblRole);
            this->mainPanel->Controls->Add(this->cmbRole);
            this->mainPanel->Controls->Add(this->btnSignUp);
            this->mainPanel->Controls->Add(this->btnCancel);
            this->mainPanel->Controls->Add(this->lnkLogin);

            // Add panels to form
            this->Controls->Add(this->headerPanel);
            this->Controls->Add(this->mainPanel);
        }

        void RemovePlaceholder(Object^ sender, EventArgs^ e)
        {
            TextBox^ textBox = safe_cast<TextBox^>(sender);
            if (textBox->ForeColor == System::Drawing::Color::Gray)
            {
                textBox->Text = "";
                textBox->ForeColor = System::Drawing::Color::Black;
                if (textBox == txtPassword || textBox == txtConfirmPassword)
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
                if (textBox == txtFirstName)
                    textBox->Text = "First Name";
                else if (textBox == txtLastName)
                    textBox->Text = "Last Name";
                else if (textBox == txtEmail)
                    textBox->Text = "Email";
                else if (textBox == txtPassword)
                {
                    textBox->Text = "Password";
                    textBox->PasswordChar = '\0';
                }
                else if (textBox == txtConfirmPassword)
                {
                    textBox->Text = "Confirm Password";
                    textBox->PasswordChar = '\0';
                }
                textBox->ForeColor = System::Drawing::Color::Gray;
            }
        }

        bool IsPasswordValid(String^ password)
        {
            if (password->Length < 8) return false;

            bool hasUpper = false;
            bool hasLower = false;
            bool hasDigit = false;
            bool hasSpecial = false;

            for each (wchar_t c in password)
            {
                if (Char::IsUpper(c)) hasUpper = true;
                else if (Char::IsLower(c)) hasLower = true;
                else if (Char::IsDigit(c)) hasDigit = true;
                else if (!Char::IsLetterOrDigit(c)) hasSpecial = true;
            }

            return hasUpper && hasLower && hasDigit && hasSpecial;
        }

        void ValidatePassword(Object^ sender, EventArgs^ e)
        {
            TextBox^ textBox = safe_cast<TextBox^>(sender);
            if (textBox->Text != "Password" && !IsPasswordValid(textBox->Text))
            {
                lblPasswordRequirements->ForeColor = System::Drawing::Color::Red;
            }
            else
            {
                lblPasswordRequirements->ForeColor = System::Drawing::Color::Gray;
            }
        }

        void NavigateToLogin()
        {
            LoginForm^ loginForm = gcnew LoginForm();
            this->Hide();
            loginForm->Show();
        }

        void btnSignUp_Click(Object^ sender, EventArgs^ e)
        {
            // Validate input fields
            if (txtFirstName->Text == "First Name" || txtLastName->Text == "Last Name" ||
                txtEmail->Text == "Email" || txtPassword->Text == "Password" ||
                txtConfirmPassword->Text == "Confirm Password" || cmbRole->SelectedIndex == -1)
            {
                MessageBox::Show("Please fill in all fields.", "Validation Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            // Validate password
            if (!IsPasswordValid(txtPassword->Text))
            {
                MessageBox::Show("Password does not meet the requirements.", "Validation Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            if (txtPassword->Text != txtConfirmPassword->Text)
            {
                MessageBox::Show("Passwords do not match.", "Validation Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            try {
                // Check if email already exists
                if (sqlConnection->State == ConnectionState::Closed)
                    sqlConnection->Open();

                String^ checkEmailQuery = "SELECT COUNT(*) FROM users WHERE email = @email";
                MySqlCommand^ checkCmd = gcnew MySqlCommand(checkEmailQuery, sqlConnection);
                checkCmd->Parameters->AddWithValue("@email", txtEmail->Text);

                int emailCount = Convert::ToInt32(checkCmd->ExecuteScalar());
                if (emailCount > 0)
                {
                    MessageBox::Show("This email is already registered.", "Registration Error",
                        MessageBoxButtons::OK, MessageBoxIcon::Warning);
                    return;
                }

                // Insert new user
                String^ insertQuery = "INSERT INTO users (first_name, last_name, email, password, role) "
                    "VALUES (@firstName, @lastName, @email, @password, @role)";

                MySqlCommand^ cmd = gcnew MySqlCommand(insertQuery, sqlConnection);

                // Add parameters
                cmd->Parameters->AddWithValue("@firstName", txtFirstName->Text);
                cmd->Parameters->AddWithValue("@lastName", txtLastName->Text);
                cmd->Parameters->AddWithValue("@email", txtEmail->Text);
                cmd->Parameters->AddWithValue("@password", txtPassword->Text);
                cmd->Parameters->AddWithValue("@role", cmbRole->SelectedItem->ToString());

                // Execute query
                cmd->ExecuteNonQuery();

                // Get the newly inserted user ID
                String^ getUserIdQuery = "SELECT LAST_INSERT_ID()";
                MySqlCommand^ idCmd = gcnew MySqlCommand(getUserIdQuery, sqlConnection);
                int userId = Convert::ToInt32(idCmd->ExecuteScalar());

                // Insert into role-specific table
                if (cmbRole->SelectedItem->ToString() == "Student")
                {
                    String^ studentQuery = "INSERT INTO students (userID, Studentfname, Studentlname, email) "
                        "VALUES (@userId, @firstName, @lastName, @email)";

                    MySqlCommand^ studentCmd = gcnew MySqlCommand(studentQuery, sqlConnection);
                    studentCmd->Parameters->AddWithValue("@userId", userId);
                    studentCmd->Parameters->AddWithValue("@firstName", txtFirstName->Text);
                    studentCmd->Parameters->AddWithValue("@lastName", txtLastName->Text);
                    studentCmd->Parameters->AddWithValue("@email", txtEmail->Text);
                    studentCmd->ExecuteNonQuery();
                }
                else if (cmbRole->SelectedItem->ToString() == "Faculty")
                {
                    String^ facultyQuery = "INSERT INTO faculty (userID, facultyfName, facultylname, email, appointmentDate) "
                        "VALUES (@userId, @firstName, @lastName, @email, CURDATE())";

                    MySqlCommand^ facultyCmd = gcnew MySqlCommand(facultyQuery, sqlConnection);
                    facultyCmd->Parameters->AddWithValue("@userId", userId);
                    facultyCmd->Parameters->AddWithValue("@firstName", txtFirstName->Text);
                    facultyCmd->Parameters->AddWithValue("@lastName", txtLastName->Text);
                    facultyCmd->Parameters->AddWithValue("@email", txtEmail->Text);
                    facultyCmd->ExecuteNonQuery();
                }

                // After successful registration:
                MessageBox::Show("Registration successful! Please login to continue.",
                    "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                NavigateToLogin();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("An error occurred during registration: " + ex->Message,
                    "Registration Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
            finally
            {
                if (sqlConnection->State == ConnectionState::Open)
                    sqlConnection->Close();
            }
        }

        void btnCancel_Click(Object^ sender, EventArgs^ e)
        {
           
            
               this->Hide();
                LoginForm^ loginForm = gcnew LoginForm();
                loginForm->Show();
            
        }

        void lnkLogin_LinkClicked(Object^ sender, LinkLabelLinkClickedEventArgs^ e)
        {
           this->Hide();
            LoginForm^ loginForm = gcnew LoginForm();
            loginForm->Show();
        }
    };
}