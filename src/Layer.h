#pragma once
#include <vector>
#include <functional>
#include "Neuron.h"

enum class ActivationFunction
{
	RELU,
	TANH,
	SIGMOID,
};

class Layer
{
public:
	Layer(size_t neuronNumber, size_t connectionNumber, ActivationFunction actFunc);

	Layer(size_t neuronNumber, size_t connectionNumber);

	void setActivationFunction(ActivationFunction actFunc);

	void setNeuronValue(const std::vector<float>& input);

	std::vector<float> getNeuronValue();

	size_t getNeuronNumber() { return m_neurons.size(); }

	void feedForward(Layer* next);

	void setConnectionNumber(size_t connectionNumber);

private:
	std::function<float(float)>		m_actFunc;
	std::vector<Neuron>				m_neurons;
	size_t							m_connectionNumber;
};