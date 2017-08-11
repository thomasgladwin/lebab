# lebab
Send markers via USB and an Arduino for psychophysiological experiments
# Hardware
An Arduino or clone; I used an Elegoo Nano. This included the USB cable and header pins. Breadboard and jumper wires for prototyping, with a LED and resistor for testing. Lab-specific cables.
# Software for the Arduino
The Processing code to be uploaded to the Arduino is in lebab.ino. What this does is check whether a character representing a digit from ‘0’ to ‘7’ is sent via USB to the Arduino. If so, the corresponding digital pin is set to HIGH for 5 ms. The characters ‘1’ through ‘8’ are mapped to digital pins 12 through 5. Note that if you take an Arduino Nano and attach it to the top of a breadboad via header pins, its digital pins 12 through 5 are connected to lines 1 (the top line) down to 8.

This allows you to control pins from task presentation software such as EPrime or Presentation (see below).

The Arduino’s ground and the digital pins can be attached to further cables as desired, such as a BNC cable or DB25 parallel port.

# Task presentation software
You can get the port information needed to define the port (like Baud rate) from Windows' device manager. 

In Presentation, go to Settings and add the serial port with that information. Then in PCL code, simply send a string with a character ‘1’ through ‘8’ to that port.

In EPrime, double-click the Experiment object and add a Serial Port with the correct information. I had to change the COM port number in device manager since EPrime didn't go up to the automatically assigned COM port. Use the Serial class to send characters as in Presentation.
