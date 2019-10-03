/*
 * This file is part of the `src-run/raspetub-arduino-app` package.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, view the LICENSE.md
 * file distributed with this source code.
 */

#ifndef RT_HR_INCLUDED_CERBERUS

    #define RT_HR_INCLUDED_CERBERUS

    #include <Arduino.h>
    #include <Debug.h>

    #if ! defined RT_CERBERUS_ENABLED
        #define RT_CERBERUS_ENABLED false
    #endif

    #if ! defined RT_CERBERUS_MAXIMUM_WAIT_MS
        #define RT_CERBERUS_MAXIMUM_WAIT_MS 60000
    #endif

    namespace RT
    { /* BEGIN namespace RT */

        namespace Cerberus
        { /* BEGIN namespace Cerberus */

            class Cerberus
            {
                private:
                    unsigned int maximumWaitMs;
                    bool enabled;
                    void initialize(bool enabled = RT_CERBERUS_ENABLED, unsigned int maximumWaitMs = RT_CERBERUS_MAXIMUM_WAIT_MS);
                public:
                    Cerberus();
                    Cerberus(bool enabled);
                    Cerberus(bool enabled, unsigned int maximumWaitMs);
                    Cerberus(unsigned int maximumWaitMs);
                    Cerberus(unsigned int maximumWaitMs, bool enabled);
            }

        } /* namespace Cerberus */

    } /* namespace RT */

#endif
