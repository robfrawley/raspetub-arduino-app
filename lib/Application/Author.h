/*
 * This file is part of the `src-run/raspetub-arduino-app` package.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, view the LICENSE.md
 * file distributed with this source code.
 */

#ifndef RT_HR_INCLUDED_AUTHOR

    #define RT_HR_INCLUDED_AUTHOR

    #include <Arduino.h>
    #include "Defaults.h"

    namespace RT
    { /* BEGIN namespace RT */

        namespace About
        { /* BEGIN namespace About */

            class Author
            {
                public:
                    bool isNameDefined();
                    bool isMailDefined();
                    bool isLinkDefined();
                    String name();
                    String mail();
                    String link();
                    String describe();
                    String describe(bool includeMail, bool includeLink);
                    String describeAbridged();
                    String describeStandard();
                    String describeComplete();
            };

        } /* CLOSE namespace About */

    } /* CLOSE namespace RT */

#endif
