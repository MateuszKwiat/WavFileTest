#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <cmath>

const int sampleRate = 44100;
const int bitDepth = 16;

class SineOscillator {
private:
	float frequency;
	float amplitude;
	float angle;
	float offset;

public:
	SineOscillator(float freq, float amp) : frequency(freq), amplitude(amp), angle(0.0f) {
		offset = 2 * M_PI * frequency / sampleRate;
	}

	float process() {
		auto sample = amplitude * sin(angle);
		angle += offset;

		return sample;
	}
};

int main() {
	int duration = 2;
	SineOscillator AsineOscillator(440, 0.5);
	SineOscillator CsineOscillator(523.25, 0.5);
	SineOscillator EsineOscillator(659.25, 0.5);
	std::ofstream audioFile;
	std::ofstream audioTest;

	audioFile.open("waveFormBin", std::ios::binary);
	audioTest.open("waveForm");

	auto maxAmplitude = pow(2, bitDepth - 1) - 1;
	for (int i = 0; i < sampleRate * duration; i++) {
		auto Asample = AsineOscillator.process();
		auto Csample = CsineOscillator.process();
		auto Esample = EsineOscillator.process();
		int intSample = static_cast<int> ((Asample + Csample + Esample) * maxAmplitude / 3);
		audioFile.write(reinterpret_cast<char*> (&intSample), 2);
		audioTest << intSample << std::endl;
	}

	audioFile.close();
}