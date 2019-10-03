/*
 * This file is part of the `src-run/raspetub-arduino-app` package.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, view the LICENSE.md
 * file distributed with this source code.
 */

#include "Application.h"

namespace RT
{ /* BEGIN namespace RT */

    namespace About
    { /* BEGIN namespace About */

        Application::Application()
        {
            Author  a();
            Version v();
            License l();
        }

        Author Application::author()
        {
            return a;
        }

        Version Application::version()
        {
            return v;
        }

        License Application::license()
        {
            return l;
        }

        bool Application::isOrganizationDefined()
        {
            return String(RT_PROJECT_ORG).length() > 0;
        }

        bool Application::isNameDefined()
        {
            return String(RT_PROJECT_NAME).length() > 0;
        }

        bool Application::isLinkDefined()
        {
            return String(RT_PROJECT_LINK).length() > 0;
        }

        String Application::organization()
        {
            return isOrganizationDefined() ? RT_PROJECT_ORG : "";
        }

        String Application::name()
        {
            return isNameDefined() ? RT_PROJECT_NAME : "";
        }

        String Application::link()
        {
            return isLinkDefined() ? RT_PROJECT_LINK : "";
        }

        String Application::describe()
        {
            return describe(false, false);
        }

        String Application::describe(bool includeOrganization /* = false */, bool includeLink /* = false */)
        {
            String d = name();

            if (includeOrganization) {
                d = organization() + "/" + d;
            }

            if (includeLink) {
                d += " <" + link() + ">";
            }

            return d;
        }

        String Application::describeAbridged()
        {
            return describe(false, false);
        }

        String Application::describeStandard()
        {
            return describe(true, false);
        }

        String Application::describeComplete()
        {
            return describe(true, true);
        }

    } /* CLOSE namespace About */

} /* CLOSE namespace RT */
