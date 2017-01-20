
/************************************
 *Author:    Thomas Dost
 *Datum:     13.06.2016
 *Beschr.
 *Changelog:
            NEUSCHREIBEN
 *TODO:
            Anschauen fuer Typen bestimmung:
                https://www.youtube.com/watch?v=qHgM5UdzPQU
 *************************************/

#ifndef LuaValue_h
#define LuaValue_h


#include <memory>
#include "../EngineTypes.h"
#include "../lua/lua.hpp"
namespace lua
{
    
    
    class LuaRef
    {
    public:
        //Damit die Funktion zugriff aus das Type Enum erhaelt
        friend std::ostream& operator<<(std::ostream& out, const LuaRef& f);
        //Haellt alle moeglichen Typen um sind Variable zu identifizieren
        enum class Type : int
        {
            INTEGER,
            FLOAT,
            BOOL,
            STRING,
            COUNT
        };
        Type mType;
        int32 ref;
        std::string identifier;
        lua_State* mState;
        
        LuaRef(int32 key, const std::string& ident, lua_State* state)
        : ref(key), identifier(ident), mState(state)
        {
            
        }
        
        LuaRef& operator=(int32 value)
        {
            mType = Type::INTEGER;
            lua_pushinteger(mState, value);
            lua_setglobal(mState, identifier.c_str());
        }
        
        LuaRef& operator=(float value)
        {
            mType = Type::FLOAT;
            lua_pushnumber(mState, value);
            lua_setglobal(mState, identifier.c_str());
        }
        LuaRef& operator=(const char* value)
        {
            mType = Type::STRING;
            lua_pushstring(mState, value);
            lua_setglobal(mState, identifier.c_str());
        }
        
        
        
        explicit operator int32() const
        {
            
            lua_getglobal(mState, identifier.c_str());
             lua_tointeger(mState, -1);
            
           
        }
        
        explicit operator float() const
        {
            lua_getglobal(mState, identifier.c_str());
            lua_tonumber(mState, -1);
            
            
        }
        explicit operator const char*() const
        {
             lua_getglobal(mState, identifier.c_str());
              auto temp = std::make_shared<const char*>(strdup(lua_tostring(mState, -1)));
              return *temp;
        }
    };
//    
//    std::ostream& operator<<(std::ostream& out, const LuaRef& f)
//    {
//        lua_getglobal(f.mState, f.identifier.c_str());
//        if(lua_isinteger(f.mState, -1))
//        {
//            out << lua_tointeger(f.mState, -1);
//            return out;
//        }
//        else if(lua_isnumber(f.mState, -1))
//        {
//            out << lua_tonumber(f.mState, -1);
//            return out;
//        }
//        else if(lua_isstring(f.mState, -1))
//        {
//            out << lua_tostring(f.mState, -1);
//            return out;
//        }
//        
//    }

}




#endif /* LuaValue_h */
