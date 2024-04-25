clear all
clc

delete(instrfind({'Port'},{'COM13'}));
% Define serial port and baud rate
serialPort = 'COM13';  % Modify this to match your serial port
baudRate = 115200;     % Modify this to match your baud rate

% Create serial port object
s = serial(serialPort, 'BaudRate', baudRate);

% Create a figure for the plot
figure;
hold on;  % Keep the existing plot while adding new data
xlabel('Time');  % X-axis label
ylabel('Value'); % Y-axis label
title('Real-time Data Plot'); % Plot title
grid on;  % Show grid

try
    % Open the serial port
    fopen(s);
    disp('Serial port opened');
    
    % Set up plot
    hPlot = plot(nan, nan, 'b.-');  % Initialize empty plot
    axis([0 100 0 100]);  % Adjust axis limits as needed
    
    % Read data and update plot continuously
    while true
        % Read a line of data from serial port
        lineData = fgetl(s);
        
        % Convert the received string to a floating-point number
        receivedValue = str2double(lineData);
        
        % Update plot with new data point
        xData = get(hPlot, 'XData');
        yData = get(hPlot, 'YData');
        xData(end+1) = numel(yData) + 1;  % Add new x-coordinate
        yData(end+1) = receivedValue;      % Add new y-coordinate
        set(hPlot, 'XData', xData, 'YData', yData);  % Update plot
        
        % Adjust axis limits to keep data in view
        if numel(yData) > 100
            axis([numel(yData)-100, numel(yData), min(yData), max(yData)]);
        end
        
        drawnow;  % Update the plot window
        
        % Display the received value
        disp(['Received value: ' num2str(receivedValue)]);
    end
    
catch e
    % Display error message if an exception occurs
    disp(['Error: ' e.message]);
end

% Close the serial port
fclose(s);
delete(s);
clear s;
disp('Serial port closed');