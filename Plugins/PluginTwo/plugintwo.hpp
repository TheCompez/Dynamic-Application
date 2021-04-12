#ifndef HELLOPLUGIN_HPP
#define HELLOPLUGIN_HPP

#include "plugin.hpp"
#include <string>

// This class is exported from the PluginTwo.dll
class __project_export PluginTwo {
public:
  PluginTwo();
  // TODO: add your methods here.
};

extern "C" __project_export Plugin* CreatePlugin();
extern "C" __project_export void DestroyPlugin();


#endif // HELLOPLUGIN_HPP
