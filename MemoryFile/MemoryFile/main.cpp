
#include"MemoryFile.h"
#include<iostream>
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
		data.LastPrice = 3303;
		data.PreSettlementPrice = 3304;
		data.PreClosePrice = 3304;
		data.PreOpenInterest = 3304;
		data.OpenPrice = 3304;
		data.HighestPrice = 3304;
		data.LowestPrice = 3304;
		data.Volume = 3304;
		data.Turnover = 3304;
		data.OpenInterest = 3304;
		data.ClosePrice = 3304;
		data.SettlementPrice = 3304;
		data.UpperLimitPrice = 3304;
		data.LowerLimitPrice = 3304;
		data.PreDelta = 3304;
		data.CurrDelta = 3304;
		data.UpdateMillisec = 3304000;
		vecdata.emplace_back(data);
	}
}



int main()
{
	InitData();
	//MemoryFile file("E:/git_my_project/c-11/Debug/data", "Global/share_001");
	MemoryFile file("data", "Global/share_001");
	for (size_t i = 0; i < 1; i++)
	{
		file.saveData(vecdata, MEM_APPEND);
		file.readData();
	}
	getchar();
	return 0;
}

