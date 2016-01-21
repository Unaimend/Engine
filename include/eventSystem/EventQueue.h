/************************************
*Author:        Thomas Dost
*Datum:         16.01.2016
*Beschr.        Klasse fuer die globale Engine EventQueue
*Changelog:
                        16.01.2016
*                       Erstellt
						21.012016
						Beginn der Arbeit
*TODO:
*************************************/


#pragma once

#include <vector>
#include "Event.h"
namespace eng
{
	class EventQueue
	{
	public:

		/***********************************
		*Descri:	Konstruktor fuer die EventQueue
		************************************/
		EventQueue()
		{
			
		}


		/***********************************
		*Descri:	Funktion zum hinzufuegen von Events
		*Param1:	event welches geaddet werden soll
		*Return:
		************************************/
		void addEvent(eng::Event* event)
		{
			mEvents.push_back(event);
		}
	public:
		std::vector<eng::Event*> mEvents;
		

	};
}
