#ifndef PLUGININTERFACE_HPP
#define PLUGININTERFACE_HPP

#include "common.hpp"

#include <vector>
#include <string>
#include <map>

//!JSON
#include "third-party/json/json.hpp"
//! TODO json configuration...
//! Add new feature for configuration plugins based on json file.

struct PluginDetail {
  std::string name;
  std::string description;
  std::string version;
  std::string author;
};

//!GLOBAL
using NameList      = std::vector<std::string>;
using PluginList    = std::vector<PluginDetail>;
using ErrorString   = std::vector<std::string>;

//!JSON
using JSon          = nlohmann::json;
using JSonException = nlohmann::detail::exception;

class PluginInterfaceImpl;

/*!
 * \brief The PluginInterface class is exported from the mail library.
 */
class __project_export PluginInterface {
public:
  //Return a static instance of this class
  static PluginInterface& instance();

  /*!
   * \brief addDetail function sets all information of plugins.
   * \param plist is type of PluginList [std::vector<PluginDetail>]
   */
  void addDetail(const PluginList& plist);

  /*!
   * \brief addName function sets name of plugins.
   * \param name of plugin.
   */
  void addName(const std::string& name);

  /*!
   * \brief setError function sets message of error inside plugins.
   * \param var is message of error.
   */
  void setError(const std::string& var);

  /*!
   * \brief getDetail function gets detail from plugins.
   * \return list of detail such as name, version and etc.
   */
  const PluginList& getDetail() const;

  /*!
   * \brief getNames function gets name of plugins.
   * \return list of plugin.
   */
  const NameList& getNames() const;

  /*!
   * \brief getErrors function gets list of errors.
   * \return list of errors as string [ErrorString : std::vector<std::string>].
   */
  const ErrorString& getErrors() const;

private:
  PluginInterface();
  virtual ~PluginInterface();
  PluginInterfaceImpl*  m_pImpl = {nullptr};
  NameList              m_nameList;
  PluginList            m_pluginList;
  ErrorString           m_errors;
};


#endif // PLUGININTERFACE_HPP
