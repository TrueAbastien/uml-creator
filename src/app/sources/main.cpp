
#include <iostream>

#include <controller/UMLController.h>

int main(int argc, char** argv)
{
    model::UMLModel model;
    view::UMLView view;
    controller::UMLController controller(&model, &view);
    
    std::cout << "Hello World!" << std::endl;

    return 0;
}