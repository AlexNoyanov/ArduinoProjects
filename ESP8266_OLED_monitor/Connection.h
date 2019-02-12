
//#ifndef Connection_h
//#define Connection_h

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class WIFI_Connector
{
   const char* ssid     = "your-ssid";                 // Your WI-FI name
   const char* password = "your-password";             // Your WI-FI password
    
    public:
        bool begin();                                   //
        void SerialData();                              // Write data on Serial
        char* getSsid();
        char* pass();
};

