

local mt = {}
-- Namepsaces lernen
 Rectangle = {}


-- Rectangle Konstuktor fuer benannte Parameter
function Rectangle.new(rrectangle)
	if type(rrectangle.xPos) ~= "number" then
        error("no xPos")
    elseif type(rrectangle.yPos) ~= "number" then
     	error("no yPos")
    elseif type(rrectangle.width) ~= "number" then
       	error("no width")
    elseif type(rrectangle.height) ~= "number" then
        error("no height")
     end

	local rectangle = {}
	setmetatable(rectangle, mt)

	rectangle.xPos = rrectangle.xPos;
	rectangle.yPos = rrectangle.yPos;
	rectangle.width = rrectangle.width;
	rectangle.height = rrectangle.height;
	return rectangle
end
function update( )
	 -- print("Lua update")
end

function render(  )
	-- print("Lua update")
end


r4 = Rectangle.new{xPos=5,yPos=10,width=22,height=19}
-- print(r4.width)

hi(50,200)
hi(50,250)
hi(50,230)
