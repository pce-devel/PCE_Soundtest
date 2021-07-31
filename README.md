# PCE_Soundtest

The PC Engine is a video game machine which was released in 1987 in Japan.
Over the lifespan of the machine, there were several versions of the hardware,
including two revisions of the CPU (which also contains the PSG sound generator).
The two revisions of the CPU are:
- Hu6280, included in the original white PC Engine, and most other iterations of
  the hardware throughout its lifetime
- Hu6280A, included with the SuperGrafx and apparently some CoreGrafx machines.

One of the differences between these two chips was the sound - and the principle
difference in the sound that I'm aware of, was the presence or absence of a "pop"
sound on occasion.

This program generates a constant (although somewhat annoying) tone on the output,
and allows the user to turn on/off the following attributes in order to determine
the nature of the 'pop' sound, and when it is generated:
- Button I: set channel balance to 0/0 (15/15 when released)
- Button II: set global balance to 0/0 (15/15 when released)
- 'Down' button: set global volume level to 0 (31 when released)
- 'Select' button: turn channel off (on when released)

The output can be captured on an oscilloscope or in an audio capture program such as Audacity.

Outputs were found to be as follows:

### Hu6280:
"pop" sound occurs, and shows as though the waveform is entirely above the center line
initially - a DC offset (but later drifting back toward center).  This has the effect of the
initial waveform's impulse being double what it should be, but the waveform peak-to-peak is not.

![Hu6280 waveform](image/Hu6280.png)


### Hu6280A: no "pop", no DC offset.

![Hu628i0A waveform](image/Hu6280A.png)


Notes:
------
 - compile with the flags '-t -v -v -ADEPRECATED=1' if using version v3.99 or greater of the HuC compiler


Use this information and software at your own risk.
