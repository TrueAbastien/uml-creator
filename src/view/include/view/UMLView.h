#pragma once
#include <core/Observer.h>
#include "view/LayoutBase.h"
#include <memory>

namespace view
{
	class UMLView : public core::Observable<NOTIFICATION_DATA>
	{
	public:

		UMLView();

		template <typename T> void setLayout();
		std::string ask(const std::string& message) const;

	private:

		std::shared_ptr<LayoutBase> m_currentLayout;
	};

	typedef std::shared_ptr<UMLView> ViewPtr;

	// ----------------------------------------------------------------------------------------- //
	template <typename T>
	inline void UMLView::setLayout()
	{
		m_currentLayout = std::make_shared<T>(this);
	}
}
