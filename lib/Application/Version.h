/*
 * This file is part of the `src-run/raspetub-arduino-app` package.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, view the LICENSE.md
 * file distributed with this source code.
 */

#ifndef RT_HR_INCLUDED_VERSION

    #define RT_HR_INCLUDED_VERSION

    #include <Arduino.h>
    #include "Defaults.h"

    namespace RT
    { /* BEGIN namespace RT */

        namespace About
        { /* BEGIN namespace About */

            class Version
            {
                public:
                    bool isMajorDefined();
                    bool isMinorDefined();
                    bool isPatchDefined();
                    bool isTypedDefined();
                    bool isNamedDefined();
                    unsigned int major();
                    unsigned int minor();
                    unsigned int patch();
                    unsigned int ident();
                    String typed();
                    String named();
                    String describe();
                    String describe(bool includeVersionChar = false, bool includeVersionType = false, bool includeVersionName = false);
                    String describeAbridged();
                    String describeStandard();
                    String describeExtended();
                    String describeComplete();
            };

        } /* CLOSE namespace About */

    } /* CLOSE namespace RT */

#endif
