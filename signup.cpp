#include "signup.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    FinalProject_ICP::SignUpForm form;
    Application::Run(% form);
    return 0;
}

