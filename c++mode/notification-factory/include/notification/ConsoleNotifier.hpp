#ifndef NOTIFICATION_CONSOLENOTIFIER_HPP
#define NOTIFICATION_CONSOLENOTIFIER_HPP

#include "INotifier.hpp"

namespace notification {

class ConsoleNotifier : public INotifier {
 public:
  void send(const std::string& receiver,
            const std::string& message) const override;

  std::string name() const override;
};

}  // namespace notification

#endif
