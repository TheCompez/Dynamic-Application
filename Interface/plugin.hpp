#ifndef PLUGIN_HPP
#define PLUGIN_HPP

#include "plugininterface.hpp"
#include "common.hpp"

/*!
 * \brief The PluginType enum
 */
enum class PluginType {
  Index,  //!For global user service.
  Admin,  //!For administrator service.
  System, //!For system service.
  Cron,   //!For cron job service.
  Core,   //!For cms core service.
  Theme,  //!For cms template.
  Default //!For default global service.
};


class __project_export Plugin
{
public:
  Plugin();
  virtual ~Plugin();

  /*!
   * \brief getName function returns name of plugin.
   * \return string of name.
   */
  [[nodiscard]] virtual std::string getName() const noexcept = 0;

  /*!
   * \brief getDescription function returns description of plugin.
   * \return string of details.
   */
  [[nodiscard]] virtual std::string getDescription() const noexcept = 0;

  /*!
   * \brief getVersion function returns version of plugin.
   * \return string of version number.
   */
  [[nodiscard]] virtual std::string getVersion() const noexcept = 0;

  /*!
   * \brief getVersion function returns version of plugin.
   * \return string of plugin's author.
   */
  [[nodiscard]] virtual std::string getAuthor() const noexcept = 0;

  /*!
   * \brief doAction is action function for plugins.
   */
  virtual void doAction() const noexcept = 0;

  template <typename... Args>
  /*!
   * \brief action as auto!
   * \param val returns any type based on user input.
   */
  auto action(const auto& val)
  {
    return val;
  }

  template <typename T>
  /*!
   * \brief multiAction as multi types.
   * \param obj
   */
  auto multiAction(T& obj) -> decltype(obj) {
    return obj;
  }

  /*!
   * \brief function type specifies the type of plugin.
   * \returns type of plugin.
   */
  virtual PluginType type() const noexcept = 0;

protected:
  friend class PluginManager;
  void setName(const std::string& name);
  void setDescription(const std::string& desc);
  void setVersion(const std::string& version);
  void setAuthor(const std::string& author);

private:
  PluginType  m_pluginType  = {PluginType::Default};
  std::string m_name        = {"unknwon"};
  std::string m_description = {"unknown"};
  std::string m_version     = {"unknown"};
  std::string m_author      = {"unknown"};
};


#endif // PLUGIN_HPP
