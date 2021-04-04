
#include <iostream>
#include <fstream>
#include "core/JsonSetting.hpp"

namespace es {


JsonSetting::JsonSetting(std::string const& file)
    : m_file(file)
{
    std::ifstream istream(file);
    istream >> m_json;
}

//JsonSetting::JsonSetting(jsonxx::json::object_type object)
//{
//    m_object = object;
//    std::cout << m_object["ip"] << std::endl;
//    std::cout << m_object["port"] << std::endl;
//}

JsonSetting::~JsonSetting()
{
}


//std::shared_ptr<ISetting> JsonSetting::MdSetting()
//{
//    auto ret = std::make_shared<ISetting>(JsonSetting(m_json["md_setting"].as_object()));
//    return ret;
//}


//std::shared_ptr<ISetting> JsonSetting::TradeSetting()
//{
//    auto ret = std::make_shared<ISetting>(JsonSetting(m_json["trade_setting"].as_object()));
//    return ret;
//}

int JsonSetting::GetIntValue(std::string key)
{
    return m_json[key].as_int();
}

std::string JsonSetting::GetStringValue(std::string key)
{
    return m_json[key].as_string();
}


}
