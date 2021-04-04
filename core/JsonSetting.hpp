#ifndef ES_JSONSETTING_INC
#define ES_JSONSETTING_INC


#include "jsonxx/json.hpp"
#include "core/setting.hpp"




namespace es {

class JsonSetting: public ISetting {
public:
    JsonSetting(std::string const& file);
    virtual ~JsonSetting() override;

    virtual int GetIntValue(std::string key) override;
    virtual std::string GetStringValue(std::string key) override;


private:
//    JsonSetting(jsonxx::json::object_type object);

private:
    std::string  m_file;
    jsonxx::json m_json;
};


}


#endif
