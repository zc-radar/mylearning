#include "ConsoleNotifier.hpp"

#include <iostream>

namespace notification {

void ConsoleNotifier::send(const std::string& receiver,
                           const std::string& message) const {
  std::cout << "[CONSOLE] To: " << receiver << ", Message: " << message << '\n';
}

std::string ConsoleNotifier::name() const { return "console"; }

}  // namespace notification
