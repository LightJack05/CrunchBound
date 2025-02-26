#ifndef TIME_HPP
#define TIME_HPP

/**
 * @brief Update the stored deltatime. Should be executed each frame.
 */
void UpdateDeltaTime();
/**
 * @brief Return the time it took to render the last frame in milliseconds
 */
unsigned int GetDeltaTime();

unsigned long long GetTimeSinceGameStart();

/**
 * @brief Reset the time since the game has started.
 */
void ResetTimeSinceGameStart();

#endif // TIME_HPP
