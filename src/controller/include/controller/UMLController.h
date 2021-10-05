#pragma once

#include <view/UMLView.h>
#include <model/UMLModel.h>

namespace controller
{
	class UMLController
	{
	private:
		view::UMLView* m_view;
		model::UMLModel* m_model;
		
	public:
		UMLController(model::UMLModel*, view::UMLView*);
	};
}
