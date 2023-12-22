#include <JetsonGPIO.h>
#ifdef __cplusplus
extern "C" {
#endif

int gpioInitialise(void)
{
return 0;
}

void gpioTerminate(void)
{
 
}

int gpioSetMode(unsigned gpio, unsigned mode)
{
     GPIO::setmode(GPIO::BCM);
     if(mode==1)
     {
        GPIO::setup(gpio, GPIO::OUT, GPIO::HIGH);
     }
     else
     {
        GPIO::setup(gpio, GPIO::IN);
     }
     return 1;
}

int gpioRead(unsigned gpio)
{
    return GPIO::input(gpio);
}

int gpioWrite(unsigned gpio, unsigned level)
{
    GPIO::output(gpio,level);
    return 1;
}

#ifdef __cplusplus
}
#endif