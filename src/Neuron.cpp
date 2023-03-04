#include "Neuron.h"

void Neuron::setConnectionNumber(size_t connectionNumber)
{
	m_weights.resize(connectionNumber);
}
