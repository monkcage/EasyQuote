#ifndef ES_IMD_INC
#define ES_IMD_INC

#include <string>
#include <vector>
#include <memory>

#include "core/objects.hpp"
#include "core/api/IMdSubscriber.hpp"

namespace es {

class IMD {
public:
    virtual ~IMD() = default;
    virtual bool Init() = 0;
    virtual void Run() = 0;
    virtual void Stop() = 0;
    virtual void RegisterSubscriber(std::shared_ptr<IMdSubscriber> const& sub) = 0;

    virtual void SubscribeMarketData(Symbol const& symbol) = 0;
    virtual void SubscribeMarketData(std::vector<std::shared_ptr<Symbol>> const& symbols) = 0;
    virtual void OnMarketData(std::shared_ptr<Tick> const& tick) = 0;


};


}



#endif
