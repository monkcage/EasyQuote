#ifndef ES_GATEWAY_INC
#define ES_GATEWAY_INC


#include <string>
#include <vector>
#include <memory>

#include "core/objects.hpp"


namespace es {


/*
* Abstract gateway class for creating gateway connection
* to different trading systems.
*/
class IGateway {
public:
    virtual ~IGateway() = default;
    virtual void SubscribeMarketData(Symbol const& symbol) = 0;
    virtual void SubscribeMarketData(std::vector<std::shared_ptr<Symbol>> const& symbols) = 0;
    virtual void SendOrder() = 0;
};


}



#endif
