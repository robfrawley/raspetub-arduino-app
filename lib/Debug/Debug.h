/*
 * This file is part of the `src-run/raspetub-arduino-app` package.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, view the LICENSE.md
 * file distributed with this source code.
 */

#ifndef RT_HR_INCLUDED_DEBUG

    #define RT_HR_INCLUDED_DEBUG

    #include <stdio.h>
    #include <Arduino.h>
    #include <HardwareSerial.h>
    #include "Application.h"
    #include "Utility.h"

    enum LogSerialHardware : long int {
        H_01 = 0,
        H_02 = 1,
        H_03 = 2,
        H_04 = 3
    };

    enum LogSerialBaudRate : long int {
        R_000300 = 300,
        R_001200 = 1200,
        R_002400 = 2400,
        R_004800 = 4800,
        R_009600 = 9600,
        R_019200 = 19200,
        R_038400 = 38400,
        R_057600 = 57600,
        R_074880 = 74880,
        R_115200 = 115200,
    };

    enum LogEntryVerbosity : long int {
        V_SILENT       = -2,
        V_QUIET        = -1,
        V_NORMAL       = 0,
        V_VERBOSE      = 1,
        V_VERY_VERBOSE = 2
    };

    enum LogEntrySituation : long int {
        S_MAIN      = 0,
        S_MAIN_CONF = 1,
        S_MAIN_STEP = 2,
        S_MAIL_TREE = 3,
        S_OBJS      = 4,
        S_OBJS_CONF = 5,
        S_OBJS_STEP = 6,
        S_OBJS_TREE = 7,
        S_LIBS      = 8,
        S_LIBS_CONF = 9,
        S_LIBS_STEP = 10,
        S_LIBS_TREE = 11,
        S_ANLG_CONF = 12,
        S_ANLG_READ = 13,
        S_ANLG_PUSH = 14,
        S_ANLG_TREE = 15,
        S_GPIO_CONF = 16,
        S_GPIO_READ = 17,
        S_GPIO_PUSH = 18,
        S_GPIO_TREE = 19
    };

    enum LogEntryCondition : long int {
        C_CRIT = -3,
        C_FAIL = -2,
        C_WARN = -1,
        C_DONE = 0,
        C_INFO = 1,
        C_NOTE = 2,
        C_MORE = 3
    };

    namespace RT
    { /* BEGIN namespace RT */

        namespace Debug
        { /* BEGIN namespace Debug */

            /* BEGIN define logSerialHardwareDefault */

            #if defined RT_LOG_SERIAL_PORT_USED
                const LogSerialHardware logSerialHardwareDefault = static_cast<LogSerialHardware>(
                    RT::Utility::constrainRange(RT_LOG_SERIAL_PORT_USED, H_01, H_04)
                );
            #else
                const LogSerialHardware logSerialHardwareDefault = H_01;
            #endif

            /* CLOSE define logSerialHardwareDefault */
            /* BEGIN define logSerialBaudRateDefault */

            #if defined RT_LOG_SERIAL_BAUD_RATE
                const LogSerialBaudRate logSerialBaudRateDefault = static_cast<LogSerialBaudRate>(
                    RT::Utility::constrainRange(RT_LOG_SERIAL_BAUD_RATE, R_000300, R_115200)
                );
            #else
                const LogSerialBaudRate logSerialBaudRateDefault = R_009600;
            #endif

            /* CLOSE define logSerialBaudRateDefault */
            /* BEGIN define logEntryVerbosityDefault */

            #if defined RT_LOG_SERIAL_VERB_TYPE
                const LogEntryVerbosity logEntryVerbosityDefault = static_cast<LogEntryVerbosity>(
                    RT::Utility::constrainRange(RT_LOG_SERIAL_VERB_TYPE, V_SILENT, V_VERY_VERBOSE)
                );
            #else
                const LogEntryVerbosity logEntryVerbosityDefault = V_NORMAL;
            #endif

            /* CLOSE define logEntryVerbosityDefault */
            /* BEGIN define logEntryConditionDefault */

            const LogEntryCondition logEntryConditionDefault = C_DONE;

            /* CLOSE define logEntryConditionDefault */
            /* BEGIN define logEntrySituationDefault */

            const LogEntrySituation logEntrySituationDefault = S_MAIN;

            /* CLOSE define logEntrySituationDefault */
            /* BEGIN class SerialLog */

            class SerialLog
            {
                private:
                    LogSerialHardware s;

                    LogEntryVerbosity v;

                    LogSerialBaudRate b;

                    bool i = false;

                    HardwareSerial& getSerial();

                    HardwareSerial& useSerial();

                    bool compareVerbType(LogEntryVerbosity verbType, bool strict);

                public:
                    SerialLog();

                    SerialLog(LogSerialHardware hwSerial);

                    SerialLog(LogSerialHardware hwSerial, LogSerialBaudRate baudRate, LogEntryVerbosity verbType);

                    SerialLog& hwSerial(LogSerialHardware hwSerial);

                    LogSerialHardware hwSerial();

                    SerialLog& verbType(LogEntryVerbosity verbType);

                    LogEntryVerbosity verbType();

                    SerialLog& baudRate(LogSerialBaudRate baudRate);

                    LogSerialBaudRate baudRate();

                    bool isSerialAvailable();

                    bool isVerbTypeShown(LogEntryVerbosity verbType);

                    bool isVerbTypeEqual(LogEntryVerbosity verbType);

                    bool isVerbTypeSilent(bool strict = false);

                    bool isVerbTypeQuiet(bool strict = false);

                    bool isVerbTypeNormal(bool strict = false);

                    bool isVerbTypeVerbose(bool strict = false);

                    bool isVerbTypeVeryVerbose(bool strict = false);

                    SerialLog& nl();

                    SerialLog& nls(unsigned short int count = 1);

                    String sprint(const char * format);

                    template <typename ...Args> String sprintf(const char * format, Args ...args);

                    SerialLog& print(const char * format);

                    template <typename ...Args> SerialLog& printf(const char * format, Args ...args);

                    String pfs(String format);

                    String pfs(char const* format);

                    template<typename Args> String pfs(Args format, ...);

                    template<typename ...Args> SerialLog& pft(String text = "", Args ...args);

                    template<typename ...Args> SerialLog& pfl(String text = "", Args ...args);

                    SerialLog& abt();

                    template<typename ...Args> SerialLog& log(String text = "", Args ...args);

                    template<typename ...Args> SerialLog& log(LogEntryCondition status, String text = "", Args ...args);

                    template<typename ...Args> SerialLog& log(LogEntrySituation nature, String text = "", Args ...args);

                    template<typename ...Args> SerialLog& log(LogEntrySituation nature, LogEntryCondition status, String text = "", Args ...args);
            };

        }; /* namespace Debug */

    }; /* namespace RT */

    extern RT::Debug::SerialLog SL;

#endif
