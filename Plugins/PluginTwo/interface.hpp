#ifndef CONCRETEPLUGIN_HPP
#define CONCRETEPLUGIN_HPP

#include "plugintwo.hpp"

class __project_export Interface : public Plugin
{
public:
  Interface();
  ~Interface();

  [[nodiscard]] std::string getName() const noexcept override;

  [[nodiscard]] std::string getDescription() const noexcept override;

  [[nodiscard]] std::string getVersion() const noexcept override;

  [[nodiscard]] std::string getAuthor() const noexcept override;

  [[nodiscard]] PluginType  type() const noexcept override;

  void doAction() const noexcept override;

  template <typename... Args>
  auto action(const auto& val)
  {
    return val;
  }

  template <typename T>
  auto multiAction(T& obj) -> decltype(obj) {
    return obj;
  }

private:
  PluginDetail m_detail;

};


#endif // CONCRETEPLUGIN_HPP
