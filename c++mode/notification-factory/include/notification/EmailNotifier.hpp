#ifndef NOTIFICATION_EMAILNOTIFIER_HPP
#define NOTIFICATION_EMAILNOTIFIER_HPP

#include <string>

#include "INotifier.hpp"

namespace notification {

class EmailNotifier : public INotifier {
 public:
  void send(const std::string& receiver,
            const std::string& message) const override;

  std::string name() const override;
};

}  // namespace notification

#endif
