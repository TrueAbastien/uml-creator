#include "controller/InputParentProcess.h"

namespace controller
{
	InputParentProcess::InputParentProcess(UMLController* controller)
		: InputProcessBase(controller), m_processID("")
	{
	}

	// ----------------------------------------------------------------------------------------- //
	bool InputParentProcess::setProcessID(const std::string& id)
	{
		if (m_children.find(id) != m_children.end())
		{
			m_processID = id;
			return true;
		}
		return false;
	}

	// ----------------------------------------------------------------------------------------- //
	int InputParentProcess::Process()
	{
		int ec = InternalProcess();
		if (ec == 0)
		{
			if (!m_processID.empty())
			{
				return m_children[m_processID]->Process();
			}
			return -1;
		}
		return ec;
	}
}
