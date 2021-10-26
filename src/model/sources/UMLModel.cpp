#include "model/UMLModel.h"

namespace model
{
    UMLModel::UMLModel()
        : m_diagrams(0)
    {
    }

    // ----------------------------------------------------------------------------------------- //
    bool UMLModel::exists(const std::shared_ptr<UMLDiagram>& diagram) const
    {
        for (auto diagram : m_diagrams)
        {
            if (diagram->getTitle() == diagram->getTitle())
            {
                return true;
            }
        }

        return false;
    }

    // ----------------------------------------------------------------------------------------- //
    bool UMLModel::add(const std::shared_ptr<UMLDiagram>& diagram)
    {
        if (!exists(diagram))
        {
            m_diagrams.push_back(diagram);
            return true;
        }
        return false;
    }

    // ----------------------------------------------------------------------------------------- //
    UMLModel::Diagrams UMLModel::getDiagrams() const
    {
        return m_diagrams;
    }
}
