#include "controller/InputInterpreterBase.h"

namespace controller
{
	int InputInterpreterBase::interpret(const NOTIFICATION_DATA& data)
	{
		NOTIFICATION_DATA data_copy = data;

		int ec = react(data_copy);
		if (ec == 0)
		{
			auto result = m_processMap.find(data);
			if (result != m_processMap.end())
			{
				return result->second->get()->Process();
			}
			else return -1;
		}
		else return ec;
	}
}
