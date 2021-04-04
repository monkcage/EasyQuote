#ifndef ES_ENGINE_INC
#define ES_ENGINE_INC


#include <string>
#include <memory>

#include "core/gateway/gateway.hpp"

namespace es {

class Engine{
public:
    Engine();

    void Gateway(std::shared_ptr<IGateway> const& gateway);
    void Gateway(std::vector<std::shared_ptr<IGateway>> const& gateway);

    void Run();

private:
    std::string m_name;
    std::string m_module;
    std::string m_abs_path;

    std::vector<std::shared_ptr<IGateway>> m_gateways;
};


}


#endif
