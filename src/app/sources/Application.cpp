#include "Application.h"

Application::Application()
{
	m_model = std::make_shared<model::UMLModel>();
	m_view = std::make_shared<view::UMLView>();
	m_controller = std::make_shared<controller::UMLController>(m_model, m_view);
}

// ----------------------------------------------------------------------------------------- //
int Application::Run(int argc, char** argv)
{
	// TODO

	return 0;
}
