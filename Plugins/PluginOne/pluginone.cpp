#include "pluginone.hpp"
#include "interface.hpp"
#include <iostream>

Interface* g_Interface = NULL;

extern "C" __project_export Plugin* CreatePlugin()
{
  assert(g_Interface == NULL);
  g_Interface = new Interface();
  return g_Interface;
}

extern "C" __project_export void DestroyPlugin()
{
  assert(g_Interface);
  delete g_Interface;
  g_Interface = NULL;
}

extern "C" __project_export void helloNow()
{
  std::cout << "Hello from Plugin One!\n";
}

