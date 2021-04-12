#include "pluginmanager.hpp"

#include <map>
#include <string>
#include <cstring>
#include <iostream>
#include <cerrno>
#include <iosfwd>
#include <dlfcn.h>

using PluginMap  =  std::map<std::string, Plugin*>;

using LibraryMap =  std::map<std::string, void*>;

class PluginManagerPimpl
{
public:
  PluginMap m_plugins;
  LibraryMap m_libs;
};

PluginManager::PluginManager()
{
  m_implementation = std::make_unique<PluginManagerPimpl>();
}

PluginManager::~PluginManager()
{

}

PluginManager& PluginManager::instance()
{
  static PluginManager pluginManager;
  return pluginManager;
}

Plugin* PluginManager::load(const std::string& name)
{
  Plugin* plugin = nullptr;
  PluginMap::iterator iter = m_implementation->m_plugins.find(name);
  if (iter == m_implementation->m_plugins.end())
  {
// Try to load the plugin library
#if defined(__PLATFORM_WINDOWS)
    void *hModule;
    hModule = LoadLibraryW(name.c_str());
#elif defined(__PLATFORM_MAC)
    void *hModule;
    hModule = dlopen(name.c_str(), RTLD_LAZY);
#elif defined(__PLATFORM_LINUX)
    void *hModule;
    hModule = dlopen(name.c_str(), RTLD_LAZY);
#endif

    if (hModule != nullptr)
    {

#if defined(__PLATFORM_WINDOWS)
      fnCreatePlugin CreatePlugin = (fnCreatePlugin)GetProcAddress(hModule, "CreatePlugin");
#elif defined(__PLATFORM_MAC)
      fnCreatePlugin CreatePlugin = (fnCreatePlugin)dlsym(hModule, "CreatePlugin");
#elif defined(__PLATFORM_LINUX)
      fnCreatePlugin CreatePlugin = (fnCreatePlugin)dlsym(hModule, "CreatePlugin");
#endif

      if (CreatePlugin != nullptr)
      {
        // Invoke the function to get the plugin from the DLL.
        plugin = CreatePlugin();

        if (plugin != nullptr)
        {
          //plugin->setName(pluginName); set real name not a name!
          // Add the plugin and library18 to the maps.
          m_implementation->m_plugins.insert(PluginMap::value_type(name, plugin));
          m_implementation->m_libs.insert(LibraryMap::value_type(name, hModule));
        }
        else
        {
          std::wcerr << "ERROR: Could not load plugin from " << name.c_str() << std::endl;

          // Unload the library.
          #if defined(__PLATFORM_WINDOWS)
                    FreeLibrary(hModule);
          #elif defined(__PLATFORM_MAC)
                    dlclose(hModule);
          #elif defined(__PLATFORM_LINUX)
                    dlclose(hModule);
          #endif
        }
      }
      else
      {
        std::wcerr << "ERROR: Could not find symbol \"CreatePlugin\" in " << name.c_str() << std::endl;
#if defined(__PLATFORM_WINDOWS)
        FreeLibrary(hModule);
#elif defined(__PLATFORM_MAC)
        dlclose(hModule);
#elif defined(__PLATFORM_LINUX)
        dlclose(hModule);
#endif
      }
    }
    else
    {
      std::wcerr << "ERROR: Could not load library: " << name.c_str() << std::endl;
      m_status = {false};
    }
  }
  else
  {
    std::wcout << "INFO: Library \"" << name.c_str() << "\" already loaded." << std::endl;
    plugin = iter->second;
    m_status = {true};
  }
  return plugin;
}

void PluginManager::unload(Plugin *&plugin)
{
  if (plugin != nullptr)
  {
    LibraryMap::iterator iter = m_implementation->m_libs.find(plugin->getName());
    if(iter != m_implementation->m_libs.end())
    {
      // Remove the plugin from our plugin map.
      m_implementation->m_plugins.erase(plugin->getName());
      void* hModule = iter->second;
#if defined(__PLATFORM_WINDOWS)
      fnDestroyPlugin DestroyPlugin = (fnDestroyPlugin)GetProcAddress(hModule, "DestroyPlugin");
#elif defined(__PLATFORM_MAC)
      fnDestroyPlugin DestroyPlugin = (fnDestroyPlugin)dlsym(hModule, "DestroyPlugin");
#elif defined(__PLATFORM_LINUX)
      fnDestroyPlugin DestroyPlugin = (fnDestroyPlugin)dlsym(hModule, "DestroyPlugin");
#endif
      if (DestroyPlugin != nullptr)
      {
        DestroyPlugin();
      }
      else
      {
        std::wcerr << "ERROR: Unable to find symbol \"DestroyPlugin\" in library \"" << plugin->getName().c_str() << std::endl;
      }
// Unload the library and remove the library from the map.
#if defined(__PLATFORM_WINDOWS)
      FreeLibrary(hModule);
#elif defined(__PLATFORM_MAC)
      dlclose(hModule);
#elif defined(__PLATFORM_LINUX)
      dlclose(hModule);
#endif
      m_implementation->m_libs.erase(iter);
    }
    else
    {
      std::cout << "WARNING: Trying to unload a plugin that is already unloaded or has never been loaded." << std::endl;
    }
    plugin = nullptr;
  }
}

bool PluginManager::isLoaded() const
{
  return m_status;
}
