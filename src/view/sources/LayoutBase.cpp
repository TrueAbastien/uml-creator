#include "view/LayoutBase.h"
#include <iostream>

namespace view
{
	LayoutBase::LayoutBase(core::Observable<NOTIFICATION_DATA>* target)
		: m_target(target)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	void LayoutBase::draw()
	{
		std::system(CLEAR);

		std::cout << headerMessage() << std::endl;

		this->render();
	}

	// ----------------------------------------------------------------------------------------- //
	std::string LayoutBase::awaits(const std::string& msg) const
	{
		std::cout << msg;
		std::string result;
		std::cin >> result;
		return result;
	}

	// ----------------------------------------------------------------------------------------- //
	void LayoutBase::notify(const NOTIFICATION_DATA& data)
	{
		if (m_target != nullptr)
		{
			m_target->notify(data);
		}
	}
}
