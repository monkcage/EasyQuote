
#include "core/engine.hpp"


namespace es {

Engine::Engine()
    : m_name("es::engine")
    , m_module("es::engine")
{
}


void Engine::Gateway(const std::shared_ptr<IGateway> &gateway)
{
    m_gateways.emplace_back(gateway);
}

void Engine::Gateway(const std::vector<std::shared_ptr<IGateway> > &gateways)
{
    for(auto&& gateway: gateways){
        m_gateways.emplace_back(gateway);
    }
}


void Engine::Run()
{

}


}
