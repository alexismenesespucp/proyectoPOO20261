#include "login.h"
using namespace ProyectoPoo20261;

int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Controller::Operations::Initialize();
	login form;
	Application::Run(%form);
	return 0;
}