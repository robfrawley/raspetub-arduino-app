/*
 * This file is part of the `src-run/raspetub-arduino-app` package.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, view the LICENSE.md
 * file distributed with this source code.
 */

#include "Author.h"

namespace RT
{ /* BEGIN namespace RT */

    namespace About
    { /* BEGIN namespace About */

        bool Author::isNameDefined()
        {
            return String(RT_AUTHOR_NAME).length() > 0;
        }

        bool Author::isLinkDefined()
        {
            return String(RT_AUTHOR_LINK).length() > 0;
        }

        bool Author::isMailDefined()
        {
            return String(RT_AUTHOR_MAIL).length() > 0;
        }

        String Author::name()
        {
            return isNameDefined() ? RT_AUTHOR_NAME : "";
        }

        String Author::link()
        {
            return isLinkDefined() ? RT_AUTHOR_LINK : "";
        }

        String Author::mail()
        {
            return isMailDefined() ? RT_AUTHOR_MAIL : "";
        }

        String Author::describe()
        {
            return describe(false, false);
        }

        String Author::describe(bool includeMail /* = false */, bool includeLink /* = false */)
        {
            String d = name();

            if (includeMail) {
                d += " (" + mail() + ")";
            }

            if (includeLink) {
                d += " <" + link() + ">";
            }

            return d;
        }

        String Author::describeAbridged()
        {
            return describe(false, false);
        }

        String Author::describeStandard()
        {
            return describe(true, false);
        }

        String Author::describeComplete()
        {
            return describe(true, true);
        }

    } /* CLOSE namespace About */

} /* CLOSE namespace RT */
