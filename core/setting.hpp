#ifndef ES_SETTING_INC
#define ES_SETTING_INC

#include <string>
#include <memory>

namespace es {


class ISetting{
public:
    virtual ~ISetting() = default;

    virtual int GetIntValue(std::string key) = 0;
    virtual std::string GetStringValue(std::string key) = 0;
//    virtual std::shared_ptr<ISetting> MdSetting() = 0;
//    virtual std::shared_ptr<ISetting> TradeSetting() = 0;
};


template <typename T>
std::shared_ptr<
    typename std::enable_if<(!std::is_same<ISetting,T>::value)
                             &&(std::is_base_of<ISetting,T>::value), T>::type
>
dyn_cast(std::shared_ptr<ISetting> ptr){
    return std::static_pointer_cast<T>(ptr);
}


}


#endif
