
#include <iostream>
#include <controller/UMLController.h>

// TEMP //
#include <model/UMLClass.h>
#include <model/ClassField.h>
#include <model/ClassDiagram.h>
#include <model/Method.h>
#include <model/UMLAbstractClass.h>
#include <model/UMLInterface.h>
#include <model/InheritanceLink.h>
#include <model/CompositionLink.h>

int main(int argc, char** argv)
{
    model::ModelPtr model = std::make_shared<model::UMLModel>();
    view::ViewPtr view = std::make_shared<view::UMLView>();
    controller::ControllerPtr controller = std::make_shared<controller::UMLController>(model, view);
    
    std::cout << "Hello World!" << std::endl; //TEMP

    {
        std::shared_ptr<model::UMLDiagram> diagram = std::make_shared<model::ClassDiagram>("Dog Diagram");

        std::shared_ptr<model::UMLInterface> being_interface = std::make_shared<model::UMLInterface>("Being");
        being_interface->addMethod(std::make_shared<model::Method>("getName", "string", model::Member::Visibility::PUBLIC, being_interface->getType()));
        diagram->addEntity(being_interface);

        std::shared_ptr<model::UMLAbstractClass> animal_abs_class = std::make_shared<model::UMLAbstractClass>("Animal");
        animal_abs_class->addMember(std::make_shared<model::ClassField>("speccy", "string", model::Member::Visibility::PROTECTED, animal_abs_class->getType()));
        std::shared_ptr<model::Method> foo = std::make_shared<model::Method>("foo", "void", model::Member::Visibility::PROTECTED, animal_abs_class->getType());
        foo->addParam("int", "v1");
        foo->addParam("int", "v2");
        animal_abs_class->addMember(foo);
        diagram->addEntity(animal_abs_class);

        std::shared_ptr<model::UMLClass> dog_class = std::make_shared<model::UMLClass>("Dog");
        dog_class->addMember(std::make_shared<model::ClassField>("age", "double", model::Member::Visibility::PROTECTED, dog_class->getType()));
        dog_class->addMember(std::make_shared<model::ClassField>("name", "string", model::Member::Visibility::PRIVATE, dog_class->getType()));
        dog_class->addMember(std::make_shared<model::ClassField>("behaviour", "int", model::Member::Visibility::PUBLIC, dog_class->getType()));
        dog_class->addMember(std::make_shared<model::Method>("getName", "string", model::Member::Visibility::PUBLIC, dog_class->getType()));
        diagram->addEntity(dog_class);

        diagram->addEntity(std::make_shared<model::InheritanceLink>(dog_class, animal_abs_class));
        diagram->addEntity(std::make_shared<model::InheritanceLink>(animal_abs_class, being_interface));

        diagram->addEntity(std::make_shared<model::CompositionLink>(dog_class, being_interface, model::Cardinal(model::Cardinal::Type::MANY, "relation")));
        
        std::cout << diagram->Export("dog", "png") << std::endl;
    }

    return 0;
}