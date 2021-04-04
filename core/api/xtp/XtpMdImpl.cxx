
#include <string>
#include "core/api/xtp/XtpMdImpl.hpp"


namespace es {

XtpMdImpl::XtpMdImpl()
{
}

XtpMdImpl::~XtpMdImpl()
{
}

bool XtpMdImpl::Init()
{
    uint8_t client_id = 0;
    uint32_t heat_beat = 5;
    std::string path("./");
//    m_api = XTP::API::QuoteApi::CreateQuoteApi(client_id,
//                                               path.c_str(),
//                                               XTP_LOG_LEVEL_DEBUG);
    m_api->RegisterSpi(this);
    m_api->SetHeartBeatInterval(heat_beat);
    int ret = m_api->Login("ip", 111, "username", "passwrd", XTP_PROTOCOL_TYPE::XTP_PROTOCOL_UDP);
    if(ret == 0) {

    }else {

    }
    return true;
}

void XtpMdImpl::SubscribeMarketData(Symbol const& symbol)
{
    XTP_EXCHANGE_TYPE type;
    if(symbol.type == es::ExchageType::SZSE){
        type = XTP_EXCHANGE_TYPE::XTP_EXCHANGE_SZ;
    }else if (symbol.type == es::ExchageType::SSE) {
        type = XTP_EXCHANGE_TYPE::XTP_EXCHANGE_SH;
    }else {
        type = XTP_EXCHANGE_TYPE::XTP_EXCHANGE_UNKNOWN;
    }

    char* *instrument = new char*[1];
    instrument[0] = new char[16];
    memcpy(instrument[0], symbol.name.c_str(), symbol.name.size());
    m_api->SubscribeMarketData(instrument, 1, type);
    delete instrument[0];
    delete[] instrument;
    instrument = nullptr;
}

void XtpMdImpl::SubscribeMarketData(const std::vector<std::shared_ptr<Symbol> > &symbols)
{
    for(auto&& symbol: symbols) {
        this->SubscribeMarketData(*symbol);
    }
}



void XtpMdImpl::OnDisconnected(int reason) {}
void XtpMdImpl::OnError(XTPRI *error_info) {}
void XtpMdImpl::OnSubMarketData(XTPST *ticker, XTPRI *error_info, bool is_last) {}
void XtpMdImpl::OnUnSubMarketData(XTPST *ticker, XTPRI *error_info, bool is_last) {}
void XtpMdImpl::OnDepthMarketData(XTPMD *market_data, int64_t *bid1_qty, int32_t bid1_count, int32_t max_bid1_count, int64_t *ask1_qty, int32_t ask1_count, int32_t max_ask1_count) {}
void XtpMdImpl::OnSubOrderBook(XTPST *ticker, XTPRI *error_info, bool is_last) {}
void XtpMdImpl::OnUnSubOrderBook(XTPST *ticker, XTPRI *error_info, bool is_last) {}
void XtpMdImpl::OnSubTickByTick(XTPST *ticker, XTPRI *error_info, bool is_last) {}
void XtpMdImpl::OnUnSubTickByTick(XTPST *ticker, XTPRI *error_info, bool is_last) {}
void XtpMdImpl::OnOrderBook(XTPOB *order_book) {}
void XtpMdImpl::OnTickByTick(XTPTBT *tbt_data) {}
void XtpMdImpl::OnQueryAllTickers(XTPQSI *ticker_info, XTPRI *error_info, bool is_last) {}
void XtpMdImpl::OnQueryTickersPriceInfo(XTPTPI *ticker_info, XTPRI *error_info, bool is_last) {}
void XtpMdImpl::OnSubscribeAllMarketData(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) {}
void XtpMdImpl::OnUnSubscribeAllMarketData(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) {}
void XtpMdImpl::OnSubscribeAllOrderBook(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) {}
void XtpMdImpl::OnUnSubscribeAllOrderBook(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) {}
void XtpMdImpl::OnSubscribeAllTickByTick(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) {}
void XtpMdImpl::OnUnSubscribeAllTickByTick(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) {}
void XtpMdImpl::OnSubscribeAllOptionMarketData(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) {}
void XtpMdImpl::OnUnSubscribeAllOptionMarketData(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) {}
void XtpMdImpl::OnSubscribeAllOptionOrderBook(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) {}
void XtpMdImpl::OnUnSubscribeAllOptionOrderBook(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) {}
void XtpMdImpl::OnSubscribeAllOptionTickByTick(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) {}
void XtpMdImpl::OnUnSubscribeAllOptionTickByTick(XTP_EXCHANGE_TYPE exchange_id, XTPRI *error_info) {}




}
