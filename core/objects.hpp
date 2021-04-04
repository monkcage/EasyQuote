#ifndef ES_OBJECTS_INC
#define ES_OBJECTS_INC

#include <string>
#include <cinttypes>

#include "core/types.hpp"

namespace es {


struct Object {
    std::string gateway_name;
};


struct Symbol {
    ExchageType type;
    std::string name;
};


struct Tick: public Object {
    std::string symbol;
    std::string exchange;
    std::string datetime;
    std::string name;
    float       volume;
    float       open_interest;
    float       last_price;
    float       last_volume;
    float       limit_up;
    float       limit_donw;
    float       open_price;
    float       high_price;
    float       low_price;
    float       close_proce;
    float       bid_price1;
    float       bid_price2;
    float       bid_price3;
    float       bid_price4;
    float       bid_price5;
    float       bid_volume1;
    float       bid_volume2;
    float       bid_volume3;
    float       bid_volume4;
    float       bid_volume5;
    float       ask_price1;
    float       ask_price2;
    float       ask_price3;
    float       ask_price4;
    float       ask_price5;
    float       ask_volume1;
    float       ask_volume2;
    float       ask_volume3;
    float       ask_volume4;
    float       ask_volume5;
};


struct KLine: public Object {
    std::string  symbol;
    std::string  exchange;
    std::string  datetime;
    std::int32_t interval;
    float        volume;
    float        open_price;
    float        high_price;
    float        low_price;
    float        close_price;
};



struct Order: public Object {
    std::string symbol;
    std::string exchange;
    std::string id;
    OrderType   type;
    OrderDirection direction;
    OrderOffset    offset;
    float          price;
    float          volume;
    OrderStatus    status;
    std::string    datetime;
};


struct Contract: public Object {
    std::string symbol;
    std::string exchange;
    float       pricetick;
    float       minVolume;
    bool        stopSupported;
    bool        netPosition;
    bool        historyData;

};


}


#endif
