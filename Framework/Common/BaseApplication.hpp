#pragma once

#include "IApplication.hpp"

namespace Ella {
	class BaseApplication : public IApplication
	{
		public:
			virtual int Initialize();
			virtual void Finalize();

			virtual void Tick();
			virtual bool IsQuick();

		protected:
			bool m_bQuit;
	};
}
