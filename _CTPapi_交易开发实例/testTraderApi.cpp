// testTraderApi.cpp : 定义控制台应用程序的入口点。
//
#include ".\ThostTraderApi\ThostFtdcTraderApi.h"
#include "TraderSpi.h"

// UserApi对象
CThostFtdcTraderApi* pUserApi;

// 配置参数
char  FRONT_ADDR[] = "tcp://ctpmn1-front1.citicsf.com:51205";		// 前置地址
TThostFtdcBrokerIDType	BROKER_ID = "1017";				// 经纪公司代码
TThostFtdcInvestorIDType INVESTOR_ID = "00000001";			// 投资者代码
TThostFtdcPasswordType  PASSWORD = "123456";			// 用户密码
TThostFtdcInstrumentIDType INSTRUMENT_ID = "if1411";	// 合约代码
TThostFtdcDirectionType	DIRECTION = THOST_FTDC_D_Sell;	// 买卖方向
TThostFtdcPriceType	LIMIT_PRICE = 2509;				// 价格

// 请求编号
int iRequestID = 0;

void main(void)
{
	// 初始化UserApi
	pUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi();			// 创建UserApi
	CTraderSpi* pUserSpi = new CTraderSpi();
	pUserApi->RegisterSpi((CThostFtdcTraderSpi*)pUserSpi);			// 注册事件类
	pUserApi->SubscribePublicTopic(TERT_RESTART);					// 注册公有流
	pUserApi->SubscribePrivateTopic(TERT_RESTART);					// 注册私有流
	pUserApi->RegisterFront(FRONT_ADDR);							// connect
	pUserApi->Init();

	pUserApi->Join();
//	pUserApi->Release();
}