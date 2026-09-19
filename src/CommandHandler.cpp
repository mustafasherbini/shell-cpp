#include <string>

enum status {
    Exit,
    Done,
    NotFound
};
class CommandHandler {

public:
    static status Processing(const std::string& command) {

        if (command=="exit")
            return Exit;

        return NotFound;
    }

};