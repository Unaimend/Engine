

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


