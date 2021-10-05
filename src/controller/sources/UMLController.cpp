#include "controller/UMLController.h"

namespace controller
{
    UMLController::UMLController(model::UMLModel* model, view::UMLView* view)
        : m_model(model), m_view(view)
    {
    }
}
