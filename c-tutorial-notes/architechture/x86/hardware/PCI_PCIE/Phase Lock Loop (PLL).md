ref: [https://www.youtube.com/watch?v=YVj9kWbDX_k](https://www.youtube.com/watch?v=YVj9kWbDX_k)

Something like a cruise control system in your car

## 3 main blocks
- ### PFD/ PD
	- **Phase Frequency Detector** or just **Phase Detector**
	- constantly monitors the frequency of the VCO and then compares it with incoming signal. 
- ### LF
	- Loop Filter
- ### VCO
	- Voltage controlled Oscillator

![[attachments/Pasted image 20250605230115.png]]
## An analogy
it has an incoming signal and an output signal.

we check if the incoming signal's frequency is the same as the frequency of the VCO. This is done majorly using PFD and the VCO.

Lets assume that you are driving a car and you can assume VCO as the motor. So lets say you had a cruise control system in your car and PFD detects your speed. It checks if your going too slow or fast and based on that it informs your VCO( or motors in the context) to speed up or to slow down.
It will keep telling this until we achieve the right speed. As you can see there is a loop between VCO and PFD.

Finally LF is something like a Low Pass Filter. It looks for **noise** by looking for high frequency signals. In basic terms it just stops all the high frequency data.

## Additional features
There are many complexities that can be added on to this to improve its performance like:
- output divider
- feedback divider
- or even different topologies for pfd and LF