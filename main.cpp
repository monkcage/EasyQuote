#include <iostream>
#include "core/engine.hpp"
#include "logging/easylogging++.hpp"

#include "core/JsonSetting.hpp"
#include "core/gateway/DefualtGateway.hpp"
#include "core/api/stp/StpMdImpl.hpp"
#include "core/api/stp/StpTradeImpl.hpp"

using namespace std;

INITIALIZE_EASYLOGGINGPP


int main(int argc, char* argv[])
{
    auto md = std::make_shared<es::StpMdImpl>("2019-01-01 00:00:00", "2020-01-01 00:00:00");
    auto trade = std::make_shared<es::StpTradeImpl>();
    auto gateway = std::make_shared<es::DefaultGateway>(md, trade);
    es::Engine engine;
//    engine.Gateway(gateway);
    engine.Run();
//    if(argc != 2) {
//        std::cout << "Cannot load config" << std::endl;
//    }
//    std::cout << argv[1] << std::endl;
//    es::JsonSetting setting(argv[1]);
//    std::cout << " ====== MD SETTING =====" << std::endl;
//    std::cout << " ip : " << setting.GetStringValue("md.ip") << std::endl;
//    std::cout << " port : " << setting.GetIntValue("md.port") << std::endl;

    return 0;
}
