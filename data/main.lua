

local mt = {}
-- Namepsaces lernen
 Rectangle = {}


function Rectangle.new(rrectangle)
	if type(rrectangle.xPos) ~= "number" then
        error("no xPos")
    elseif type(rrectangle.yPos) ~= "number" then
     	error("no yPos")
    end
    createRectangle(rrectangle.xPos, rrectangle.yPos)
	local rectangle = {}
	setmetatable(rectangle, mt)
end
-- -- Rectangle Konstuktor fuer benannte Parameter
-- function Rectangle.new(rrectangle)
-- 	if type(rrectangle.xPos) ~= "number" then
--         error("no xPos")
--     elseif type(rrectangle.yPos) ~= "number" then
--      	error("no yPos")
--     elseif type(rrectangle.width) ~= "number" then
--        	error("no width")
--     elseif type(rrectangle.height) ~= "number" then
--         error("no height")
--      end

-- 	local rectangle = {}
-- 	setmetatable(rectangle, mt)

-- 	rectangle.xPos = rrectangle.xPos;
-- 	rectangle.yPos = rrectangle.yPos;
-- 	rectangle.width = rrectangle.width;
-- 	rectangle.height = rrectangle.height;
-- 	return rectangle
-- end

function startUp( )
	r4 = Rectangle.new{xPos=5,yPos=10,width=22,height=19}
	r5 = Rectangle.new{xPos=20,yPos=100}
	createRectangle(50,50)
	print("Hallo aus Lua")
end


function shutDown( )
	print("Tchuess aus Lua")
end


function update( )
	 -- print("Lua update")
end

function render(  )
	-- print("Lua render")
end



-- print(r4.width)


