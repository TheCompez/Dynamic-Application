#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "pluginmanager.hpp"


int main()
{
  std::cout << "Hello World!" << std::endl;

  std::vector<std::string> plugins;
  plugins.push_back("libPluginOne.dylib");
  plugins.push_back("libPluginTwo.dylib");

  Plugin* plugin = nullptr;
  //Plugin* plugin2 = nullptr;

  for(const auto& c : plugins) {
    std::cout << "C: " << c << std::endl;

    plugin = PluginManager::instance().load("plugins/"+c);
    //plugin2 = PluginManager::Instance().load("plugins/libPluginTwo.dylib");

//    plugin1->doAction();
//    plugin2->doAction();

    plugin->doAction();

    switch (plugin->type()) {
    case PluginType::Theme:
        std::cout << "1\n";
      break;
      case PluginType::Admin:
        std::cout << "2\n";
      break;
      case PluginType::Core:
        std::cout << "3\n";
      break;
    default:
      break;
    }

//    std::vector<std::string> v1 = {"A", "B", "C"};
//    std::vector<int> v2 = {1, 2, 3};

//    for(const auto& c : plugin1->action(v1)) {
//      std::cout << "action for p1 : " << c << std::endl;
//    }

//    for(const auto& c : plugin2->action(v2)) {
//      std::cout << "action for p2 : " << c << std::endl;
//    }

//    std::cout << "action as int " << plugin->action(1) << std::endl;
//    std::cout << "action as string: " << plugin->action("Hi Action!") << std::endl;

//    std::vector<std::string> v = {"A", "B", "C"};

//    for(const auto& c : plugin->action(v)) {
//      std::cout << "action as vector : " << c << std::endl;
//    }


//    const auto temp = plugin->multiAction(v);
//    for(const auto& c : temp) {
//      std::cout << "V : " << c << std::endl;
//    }

//    if ( plugin != NULL )
//    {
//      std::cout << "INFO: Plugin --" << plugin->getName() << "(" << plugin->getVersion() << ") \n " << " : " << plugin->getDescription() << " -- successfully loaded." << std::endl;
//    }
//    else
//    {
//      std::cerr << "ERROR: Plugin --" << plugin->getName() << "-- failed to load." << std::endl;
//    }
  }


  //assert( plugin != nullptr );

  //  PluginList plist;

  //  std::string pName;
  //  for(const auto& o : PluginInterface::Instance().getDetail()) {
  //    std::cout << "Name : " << o.name << std::endl;
  //    pName = o.name;
  //    std::cout << "Description : " << o.description << std::endl;
  //    std::cout << "Version : " << o.version << std::endl;
  //    std::cout << "Author : " << o.author << std::endl;
  //  }


    for(const auto& c : PluginInterface::instance().getErrors()) {
      std::cout << " P : " << c << std::endl;
    }

  //PluginManager::Instance().unload(plugin1);
  //PluginManager::Instance().unload(plugin2);

  std::cout << "INFO: Plugin Unloaded." << std::endl;

  //system("PAUSE");

  return 0;
}
