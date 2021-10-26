#pragma once
#include "controller/InputProcessBase.h"
#include <map>
#include <string>

namespace controller
{
	class InputParentProcess : public InputProcessBase
	{
	public:

		typedef std::map<std::string, std::shared_ptr<InputProcessBase>> ChildrenMap;

	protected:

		InputParentProcess(UMLController* controller);

		virtual int PreProcess() = 0;
		virtual int PostProcess() = 0;

		bool setProcessID(const std::string& id);
		void awaitsID();

	public:

		int Process() override;

	protected:

		ChildrenMap m_children;
		std::string m_processID;
	};
}
