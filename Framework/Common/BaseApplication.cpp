#include "BaseApplication.hpp"

namespace Ella {

	//解析命令行，读取配置，初始化所有的子模块
	int BaseApplication::Initialize()
	{
		m_bQuit = false;
		return 0;
	}
	
	void BaseApplication::Finalize()
	{
		
	}

	void BaseApplication::Tick()
	{
	
	}

	bool BaseApplication::IsQuit()
	{
		return m_bQuit;
	}
}
