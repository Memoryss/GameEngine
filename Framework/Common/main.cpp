#include <iostream>
#include "IApplication.hpp"

namespace Ella {
	extern IApplication *g_pApp;
}

int main(int argc, char **argv)
{
	int ret;

	if (ret = g_pApp->Initialize() != 0)
	{
		std::cout << "App Initialize failed, will exit now";
		return ret;
	}

	while (!g_pApp->IsQuit())
	{
		g_pApp->Tick();
	}

	g_pApp->Finalize();

	return 0;
}
