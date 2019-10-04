##
## This file is part of the `src-run/raspetub-arduino-app` package.
##
## (c) Rob Frawley 2nd <rmf@src.run>
##
## For the full copyright and license information, view the LICENSE.md
## file distributed with this source code.
##

# import required external code
from enum import Enum


class DebugLogger:
    class VerbType(Enum):
        SILENT = -2
        QUIET = -1
        NORMAL = 0
        VERBOSE = 1
        DEBUG = 2

    class ExecMode(Enum):
        NO_WRITE = -2
        NO_WRITE_TO_FILE = -1
        DO_WRITE_TO_CONSOLE = 0
        DO_WRITE_TO_FILE = 1
        DO_WRITE_TO_BOTH = 2

    def __init__(self, verb_type: VerbType, exec_mode: ExecMode, file_path=False):
        self.verb_type = verb_type
        self.exec_mode = exec_mode
        self.file_path = file_path

        if exec_mode.value > 0:
            if not file_path:
                self.write('Invalid execution mode "%s": log file path is not set.', exec_mode.name)



    def write(self, string_format, *replacements):
        pass
