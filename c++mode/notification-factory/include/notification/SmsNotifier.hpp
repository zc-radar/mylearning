#ifndef NOTIFICATION_SMSNOTIFIER_HPP
#define NOTIFICATION_SMSNOTIFIER_HPP

#include "INotifier.hpp"

namespace notification {

class SmsNotifier : public INotifier {
 public:
  void send(const std::string& receiver,
            const std::string& message) const override;

  std::string name() const override;
};

}  // namespace notification

#endif
