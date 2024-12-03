#pragma once
//#include "StudentEnrollment.h"
//#include "StudentGrades.h"
//#include "StudentSchedule.h"
//#include "StudentProfile.h"
//#include "FacultyGrades.h"
//#include "FacultyRoster.h"
//#include "FacultyCourses.h"
//#include "FacultyProfile.h"

namespace UniversityManagementSystem {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MainMDIForm : public System::Windows::Forms::Form
    {
    public:
        MainMDIForm(String^ userID, String^ userRole)
        {
            InitializeComponent();
            this->userID = userID;
            this->userRole = userRole;
            ConfigureMenuAccess();
        }

    protected:
        ~MainMDIForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::MenuStrip^ menuStrip;
        System::Windows::Forms::StatusStrip^ statusStrip;
        System::Windows::Forms::ToolStripStatusLabel^ statusLabel;
        System::ComponentModel::Container^ components;
        String^ userID;
        String^ userRole;

        // Menu Items
        System::Windows::Forms::ToolStripMenuItem^ fileMenu;
        System::Windows::Forms::ToolStripMenuItem^ userMenu;
        System::Windows::Forms::ToolStripMenuItem^ helpMenu;

        // Student Menu Items
        System::Windows::Forms::ToolStripMenuItem^ enrollmentMenuItem;
        System::Windows::Forms::ToolStripMenuItem^ gradesMenuItem;
        System::Windows::Forms::ToolStripMenuItem^ scheduleMenuItem;
        System::Windows::Forms::ToolStripMenuItem^ profileMenuItem;

        // Faculty Menu Items
        System::Windows::Forms::ToolStripMenuItem^ courseManagementMenuItem;
        System::Windows::Forms::ToolStripMenuItem^ gradeEntryMenuItem;
        System::Windows::Forms::ToolStripMenuItem^ classRosterMenuItem;
        System::Windows::Forms::ToolStripMenuItem^ facultyProfileMenuItem;

        void InitializeComponent(void)
        {
            this->components = gcnew System::ComponentModel::Container();

            // Form Settings
            this->IsMdiContainer = true;
            this->Text = L"University Management System";
            this->WindowState = FormWindowState::Maximized;

            // Initialize MenuStrip
            this->menuStrip = gcnew MenuStrip();
            this->menuStrip->BackColor = System::Drawing::Color::FromArgb(0, 71, 160);
            this->menuStrip->ForeColor = System::Drawing::Color::White;
            this->menuStrip->Dock = DockStyle::Top;

            // File Menu
            this->fileMenu = gcnew ToolStripMenuItem(L"File");
            ToolStripMenuItem^ logoutMenuItem = gcnew ToolStripMenuItem(L"Logout", nullptr,
                gcnew EventHandler(this, &MainMDIForm::LogoutMenuItem_Click));
            ToolStripMenuItem^ exitMenuItem = gcnew ToolStripMenuItem(L"Exit", nullptr,
                gcnew EventHandler(this, &MainMDIForm::ExitMenuItem_Click));
            this->fileMenu->DropDownItems->AddRange(gcnew array<ToolStripItem^> {
                logoutMenuItem,
                    gcnew ToolStripSeparator(),
                    exitMenuItem
            });

            // Student Menu
            this->userMenu = gcnew ToolStripMenuItem(L"Menu");

            // Student-specific menu items
            this->enrollmentMenuItem = gcnew ToolStripMenuItem(L"Course Enrollment", nullptr,
                gcnew EventHandler(this, &MainMDIForm::EnrollmentMenuItem_Click));
            this->gradesMenuItem = gcnew ToolStripMenuItem(L"View Grades", nullptr,
                gcnew EventHandler(this, &MainMDIForm::ViewGradesMenuItem_Click));
            this->scheduleMenuItem = gcnew ToolStripMenuItem(L"View Schedule", nullptr,
                gcnew EventHandler(this, &MainMDIForm::ViewScheduleMenuItem_Click));
            this->profileMenuItem = gcnew ToolStripMenuItem(L"View Profile", nullptr,
                gcnew EventHandler(this, &MainMDIForm::ViewProfileMenuItem_Click));

            // Faculty-specific menu items
            this->courseManagementMenuItem = gcnew ToolStripMenuItem(L"Manage Courses", nullptr,
                gcnew EventHandler(this, &MainMDIForm::ManageCoursesMenuItem_Click));
            this->gradeEntryMenuItem = gcnew ToolStripMenuItem(L"Enter Grades", nullptr,
                gcnew EventHandler(this, &MainMDIForm::EnterGradesMenuItem_Click));
            this->classRosterMenuItem = gcnew ToolStripMenuItem(L"View Class Roster", nullptr,
                gcnew EventHandler(this, &MainMDIForm::ViewRosterMenuItem_Click));
            this->facultyProfileMenuItem = gcnew ToolStripMenuItem(L"Faculty Profile", nullptr,
                gcnew EventHandler(this, &MainMDIForm::ViewFacultyProfileMenuItem_Click));

            // Help Menu
            this->helpMenu = gcnew ToolStripMenuItem(L"Help");
            ToolStripMenuItem^ aboutMenuItem = gcnew ToolStripMenuItem(L"About", nullptr,
                gcnew EventHandler(this, &MainMDIForm::AboutMenuItem_Click));
            this->helpMenu->DropDownItems->Add(aboutMenuItem);

            // Status Strip
            this->statusStrip = gcnew StatusStrip();
            this->statusLabel = gcnew ToolStripStatusLabel();
            this->statusStrip->Items->Add(this->statusLabel);

            // Add Menus to MenuStrip
            this->menuStrip->Items->AddRange(gcnew array<ToolStripItem^> {
                this->fileMenu,
                    this->userMenu,
                    this->helpMenu
            });

            // Add MenuStrip and StatusStrip to Form
            this->Controls->Add(this->menuStrip);
            this->Controls->Add(this->statusStrip);
            this->MainMenuStrip = this->menuStrip;
        }

