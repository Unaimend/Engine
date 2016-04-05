/************************************
 *Author:    Thomas Dost
 *Datum:     04.04.2015
 *Beschr.    Wrapper um tinyxml2 um einfachere Bedienung zu ermoeglichen
 *Changelog:
            Klasse ist nun Funktionsfaehig
            XmlElement hinzugefuegt
            Conversion Konstruktor fuer XmlElement hinzugefuegt
            Funktion aus tinyxml2 zu eigener Klasse hinzugefuegt
            --operator und ++ operator hinzugefuegt
            getText hinzugefuegt
            isNull hinzugefuegt
 *TODO:
            Warum funktioniert der Parse Check nicht?
            XmlNode zugriff returnt bool oder etaws passenderes aka KEINE exception
            Methoden der tinyxml XMLElement Klasse implementieren
                http://www.grinninglizard.com/tinyxml2docs/classtinyxml2_1_1_x_m_l_element.html
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
            
            if(mDoc.LoadFile(filepath.c_str()) == XML_NO_ERROR)
            {
//                if(mDoc.Parse(filepath.c_str()) == XML_NO_ERROR)
//                {
//                    
//                }
//                else
//                {
//                    std::cerr << "Die Datei:" << filepath << " konnte nicht GEPARSED werden" << std::endl;
//                    std::cerr << mDoc.GetErrorStr1() << std::endl;
//                    std::cerr << mDoc.GetErrorStr2() << std::endl;
//                }
            }
            else
            {
                std::cerr << "Die Datei:" << filepath << " konnte nicht GELADEN werden" << std::endl;
            }
            
        }
        void print()
        {
            mDoc.Print();
        }
        
    public:
        XMLDocument mDoc;
        
    
    };
    
    class XmlElement
    {
    public:
        XmlElement(XMLElement& rhs)
        {
            mNode = &rhs;
        }
        
        XmlElement(XMLElement* rhs)
        {
            mNode = rhs;
        }
        
        std::string getText()
        {
            if(mNode != nullptr)
            {
                return mNode->GetText();
            }
        }
        
        XmlElement& operator++()
        {
            mNode = mNode->NextSiblingElement();
            return *this;
        }
        
        XmlElement& operator--()
        {
            mNode = mNode->PreviousSiblingElement();
            return *this;
        }
        
        bool isNull()
        {
            if(mNode == nullptr)
            {
                return true;
            }
            return false;
        }
    public:
        XMLElement* mNode;
       
    };
}