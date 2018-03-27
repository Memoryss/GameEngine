#pragma once

#include "Interface.hpp"

namespace Ella {
	class IRuntimeModule
	{
		public:
			virtual ~IRuntimeModule() {};
			// 初始化模块
			virtual int Initialize() = 0;
			// 清理模块
			virtual void Finalize() = 0;
			// 执行
			virtual void Tick() = 0;
	}
}
