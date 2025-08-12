## Basic working

![A signal transmitted differentially](attachments/Pasted%20image%2020250608191605.png)

![Differential amplifiers respond to differential signals by amplifying the difference between the voltages on the amplifier’s two inputs.](attachments/Pasted%20image%2020250608191618.png)

Basically we have two wires, in one wire we send the actual signal and in the other wire, we send a negated signal inverse of the signal.

> In differential signals, determining the logic state is more straightforward. If the non-inverted signal's voltage is higher than the inverted signal's voltage, you have logic high. If the non-inverted voltage is lower than the inverted voltage, you have logic low. And the transition between the two states is the point at which the non-inverted and inverted signals intersect—i.e., the crossover point.

## Advantages
- **Doubled signal** voltage between the differential pair (compared to a single-ended signal of the same nominal level, giving 6 dB extra headroom
- **Ideally no return current** Unlike the normal single ended signaling, we don't need to use the ground voltage as an reference to measure voltage and then decide on low signal or high signal. So return currents are no longer an issue.
- **Resistance to Incoming EMI and Crosstalk** well now there are two wire carrying the same data and both are next to each other, so if there is an external disturbance which causes, EMI fluctuations it will occur on bot the wires hence it will be negated out
  ![](attachments/Pasted%20image%2020250608212404.png)

		now if you take note, in the above 2 signals, if we subtract them, we see that the noise nearly dissapears
- **Lower-Voltage Operation** Single-ended signals must maintain a relatively high voltage to ensure adequate signal-to-noise ratio (SNR). Common single-ended interface voltages are 3.3 V and 5 V. Because of their improved resistance to noise, differential signals can use lower voltages and still maintain adequate SNR.