        void ConfigureMenuAccess()
        {
            // Configure menu based on user role
            if (this->userRole == "Student") {
                this->userMenu->DropDownItems->AddRange(gcnew array<ToolStripItem^> {
                    this->enrollmentMenuItem,
                        this->gradesMenuItem,
                        this->scheduleMenuItem,
                        this->profileMenuItem
                });
                this->statusLabel->Text = "Logged in as Student";
            }
            else if (this->userRole == "Faculty") {
                this->userMenu->DropDownItems->AddRange(gcnew array<ToolStripItem^> {
                    this->courseManagementMenuItem,
                        this->gradeEntryMenuItem,
                        this->classRosterMenuItem,
                        this->facultyProfileMenuItem
                });
                this->statusLabel->Text = "Logged in as Faculty";
            }
        }

        // Student Menu Event Handlers
        //System::Void EnrollmentMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        //    StudentEnrollment^ enrollmentForm = gcnew StudentEnrollment(userID);
        //    enrollmentForm->MdiParent = this;
        //    enrollmentForm->Show();
        //}

        //System::Void ViewGradesMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        //    StudentGrades^ gradesForm = gcnew StudentGrades(userID);
        //    gradesForm->MdiParent = this;
        //    gradesForm->Show();
        //}

        //System::Void ViewScheduleMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        //    StudentSchedule^ scheduleForm = gcnew StudentSchedule(userID);
        //    scheduleForm->MdiParent = this;
        //    scheduleForm->Show();
        //}

        //System::Void ViewProfileMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        //    StudentProfile^ profileForm = gcnew StudentProfile(userID);
        //    profileForm->MdiParent = this;
        //    profileForm->Show();
        //}

        //// Faculty Menu Event Handlers
        //System::Void ManageCoursesMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        //    FacultyCourses^ coursesForm = gcnew FacultyCourses(userID);
        //    coursesForm->MdiParent = this;
        //    coursesForm->Show();
        //}

        //System::Void EnterGradesMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        //    FacultyGrades^ gradesForm = gcnew FacultyGrades(userID);
        //    gradesForm->MdiParent = this;
        //    gradesForm->Show();
        //}

        //System::Void ViewRosterMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        //    FacultyRoster^ rosterForm = gcnew FacultyRoster(userID);
        //    rosterForm->MdiParent = this;
        //    rosterForm->Show();
        //}

        //System::Void ViewFacultyProfileMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        //    FacultyProfile^ profileForm = gcnew FacultyProfile(userID);
        //    profileForm->MdiParent = this;
        //    profileForm->Show();
        //}

        // File Menu Event Handlers
        System::Void LogoutMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
            if (MessageBox::Show("Are you sure you want to logout?", "Confirm Logout",
                MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
            {
                Application::Restart();
            }
        }

        System::Void ExitMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
            if (MessageBox::Show("Are you sure you want to exit?", "Confirm Exit",
                MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
            {
                Application::Exit();
            }
        }

        System::Void AboutMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
            MessageBox::Show("University Management System\nVersion 1.0\n©2024", "About",
                MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
    };
}