#pragma once
#include <core/Definitions.h>
#include <core/Observable.h>

#define LAYOUT_CONSTRUCTOR(__class__) __class__(core::Observable<NOTIFICATION_DATA>* target) : LayoutBase(target) { }

namespace view
{
	class LayoutBase
	{
	public:

		LayoutBase(core::Observable<NOTIFICATION_DATA>* target);

		void draw();

	private:

		core::Observable<NOTIFICATION_DATA>* m_target;

	protected:

		void notify(const NOTIFICATION_DATA& data);
		std::string awaits(const std::string& msg) const;

		virtual std::string headerMessage() const = 0;
		virtual void render() = 0;
	};
}
