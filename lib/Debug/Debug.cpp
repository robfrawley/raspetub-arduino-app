/*
 * This file is part of the `src-run/raspetub-arduino-app` package.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, view the LICENSE.md
 * file distributed with this source code.
 */

#include "Debug.h"

namespace RT
{ /* BEGIN namespace RT */

    namespace Debug
    { /* BEGIN namespace Debug */

        /* BEGIN class SerialLog PRIVATE members */

        HardwareSerial& SerialLog::getSerial()
        {
            switch (this->s) {
                case H_04:
                    return SERIAL_PORT_HARDWARE3;
                case H_03:
                    return SERIAL_PORT_HARDWARE2;
                case H_02:
                    return SERIAL_PORT_HARDWARE1;
                default:
                    return SERIAL_PORT_HARDWARE;
            }
        }

        HardwareSerial& SerialLog::useSerial()
        {
            if (!this->i) {
                this->getSerial().end();
                this->getSerial().begin(this->b);

                while (!this->isSerialAvailable()) {
                    /* wait for serial to become available */
                }

                this->i = true;
            }

            return this->getSerial();
        }

        bool SerialLog::compareVerbType(LogEntryVerbosity verbType, bool strict)
        {
            return strict ? this->isVerbTypeEqual(verbType) : this->isVerbTypeShown(verbType);
        }

        /* CLOSE class SerialLog PRIVATE members */
        /* BEGIN class SerialLog PUBLIC members */

        SerialLog::SerialLog()
        {
            this->hwSerial(logSerialHardwareDefault);
            this->baudRate(logSerialBaudRateDefault);
            this->verbType(logEntryVerbosityDefault);
        }

        SerialLog::SerialLog(LogSerialHardware hwSerial)
        {
            this->hwSerial(hwSerial);
            this->baudRate(logSerialBaudRateDefault);
            this->verbType(logEntryVerbosityDefault);
        }

        SerialLog::SerialLog(LogSerialHardware hwSerial, LogSerialBaudRate baudRate, LogEntryVerbosity verbType)
        {
            this->hwSerial(hwSerial);
            this->baudRate(baudRate);
            this->verbType(verbType);
        }

        SerialLog& SerialLog::hwSerial(LogSerialHardware hwSerial)
        {
            this->s = hwSerial;
            this->i = false;

            return *this;
        }

        LogSerialHardware SerialLog::hwSerial()
        {
            return this->s;
        }

        SerialLog& SerialLog::verbType(LogEntryVerbosity verbType)
        {
            this->v = verbType;

            return *this;
        }

        LogEntryVerbosity SerialLog::verbType()
        {
            return this->v;
        }

        SerialLog& SerialLog::baudRate(LogSerialBaudRate baudRate)
        {
            this->b = baudRate;

            return *this;
        }

        LogSerialBaudRate SerialLog::baudRate()
        {
            return this->b;
        }

        bool SerialLog::isSerialAvailable()
        {
            return this->getSerial() ? true : false;
        }

        bool SerialLog::isVerbTypeShown(LogEntryVerbosity verbType)
        {
            return this->v >= verbType;
        }

        bool SerialLog::isVerbTypeEqual(LogEntryVerbosity verbType)
        {
            return this->v == verbType;
        }

        bool SerialLog::isVerbTypeSilent(bool strict)
        {
            return this->compareVerbType(V_SILENT, strict);
        }

        bool SerialLog::isVerbTypeQuiet(bool strict)
        {
            return this->compareVerbType(V_QUIET, strict);
        }

        bool SerialLog::isVerbTypeNormal(bool strict)
        {
            return this->compareVerbType(V_NORMAL, strict);
        }

        bool SerialLog::isVerbTypeVerbose(bool strict)
        {
            return this->compareVerbType(V_VERBOSE, strict);
        }

        bool SerialLog::isVerbTypeVeryVerbose(bool strict)
        {
            return this->compareVerbType(V_VERY_VERBOSE, strict);
        }

        SerialLog& SerialLog::nl()
        {
            Serial.println();
        }

        SerialLog& SerialLog::nls(unsigned short count)
        {
            for (unsigned int i = 0; i < count; i++) {
                this->nl();
            }

            return *this;
        }

        String SerialLog::sprint(const char * format)
        {
            return String(format);
        }

        template <typename ...Args> String SerialLog::sprintf(const char * format, Args ...args)
        {
            char buffer[256];

            snprintf(buffer, 256, format, args...);

            return String(buffer);
        }

        SerialLog& SerialLog::print(const char * format)
        {
            Serial.print(format);

            return *this;
        }

        template <typename ...Args> SerialLog& SerialLog::printf(const char * format, Args ...args)
        {
            Serial.print(this->sprintf(format, args...));

            return *this;
        }

        String SerialLog::pfs(String format)
        {
            return format;
        }

        String SerialLog::pfs(char const* format)
        {
            return String(format);
        }

        template<typename Args> String SerialLog::pfs(Args format, ...)
        {
            Serial.println("START[pfs()]");
            char buffer[256];
            va_list args;

            va_start(args, format);
            Serial.println("FORMAT["+format+"]");
            vsprintf(buffer, format.c_str(), args);
            va_end(args);

            Serial.println("CLOSE[pfs()]");
            return String(*buffer);
        }

        template<typename ...Args> SerialLog& SerialLog::pft(String text, Args ...args)
        {
            Serial.print(
                this->pfs(text, args...).c_str()
            );

            return *this;
        }

        template<typename ...Args> SerialLog& SerialLog::pfl(String text, Args ...args)
        {
            Serial.println(
                this->pfs(text, args...).c_str()
            );

            return *this;
        }

        SerialLog& SerialLog::abt()
        {
            RT::About::Application App;

            this->nls(2);
            this->pfl("##");
            Serial.println("APP-DESC["+App.describe(true, true)+"]");
            this->pfl("## @package : %s", App.describe(true, true));
            Serial.println("VERSION ["+App.version().describe(false, true, true)+"]");
            this->pfl("## @version : %s", App.version().describe(false, true, true));
            Serial.println("AUTHOR  ["+App.author().describe(true, true)+"]");
            this->pfl("## @author  : %s", App.author().describe(true, true));
            Serial.println("LICENSE ["+App.license().describe(true)+"]");
            this->pfl("## @license : %s", App.license().describe(true));
            this->pfl("##");
            this->nls(1);

            return *this;
        }

        template<typename ...Args> SerialLog& SerialLog::log(String text, Args ...args)
        {
            this->pfl(text);

            return *this;
        }

        template<typename ...Args> SerialLog& SerialLog::log(LogEntryCondition status, String text, Args ...args)
        {
            this->pfl(text);

            return *this;
        }

        template<typename ...Args> SerialLog& SerialLog::log(LogEntrySituation nature, String text, Args ...args)
        {
            this->pfl(text);

            return *this;
        }

        template<typename ...Args> SerialLog& SerialLog::log(LogEntrySituation nature, LogEntryCondition status, String text, Args ...args)
        {
            this->pfl(text);

            return *this;
        }

        /* CLOSE class SerialLog PUBLIC members */

    } // CLOSE namespace Debug

} // CLOSE namespace RT

/* @todo: decide on desired construction routine */
//RT::Debug::SerialLog SL(RT::Debug::logSerialHardwareDefault, RT::Debug::logSerialBaudRateDefault, RT::Debug::logEntryVerbosityDefault);
//RT::Debug::SerialLog SL(LogSerialHardware::H_01, LogSerialBaudRate::R_009600, LogEntryVerbosity::V_VERY_VERBOSE);
RT::Debug::SerialLog SL;
