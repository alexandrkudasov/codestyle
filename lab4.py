import numpy as np

WTxPower = 23
UTxPower = 20
WAntGain = 6
UAntGain = 0
WNoiseFig = 3
UNoiseFig = 7
WsinR = -1
UsinR = -1
height = 5

BP= 6
im = 3
fq = 5
fq2= 2.4

thenois = -174 + 10 * np.log10(20000000)
RxSense = thenois+ WNoiseFig + UsinR
Power = WTxPower+ WAntGain
MAPL = Power - BP - im - RxSense - 1
d = pow(10, (MAPL - 26 * np.log10(fq) - 22.7) / 36.7)
Dist = np.sqrt(d * d - height * height)
print("wifi 5 Ghz = ", Dist)

thenois = -174 + 10 * np.log10(20000000)
RxSense = thenois + UNoiseFig + WsinR
Power = UTxPower+ UAntGain
MAPL = Power - BP - im - RxSense - 1
d = pow(10, (MAPL - 26 * np.log10(fq) - 22.7) / 36.7)
D2 = np.sqrt(d * d - height * height)
print("UA 5 Ghz = ", D2)


