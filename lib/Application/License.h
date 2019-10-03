/*
 * This file is part of the `src-run/raspetub-arduino-app` package.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, view the LICENSE.md
 * file distributed with this source code.
 */

#ifndef RT_HR_INCLUDED_LICENSE

    #define RT_HR_INCLUDED_LICENSE

    #include <Arduino.h>
    #include "Defaults.h"

    namespace RT
    { /* BEGIN namespace RT */

        namespace About
        { /* BEGIN namespace About */

            class License
            {
                public:
                    bool isNameDefined();
                    bool isLinkDefined();
                    String name();
                    String link();
                    String describe();
                    String describe(bool includeLink);
                    String describeAbridged();
                    String describeComplete();
            };

        } /* CLOSE namespace About */

    } /* CLOSE namespace RT */

#endif
