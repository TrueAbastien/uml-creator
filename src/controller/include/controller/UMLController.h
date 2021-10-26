#pragma once
#include <memory>
#include <view/UMLView.h>
#include <model/UMLModel.h>
#include <core/Observer.h>
#include <core/Definitions.h>

namespace controller
{
	class InputInterpreterBase;

	class UMLController : public core::Observer<NOTIFICATION_DATA>
	{
	private:

		view::ViewPtr m_view;
		model::ModelPtr m_model;

		std::shared_ptr<InputInterpreterBase> m_currentInterpreter;
		
	public:

		UMLController(const model::ModelPtr model, const view::ViewPtr view);

		template <typename T> void setInterpreter();

		void update(const NOTIFICATION_DATA& data) override;

		view::ViewPtr getView() const;
		model::ModelPtr getModel() const;

	protected:

		bool verifyInput(NOTIFICATION_DATA& data);
	};

	typedef std::shared_ptr<UMLController> ControllerPtr;

	// ----------------------------------------------------------------------------------------- //
	template <typename T>
	inline void UMLController::setInterpreter()
	{
		m_currentInterpreter = std::make_shared<T>(this);
	}
}
