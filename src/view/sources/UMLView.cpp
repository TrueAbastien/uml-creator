#include "view/UMLView.h"
#include <iostream>

namespace view
{
    UMLView::UMLView()
        : m_currentLayout(nullptr)
    {
    }

    // ----------------------------------------------------------------------------------------- //
    std::string UMLView::ask(const std::string& message) const
    {
        return (m_currentLayout ? m_currentLayout->awaits(message) : "");
    }

    // ----------------------------------------------------------------------------------------- //
    void UMLView::display(const std::string& message)
    {
        std::cout << message << std::endl;
    }
}
