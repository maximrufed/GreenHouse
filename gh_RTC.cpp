﻿#include "gh_RTC.h"


/*bool gh_RTC :: Begin(){
  return(rtcDS3231.begin());
}*/

bool gh_RTC :: IsNight(){

	unsigned long currentMillis = millis();
  //LOG("gh_RTC: IsNight");
	// Не пытаемся считывать значения датчиков каждый тик, а делаем это не чаще 1 раза в 5 минут (300 000 миллисекунд)
	if(currentMillis - IsNightPreviousMillis > (long)300000) { 
		// сохраняем время последнего обновления
		IsNightPreviousMillis = currentMillis; 
	}


	//DateTime nowTime = now();
	//int nowHour = nowTime.hour();
	//LOG(nowHour);
	int Hour = now().hour();
  //LOG("Hour: " + (String)Hour);
	if( (Hour > 20) or (Hour < 7) ) {
		//LOG("Night");
		return(true);
	} else {
		//LOG("Day");
		return(false);
	}
}

bool gh_RTC :: IsDay(){
	return(!IsNight());
}
