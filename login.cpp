#include "login.h"
using namespace ProyectoPoo20261;

int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ProyectoPoo20261::login form;
	Application::Run(%form);
	return 0;
}