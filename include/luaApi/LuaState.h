#pragma once
//***************************************************************
//Author: Thomas Dost
//Version: 1.0.0
//Changelog	: Erstellt
//			:
//TODO:
//		Funktor durch Lambada austauschen
//***************************************************************

#include <memory>
#include "LuaValue.h"
extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}
#define FAST1

namespace lua 
{
	class LuaState
	{
	public:
		LuaState(const std::string& filepath, int stacksize = 30)  :
			mState(luaL_newstate()), mFilePath(filepath)
		{
			openLibs();
            loadFile();
            runFile();
			

		}
		~LuaState()
		{

		}
		void openLibs()
		{
			luaopen_base(mState);             /* opens the basic library */
     		luaopen_table(mState);            /* opens the table library */
      		luaopen_io(mState);               /* opens the I/O library */
     		luaopen_string(mState);           /* opens the string lib. */
      		luaopen_math(mState);             /* opens the math lib. */
			
		}
		void runFile(const filepath& filepath)
		{
  		 luaL_dofile(mState, filepath.c_str());

		}
		void runFile()
		{
  		 if(luaL_dofile(mState, mFilePath.c_str()) != 0)
         {
             std::cerr << "Fehler beim Ausfuehren der Lua Datei " << mFilePath << std::endl;
         }

		}

		void push(int var)
		{
			lua_pushinteger(mState, var);
		}
		void push(float var)
		{
			lua_pushnumber(mState, var);
		}
		void push(bool var)
		{
			lua_pushboolean(mState, var);
		}
		void push(const char* var)
		{
			lua_pushstring(mState, var);
		}
		void push(std::string var)
		{
			lua_pushstring(mState, var.c_str());
		}

		template <typename T, typename... Ts>
		void push(const T value, const Ts... values) {
    	push(value);
    	push(values...);
}


#ifdef FAST
#else
		template<typename T, typename... Rest>
		inline void addParams( const T& obj, const Rest&... rest)
		{	
			pushGlobal(obj);
			++mFuncParaCount;
			addParams(rest...);
		}
		void callFunction(int returncount = 1)
		{
            if(!lua_isfunction(this->mState,-1))
            {
                std::cerr << "Auf dem Stack befindet sich keine Funktion" << std::endl;
            }
			lua_pcall(mState, mFuncParaCount, returncount, 0);
			mFuncParaCount = 0;
		}
#endif
        
        
//        unsigned int operator [](const std::string& varname) const
//        {
//            lua_pushlightuserdata(L, (void *)&Key);  /* push address */
//            lua_pushnumber(L, myNumber);  /* push value */
//            /* registry[&Key] = myNumber */
//            lua_settable(L, LUA_REGISTRYINDEX);
//            
//            return
//        
//        }
        
        //GETTER
        lua::Variant operator [](std::string&& varname)
        {
            lua_getglobal(this->mState, varname.c_str());
            if (lua_isinteger(mState, -1))
            {
                return lua::Variant(lua::Variant::Type::INTEGER,lua_tointeger(mState, -1) );
            }
            else if (lua_isnumber(mState, -1))
            {
                return lua::Variant(lua::Variant::Type::DOUBLE,lua_tonumber(mState, -1) );
            }
        }
        
        lua::Variant & operator [](const std::string& varname)
        {
            lua_getglobal(this->mState, varname.c_str());
            
        }
        
        
		
		int getInt(int stackpos)
		{
			return lua_tointeger(mState, stackpos);
		}
		template<class T>
		T getSingleValue()
		{
			if (lua_isinteger(mState, -1))
			{
				return lua_tointeger(mState, -1);
			}
			else if (lua_isnumber(mState, -1))
			{
				return lua_tonumber(mState, -1);

			}
			else
			{
				return lua_tonumber(mState, -1);
				std::cout << ("getSingleReturn : lua, richtig implementieren\n");
			}

		}
        
        void error (const char *fmt, ...) {
            va_list argp;
            va_start(argp, fmt);
            vfprintf(stderr, fmt, argp);
            va_end(argp);
            lua_close(this->mState);
            exit(EXIT_FAILURE);
        }

		void stackDump() {
			int i;
			int top = lua_gettop(this->mState);
			for (i = 1; i <= top; i++) {  /* repeat for each level */
				int t = lua_type(this->mState, i);
				switch (t) {

				case LUA_TSTRING:  /* strings */
					printf("`%s'", lua_tostring(this->mState, i));
					break;

				case LUA_TBOOLEAN:  /* booleans */
					printf(lua_toboolean(this->mState, i) ? "true" : "false");
					break;

				case LUA_TNUMBER:  /* numbers */
					printf("%g", lua_tonumber(this->mState, i));
					break;

				default:  /* other values */
					printf("%s", lua_typename(this->mState, t));
					break;

				}
				printf("  ");  /* put a separator */
			}
			printf("\n");  /* end the listing */
		}

	public:
		lua_State* mState;
		std::string mFilePath;
		int mStatus;
		int mFuncParaCount = 0;
	private:
		void loadFile()
		{
			
			mStatus = luaL_loadfile(mState, mFilePath.c_str());
			if (mStatus) {
				/* If something went wrong, error message is at the top of */
				/* the stack */
				fprintf(stderr, "Couldn't load file: %s\n", lua_tostring(mState, -1));
				
			}
		}
	};
}

//inline void DBG()
//{
//	std::cout << std::endl;
//}
//
//template<typename T, typename... Rest>
//inline void DBG(const T& obj, const Rest&... rest)
//{
//	std::cout << obj << " ";
//	DBG(rest...);
//}
