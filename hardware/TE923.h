#pragma once

#include "DomoticzHardware.h"
#include <iostream>
#include "TE923Tool.h"

class CTE923 : public CDomoticzHardwareBase
{
public:
	CTE923(const int ID);
	~CTE923(void);

	void WriteToHardware(const char *pdata, const unsigned char length);
private:
	CTE923Tool m_te923tool;
	bool m_bIsOpen;
	volatile bool m_stoprequested;
	time_t m_LastPollTime;
	boost::shared_ptr<boost::thread> m_thread;

	void Init();
	bool StartHardware();
	bool StopHardware();
	void Do_Work();
	void GetSensorDetails();
};
