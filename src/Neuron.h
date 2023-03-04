#pragma once
#include <vector>

class Neuron
{
public:
	void setConnectionNumber(size_t connectionNumber);

	// Access to elements
	float& operator[](size_t index) { return m_weights[index]; }
	float operator[](size_t index)const { return m_weights[index]; }
	float& at(size_t index) { return m_weights.at(index); }
	float at(size_t index)const { return m_weights.at(index); }

	float getValue() const { return m_value; }

	void setValue(float value) { m_value = value; }

private:
	std::vector<float>	m_weights;
	float				m_value{ 0.0f };
};