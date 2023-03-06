#include<iostream>
#include "NeuralNetwork.h"

int main()
{
	// Set Up
	NeuralNetwork network(100, 5, ActivationFunction::SIGMOID);
	network.addLayer(10, ActivationFunction::TANH);
	network.addLayer(20, ActivationFunction::RELU);
	std::vector<float>test(100);

	// Network weights
	std::vector<float> input(network.getNetworkWeightSize());
	for (int i = 0; i < input.size(); ++i)
	{
		input[i] = 1.0f * i;
	}
	
	// Set/Get weights
	network.setWeight(input);
	auto result = network.getWeight();

	// Prediction
	auto predResult = network.predict(test);

	return 0;
}