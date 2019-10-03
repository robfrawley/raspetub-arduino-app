/*
 * This file is part of the `src-run/raspetub-arduino-app` package.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, view the LICENSE.md
 * file distributed with this source code.
 */

#include "License.h"

namespace RT
{ /* BEGIN namespace RT */

    namespace About
    { /* BEGIN namespace About */

        bool License::isNameDefined()
        {
            return String(RT_LICENSE_NAME).length() > 0;
        }

        bool License::isLinkDefined()
        {
            return String(RT_LICENSE_LINK).length() > 0;
        }

        String License::name()
        {
            return isNameDefined() ? RT_LICENSE_NAME : "";
        }

        String License::link()
        {
            return isLinkDefined() ? RT_LICENSE_LINK : "";
        }

        String License::describe()
        {
            return describe(false);
        }

        String License::describe(bool includeLink /* = false */)
        {
            String d = name();

            if (includeLink) {
                d += " <" + link() + ">";
            }

            return d;
        }

        String License::describeAbridged()
        {
            return describe(false);
        }

        String License::describeComplete()
        {
            return describe(true);
        }

    } /* CLOSE namespace About */

} /* CLOSE namespace RT */
