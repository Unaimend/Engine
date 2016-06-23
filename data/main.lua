-- package.path = package.path .. ";/Users/thomasdost/Documents/dev/Engine/data/?.lua"
-- test = require("testfile")

hallo = 5
x = "HALLO"

function startUp( )
	io.write("Pfad zur Engine:", filepath, "\n")
	io.write("resX:", resX,"\n" )
	io.write("resY:", resY,"\n" )

	-- test.testFunction()	
end


function shutDown( )

	io.write("Lua shutdown")
end


function update( )
	
	 -- print(resX)
end

function render(  )
	-- print("Lua render")
end




