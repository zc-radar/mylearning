#ifndef NOTIFICATION_NOTIFIERFACTORY_HPP
#define NOTIFICATION_NOTIFIERFACTORY_HPP

#include <memory>
#include <string>

#include "INotifier.hpp"

namespace notification {

class NotifierFactory {
 public:
  static std::unique_ptr<INotifier> createNotifier(const std::string& type);
};

}  // namespace notification

#endif
