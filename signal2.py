
import sounddevice as sd
import numpy as np
import matplotlib
import matplotlib.pyplot as plt
duration1=0.7
duration = 0.3  
amplitude = 0.5  
frequency = 0  

fs = 80000 


timeSamples = np.arange(np.ceil(duration * fs)) / fs
timeSamples
timeSamples1 = np.arange(np.ceil(duration1 * fs)) / fs
timeSamples1

signal2 = amplitude * np.sin(2 * np.pi * 1318.500 * timeSamples1)
signal02 = amplitude * np.sin(2 * np.pi * 1318.500 * timeSamples)
signal3 = amplitude * np.sin(2 * np.pi * 1558 * timeSamples)
signal4 = amplitude * np.sin(2 * np.pi * 1174.700 * timeSamples)
signal5 = amplitude * np.sin(2 * np.pi * 1046.500 * timeSamples1)
signal6 = amplitude * np.sin(2 * np.pi * 987.770 * timeSamples1)


for i  in range(0, 2):
    sd.play(signal2, fs, None, 1)
    sd.play(signal02, fs, None, 1)
    sd.play(signal3, fs, None, 1)
    sd.play(signal02, fs, None, 1)
    sd.play(signal4, fs, None, 1)
    sd.play(signal5, fs, None, 1)
    sd.play(signal6, fs, None, 1)





