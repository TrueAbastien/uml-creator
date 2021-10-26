#include "view/UMLView.h"

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
}
