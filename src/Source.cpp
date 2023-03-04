#include<iostream>
#include "NeuralNetwork.h"

int main()
{
	NeuralNetwork network(100, 5, ActivationFunction::SIGMOID);
	network.addLayer(10, ActivationFunction::TANH);
	network.addLayer(20, ActivationFunction::RELU);

	std::vector<float>test(100);

	network.predict(test);


	return 0;
}