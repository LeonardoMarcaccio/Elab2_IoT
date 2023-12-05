#ifndef _SERIALPC_
#define _SERIALPC_

#include <Arduino.h>
#include "SerialListener.h"
#include "SerialPCCommandFactory.h"

/**
 * Represents a computer that is connected via the serial line trough the
 * embedded device.
*/
class SerialPC {
    private:
        bool open = false;
        bool connected = false;
    public:
        SerialPC();
        ~SerialPC();
        /**
         * Checks if a device with the driver for this software is currently
         * active and connected.
         * @return returns true if a compatible device is currently connected
         * @warning This operation is blocking and might cause some hang,
         * use with care!
        */
        bool isConnected();
        /**
         * Opens a connection via the serial line.
         * @warning This operation is blocking and might cause some hang,
         * use with care!
        */
        void connect();
        /**
         * Sends a string to the connected device via the serial line.
         * @param data the string to send to the connected device
        */
        void sendMessage(String data);
        /**
         * Receives a string from the connected device via the serial line.
         * @return the message to receive
        */
        String receiveMessage();
        /**
         * Registers a listener that is going to be triggered whenever
         * something happens in the serial line.
         * @param listener the listener that has to be registered
        */
        void addListener(SerialListener* listener);
        /**
         * Unregisters a previously registered listener.
         * @param listener the listener that has to be removed
        */
        void removeListener(SerialListener* listener);
        /**
         * This function will remove and destroy every registered listener.
         * @warning This function will delete indiscriminately all listeners!
         * Using this function without proper care might cause unexpected results!
        */
        void clearListeners();
};
#endif
