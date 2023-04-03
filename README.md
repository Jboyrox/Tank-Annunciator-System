# Tank-Annunciator-System
A maple syrup factory in Vermont has a problem. They have a holding tank that stores their
product that overflows from time-to-time. When this happens, an operator in a remote monitoring room
is sent to clean up the mess. As part of the Computer Systems Archtitecure project I  implemented an “Annunciator” system to
monitor the holding tank and report its status to the operator in the monitoring room. The system has
two objectives, to notify the operator when the tank is near full (so they can manually turn off the fill
valve), then to notify the operator when the tank has over flown (so they can be sent to clean it up).
![Screen Shot 2023-04-03 at 1 16 12 AM](https://user-images.githubusercontent.com/45749588/229417583-698f1700-5d93-493f-ab21-7e5bf6e2364c.png)
There are 4 input to the system. There are two level switches in the tank, full level alarm (FLA)
and overflow level alarm (OLA). On the Annunciator box in the control room, there are two momentary
push buttons, acknowledge (ACK) and test (TST).
On the Annunciator box, there are 3 outputs from the system, a green ok indicator, a yellow full
indicator and a red overflow indicator. The system has 6 states as shown in the figure below.
![Screen Shot 2023-04-03 at 1 19 15 AM](https://user-images.githubusercontent.com/45749588/229417986-1b8d9467-f237-4a46-b47b-500f5e4b55f2.png)
Procedure</br>
1. Select the GPIO’s to be used for the inputs and outputs. Use recommended pins. Modify
setupGPIO.S to enable selected pins for input or output. In setupGPIO.S delete
sw t1, GPIO_OUTPUT_XOR(t0)</br>
2. On the solderless breadboard, wire 2 pushbuttons and 2 of the DIP stitches to the 4 GPIO’s
selected as the inputs in a pull-up resistor configuration with one side of the switch to theGPIO
and the other side to ground.</br>
3. On the solderless breadboard, wire the 3 outputs to the anodes of the red yellow and green
LED’s. Tie the cathodes of the LED to ground though 200 ohm resistors.</br>
4. Modify code of checkBot.S to accept mask for a pin (ex. int checkBot(int PIN)). The parameter
will be passed onto the register a0. Before proceeding any further, test this newfunctionality.
5. In setLED.S, change the first line after ledOn: to or t1, t1, a0.</br>
6. Add code to main.c to handle the states of the Annunciator state machine. When returning value</br>
from checkBot(int PIN) do not forget to invert it, since the pullup function is on, pins are in
active low state which is not intuitive. (ex TST = !checkBot(PIN_2);)</br>
The video
