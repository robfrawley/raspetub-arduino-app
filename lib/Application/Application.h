/*
 * This file is part of the `src-run/raspetub-arduino-app` package.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, view the LICENSE.md
 * file distributed with this source code.
 */

#ifndef RT_HR_INCLUDED_APPLICATION

    #define RT_HR_INCLUDED_APPLICATION

    #include <Arduino.h>
    #include "Defaults.h"
    #include "Author.h"
    #include "License.h"
    #include "Version.h"

    namespace RT
    { /* BEGIN namespace RT */

        namespace About
        { /* BEGIN namespace About */

            class Application
            {
                private:
                    Author a;
                    Version v;
                    License l;
                public:
                    Application();
                    License license();
                    Version version();
                    Author author();
                    bool isOrganizationDefined();
                    bool isNameDefined();
                    bool isLinkDefined();
                    String organization();
                    String name();
                    String link();
                    String describe();
                    String describe(bool includeOrganization, bool includeLink);
                    String describeAbridged();
                    String describeStandard();
                    String describeComplete();

            };

        } /* CLOSE namespace RT */

    } /* CLOSE namespace RT */

#endif
