#ifndef jetgpio_h__
#define jetgpio_h__
#ifdef __cplusplus
extern "C" {
#endif

int gpioInitialise(void);
/**<
 * @brief Initialises the library.
 * gpioInitialise must be called before using the other library functions, it stores the status of all the relevant registers before using/modifying them.
 * 
 * @return Returns 0 if OK, otherwise a negative number
 *
 * @code if (gpioInitialise() < 0)
 * {
 *   // jetgpio initialisation failed.
 * }
 * else
 * {
 *   // jetgpio initialised okay.
 * } @endcode
 */

void gpioTerminate(void);
/**<
 * @brief Terminates the library.
 * This function restores the used registers to their previous state and releases memory.
 *
 * @return Returns nothing
 *
 * @code gpioTerminate(); @endcode
*/

int gpioSetMode(unsigned gpio, unsigned mode);
/**<
 * @brief Sets the GPIO mode, typically input or output.
 *
 * @param gpio 3-40
 * @param mode JET_INPUT, JET_OUTPUT
 * @return Returns 0 if OK, -1 otherwise
 *
 * @code gpioSetMode(17, JET_INPUT);  // Sets pin 17 as input. @endcode
 * @code gpioSetMode(18, JET_OUTPUT); // Sets pin 18 as output. @endcode
*/

int gpioRead(unsigned gpio);
/**<
 * @brief Reads the GPIO level, on or off, 0 or 1.
 * Arduino style: digitalRead. Wheter a pin has been set as input or output it can be read with this function.
 * @param gpio 3-40
 * @return Returns the GPIO level if OK, otherwise a negative number
 *
 * @code printf("pin 24 is level %d", gpioRead(24)); @endcode
*/

int gpioWrite(unsigned gpio, unsigned level);
/**<
 * @brief Sets the GPIO level, on or off.
 * Arduino style: digitalWrite
 * @param gpio 3-40
 * @param level 0-1
 * @return Returns 0 if OK, otherwise a negative number
 *
 * @code gpioWrite(24, 1); // Sets pin 24 high. @endcode
*/

#ifdef __cplusplus
}
#endif
 
#endif  // jetgpio_h__
