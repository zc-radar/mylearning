#include "NotifierFactory.hpp"

#include <memory>
#include <stdexcept>

#include "ConsoleNotifier.hpp"
#include "EmailNotifier.hpp"
#include "SmsNotifier.hpp"

namespace notification {

std::unique_ptr<INotifier> NotifierFactory::createNotifier(
    const std::string& type) {
  if (type == "email") {
    return std::make_unique<EmailNotifier>();
  }

  if (type == "sms") {
    return std::make_unique<SmsNotifier>();
  }

  if (type == "console") {
    return std::make_unique<ConsoleNotifier>();
  }

  throw std::invalid_argument("Unknown notifier type: " + type);
}

}  // namespace notification
