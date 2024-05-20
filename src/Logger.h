#pragma once
#include "stdafx.h"

class Logger {
private:
	static const auto& current_datetime ()
	{
		static struct tm newtime;
		static __time64_t long_time;
		_time64 (&long_time);
		localtime_s (&newtime, &long_time);
		return newtime;
	}
	
	std::wofstream log_wstream;

public:

	const bool read(std::wstring_view app, std::wstring_view key, const int def_value = 0) {
		if (1 == GetPrivateProfileInt(app.data(), key.data(), def_value, L"./config.ini")) {
			return true;
		}
		return false;
	}

	Logger () {
		if (true == read (L"Config", L"Log")) {
			log_wstream.open (L"blockthespot_log.txt", std::ios::out | std::ios::app);
			//m_log << "BlockTheSpot - Build date: " << __TIMESTAMP__ << std::endl;
		}
	}

	~Logger () {
		if (true == log_wstream.is_open()) {
			log_wstream.flush ();
			log_wstream.close ();
		}
	}

	void Log (std::wstring_view log) {
		if (true == log_wstream.is_open ()) {
			std::wstringstream message;
			const auto& time = current_datetime();
			message << L"LOG | " << std::put_time(&time, L"%d-%b-%Y %H:%M:%S") << L" - " << log;
			log_wstream << message.str() << std::endl;
		}
			
	}


};
