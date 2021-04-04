#ifndef ES_ITRADE_INC
#define ES_ITRADE_INC

#include <memory>
#include "core/api/ITradeSubscriber.hpp"

namespace es {



class ITrade {
public:
    virtual ~ITrade() = default;
    virtual bool Init() = 0;
    virtual void RegisterSubscriber(std::shared_ptr<ITradeSubscriber> const& sub) = 0;
};



}



#endif
