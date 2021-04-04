
#include <numeric>
#include <cstring>

#include "logging/easylogging++.hpp"
#include "core/api/ctp/CtpMdImpl.hpp"
//#include "core/objects.hpp"


namespace es {


CtpMdImpl::CtpMdImpl()
{

}

CtpMdImpl::~CtpMdImpl()
{

}




bool CtpMdImpl::Init()
{
    m_api = CThostFtdcMdApi::CreateFtdcMdApi();
    m_api->RegisterSpi(this);

    std::string host("tcp://180.168.146.187:10010");
//    m_api->RegisterFront(const_cast<char*>(host.c_str()));
    m_api->RegisterNameServer(const_cast<char*>(host.c_str()));
    return true;
}

void CtpMdImpl::Run()
{
    m_api->Init();
}

void CtpMdImpl::Stop()
{
    if(m_api) {
        m_api->Release();
        m_api = nullptr;
    }
}

void CtpMdImpl::RegisterSubscriber(const std::shared_ptr<IMdSubscriber> &sub)
{
    m_subscribers.emplace_back(sub);
}


void CtpMdImpl::OnFrontConnected()
{
    LOG(INFO) << "CTP Connected.";

    CThostFtdcReqUserLoginField field;
    memset(&field, 0x00, sizeof(field));
//    strncpy(field.UserID, "099511", 6);
//    strncpy(field.Password, "201708", 6);
//    strncpy(field.BrokerID, "9999", 4);
    m_api->ReqUserLogin(&field, 0);
}


void CtpMdImpl::OnFrontDisconnected(int nReason)
{
    LOG(WARNING) << "CTP Disconnected [" << nReason << "]";
}


void CtpMdImpl::OnHeartBeatWarning(int nTimeLapse)
{
    LOG(WARNING) << "CTP Heart Beat Warning : " << nTimeLapse << " second since last heart beat.";
}


void CtpMdImpl::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    if(!pRspInfo || pRspInfo->ErrorID == 0) {
        LOG(INFO) << "CTP login successful : " << pRspUserLogin->TradingDay;
    }else{
        LOG(INFO) << "CTP login error: " << pRspInfo->ErrorMsg;
    }
}

void CtpMdImpl::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    if(pRspInfo && pRspInfo->ErrorID) {
        LOG(INFO) << "CTP logout.";
    }
}

void CtpMdImpl::OnRspQryMulticastInstrument(CThostFtdcMulticastInstrumentField *pMulticastInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{}


void CtpMdImpl::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    LOG(ERROR) << "OnRspError : ["<< pRspInfo->ErrorID << ": " << pRspInfo->ErrorMsg <<"]";
}


void CtpMdImpl::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    if(pRspInfo && pRspInfo->ErrorID != 0){
        LOG(WARNING) << "Subscribe("<< pSpecificInstrument->InstrumentID << ") market data failed - " << pRspInfo->ErrorMsg;
    }else{
        LOG(INFO) << "Subscribe(" << pSpecificInstrument->InstrumentID << ") market data success.";
    }
}

void CtpMdImpl::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{}

void CtpMdImpl::OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{}

void CtpMdImpl::OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{}

void CtpMdImpl::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
//    std::shared_ptr<Tick> data(new Tick);

//    for(auto&& sub: m_subscribers){
//        sub->OnMarketData(data);
//    }
}

void CtpMdImpl::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp)
{}


}
