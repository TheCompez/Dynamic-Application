#include "interface.hpp"
#include "plugin.hpp"
#include <iostream>
#include <sstream>

Interface::Interface()
{
  m_detail.name = "Plugin Two";
  m_detail.description = "This is Plugin Two for Tegra CMS.";
  m_detail.version = "0.5";
  m_detail.author = "Kambiz Asadzadeh";

  PluginList plist = {m_detail};
  PluginInterface::instance().addDetail(plist);
  PluginInterface::instance().addName(m_detail.name);

}

Interface::~Interface()
{
}

std::string Interface::getName() const noexcept {
  return "Plugin Two";
}

std::string Interface::getDescription() const noexcept {
  return "This is Plugin Two for Tegra CMS.";
}

std::string Interface::getVersion() const noexcept {
  return "0.2";
}

std::string Interface::getAuthor() const noexcept {
  return "Kambiz Asadzadeh";
}

void Interface::doAction() const noexcept {
  std::cout << "Do action... for " << m_detail.name << " !\n";
  std::stringstream message;
  message << "Error on line : " << __project_compiler_line << " inside plugin : " << m_detail.name;
  PluginInterface::instance().setError(message.str());
}

PluginType Interface::type() const noexcept {
  return PluginType::Admin;
}
