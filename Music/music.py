import numpy as np
import sounddevice as sd

duration = 1  # длительность сигнала в секундах
amplitude = 0.3  # амплитуда  (в пределах: +-1.0)
frequency = 600  # частота сигнала в [Гц]
# т.к. невозможно программно организовать аналоговый сигнал, необходимо обозначить
fs = 80000 # 80 тыс. временных отсчетов в 1 секунду количество временных отчетов, т.е. частоту дискретизации (об этом чуть позже)

timeSamples = np.arange(np.ceil(duration * fs)) / fs

signal = amplitude * np.sin(2 * np.pi * frequency * timeSamples)
F1 = amplitude * np.sin(2 * np.pi * 349.23 * timeSamples)
E = amplitude * np.sin(2 * np.pi * 329.63 * timeSamples)
D = amplitude * np.sin(2 * np.pi * 293.66 * timeSamples)
C = amplitude * np.sin(2 * np.pi * 261.63 * timeSamples)
B = amplitude * np.sin(2 * np.pi * 246.96 * timeSamples)
A = amplitude * np.sin(2 * np.pi * 220.00 * timeSamples)
Q = amplitude * np.sin(1 * np.pi * 1 * timeSamples)

s1 = np.concatenate((F1, F1, E, E), axis=0)
s2 = np.concatenate((D, D, D, E), axis=0)
s3 = np.concatenate((D, Q, D, Q), axis=0)
s4 = np.concatenate((C, C, B, B), axis=0)
s5 = np.concatenate((A, A, A, B), axis=0)
s6 = np.concatenate((A, Q, A, Q), axis=0)

#1
sd.play(s1, fs)

#2
sd.play(s2, fs)

#1
sd.play(s1, fs)

#3
sd.play(s3, fs)

#4
sd.play(s4, fs)

#5
sd.play(s5, fs)

#4
sd.play(s4, fs)

#6
sd.play(s6, fs)

print("end")
