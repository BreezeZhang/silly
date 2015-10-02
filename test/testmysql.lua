--[[
local socket = require("socket")
local core = require("core")
local spacker = require("spacker")

--connect
local CONN = {}

function CONN.accept(fd)
        print("accept, because the socket is initactive, so it never be called")
end
function CONN.close(fd)
        print("closexx")
end

function CONN.data(fd, data)
        print("xxxx")
        print("data", #data, data)
        socket.close(fd)
end

core.start(function()
        local fd = socket.connect("127.0.0.1", 3306, CONN, spacker:create("raw"))
        print("conn", fd)
end)

]]--

local core = require("core")
local mysql = require("mysql")

local function dprint(tbl)
        for _, v in pairs(tbl) do
                if type(v) == "table" then
                        dprint(v)
                else
                        print(v)
                end
        end
end

core.start(function()
        local db = mysql:create {
                        host = "127.0.0.1",
                        port = 3306,
                        user = "root",
                        password = ""
                }
        print ("mysql connect:", db:connect())

        for lines in io.stdin:lines() do
                local t = db:query(lines)
                dprint(t)
        end
end)