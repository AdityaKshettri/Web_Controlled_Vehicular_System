# Web-Controlled-Vehicle
Vehicular system which will be controlled by a web app designed using Node.js. The directions for controlling the vehicle (forward, backward, left, right, stop) will be selected by clicking on our Web app screen which is deployed using Node.js on Raspberry Pi.

# Hardware Requirements :

Raspberry Pi (To Host the Node.js web app)

Arduino Uno (To receive serially from Raspberry Pi)

Motor driver L293DNE (To move vehicle in given directions)

BO Motor - 2

Wheels - 2

Bread Board - 1

Battery 9V (To power the Motor driver)

Voltage Regulator 7805

Connecting Wires

# Software Requirements :

Arduino IDE (Integrated Development Environment)

Node.Js

HTML (For Front End)

Putty (For SSH, remote connection to Raspberry Pi)

Windows Remote Desktop Connection (For Accessing the GUI of Raspberry Pi)

# Methodology :

Raspberry Pi is Serially Connected to Arduino Uno and Arduino Uno’s Output pins are connected to Motor Driver and motors of the car are connected to Motor Driver.

The Node.js Application is hosted on Raspberry Pi

The Interface of Web App has five buttons i.e. Forward, Backward, Left, Right, Stop.

Each button has a control associated with it.

When user clicks on a certain button respective control is called and that control send a certain value to Arduino Uno through Serial Communication

Arduino Uno Reads the serial Data and Checks the If-else loop

Arduino outputs are sent to the 4 output pins Q1, Q2, Q3, Q4 that is, pin 9, 10, 11, 12 of Arduino.

These digital values are sent to the Motor Driver L293D on pins 2, 7, 10 and 15 respectively.
