#ifndef ES_IMDSUBSCRIBER_INC
#define ES_IMDSUBSCRIBER_INC

#include <memory>
#include "core/objects.hpp"

namespace es {

class IMdSubscriber {
public:
    virtual ~IMdSubscriber() = default;
    virtual void OnMarketData(std::shared_ptr<Tick> const& tick) = 0;
};


}



#endif // IMDSUBSCRIBER_HPP
