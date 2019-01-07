
#include"MemoryFile.h"
#include<iostream>
#include<Windows.h>
using namespace std;

//https://blog.csdn.net/tiankefeng19850520/article/details/18838991

struct SData
{
	int size;
	double price;
	string  name;
};

vector<MarketDataFile> vecdata;
void InitData(long count =102400)
{
	std::cout << "max_size: " << vecdata.max_size() << std::endl;
	vecdata.reserve(count);
	for (long n = 0; n < count; n++)
	{
		MarketDataFile data;
		memset(&data, 0x00, sizeof(MarketDataFile));
		strncpy(data.TradingDay, "20190101", sizeof(data.TradingDay));
		strncpy(data.InstrumentID, "IF1905", sizeof(data.InstrumentID));
		strncpy(data.ExchangeID, "DCE", sizeof(data.ExchangeID));
		strncpy(data.ExchangeInstID, "DCE", sizeof(data.ExchangeInstID));
		strncpy(data.UpdateTime, "14:12:12", sizeof(data.UpdateTime));
		strncpy(data.ActionDay, "20190108", sizeof(data.ActionDay));
		data.LastPrice =  n * 100;
		data.PreSettlementPrice = n * 100;
		data.PreClosePrice = n * 100;
		data.PreOpenInterest = n * 100;
		data.OpenPrice = n * 100;
		data.HighestPrice = n * 100;
		data.LowestPrice = n * 100;
		data.Volume = n * 100;
		data.Turnover = n * 100;
		data.OpenInterest = n * 100;
		data.ClosePrice = n * 100;
		data.SettlementPrice = n * 100;
		data.UpperLimitPrice = n * 100;
		data.LowerLimitPrice = n * 100;
		data.PreDelta = n * 100;
		data.CurrDelta = n * 100;
		data.UpdateMillisec = n * 100;
		vecdata.emplace_back(data);
	}
}



int main()
{
	InitData();
	//MemoryFile file("E:/git_my_project/c-11/Debug/data", "Global/share_001");
	MemoryFile file("data", "Global\share_001");
	for (size_t i = 0; i < 20; i++)
	{
		file.saveData(vecdata);
		//file.readData();
	//	PBYTE buffer = nullptr;
	//	buffer = (PBYTE)malloc(vecdata.size() * sizeof(MarketDataFile));
	////	memset(buffer, 0x00, vecdata.size() * sizeof(MarketDataFile));
	//	_int64 size_t = vecdata.size() * sizeof(MarketDataFile);
	//	memcpy(buffer, (PBYTE)(vecdata.data()), vecdata.size() * sizeof(MarketDataFile));
	//	if(vecdata.size() * sizeof(MarketDataFile) > 117047296)
	//	memmove(buffer, buffer + 117047296, 117047296);
	//	free(buffer);
	//	buffer = nullptr;
	}

	__int64 n = ((__int64)1<<32);

	__int64 data = (__int64)1024 * (__int64)1024 * (__int64)1024 * (__int64)4;
	std::cout << "test is over" << std::endl;
	getchar();
	return 0;
}

