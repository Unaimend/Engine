
/************************************
 *Author:    Thomas Dost
 *Datum:     03.06.2016
 *Beschr.
 *Changelog:
            NEUSCHREIBEN
 *TODO:
 *************************************/

#ifndef LuaValue_h
#define LuaValue_h

namespace lua {
    
    
    class Variant
    {
    public:
        //Damit die Funktion zugriff aus das Type Enum erhaelt
        friend std::ostream& operator<<(std::ostream& out, const Variant& f);
        //Haellt alle moeglichen Typen um sind Variable zu identifizieren
        enum class Type : int
        {
            INTEGER,
            DOUBLE,
            BOOL,
            STRING_ID,
            COUNT
        };
        //Union um die Variale zu speichern
        typedef union
        {
            int32 mAsInteger;
            long double mAsDouble;
            bool  mAsBool;
            eng::hash   mAsStringId;
        } Value ;
        
        Variant() = default;
        
        Variant(Type type, double value)
        {
            switch(type)
            {
                case 	Type::INTEGER:
                    mType = Type::INTEGER;
                    mValue.mAsInteger = value;
                    break;
                    
                case	Type::DOUBLE:
                    mType = Type::DOUBLE;
                    mValue.mAsDouble = value;
                    break;
                case	Type::BOOL:
                    mType = Type::BOOL;
                    mValue.mAsBool = value;
                    break;
                case	Type::STRING_ID:
                    mType = Type::STRING_ID;
                    mValue.mAsStringId = value;
                    break;
                default:
                    std::cout << "Unknown Type in eng::Variant::Variant" << std::endl;
            }
            
        }
        
        Variant(const std::string& value)
        {
            mType = Type::STRING_ID;
            mValue.mAsStringId = eng::util::toHash(value);
        }
        
        
        inline void initAsInt(int32 value)
        {
            mType = Type::INTEGER;
            mValue.mAsInteger = value;
        }
        
        
        inline void initAsDouble(double value)
        {
            mType = Type::DOUBLE;
            mValue.mAsDouble = value;
        }
        
        
        inline void initAsBool(bool value)
        {
            mType = Type::BOOL;
            mValue.mAsBool = value;
        }
        
        
        inline void initAsHash(eng::hash value)
        {
            mType = Type::STRING_ID;
            mValue.mAsStringId = value;
        }
        
        //Typ des Variants
        Type mType;
        //Wert des Variants
        Value mValue;
        
        Variant(const Variant& rhs)
        {
            mType = rhs.mType;
            mValue = rhs.mValue;
            //std::cout <<"VARAINT COPPY" << std::endl;
        }
        
        Variant& operator=(const Variant& rhs)
        {
            mType = rhs.mType;
            mValue = rhs.mValue;
            //std::cout <<"VARAINT ASSIGN" << std::endl;
        }
        
        Variant operator=(int&& rhs)
        {
            return Variant(Type::INTEGER, rhs);
            //std::cout <<"VARAINT ASSIGN" << std::endl;
        }
        
        Variant operator=(float&& rhs)
        {
            return Variant(Type::DOUBLE, rhs);
            //std::cout <<"VARAINT ASSIGN" << std::endl;
        }
        
        Variant operator=(double&& rhs)
        {
            return Variant(Type::DOUBLE, rhs);
            //std::cout <<"VARAINT ASSIGN" << std::endl;
        }
    };
    
    std::ostream& operator<<(std::ostream& out, const Variant& f)
    {
        switch(f.mType)
        {
            case 	Variant::Type::INTEGER:
                return out << f.mValue.mAsInteger ;
                break;
                
            case	Variant::Type::DOUBLE:
                return out << f.mValue.mAsDouble ;
                break;
            case	Variant::Type::BOOL:
                return out << f.mValue.mAsBool ;
                break;
            case	Variant::Type::STRING_ID:
                return out << f.mValue.mAsStringId ;
                break;
            default:				
                return out << "Unknown in eng::Variant::operator<<" ;
        }
        
    }
};



#endif /* LuaValue_h */
