#ifndef ES_TYPES_INC
#define ES_TYPES_INC

namespace es {


enum ExchageType {
    SHFE,
    CFFEX,
    DCE,
    CZCE,
    INE,
    SZSE,
    SSE,
    UNKNWON
};


enum OrderType {
    LIMIT
};

enum OrderStatus {
    SUBMITTING
};

enum OrderDirection {
    BUY,
    SELL
};

enum OrderOffset {
    OPEN,
    CLOSE
};


}
#endif
