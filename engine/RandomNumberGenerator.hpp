#ifndef RANDOMNUMBERGENERATOR_HPP
#define RANDOMNUMBERGENERATOR_HPP

/**
 * @brief Generate a random integer in bounds
 *
 * @param lowerBound The lower bound for the integer
 * @param upperBound The upper bound for the integer
 * @return A random integer between upper and lower bound
 */
int GetRandomInt(int lowerBound, int upperBound);
/**
 * @brief Generate a random float between 0 and 1.
 *
 * @return A random float between 0 and 1.
 */
float GetRandomNormalizedFloat();

#endif // RANDOMNUMBERGENERATOR_HPP
