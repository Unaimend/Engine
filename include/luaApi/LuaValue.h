
/************************************
 *Author:    Thomas Dost
 *Datum:     13.06.2016
 *Beschr.
 *Changelog:
            NEUSCHREIBEN
 *TODO:
 *************************************/

#ifndef LuaValue_h
#define LuaValue_h

#include <typeinfo>

namespace lua {
    
    
    class LuaValue
    {
    public:
        //Damit die Funktion zugriff aus das Type Enum erhaelt
        friend std::ostream& operator<<(std::ostream& out, const LuaValue& f);
        //Haellt alle moeglichen Typen um sind Variable zu identifizieren
        enum class Type : int
        {
            INTEGER,
            FLOAT,
            BOOL,
            STRING,
            COUNT
        };
        //Union um die Variale zu speichern
        typedef union
        {
            int32 mAsInteger;
            float mAsFloat;
            bool  mAsBool;
            char*  mAsString;
        } Value ;
        
        LuaValue() = default;
       
       
//        Variant(Type type, double value)
//        {
//            switch(type)
//            {
//                case 	Type::INTEGER:
//                    mType = Type::INTEGER;
//                    mValue.mAsInteger = value;
//                    break;
//                    
//                case	Type::DOUBLE:
//                    mType = Type::DOUBLE;
//                    mValue.mAsDouble = value;
//                    break;
//                case	Type::BOOL:
//                    mType = Type::BOOL;
//                    mValue.mAsBool = value;
//                    break;
//                case	Type::STRING_ID:
//                    mType = Type::STRING_ID;
//                    mValue.mAsStringId = value;
//                    break;
//                default:
//                    std::cout << "Unknown Type in eng::Variant::Variant" << std::endl;
//            }
//            
//        }
        
        
        
//        Variant(const std::string& value)
//        {
//            mType = Type::STRING_ID;
//            mValue.mAsStringId = eng::util::toHash(value);
//        }
        
        LuaValue(int32&& rhs)
        {
            this->mType = Type::INTEGER;
            this->mValue.mAsInteger = rhs;
        }
        
        LuaValue(float&& rhs)
        {
            this->mType = Type::FLOAT;
            this->mValue.mAsFloat = rhs;
        }
        
        LuaValue(bool&& rhs)
        {
            this->mType = Type::BOOL;
            this->mValue.mAsBool = rhs;
        }
        
        LuaValue(const char* rhs)
        {
            this->mType = Type::STRING;
            this->mValue.mAsString = strdup(rhs);
        }
        
        //Typ des Variants
        Type mType;
        //Wert des Variants
        Value mValue;
        
        LuaValue(const LuaValue& rhs)
        {
            mType = rhs.mType;
            mValue = rhs.mValue;
            return this;
            std::cerr <<"Gefaehrlich  durch char* im Uniun"<< std::endl;
        }
        
        LuaValue& operator=(const LuaValue& rhs)
        {
            mType = rhs.mType;
            mValue = rhs.mValue;
            return *this;
            //std::cout <<"VARAINT ASSIGN" << std::endl;
        }
        
        LuaValue& operator=(int32&& rhs)
        {
            this->mType = Type::INTEGER;
            this->mValue.mAsInteger = rhs;
            return *this;
        }

        LuaValue& operator=(float&& rhs)
        {
            this->mType = Type::FLOAT;
            this->mValue.mAsFloat = rhs;
            return *this;
        }
        LuaValue& operator=(bool&& rhs)
        {
            this->mType = Type::FLOAT;
            this->mValue.mAsBool = rhs;
            return *this;
        }
        LuaValue& operator=(const char* rhs)
        {
            this->mType = Type::STRING;
            this->mValue.mAsString = strdup(rhs);
            return *this;
        }
    };
    
    std::ostream& operator<<(std::ostream& out, const LuaValue& f)
    {
        switch(f.mType)
        {
            case 	LuaValue::Type::INTEGER:
                return out << f.mValue.mAsInteger ;
                break;
                
            case	LuaValue::Type::FLOAT:
                return out << f.mValue.mAsFloat ;
                break;
            case	LuaValue::Type::BOOL:
                return out << f.mValue.mAsBool ;
                break;
            case	LuaValue::Type::STRING:
                return out << f.mValue.mAsString ;
                break;
            default:				
                return out << "Unknown in eng::Variant::operator<<" ;
        }
        
    }
};



#endif /* LuaValue_h */
