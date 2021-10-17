
#include <iostream>

#include <controller/UMLController.h>

int main(int argc, char** argv)
{
    model::ModelPtr model = std::make_shared<model::UMLModel>();
    view::ViewPtr view = std::make_shared<view::UMLView>();
    controller::ControllerPtr controller = std::make_shared<controller::UMLController>(model, view);
    
    std::cout << "Hello World!" << std::endl; //TEMP

    return 0;
}