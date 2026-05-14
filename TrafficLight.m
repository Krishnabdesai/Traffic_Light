% Matlab Code for TrafficLight.m

classdef TrafficLight < handle
    properties (Access = private)
        states = ["Red", "Green", "Yellow"];
        currState = 1;
    end
    methods
        function obj = TrafficLight()
            obj.currState = 1;
        end
        function state = GetState(obj)
            state = obj.states(obj.currState);
        end
        function Advance(obj)
            obj.currState = mod(obj.currState, 3) + 1;
        end
    end
end
