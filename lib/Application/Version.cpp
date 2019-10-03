/*
 * This file is part of the `src-run/raspetub-arduino-app` package.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, view the LICENSE.md
 * file distributed with this source code.
 */

#include "Version.h"

namespace RT
{ /* BEGIN namespace RT */

    namespace About
    { /* BEGIN namespace About */

        bool Version::isMajorDefined()
        {
            return RT_VERSION_MAJOR > 0;
        }

        bool Version::isMinorDefined()
        {
            return RT_VERSION_MINOR > 0;
        }

        bool Version::isPatchDefined()
        {
            return RT_VERSION_PATCH > 0;
        }

        bool Version::isTypedDefined()
        {
            return String(RT_VERSION_TYPED).length() > 0;
        }

        bool Version::isNamedDefined()
        {
            return String(RT_VERSION_NAMED).length() > 0;
        }

        unsigned int Version::major()
        {
            return isMajorDefined() ? RT_VERSION_MAJOR : 0;
        }

        unsigned int Version::minor()
        {
            return isMinorDefined() ? RT_VERSION_MINOR : 0;
        }

        unsigned int Version::patch()
        {
            return isPatchDefined() ? RT_VERSION_PATCH : 0;
        }

        unsigned int Version::ident()
        {
            char buffer[6];
            snprintf("%02d%02d%02d", 6, String(major()).c_str(), String(minor()).c_str(), String(patch()).c_str());

            return atoi(buffer);
        }

        String Version::typed()
        {
            return isTypedDefined() ? String(RT_VERSION_TYPED) : "";
        }

        String Version::named()
        {
            return isNamedDefined() ? String(RT_VERSION_NAMED) : "";
        }

        String Version::describe()
        {
            return describe(false, false, false);
        }

        String Version::describe(bool includeChar /* = false */, bool includeType /* = false */, bool includeName /* = false */)
        {
            String d = (includeChar ? "v" : "") + String(major()) + "." + String(minor()) + "." + String(patch());

            if (includeType && isTypedDefined()) {
                d += "-" + typed();
            }

            if (includeName && isNamedDefined()) {
                d += " (" + named() + ")";
            }

            return d;
        }

        String Version::describeAbridged()
        {
            return describe(false, false, false);
        }

        String Version::describeStandard()
        {
            return describe(true, false, false);
        }

        String Version::describeExtended()
        {
            return describe(true, true, false);
        }

        String Version::describeComplete()
        {
            return describe(true, true, true);
        }

    } /* CLOSE namespace About */

} /* CLOSE namespace RT */
