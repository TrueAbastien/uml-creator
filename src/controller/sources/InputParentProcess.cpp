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
	void InputParentProcess::awaitsID()
	{
		std::string cmd;
		do { cmd = input(">"); }
		while (!setProcessID(cmd));
	}

	// ----------------------------------------------------------------------------------------- //
	int InputParentProcess::Process()
	{
		int ec = PreProcess();
		if (ec == 0)
		{
			if (!m_processID.empty())
			{
				do
				{
					ec = m_children[m_processID]->Process();
				}
				while (ec > 0);
			}

			return PostProcess();
		}
		return ec;
	}
}
