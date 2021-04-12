#include "plugin.hpp"
#include "plugininterface.hpp"

Plugin::Plugin()
{
  PluginInterface::instance().addName("Interface");
}

Plugin::~Plugin()
{
}

//std::string Plugin::getName()
//{
//  return m_name;
//}

//void Plugin::setName(const std::string &name)
//{
//  m_name = name;
//}

//std::string Plugin::getDescription() const noexcept
//{
//  return m_description;
//}

//void Plugin::setDescription(const std::string &desc)
//{
//  m_description = desc;
//}

//std::string Plugin::getVersion() const noexcept
//{
//  return m_version;
//}

//void Plugin::setVersion(const std::string &version)
//{
//  m_version = version;
//}

//std::string Plugin::getAuthor() const noexcept
//{
//  return m_author;
//}

//void Plugin::setAuthor(const std::string &author)
//{
//  m_author = author;
//}

