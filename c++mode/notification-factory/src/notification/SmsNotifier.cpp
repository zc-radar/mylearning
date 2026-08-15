#include "SmsNotifier.hpp"

#include <iostream>

namespace notification {

void SmsNotifier::send(const std::string& receiver,
                       const std::string& message) const {
  std::cout << "[SMS] To: " << receiver << ", Message: " << message << '\n';
}

std::string SmsNotifier::name() const { return "sms"; }

}  // namespace notification
