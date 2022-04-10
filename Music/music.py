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

#1
sd.play(F1, fs) # функция воспроизведения массива signal, с частотой дискретизации fs (частота нужна для ЦАП)
sd.sleep(600)

sd.play(F1, fs)
sd.sleep(600)

sd.play(E, fs)
sd.sleep(600)

sd.play(E, fs)
sd.sleep(600)

#2
sd.play(D, fs)
sd.sleep(600)

sd.play(D, fs)
sd.sleep(600)

sd.play(D, fs)
sd.sleep(600)

sd.play(E, fs)
sd.sleep(600)

#1
sd.play(F1, fs) # функция воспроизведения массива signal, с частотой дискретизации fs (частота нужна для ЦАП)
sd.sleep(600)

sd.play(F1, fs)
sd.sleep(600)

sd.play(E, fs)
sd.sleep(600)

sd.play(E, fs)
sd.sleep(600)

#3
sd.play(D, fs)
sd.sleep(1000)

sd.play(D, fs)
sd.sleep(1000)

#4
sd.play(C, fs)
sd.sleep(600)

sd.play(C, fs)
sd.sleep(600)

sd.play(B, fs)
sd.sleep(600)

sd.play(B, fs)
sd.sleep(600)

#5
sd.play(A, fs)
sd.sleep(600)

sd.play(A, fs)
sd.sleep(600)

sd.play(A, fs)
sd.sleep(600)

sd.play(B, fs)
sd.sleep(600)

#4
sd.play(C, fs)
sd.sleep(600)

sd.play(C, fs)
sd.sleep(600)

sd.play(B, fs)
sd.sleep(600)

sd.play(B, fs)
sd.sleep(600)

#6
sd.play(A, fs)
sd.sleep(1000)

sd.play(A, fs)
sd.sleep(1000)