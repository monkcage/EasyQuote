#ifndef ES_SIMTRADEIMPL_INC
#define ES_SIMTRADEIMPL_INC

#include "core/api/ITrader.hpp"

namespace es {

class StpTradeImpl:  public ITrade{
public:
    virtual ~StpTradeImpl() = default;
    virtual bool Init() override
    {

    }

    virtual void RegisterSubscriber(std::shared_ptr<ITradeSubscriber> const& sub) {}
};


}



#endif
