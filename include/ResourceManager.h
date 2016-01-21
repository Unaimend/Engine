/************************************
*Author: 	Thomas Dost
*Datum: 	22.12.2015
*Beschr.	Verwaltet Assets, dazu gehoert: Laden, Speichern und Streamen
*Changelog:
*			22.12.205
*			Erstellt
*TODO:
*			Kommentieren
*			Nichtbenutzte Konstruktoren loeschen
*			Zugriff auf den Manager programmieren, so dass RefCount richtig gehandelt wird
*************************************/


#pragma once
#include <string>
#include <functional> //std::hash
#include "EngineTypes.h"


template<typename T>
class Resource
{
public:
	/*
	*Konstruktor fuer das initilisieren der Klasse.
	*Param1: Pfad zum Asset
	*Param2: Pfad zum Asset als Hash.
	*/
	Resource(const filepath& pathToRessource ) 
		: mPathToRessource(pathToRessource), mFileHandle(  std::hash<std::string>()(pathToRessource)), mRefCount(1)
	{
		
	}

	/*
	*Desktruktor
	*/
	~Resource()
	{
		delete mDataPointer;
		//Nullsetzen damit man ueberprufen kann, ob das objek valid ist.
		mDataPointer = nullptr;
	}


	/*
	*Movekonstruktor
	*Param1: -----
	*/
	explicit Resource(Resource&& rhs) noexcept
	{
		//Typische Movestuff
		mPathToRessource = rhs.mPathToRessource;
		mFileHandle = rhs.mFileHandle;
		mDataPointer = rhs.mDataPointer;
		mRefCount = rhs.RefCount;

		rhs.mDataPointer = nullptr;
		rhs.mRefCount = 0;
	}


	/*
	*Move-Assignment-Operator
	*Param1: -----
	*/
	Resource& operator=(Resource&& rhs) noexcept
	{
		//Typische Movestuff
		if (this != &rhs)
		{
			mPathToRessource = rhs.mPathToRessource;
			mFileHandle = rhs.mFileHandle;
			mDataPointer = rhs.mDataPointer;
			mRefCount = rhs.RefCount;
	
			rhs.mDataPointer = nullptr;
			rhs.mRefCount = 0;	
		}		
	}


	/*
	*Dekrementiert den RefCount und checkt ob die Ressource freigegeben werden kann
	*/
	void unloadIfNotNeeded()
	{
		--mRefCount;
		//Ist der RefCount 0, wird das objekt nichtmehr benoetigt
		if(mRefCount == 0)
		{	
			delete mDataPointer;
			//Nullsetzen damit man ueberprufen kann, ob das objek valid ist.
			mDataPointer = nullptr;
		}
	}

    Resource(Resource& rhs) = delete;
	Resource& operator=(Resource& rhs) = delete;
public:
	//Pfad zur Ressource
	filepath mPathToRessource;
	//Pfad zur Ressource als Hash
	eng::hash mFileHandle;
	//Pointer zu den Ressourcendaten
	T* mDataPointer;
	//Refcount zum Ueberpruefen ob das Objekt noch gebraucht wird.
	int64 mRefCount;
};


template<typename T>
class ResourceManager
{
public:

private:

public:
	//std::map<hash, Resource<T> > mResourceMap;
private:
};

