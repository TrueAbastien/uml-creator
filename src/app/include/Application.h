#pragma once
#include <controller/UMLController.h>

class Application
{
public:

    Application();

    int Run(int argc, char** argv);

private:

    model::ModelPtr m_model;
    view::ViewPtr m_view;
    controller::ControllerPtr m_controller;
};
