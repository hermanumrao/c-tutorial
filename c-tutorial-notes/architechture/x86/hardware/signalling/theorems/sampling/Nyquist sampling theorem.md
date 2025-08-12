The Nyquist theorem states that an analog signal must be sampled at least twice as fast as the bandwidth of the signal to accurately reconstruct the waveform; otherwise, the high-frequency content creates an alias at a frequency inside the spectrum of interest (passband). An alias is a false lower frequency component that appears in sampled data acquired at too low a sampling rate. The following figure shows a 5 MHz sine wave digitized by a 6 MS/s analog-to-digital converter (ADC). In this figure, the dotted line represents the sine wave being digitized, while the solid line represents the aliased signal recorded by the ADC at that sample rate.

![waveform for nyquist theorem](attachments/Pasted%20image%2020250625184133.png)
The 5 MHz frequency aliases back in the passband, falsely appearing as a 1 MHz sine wave.


