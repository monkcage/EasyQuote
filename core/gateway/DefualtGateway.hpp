#ifndef ES_DEFAULTGATEWAY_INC
#define ES_DEFAULTGATEWAY_INC

#include "core/api/IMD.hpp"
#include "core/api/ITrader.hpp"
#include "core/gateway/gateway.hpp"

namespace es {


class DefaultGateway: public IGateway {
public:
    DefaultGateway(std::shared_ptr<IMD> const& md, std::shared_ptr<ITrade> const& trade)
        : m_md(md)
        , m_trade(trade)
    {}

    virtual ~DefaultGateway() = default;


    virtual void SubscribeMarketData(const Symbol &symbol) override
    {
        m_md->SubscribeMarketData(symbol);
    }

    virtual void SubscribeMarketData(const std::vector<std::shared_ptr<Symbol>> &symbols) override
    {
        m_md->SubscribeMarketData(symbols);
    }

    virtual void SendOrder() override
    {}

private:
    std::shared_ptr<IMD>    m_md;
    std::shared_ptr<ITrade> m_trade;
};


}



#endif
