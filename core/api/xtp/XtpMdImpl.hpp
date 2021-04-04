#ifndef ES_XTPMDIMPL_INC
#define ES_XTPMDIMPL_INC

#include "xtp/include/xtp_quote_api.h"
#include "core/api/IMD.hpp"

namespace es {

class XtpMdImpl: public IMD, public XTP::API::QuoteSpi{
public:
    XtpMdImpl();
    virtual bool Init() override;
    virtual void SubscribeMarketData(const Symbol &symbol) override;
    virtual void SubscribeMarketData(std::vector<std::shared_ptr<Symbol>> const& symbols) override;

    virtual ~XtpMdImpl() override;

    virtual void OnDisconnected(int reason) override;
    virtual void OnError(XTPRI *error_info) override;
    virtual void OnSubMarketData(XTPST *ticker, XTPRI *error_info, bool is_last) override;
    virtual void OnUnSubMarketData(XTPST *ticker, XTPRI *error_info, bool is_last) override;
    virtual void OnDepthMarketData(XTPMD *market_data, int64_t *bid1_qty, int32_t bid1_count, int32_t max_bid1_count, int64_t *ask1_qty, int32_t ask1_count, int32_t max_ask1_count) override;
    virtual void OnSubOrderBook(XTPST *ticker, XTPRI *error_info, bool is_last) override;
    virtual void OnUnSubOrderBook(XTPST *ticker, XTPRI *error_info, bool is_last) override;
    virtual void OnSubTickByTick(XTPST *ticker, XTPRI *error_info, bool is_last) override;
    virtual void OnUnSubTickByTick(XTPST *ticker, XTPRI *error_info, bool is_last) override;
    virtual void OnOrderBook(XTPOB *order_book) override;
    virtual void OnTickByTick(XTPTBT *tbt_data) override;
    virtual void OnQueryAllTickers(XTPQSI *ticker_info, XTPRI *error_info, bool is_last) override;
    virtual void OnQueryTickersPriceInfo(XTPTPI *ticker_info, XTPRI *error_info, bool is_last) override;
    virtual void OnSubscribeAllMarketData(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) override;
    virtual void OnUnSubscribeAllMarketData(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) override;
    virtual void OnSubscribeAllOrderBook(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) override;
    virtual void OnUnSubscribeAllOrderBook(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) override;
    virtual void OnSubscribeAllTickByTick(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) override;
    virtual void OnUnSubscribeAllTickByTick(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) override;
    virtual void OnSubscribeAllOptionMarketData(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) override;
    virtual void OnUnSubscribeAllOptionMarketData(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) override;
    virtual void OnSubscribeAllOptionOrderBook(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) override;
    virtual void OnUnSubscribeAllOptionOrderBook(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) override;
    virtual void OnSubscribeAllOptionTickByTick(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) override;
    virtual void OnUnSubscribeAllOptionTickByTick(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) override;
private:
    XTP::API::QuoteApi* m_api;
};


}



#endif
