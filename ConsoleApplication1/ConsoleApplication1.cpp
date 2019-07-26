// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "CAENDigitizerA.h"
#define MAXNB 1

int main()
{

	CAEN_DGTZ_ErrorCode ret;
	int	handle[MAXNB];
	CAEN_DGTZ_BoardInfo_t BoardInfo;
	CAEN_DGTZ_EventInfo_t eventInfo;
	CAEN_DGTZ_UINT16_EVENT_t* Evt = NULL;
	char* buffer = NULL;
	int MajorNumber;
	int i, b=0;
	int c = 0, count[MAXNB];
	char* evtptr = NULL;
	uint32_t size, bsize;
	uint32_t numEvents;
	i = sizeof(CAEN_DGTZ_TriggerMode_t);
	const LPCTSTR DLLName = TEXT("CAENDigitizer.dll");
	CAENDigitizer* myCAEN = new CAENDigitizer(DLLName);
	ret=myCAEN->CAEN_DGTZ_OpenDigitizer(CAEN_DGTZ_USB, 0, 0, 0, &handle[b]);
	if (ret != CAEN_DGTZ_Success) {
		std::cout << "Can't open digitizer"<<std::endl;
		goto QuitProgram;
	}
	ret = myCAEN->CAEN_DGTZ_GetInfo(handle[b], &BoardInfo);
	std::cout<<"Connected to CAEN Digitizer Model"<<BoardInfo.ModelName<<"recognized as board "<< b<<(std::endl);
	std::cout << "ROC FPGA Release is"<<BoardInfo.ROC_FirmwareRel<<std::endl;
	std::cout << "AMC FPGA Release is"<<BoardInfo.AMC_FirmwareRel<< std::endl;
    //std::cout << "Opened!\n";
	ret = myCAEN->CAEN_DGTZ_CloseDigitizer(handle[b]);
	
QuitProgram:
	system("pause");
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
