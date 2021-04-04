#ifndef ES_SIMMDIMPL_INC
#define ES_SIMMDIMPL_INC

#include "core/api/IMD.hpp"
#include "core/api/IMdSubscriber.hpp"

namespace es {

class StpMdImpl: public IMD {
public:
    StpMdImpl(std::string const& start, std::string const& end)
        : m_start_time(start)
        , m_end_time(end)
    {
    }

    virtual ~StpMdImpl() = default;

    virtual bool Init() override
    {}

    virtual void Run() override
    {

    }

    virtual void SubscribeMarketData(const Symbol &symbol) override
    {
        m_symbols.emplace_back(std::make_shared<Symbol>(symbol));
    }
    virtual void SubscribeMarketData(const std::vector<std::shared_ptr<Symbol> > &symbols) override
    {
        for(auto&& symbol: symbols){
            m_symbols.emplace_back(symbol);
        }
    }

    virtual void RegisterSubscriber(const std::shared_ptr<IMdSubscriber> &sub) override
    {
        m_subscribers.emplace_back(sub);
    }

    virtual void OnMarketData(const std::shared_ptr<Tick> &tick) override
    {
        for(auto&& obs: m_subscribers){
            obs->OnMarketData(nullptr);
        }
    }

    virtual void Stop() {}



private:
    std::vector<std::shared_ptr<IMdSubscriber>> m_subscribers;
    std::vector<std::shared_ptr<Symbol>>      m_symbols;
    std::string                               m_start_time;
    std::string                               m_end_time;
};



}



#endif
