#include "plugininterface.hpp"

class PluginInterfaceImpl
{
public:
  NameList m_nameList;
  PluginList m_pluginList;
  ErrorString m_errors;
};

PluginInterface::PluginInterface()
{
  m_pImpl = new PluginInterfaceImpl();
  return;
}

PluginInterface::~PluginInterface()
{
  m_pImpl->m_nameList.clear();
  delete m_pImpl;
}

PluginInterface& PluginInterface::instance()
{
  static PluginInterface inst;
  return inst;
}

void PluginInterface::addDetail(const PluginList& plist) {
  m_pImpl->m_pluginList = plist;
}

void PluginInterface::addName(const std::string& name)
{
  m_pImpl->m_nameList.push_back(name);
}

void PluginInterface::setError(const std::string &var)
{
  m_pImpl->m_errors.push_back(var);
}

const NameList& PluginInterface::getNames() const
{
  return m_pImpl->m_nameList;
}

const PluginList& PluginInterface::getDetail() const
{
  return m_pImpl->m_pluginList;
}

const ErrorString& PluginInterface::getErrors() const
{
  return m_pImpl->m_errors;
}
