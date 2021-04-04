TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt


INCLUDEPATH += $$PWD/core/api \
               $$PWD/th3party

LIBS += -L$$PWD/core/api/ctp/win -lthostmduserapi_se


SOURCES += \
        core/JsonSetting.cxx \
        core/api/ctp/CtpMdImpl.cxx \
        core/api/stp/StpMdImpl.cxx \
        core/api/stp/StpTradeImpl.cxx \
        core/api/xtp/XtpMdImpl.cxx \
        core/api/xtp/XtpTradeImpl.cxx \
        core/engine.cxx \
        main.cpp

HEADERS += \
    core/JsonSetting.hpp \
    core/api/IMD.hpp \
    core/api/IMdSubscriber.hpp \
    core/api/ITradeSubscriber.hpp \
    core/api/ITrader.hpp \
    core/api/ctp/CtpMdImpl.hpp \
    core/api/ctp/CtpTradeImpl.hpp \
    core/api/ctp/error.hpp \
    core/api/stp/StpMdImpl.hpp \
    core/api/stp/StpTradeImpl.hpp \
    core/api/xtp/XtpMdImpl.hpp \
    core/api/xtp/XtpTradeImpl.hpp \
    core/engine.hpp \
    core/gateway/DefualtGateway.hpp \
    core/gateway/gateway.hpp \
    core/objects.hpp \
    core/setting.hpp \
    core/types.hpp
