#include "PwdCommand.h"

void PwdCommand::Processing() {
    _msg = GetCurrentWorkingDirectory();
}
