#ifndef PLUGINMANAGER_HPP
#define PLUGINMANAGER_HPP

#include "plugin.hpp"
#include "plugininterface.hpp"
#include <string>
#include <iosfwd>

// Define the prototype for a function that should exist in the lib
// that is used to create and return the plugin type in the lib.

PointerToObject(Plugin, fnCreatePlugin)

// Destroys the plugin type from the lib before the library is unloaded.
using fnDestroyPlugin = PointerToFunction;

class PluginManagerPimpl;

/*!
 * \brief The PluginManager class
 */
class __project_export PluginManager
{
public:
  static PluginManager& instance();

  /*!
   * \brief load function loads the plugin and returns true if the plugin was loaded successfully; otherwise returns false.
   * \param plugin is plugin name.
   * \return plugin.
   */
  Plugin* load(const std::string& plugin);

  /*!
   * \brief unload function unloads the plugin and returns true if the plugin could be unloaded; otherwise returns false.
   * \param plugin
   */
  void unload(Plugin*& plugin);

  /*!
   * \brief isLoaded function returns true if the plugin is loaded; otherwise returns false.
   * \return bolean of status.
   */
  bool isLoaded() const;

private:
  PluginManager();
  ~PluginManager();

  bool m_status = {false};

  std::unique_ptr<PluginManagerPimpl> m_implementation;
};


#endif // PLUGINMANAGER_HPP
