/************************************
 *Author:    Thomas Dost
 *Datum:     04.04.2015
 *Beschr.    Wrapper um tinyxml2 um einfachere Bedienung zu ermoeglichen
 *Changelog:
 *TODO:
 *************************************/
#pragma once
#include <string>
#include <iostream>

#include "../tinyXML/tinyxml2.h"
#include "../EngineTypes.h"


namespace eng
{
    using namespace tinyxml2;
    class Xml
    {
    public:
        Xml(filepath filepath)
        {
            if(mDoc.LoadFile(filepath.c_str()) != XML_NO_ERROR)
            {
                if(mDoc.Parse(filepath.c_str()) != XML_NO_ERROR)
                {
                    
                }
                else
                {
                    std::cerr << "Die Datei:" << filepath << "konnte nicht GEPARSED werden" << std::endl;
                    std::cerr << mDoc.GetErrorStr1() << std::endl;
                    std::cerr << mDoc.GetErrorStr2() << std::endl;
                }
            }
            else
            {
                std::cerr << "Die Datei:" << filepath << "konnte nicht GELADEN werden" << std::endl;
            }
            
        }
        void print()
        {
            mDoc.Print();
        }
    
    private:
        XMLDocument mDoc;
        
    
    };
}