#include "controller/UMLController.h"
#include "controller/InputInterpreterBase.h"

namespace controller
{
    UMLController::UMLController(const model::ModelPtr model, const view::ViewPtr view)
        : m_model(model), m_view(view), m_currentInterpreter(nullptr)
    {
        m_view->add(this);
    }

    // ----------------------------------------------------------------------------------------- //
    void UMLController::notify(const NOTIFICATION_DATA& data)
    {
        NOTIFICATION_DATA data_copy = data;
        if (verifyInput(data_copy))
        {
            if (m_currentInterpreter != nullptr)
            {
                int ec = m_currentInterpreter->interpret(data_copy);

                if (ec != 0)
                {
                    // TODO
                }
            }
        }
    }

    // ----------------------------------------------------------------------------------------- //
    bool UMLController::verifyInput(NOTIFICATION_DATA& data)
    {
        // TODO

        return true;
    }
}
