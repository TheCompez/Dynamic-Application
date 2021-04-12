#ifndef HELLOPLUGIN_HPP
#define HELLOPLUGIN_HPP

#include "plugin.hpp"
#include <string>

// This class is exported from the PluginOne.dll
class __project_export PluginOne {
public:
  PluginOne();
  // TODO: add your methods here.
  void helloNow();
};

extern "C" __project_export Plugin* CreatePlugin();
extern "C" __project_export void DestroyPlugin();


#endif // HELLOPLUGIN_HPP
