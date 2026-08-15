#include "EmailNotifier.hpp"

#include <iostream>

namespace notification {

void EmailNotifier::send(const std::string& receiver,
                         const std::string& message) const {
  std::cout << "[EMAIL] To: " << receiver << ", Message: " << message << '\n';
}

std::string EmailNotifier::name() const { return "email"; }

}  // namespace notification
