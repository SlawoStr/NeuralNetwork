#include "NeuralNetwork.h"
#include "NetworkInputExcepction.h"

NeuralNetwork::NeuralNetwork(size_t inputSize, size_t outputSize, ActivationFunction outActFunc) : m_inputSize{ inputSize }, m_outputSize{ outputSize }
{
	m_layers.emplace_back(m_inputSize, m_outputSize);
	m_layers.emplace_back(m_outputSize, 0, outActFunc);
}

void NeuralNetwork::addLayer(size_t neuronNumber, ActivationFunction actFunc)
{
	if (neuronNumber == 0)
	{
		throw NetworkInputExcepction("Error: Size of layer cant be equal to 0");
	}
	auto it = m_layers.insert(m_layers.end() - 1, Layer{ neuronNumber,m_outputSize,actFunc });
	std::prev(it)->setConnectionNumber(neuronNumber);
}

std::vector<float> NeuralNetwork::predict(const std::vector<float>& input)
{
	if (input.size() != m_inputSize)
	{
		throw NetworkInputExcepction("Error: Required input size: " + std::to_string(m_inputSize) + "\t received input size: " + std::to_string(input.size()));
	}
	// Start prediction
	m_layers[0].setNeuronValue(input);
	for (auto it = m_layers.begin(); it != m_layers.end() - 1; ++it)
	{
		it->feedForward(&(*std::next(it)));
	}
	// Return output layer neuron values
	return m_layers.back().getNeuronValue();
}
