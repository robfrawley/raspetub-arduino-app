/*
 * This file is part of the `src-run/raspetub-arduino-app` package.
 *
 * (c) Rob Frawley 2nd <rmf@src.run>
 *
 * For the full copyright and license information, view the LICENSE.md
 * file distributed with this source code.
 */

#include "Cerberus.h"

namespace RT
{ /* BEGIN namespace RT */

    namespace Cerberus
    { /* BEGIN namespace Cerberus */

        Cerberus()
        {
            this->initialize(RT_CERBERUS_ENABLED, RT_CERBERUS_MAXIMUM_WAIT_MS);
        }

        Cerberus(bool enabled)
        {
            this->initialize(enabled, RT_CERBERUS_MAXIMUM_WAIT_MS);
        }

        Cerberus(bool enabled, unsigned int maximumWaitMs)
        {
            this->initialize(enabled, maximumWaitMs);
        }

        Cerberus(unsigned int maximumWaitMs)
        {
            this->initialize(RT_CERBERUS_ENABLED, maximumWaitMs);
        }

        Cerberus(unsigned int maximumWaitMs, bool enabled)
        {
            this->initialize(enabled, maximumWaitMs);
        }

        void Cerberus::initialize(bool enabled, unsigned int maximumWaitMs)
        {
            this->enabled = enabled;
            this->maximumWaitMs = maximumWaitMs;
        }

    } // namespace Cerberus

} // namespace RT