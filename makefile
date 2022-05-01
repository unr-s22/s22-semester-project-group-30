run: main.o Console.o Controller.o WavModel.o Wav.o WavReader.o IWavModel.o Echo.o Normalizer.o SignalProcessor.o WavWriter.o
	g++ -std=c++11 -o run main.o Console.o Controller.o WavModel.o Wav.o WavReader.o IWavModel.o Echo.o Normalizer.o SignalProcessor.o WavWriter.o

main.o: main.cpp Console.h Controller.h
	g++ -std=c++11 -c main.cpp

Controller.o: Controller.cpp Controller.h Console.h WavModel.h Echo.h Normalizer.h
	g++ -std=c++11 -c Controller.cpp

Console.o: Console.cpp Console.h
	g++ -std=c++11 -c Console.cpp

WavModel.o: WavModel.cpp WavModel.h IWavModel.h WavReader.h Wav.h
	g++ -std=c++11 -c WavModel.cpp

IWavModel.o: IWavModel.cpp IWavModel.h

WavReader.o: WavReader.cpp WavReader.h Wav.h
	g++ -std=c++11 -c WavReader.cpp

Wav.o: Wav.cpp Wav.h
	g++ -std=c++11 -c Wav.cpp

Echo.o: Echo.cpp Echo.h
	g++ -std=c++11 -c Echo.cpp

Normalizer.o: Normalizer.cpp Normalizer.h
	g++ -std=c++11 -c Normalizer.cpp

SignalProcessor.o: SignalProcessor.cpp 
	g++ -std=c++11 -c SignalProcessor.cpp

WavWriter.o: WavWriter.cpp WavWriter.h
	g++ -std=c++11 -c WavWriter.cpp

clean:
	rm *.o run