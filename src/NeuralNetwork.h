#pragma once
#include <vector>
#include "Layer.h"

class NeuralNetwork
{
public:
	NeuralNetwork(size_t inputSize, size_t outputSize, ActivationFunction outActFunc);

	void addLayer(size_t neuronNumber, ActivationFunction actFunc);

	size_t getNetworkSize()const { return m_layers.size(); }

	std::vector<float> predict(const std::vector<float>& input);

private:
	std::vector<Layer> m_layers;		//!<	Neural network layers
	size_t			   m_inputSize;		//!<	Number of neurons in inputLayer
	size_t			   m_outputSize;
};