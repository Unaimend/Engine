#pragma once
//***************************************************************
//Author: Thomas Dost
//Version: 1.0.0
//Changelog	: Erstellt
//			25.01.2016
//			T read() hinzugefuegt
//TODO:
//		Funktor durch Lambada austauschen
//***************************************************************

#include <memory>
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
  		 luaL_dofile(mState, mFilePath.c_str());

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
		void push(const T value, const Ts... values) 
		{
    	push(value);
    	push(values...);
		}

		template<typename T>
		void setGlobal(const std::string& name,const T value)
		{
			push(value);
			lua_setglobal(mState, name.c_str());
		}


		template<typename T>
		T getGlobal(const std::string& name)
		{
			lua_getglobal(mState ,name.c_str());
			read<T>(lua_gettop(mState));
		}


		
		template<typename T>
		T read(const int index) const
		{
			std::cout << "Template Specialization for this Type doesnt exist." << std::endl;
		}
		
		/*
		int& LuaState::operator[] (const std::string& ident)
		{
		    
		}
		*/
		/*
		int& LuaState::operator[] (const std::string&& ident)
		{
			std::cout << "RVALUE STATE" << std::endl;
		    return m_anList[nIndex];
		}*/

#ifdef FAST
		
		void callFunction(int paramcount, int returncount)
		{
			lua_pcall(mState, paramcount, returncount, 0);
		}
#else 
		void callFunction(int returncount = 1)
		{
			lua_pcall(mState, mFuncParaCount, returncount, 0);
			mFuncParaCount = 0;
		}
#endif
		

		void stackDump(lua::LuaState& state ) {
			int i;
			int top = lua_gettop(state.mState);
			for (i = 1; i <= top; i++) {  /* repeat for each level */
				int t = lua_type(state.mState, i);
				switch (t) {

				case LUA_TSTRING:  /* strings */
					printf("`%s'", lua_tostring(state.mState, i));
					break;

				case LUA_TBOOLEAN:  /* booleans */
					printf(lua_toboolean(state.mState, i) ? "true" : "false");
					break;

				case LUA_TNUMBER:  /* numbers */
					printf("%g", lua_tonumber(state.mState, i));
					break;

				default:  /* other values */
					printf("%s", lua_typename(state.mState, t));
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

	template<>
	float lua::LuaState::read(const int index) const
	{
		lua_tonumber(mState, index);
	}

	template<>
	int32 lua::LuaState::read(const int index) const
	{
		lua_tointeger(mState, index);
	}

	template<>
	const char* lua::LuaState::read(const int index) const
	{
		lua_tostring(mState, index);
	}
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
