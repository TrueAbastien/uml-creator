#pragma once
#include "controller/UMLController.h"
#include "controller/InputProcessBase.h"
#include <map>


#define MAKE_PROCESS(__type__) std::make_shared<InputInterpreterBase::Maker<__type__>>

namespace controller
{
	class InputInterpreterBase
	{
	protected:

		class MakerBase
		{
		public:

			virtual std::shared_ptr<InputProcessBase> get() const = 0;
		};

		template <typename Process>
		class Maker : public MakerBase
		{
		private:

			UMLController* m_controller;

		public:

			Maker(UMLController* controller)
				: m_controller(controller)
			{
			}

			std::shared_ptr<Process> get() const override
			{
				return std::make_shared<Process>(controller);
			}
		};

		std::map<NOTIFICATION_DATA, std::shared_ptr<MakerBase>> m_processMap;

	public:

		int interpret(const NOTIFICATION_DATA& data);

	protected:

		virtual int react(NOTIFICATION_DATA& data) = 0;
	};
}
