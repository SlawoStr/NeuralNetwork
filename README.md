# NeuralNetwork

Implementation of feed forward fully connected neural network.

```c
const size_t inputSize = 10;
const size_t outputSize = 5;
// Creat network
NeuralNetwork network(inputSize, outputSize, ActivationFunction::SIGMOID);
// Add layers
network.addLayer(10, ActivationFunction::TANH);
network.addLayer(20, ActivationFunction::RELU);
// Generate network weights
std::vector<float> input(network.getNetworkWeightSize());
for (int i = 0; i < input.size(); ++i)
{
  input[i] = 1.0f * i;
}
// Set/Get weights
network.setWeight(input);
auto result = network.getWeight();
// Make prediction
std::vector<float>test(inputSize);
auto predResult = network.predict(test);
```
